
+++
authors = ["grid47"]
title = "Leetcode 2116: Check if a Parentheses String Can Be Valid"
date = "2024-04-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2116: Check if a Parentheses String Can Be Valid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kyyf-hiGeVc"
youtube_upload_date="2021-12-26"
youtube_thumbnail="https://i.ytimg.com/vi/kyyf-hiGeVc/maxresdefault.jpg"
comments = true
+++



---
You are given a string s consisting of parentheses '(' and ')', and a binary string locked of the same length. Each position in locked determines whether the corresponding character in s can be changed or not. If locked[i] is '1', the character s[i] cannot be modified, but if locked[i] is '0', you can change s[i] to either '(' or ')'. Your task is to determine if it is possible to make the string s a valid parentheses string by changing the positions where locked[i] is '0'. A valid parentheses string is defined by the following conditions: It is either '()', or a concatenation of valid parentheses strings, or it can be written as (A) where A is a valid parentheses string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s representing the parentheses and a binary string locked representing which characters can be modified.
- **Example:** `s = ')())(', locked = '01001'`
- **Constraints:**
	- 1 <= n <= 10^5
	- s consists of '(' and ')'.
	- locked consists of '0' and '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to make s a valid parentheses string by modifying the characters that correspond to '0' in locked. Otherwise, return false.
- **Example:** `For s = ')())(', locked = '01001', the output is true.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if it's possible to modify certain characters in s to make it a valid parentheses string.

- Check if the string length is even, as a valid parentheses string must have an even number of characters.
- Use a helper function to check the string from left to right, counting the open and closed parentheses while considering the positions where characters can be modified (i.e., where locked[i] = '0').
- Use another helper function to check the string from right to left to ensure the string can be balanced correctly from both directions.
{{< dots >}}
### Problem Assumptions ✅
- The input strings s and locked are non-empty.
- Each character in s is either '(' or ')'.
- Each character in locked is either '0' or '1'.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: s = ')())(', locked = '01001'`  \
  **Explanation:** In this example, we can change the characters at positions 1, 4, and 5 to balance the parentheses, resulting in a valid string. The output is true.

- **Input:** `Example 2: s = '(()', locked = '010'`  \
  **Explanation:** In this case, no modification can balance the parentheses, so the output is false.

{{< dots >}}
## Approach 🚀
The approach is to use a greedy method to count the number of valid parentheses from left to right and right to left while respecting the locked positions.

### Initial Thoughts 💭
- The length of the string must be even for it to potentially be valid.
- We need to track both the open and closed parentheses counts while considering the positions where characters can be changed.
- A two-pass solution works: one pass from left to right to handle opening parentheses and another from right to left for closing parentheses.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, it cannot be a valid parentheses string, so return false.
- Ensure the solution runs efficiently for the maximum input size of 100,000.
- If the string consists entirely of locked characters that already form a valid parentheses string, return true.
- The solution should run in O(n) time to handle the largest inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
bool canBeValid(string s, string lck) {
    
    return (s.size() % 2) == 0 && check(s, lck, '(') && check(s, lck, ')');
    
}

bool check(string s, string lck, char op) {

    int blk = 0, wild = 0;
    int n = s.size();

    int st  =  ( op == '(' ) ? 0 :  n - 1;
    int nd  =  ( op == '(' ) ? n - 1:  0;
    int dir =  ( op == '(' ) ? 1 : -1;

    for(int i = st; (i < n) && (i >= 0); i += dir) {

        if(lck[i] == '1') blk += (s[i] == op) ? 1: -1;
        else              wild++;

        if(blk + wild < 0) return false;

    }

    return blk <= wild;

}
```

This code defines two functions to check if a string of parentheses can be valid, considering blocked and wildcard positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool canBeValid(string s, string lck) {
	```
	Defines the main function `canBeValid`, which checks if the parentheses in the string `s` can be valid given the locking conditions in string `lck`.

2. **Return Statement**
	```cpp
	    return (s.size() % 2) == 0 && check(s, lck, '(') && check(s, lck, ')');
	```
	Checks if the size of the string `s` is even and both opening and closing parentheses can be valid by calling the `check` function for each.

3. **Function Definition**
	```cpp
	bool check(string s, string lck, char op) {
	```
	Defines the helper function `check`, which verifies if a certain type of parenthesis (`(` or `)`) can be correctly matched in string `s` considering the locking conditions in `lck`.

4. **Variable Initialization**
	```cpp
	    int blk = 0, wild = 0;
	```
	Initializes variables `blk` (for blocked parentheses) and `wild` (for wildcards).

5. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Stores the size of string `s` in variable `n`.

6. **Logic**
	```cpp
	    int st  =  ( op == '(' ) ? 0 :  n - 1;
	```
	Sets the starting index `st` based on whether the operator is `(` or `)`. For `(`, it starts from the beginning of the string, otherwise from the end.

7. **Logic**
	```cpp
	    int nd  =  ( op == '(' ) ? n - 1:  0;
	```
	Sets the end index `nd` based on whether the operator is `(` or `)`. For `(`, it ends at the last index, otherwise at the start.

8. **Logic**
	```cpp
	    int dir =  ( op == '(' ) ? 1 : -1;
	```
	Sets the direction of iteration (`dir`) based on whether the operator is `(` or `)`. For `(`, direction is positive (left to right), and for `)`, it's negative (right to left).

9. **Loop**
	```cpp
	    for(int i = st; (i < n) && (i >= 0); i += dir) {
	```
	Starts a loop from the calculated index `st`, iterating in the specified direction (`dir`) until the string bounds are reached.

10. **Conditional Logic**
	```cpp
	        if(lck[i] == '1') blk += (s[i] == op) ? 1: -1;
	```
	Checks if the current character is blocked. If so, adjusts the `blk` counter based on whether the character matches the operator (`op`).

11. **Increment**
	```cpp
	        else              wild++;
	```
	If the current character is not blocked, it increments the wildcard counter `wild`.

12. **Early Exit**
	```cpp
	        if(blk + wild < 0) return false;
	```
	If the sum of `blk` and `wild` becomes negative, it means the parentheses are invalid, so the function returns `false`.

13. **Return Statement**
	```cpp
	    return blk <= wild;
	```
	Returns `true` if the number of blocked parentheses is less than or equal to the number of wildcards, indicating a valid configuration.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input string s.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only use a constant amount of extra space to track counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/)

---
{{< youtube kyyf-hiGeVc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
