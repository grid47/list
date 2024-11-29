
+++
authors = ["grid47"]
title = "Leetcode 1737: Change Minimum Characters to Satisfy One of Three Conditions"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1737: Change Minimum Characters to Satisfy One of Three Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RRiBv833lVQ"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/RRiBv833lVQ/maxresdefault.jpg"
comments = true
+++



---
You are given two strings, `a` and `b`, consisting of lowercase letters. In one operation, you can change any character in either string to any lowercase letter. Your goal is to perform the minimum number of operations to satisfy one of the following three conditions:

1) Every character in string `a` is strictly less than every character in string `b` alphabetically.
2) Every character in string `b` is strictly less than every character in string `a` alphabetically.
3) Both `a` and `b` consist of only one distinct character.

Return the minimum number of operations needed to achieve one of these conditions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings `a` and `b` that consist of lowercase letters.
- **Example:** `Input: a = "cbd", b = "bbf"`
- **Constraints:**
	- 1 <= a.length, b.length <= 10^5
	- Strings `a` and `b` consist only of lowercase letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to satisfy one of the three conditions mentioned above.
- **Example:** `Output: 3`
- **Constraints:**
	- The number of operations should be minimized while achieving one of the valid conditions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the minimum number of operations needed to achieve one of the valid conditions by analyzing the frequency of characters in both strings.

