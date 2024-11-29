
+++
authors = ["grid47"]
title = "Leetcode 392: Is Subsequence"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 392: Is Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/392.webp"
youtube = "M_OB20n4hfo"
youtube_upload_date="2024-06-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/M_OB20n4hfo/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/392.webp" 
    alt="A sequence of characters gently forming into a subsequence, glowing as each match is found."
    caption="Solution to LeetCode 392: Is Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two strings s and t, return true if s is a subsequence of t, or false otherwise. A subsequence is formed by deleting some characters of t while maintaining the relative order of the remaining characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, s and t.
- **Example:** `s = 'abc', t = 'ahbgdc'`
- **Constraints:**
	- 0 <= s.length <= 100
	- 0 <= t.length <= 10^4
	- s and t consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean indicating whether s is a subsequence of t.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be true if s is a subsequence of t, otherwise false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if string s can be derived from string t by deleting characters while preserving the order of the remaining characters.

- Use two pointers to traverse both strings.
- Start with both pointers at the beginning of their respective strings.
- Move through string t and match characters with string s one by one.
- If all characters in s are matched in order, return true, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- Both strings consist only of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abc', t = 'ahbgdc'`  \
  **Explanation:** Starting with pointers at the beginning of both strings, 'a' matches, then 'b' matches, and finally 'c' matches in order, so 'abc' is a subsequence of 'ahbgdc'.

- **Input:** `Input: s = 'axc', t = 'ahbgdc'`  \
  **Explanation:** Starting from the first letter of both strings, 'a' matches, but 'x' does not appear in order in 'ahbgdc', so 'axc' is not a subsequence of 'ahbgdc'.

{{< dots >}}
## Approach 🚀
The problem can be efficiently solved using a two-pointer technique to traverse both strings and check if all characters of s appear in t in the same order.

### Initial Thoughts 💭
- We need to check whether every character in string s can be found in order in string t.
- This problem can be solved efficiently with O(n) time complexity using two pointers to traverse both strings.
{{< dots >}}
### Edge Cases 🌐
- When s is an empty string, it is always a subsequence of any string, so return true.
- The solution should handle the case where t is large (up to 10^4 characters).
- If s is longer than t, it is impossible for s to be a subsequence of t, so return false.
- The solution should be optimized to handle t with lengths up to 10^4 efficiently.
{{< dots >}}
## Code 💻
```cpp
bool isSubsequence(string s, string t) {
    if(s == "") return true;
    int sdx = 0, tdx = 0;
    // sdx is sub seq of tdx

    for(; tdx < t.size(); tdx++) {
        if(t[tdx] == s[sdx]) sdx++;
        if(sdx == s.size()) return true;
    }
    return false;
}
```

This function checks whether string 's' is a subsequence of string 't'. It iterates through 't' and compares characters with 's'. If all characters of 's' are found in 't' in the correct order, it returns true, otherwise false.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isSubsequence(string s, string t) {
	```
	Define the function 'isSubsequence' that takes two strings 's' and 't'. It will return a boolean value indicating whether 's' is a subsequence of 't'.

2. **Edge Case Handling**
	```cpp
	    if(s == "") return true;
	```
	Handle the edge case where 's' is an empty string. An empty string is considered a subsequence of any string, so return true.

3. **Variable Initialization**
	```cpp
	    int sdx = 0, tdx = 0;
	```
	Initialize two variables 'sdx' (for the index in string 's') and 'tdx' (for the index in string 't').

4. **For Loop**
	```cpp
	    for(; tdx < t.size(); tdx++) {
	```
	Start a for loop that iterates through each character in string 't' using 'tdx' as the index.

5. **Character Comparison**
	```cpp
	        if(t[tdx] == s[sdx]) sdx++;
	```
	Check if the current character of 't' matches the current character of 's'. If they match, increment 'sdx' to move to the next character in 's'.

6. **Subsequence Check**
	```cpp
	        if(sdx == s.size()) return true;
	```
	If all characters of 's' are found in 't' (i.e., 'sdx' reaches the size of 's'), return true, indicating that 's' is a subsequence of 't'.

7. **Return Statement**
	```cpp
	    return false;
	```
	If the loop completes and not all characters of 's' were found in 't', return false, indicating that 's' is not a subsequence of 't'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of string t, since we only traverse the strings once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/is-subsequence/description/)

---
{{< youtube M_OB20n4hfo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
