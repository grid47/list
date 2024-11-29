
+++
authors = ["grid47"]
title = "Leetcode 2222: Number of Ways to Select Buildings"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2222: Number of Ways to Select Buildings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EcQ0uhiF3HU"
youtube_upload_date="2022-04-02"
youtube_thumbnail="https://i.ytimg.com/vi/EcQ0uhiF3HU/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string `s` that represents the types of buildings along a street. Each building is either an office ('0') or a restaurant ('1'). You are tasked with selecting 3 buildings for inspection, with the constraint that no two consecutive buildings in the selection can be of the same type. Return the number of valid ways to select 3 buildings where no two consecutive buildings are of the same type.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string `s`, where each character is either '0' (for an office) or '1' (for a restaurant).
- **Example:** `s = '101010'`
- **Constraints:**
	- 3 <= s.length <= 10^5
	- s[i] is either '0' or '1'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid ways to select 3 buildings such that no two consecutive buildings are of the same type.
- **Example:** `Output: 4`
- **Constraints:**
	- The input string will always have at least three characters.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count all possible valid selections of 3 buildings such that no two consecutive buildings in the selected set are of the same type.

- Count the total number of '0's and '1's in the string.
- Iterate through the string and, for each character, calculate how many valid combinations of 3 buildings can be made, taking care to avoid consecutive buildings of the same type.
- Use efficient counting to avoid checking each triplet explicitly.
{{< dots >}}
### Problem Assumptions ✅
- The string will always have at least three characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = '101010'`  \
  **Explanation:** The valid selections of 3 buildings are: [0, 2, 4], [0, 2, 5], [1, 2, 4], and [1, 2, 5]. Each of these selections alternates between '0' and '1', making them valid.

- **Input:** `Input: s = '11100'`  \
  **Explanation:** There are no valid selections, as all possible combinations of 3 buildings either have consecutive '1's or '0's, violating the problem's constraints.

{{< dots >}}
## Approach 🚀
The approach focuses on counting how many valid selections of 3 buildings can be made by iterating through the string and using efficient counting of '0's and '1's.

### Initial Thoughts 💭
- Each selection of 3 buildings must alternate between '0' and '1'.
- We can use efficient counting and combinatorics to avoid explicitly checking all possible triplets.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least 3 characters, so empty inputs are not a concern.
- The solution must be efficient enough to handle strings of length up to 100,000.
- Strings with consecutive identical characters (e.g., '000', '111') should return 0 valid selections.
- The string will always have at least 3 characters, and each character is either '0' or '1'.
{{< dots >}}
## Code 💻
```cpp
long long numberOfWays(string s) {

    typedef long long ll;

    int z = 0, o = 0;        
    int n = s.length();
    
    for(int i = 0; i < n; i++) {
        
        if(s[i] == '0') z++;
        if(s[i] == '1') o++;
        
    }

    int zl = 0, ol = 0;

    ll res = 0;
    
    for(int i = 0; i < n; i++) {
        
        if(s[i] == '0') {
            res += (ol * (o - ol));
            
            zl++;
        }
        else if(s[i] == '1') {
            res += (zl * (z - zl));            
            
            ol++;
        }
                                
    }
    
    return res;
}
```

This function calculates the number of ways to partition the input string `s` into two subsequences where the number of '0's and '1's are balanced in both. It iterates through the string, counting the occurrences of '0' and '1', and calculates a result based on the position of these values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long numberOfWays(string s) {
	```
	This is the function declaration of `numberOfWays`, which takes a string `s` and returns a `long long` integer representing the number of ways to partition the string into subsequences.

2. **Type Alias**
	```cpp
	    typedef long long ll;
	```
	This line defines a type alias `ll` for `long long` to make the code easier to read and more concise.

3. **Variable Initialization**
	```cpp
	    int z = 0, o = 0;        
	```
	Two integer variables, `z` and `o`, are initialized to count the number of '0's and '1's in the string `s` respectively.

4. **Length Calculation**
	```cpp
	    int n = s.length();
	```
	The length of the input string `s` is stored in the variable `n`.

5. **First Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This is the first loop that iterates through each character in the string `s`.

6. **Count '0'**
	```cpp
	        if(s[i] == '0') z++;
	```
	If the current character is '0', the variable `z` is incremented.

7. **Count '1'**
	```cpp
	        if(s[i] == '1') o++;
	```
	If the current character is '1', the variable `o` is incremented.

8. **Variable Initialization**
	```cpp
	    int zl = 0, ol = 0;
	```
	Two integer variables, `zl` and `ol`, are initialized to keep track of the count of '0's and '1's in the left subsequence during the iteration.

9. **Result Initialization**
	```cpp
	    ll res = 0;
	```
	The result variable `res` is initialized to 0. It will store the number of valid subsequences.

10. **Second Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This is the second loop that iterates through each character in the string `s`, processing each '0' and '1' to compute the result.

11. **Process '0'**
	```cpp
	        if(s[i] == '0') {
	```
	If the current character is '0', the corresponding calculation for `res` is performed based on the number of '1's seen so far and the remaining '1's.

12. **Update Result for '0'**
	```cpp
	            res += (ol * (o - ol));
	```
	The result `res` is updated by adding the product of the count of '1's in the left subsequence (`ol`) and the count of '1's in the right subsequence (`o - ol`).

13. **Update Left '0' Count**
	```cpp
	            zl++;
	```
	The count of '0's in the left subsequence is incremented.

14. **Process '1'**
	```cpp
	        else if(s[i] == '1') {
	```
	If the current character is '1', the corresponding calculation for `res` is performed based on the number of '0's seen so far and the remaining '0's.

15. **Update Result for '1'**
	```cpp
	            res += (zl * (z - zl));            
	```
	The result `res` is updated by adding the product of the count of '0's in the left subsequence (`zl`) and the count of '0's in the right subsequence (`z - zl`).

16. **Update Left '1' Count**
	```cpp
	            ol++;
	```
	The count of '1's in the left subsequence is incremented.

17. **Return Result**
	```cpp
	    return res;
	```
	The function returns the computed result `res`, which is the number of valid subsequences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input string, as we only need to iterate through the string once.
- **Average Case:** O(n), as each step involves constant-time operations.
- **Worst Case:** O(n), as the string length can go up to 10^5.

The time complexity is linear with respect to the length of the input string.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required except for counters.
- **Worst Case:** O(1), as the space usage is constant regardless of the input size.

The space complexity is constant, as only a few counters are needed.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-select-buildings/description/)

---
{{< youtube EcQ0uhiF3HU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