- 1. Calculate the frequency of characters in both strings `a` and `b`.
- 2. Check each of the three conditions and calculate the number of operations needed for each.
- 3. Return the minimum number of operations required.
{{< dots >}}
### Problem Assumptions ✅
- The input strings will always be valid, containing only lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = "aba", b = "caa"`  \
  **Explanation:** We can achieve a valid condition in 2 operations: Change `b` to `ccc` (operation 1), making all characters in `a` less than those in `b`.

- **Input:** `Input: a = "dabadd", b = "cda"`  \
  **Explanation:** The best solution is to change all characters in `b` to 'e' (operation 3), making every character in `a` less than those in `b`.

{{< dots >}}
## Approach 🚀
We can solve this problem by analyzing the frequency of each character in both strings `a` and `b`. Then, we calculate the number of operations required for each condition and return the minimum number.

### Initial Thoughts 💭
- We need to compare the characters in both strings to find the best way to satisfy one of the conditions.
- Instead of modifying characters one by one, we can analyze the frequency distribution to determine the minimum number of operations needed.
{{< dots >}}
### Edge Cases 🌐
- The input strings will always have at least one character.
- For large inputs (e.g., 10^5 characters), ensure that the solution handles the character counting efficiently.
- Consider edge cases where the strings already satisfy one of the conditions.
- The solution must work within the constraints where `a` and `b` can have lengths up to 10^5.
{{< dots >}}
## Code 💻
```cpp
class Solution {
typedef long long ll;
public:
int minCharacters(string a, string b) {
    int m = a.size(), n = b.size();
    vector<int> ca(26, 0), cb(26, 0);
    for(int i = 0; i < m; i++) {
        ca[a[i] - 'a']++; }
    for(int j = 0; j < n; j++) {
        cb[b[j] - 'a']++; }
    
    int res = m + n;
    for(int i = 0; i < 26; i++) {
        res = min(res, m + n - ca[i] - cb[i]);
        if(i > 0) {

     ca[i] += ca[i - 1];
     cb[i] += cb[i - 1];
            }
        if(i < 25) {
res = min(res, m - ca[i] + cb[i]);
res = min(res, n - cb[i] + ca[i]);

        }
        
        }
    return res;
}
```

This function calculates the minimum number of changes needed to make two strings distinct by modifying one character at a time. It calculates the frequency of each character in both strings, and then computes the minimum number of changes based on those frequencies.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	This line defines the class `Solution`, which contains the main logic for solving the problem.

2. **Type Alias**
	```cpp
	typedef long long ll;
	```
	Here, a type alias `ll` is defined for `long long` to simplify the code and make it more readable.

3. **Access Modifier**
	```cpp
	public:
	```
	This access modifier makes the following methods accessible outside the class.

4. **Function Declaration**
	```cpp
	int minCharacters(string a, string b) {
	```
	The function `minCharacters` is declared, taking two string inputs `a` and `b`. It returns the minimum number of changes required to make the strings distinct.

5. **Variable Initialization**
	```cpp
	    int m = a.size(), n = b.size();
	```
	Here, the sizes of the input strings `a` and `b` are stored in variables `m` and `n` respectively.

6. **Array Initialization**
	```cpp
	    vector<int> ca(26, 0), cb(26, 0);
	```
	Two vectors `ca` and `cb` are initialized to store the frequency of each character (from 'a' to 'z') in the strings `a` and `b`.

7. **Loop Start**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	This loop iterates through the characters in string `a`.

8. **Character Counting**
	```cpp
	        ca[a[i] - 'a']++; }
	```
	For each character in `a`, the frequency count in vector `ca` is incremented based on the character's position in the alphabet.

9. **Loop Start**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	This loop iterates through the characters in string `b`.

10. **Character Counting**
	```cpp
	        cb[b[j] - 'a']++; }
	```
	For each character in `b`, the frequency count in vector `cb` is incremented based on the character's position in the alphabet.

11. **Blank**
	```cpp
	    
	```
	A blank line used for clarity between code sections.

12. **Initial Result Calculation**
	```cpp
	    int res = m + n;
	```
	The variable `res` is initialized to the sum of the lengths of `a` and `b`, representing the worst case where all characters need to be modified.

13. **Loop Start**
	```cpp
	    for(int i = 0; i < 26; i++) {
	```
	This loop iterates through each character (from 'a' to 'z') to calculate the minimum number of changes.

14. **Frequency Comparison**
	```cpp
	        res = min(res, m + n - ca[i] - cb[i]);
	```
	For each character, this line updates `res` to the minimum number of changes by comparing the sum of `m + n` and the frequency counts in `ca` and `cb`.

15. **Condition Check**
	```cpp
	        if(i > 0) {
	```
	This condition checks if `i` is greater than 0 to avoid out-of-bounds errors when updating the frequencies.

16. **Blank**
	```cpp
	
	```
	An empty line for better readability.

17. **Prefix Sum Calculation**
	```cpp
	     ca[i] += ca[i - 1];
	```
	This line accumulates the frequencies in `ca` to create a prefix sum for efficient range queries.

18. **Prefix Sum Calculation**
	```cpp
	     cb[i] += cb[i - 1];
	```
	This line accumulates the frequencies in `cb` to create a prefix sum for efficient range queries.

19. **Condition Check**
	```cpp
	        if(i < 25) {
	```
	This condition checks if `i` is less than 25 to ensure no out-of-bounds error occurs when accessing elements beyond the last valid index.

20. **Frequency Comparison**
	```cpp
	res = min(res, m - ca[i] + cb[i]);
	```
	This line updates `res` by considering the frequency of characters between the two strings after the prefix sums have been calculated.

21. **Frequency Comparison**
	```cpp
	res = min(res, n - cb[i] + ca[i]);
	```
	This line updates `res` again by considering the reversed situation, checking the frequency differences.

22. **Blank**
	```cpp
	
	```
	An empty line for readability.

23. **Block End**
	```cpp
	        }
	```
	Closing the block of code that compares the frequencies and updates the result `res`.

24. **Return**
	```cpp
	    return res;
	```
	This line returns the calculated result `res`, which represents the minimum number of changes required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where `n` and `m` are the lengths of strings `a` and `b`, respectively.
- **Average Case:** O(n + m), as we need to process both strings.
- **Worst Case:** O(n + m), due to the same reasons above.

The time complexity is linear in the length of the input strings, O(n + m), where `n` and `m` are the lengths of the strings `a` and `b`.

### Space Complexity 💾
- **Best Case:** O(1), as the space required does not change with the input size.
- **Worst Case:** O(1), as the space required is constant and depends only on the size of the character frequency array (26 elements).

The space complexity is constant, O(1), since we only store the frequency counts for the 26 lowercase letters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/description/)

---
{{< youtube RRiBv833lVQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
