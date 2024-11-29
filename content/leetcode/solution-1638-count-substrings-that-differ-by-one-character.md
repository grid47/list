
+++
authors = ["grid47"]
title = "Leetcode 1638: Count Substrings That Differ by One Character"
date = "2024-05-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1638: Count Substrings That Differ by One Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QOmHQiUMBuI"
youtube_upload_date="2020-10-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QOmHQiUMBuI/maxresdefault.webp"
comments = true
+++



---
Given two strings s and t, count the number of ways to choose a non-empty substring of s and replace exactly one character such that the resulting substring becomes a substring of t. In other words, find how many substrings in s differ from substrings in t by exactly one character.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings s and t. Both strings are lowercase English letters.
- **Example:** `s = "cat", t = "bat"`
- **Constraints:**
	- 1 <= s.length, t.length <= 100
	- s and t consist of lowercase English letters only.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the number of substrings in s that differ from some substring in t by exactly one character.
- **Example:** `Output: 3`
- **Constraints:**
	- The output will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many substrings in s differ by exactly one character from substrings in t.

- Iterate over all possible substrings of s and t.
- For each pair of substrings, check if they differ by exactly one character.
- Count the number of valid substring pairs.
{{< dots >}}
### Problem Assumptions ✅
- The strings s and t will always contain at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "cat", t = "bat"`  \
  **Explanation:** The substrings that differ by exactly one character are 'cat' vs 'bat', which gives a count of 3.

{{< dots >}}
## Approach 🚀
We will solve this problem by iterating through all possible substrings of s and t, checking if they differ by exactly one character, and counting those pairs.

### Initial Thoughts 💭
- Checking every pair of substrings from s and t is a brute force approach.
- Optimizing the approach to check for only those substrings that are similar in size might improve performance.
{{< dots >}}
### Edge Cases 🌐
- Both strings will have at least one character, so no need to handle empty inputs.
- For large inputs, the algorithm may need optimization to avoid exceeding time limits.
- Substrings of length 1 should be handled carefully.
- Ensure that the algorithm works for all valid lengths of strings.
{{< dots >}}
## Code 💻
```cpp
int countSubstrings(string s, string t) {
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        res += helper(s, t, i, 0);
    for(int j = 1; j < t.size(); j++)
        res += helper(s, t, 0, j);
    return res;
}

int helper(string s, string t, int i, int j) {
    int res = 0, pre = 0, cur = 0;
    for(int n = s.size(), m = t.size(); i < n && j < m; i++, j++) {
        cur++;
        if(s[i] != t[j]) {
            pre = cur;
            cur = 0;
        }
        res += pre;
    }
    return res;
}
```

This function counts the number of substrings where characters from strings 's' and 't' match at corresponding positions, using a helper function for the matching process.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int countSubstrings(string s, string t) {
	```
	Define the method 'countSubstrings' that takes two strings, 's' and 't', as input and calculates the number of matching substrings.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize a result variable 'res' to store the total count of matching substrings.

3. **Loop Constructs**
	```cpp
	    for(int i = 0; i < s.size(); i++)
	```
	Start a loop that iterates over the string 's' from the first to the last character.

4. **Function Call**
	```cpp
	        res += helper(s, t, i, 0);
	```
	Call the helper function for each starting position 'i' in string 's' and fixed starting position 0 in string 't'.

5. **Loop Constructs**
	```cpp
	    for(int j = 1; j < t.size(); j++)
	```
	Start another loop that iterates over the string 't' from the second character to the last.

6. **Function Call**
	```cpp
	        res += helper(s, t, 0, j);
	```
	Call the helper function for each starting position 'j' in string 't' and fixed starting position 0 in string 's'.

7. **Return Statement**
	```cpp
	    return res;
	```
	Return the final result, which is the total number of matching substrings.

8. **Helper Function Definition**
	```cpp
	int helper(string s, string t, int i, int j) {
	```
	Define the helper function that counts matching substrings starting from the given positions 'i' in string 's' and 'j' in string 't'.

9. **Variable Initialization**
	```cpp
	    int res = 0, pre = 0, cur = 0;
	```
	Initialize variables 'res' for the total count of matches, 'pre' for tracking previous matches, and 'cur' for the current matching length.

10. **Loop Constructs**
	```cpp
	    for(int n = s.size(), m = t.size(); i < n && j < m; i++, j++) {
	```
	Start a loop that iterates over the strings 's' and 't' as long as both indices 'i' and 'j' are within the bounds of their respective strings.

11. **Mathematical Operations**
	```cpp
	        cur++;
	```
	Increment the 'cur' variable as we find a matching character at the current positions 'i' and 'j'.

12. **Conditional Statement**
	```cpp
	        if(s[i] != t[j]) {
	```
	Check if the characters at positions 'i' in string 's' and 'j' in string 't' do not match.

13. **Variable Update**
	```cpp
	            pre = cur;
	```
	If the characters don't match, store the value of 'cur' (the length of the previous match) in 'pre'.

14. **Variable Reset**
	```cpp
	            cur = 0;
	```
	Reset 'cur' to 0 because the match was broken.

15. **Mathematical Operations**
	```cpp
	        res += pre;
	```
	Add the value of 'pre' (previous match length) to 'res'.

16. **Return Statement**
	```cpp
	    return res;
	```
	Return the total number of matching substrings found by the helper function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we are generating and comparing all possible substrings.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to storing all possible substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/)

---
{{< youtube QOmHQiUMBuI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
