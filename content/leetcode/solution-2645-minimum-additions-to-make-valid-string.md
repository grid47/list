
+++
authors = ["grid47"]
title = "Leetcode 2645: Minimum Additions to Make Valid String"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2645: Minimum Additions to Make Valid String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7IAA0sdeACw"
youtube_upload_date="2023-04-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7IAA0sdeACw/maxresdefault.webp"
comments = true
+++



---
Given a string 'word' consisting of letters 'a', 'b', and 'c', you can insert letters 'a', 'b', or 'c' anywhere and as many times as needed. Your task is to determine the minimum number of insertions required to transform 'word' into a valid string. A string is considered valid if it can be formed by repeatedly concatenating the string 'abc'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single string 'word' containing only the characters 'a', 'b', and 'c'.
- **Example:** `word = 'ab'`
- **Constraints:**
	- 1 <= word.length <= 50
	- word consists of only the characters 'a', 'b', and 'c'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of insertions required to make the string valid, i.e., form 'abc' repeatedly.
- **Example:** `Output: 1`
- **Constraints:**
	- The output should be a non-negative integer representing the minimum number of insertions needed.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the number of insertions needed to convert the input string into a valid 'abc' repeated string.

- Step 1: Track the expected character sequence ('a', 'b', 'c') as you iterate through the string.
- Step 2: If the character in the string does not match the expected one, count the number of insertions required and update the expected character.
- Step 3: After processing the string, handle any remaining expected characters by inserting them.
{{< dots >}}
### Problem Assumptions ✅
- Each string will only contain 'a', 'b', and 'c'.
- The string may not initially form a valid 'abc' repeated pattern.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: word = 'ab'`  \
  **Explanation:** The string 'ab' is missing 'c' to form 'abc'. So, we need 1 insertion (add 'c') to make the string valid.

- **Input:** `Input: word = 'aab'`  \
  **Explanation:** The string 'aab' is missing 'c' after the first 'a'. We need to insert 'c' after the second 'a' to make it valid, resulting in 1 insertion.

{{< dots >}}
## Approach 🚀
The approach is to iterate through the string while keeping track of the expected character ('a', 'b', or 'c'). If the current character does not match the expected one, we insert the required characters to complete the 'abc' pattern.

### Initial Thoughts 💭
- The string should follow the 'abc' pattern, so we need to ensure the correct sequence of characters is maintained.
- We need to count how many characters need to be inserted to make the string valid.
{{< dots >}}
### Edge Cases 🌐
- Empty strings are not allowed as per the problem constraints.
- Ensure the solution handles strings close to the upper limit of length 50 efficiently.
- Consider cases where the string is already valid (e.g., 'abc').
- The solution should work efficiently for strings of length up to 50.
{{< dots >}}
## Code 💻
```cpp
int addMinimum(string word) {
    int exp = 0, res = 0;
    int n = word.size();
    for(int i = 0; i < n; i++) {
        if(exp == (word[i] - 'a')) {
            exp = (exp + 1) % 3;
            continue;
        }
        while(exp != (word[i] - 'a')) {
            res++;
            exp = (exp + 1) % 3;
        }
        exp = (exp + 1) % 3;            
        // cout << i << " " << res << " " << exp << "\n";
    }
    if(word[n - 1] == 'a') res += 2;
    if(word[n - 1] == 'b') res += 1;
    return res;
}
```

This function calculates the minimum number of insertions required to make a string alternating between 'a' and 'b'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int addMinimum(string word) {
	```
	This line defines the function 'addMinimum', which takes a string 'word' as input and returns an integer value.

2. **Variable Declaration**
	```cpp
	    int exp = 0, res = 0;
	```
	Here, 'exp' tracks the expected character ('a' or 'b'), and 'res' counts the number of insertions needed.

3. **Length Calculation**
	```cpp
	    int n = word.size();
	```
	This line calculates the length of the input string 'word' and stores it in the variable 'n'.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to iterate through each character in the string 'word'.

5. **Check Expected Character**
	```cpp
	        if(exp == (word[i] - 'a')) {
	```
	This conditional checks if the current character matches the expected character ('a' or 'b').

6. **Update Expected Character**
	```cpp
	            exp = (exp + 1) % 3;
	```
	If the character matches, 'exp' is updated to the next expected character in a cyclic manner (0 -> 1 -> 2 -> 0).

7. **Continue to Next Iteration**
	```cpp
	            continue;
	```
	If the character matches, the loop moves to the next iteration without performing further actions.

8. **While Loop for Insertions**
	```cpp
	        while(exp != (word[i] - 'a')) {
	```
	This 'while' loop runs when the current character does not match the expected character.

9. **Increment Insertions**
	```cpp
	            res++;
	```
	If the character doesn't match the expected one, an insertion is counted, and 'res' is incremented.

10. **Update Expected Character Inside While Loop**
	```cpp
	            exp = (exp + 1) % 3;
	```
	The expected character is updated after each insertion, cycling through 'a' and 'b'.

11. **Update Expected Character**
	```cpp
	        exp = (exp + 1) % 3;            
	```
	This updates the expected character after processing each character in the string.

12. **Check Last Character for Insertions**
	```cpp
	    if(word[n - 1] == 'a') res += 2;
	```
	If the last character of the string is 'a', two insertions are needed to make the string alternating.

13. **Check Last Character for Insertions**
	```cpp
	    if(word[n - 1] == 'b') res += 1;
	```
	If the last character of the string is 'b', one insertion is needed to make the string alternating.

14. **Return Result**
	```cpp
	    return res;
	```
	Finally, the function returns the total number of insertions required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity remains linear in all cases, as we simply iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few variables to track the state of the expected character and the insertion count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/)

---
{{< youtube 7IAA0sdeACw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
