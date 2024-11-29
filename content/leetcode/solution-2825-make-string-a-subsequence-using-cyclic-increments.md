
+++
authors = ["grid47"]
title = "Leetcode 2825: Make String a Subsequence Using Cyclic Increments"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2825: Make String a Subsequence Using Cyclic Increments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SfXj_8QoeL8"
youtube_upload_date="2023-08-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SfXj_8QoeL8/maxresdefault.webp"
comments = true
+++



---
Given two strings, `str1` and `str2`, you can perform an operation on `str1` where you select a set of indices and increment the characters at those indices cyclically. The task is to check if it is possible to make `str2` a subsequence of `str1` by performing the operation at most once.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two strings `str1` and `str2` consisting only of lowercase English letters.
- **Example:** `str1 = 'abc', str2 = 'ad'`
- **Constraints:**
	- 1 <= str1.length <= 10^5
	- 1 <= str2.length <= 10^5
	- str1 and str2 consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it is possible to make `str2` a subsequence of `str1` by performing the operation at most once, otherwise return `false`.
- **Example:** `For `str1 = 'abc'`, `str2 = 'ad'`, the output should be `true`.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The task is to check if `str2` can be a subsequence of `str1` after performing the operation once.

- Loop through the characters of `str1` and try to match them with `str2`.
- If a match is found, check if the character in `str1` can be incremented to match the character in `str2`.
{{< dots >}}
### Problem Assumptions ✅
- The strings consist only of lowercase English letters.
- The operation can be applied at most once.
{{< dots >}}
## Examples 🧩
- **Input:** `For `str1 = 'abc'`, `str2 = 'ad'``  \
  **Explanation:** By incrementing the character at index 2 in `str1` to 'd', `str1` becomes 'abd' and `str2` is now a subsequence of `str1`.

{{< dots >}}
## Approach 🚀
The solution involves checking if the characters in `str2` can be matched with `str1` by performing the operation at most once.

### Initial Thoughts 💭
- Both strings consist of lowercase English letters.
- We can increment characters in `str1` to try and match `str2`.
- The matching needs to be done in sequence, and we should only increment characters when necessary.
{{< dots >}}
### Edge Cases 🌐
- If `str2` is empty, return `true` immediately.
- Ensure the solution works efficiently for the maximum input sizes.
- If `str1` and `str2` are already the same, return `true`.
- Handle large inputs within time limits.
{{< dots >}}
## Code 💻
```cpp
bool canMakeSubsequence(string s1, string s2) {
    int j = 0, n = s1.size(), m = s2.size();
    for (int i = 0; i < n && j < m; ++i)
        if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j])
            ++j;
    return j == m;
}
```

This function checks whether string 's2' can be formed as a subsequence of string 's1'. It iterates through both strings and matches characters under specific conditions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool canMakeSubsequence(string s1, string s2) {
	```
	The function 'canMakeSubsequence' is defined, taking two strings 's1' and 's2' as input. It returns a boolean value indicating whether 's2' can be formed as a subsequence of 's1'.

2. **Variable Initialization**
	```cpp
	    int j = 0, n = s1.size(), m = s2.size();
	```
	Variables 'j', 'n', and 'm' are initialized. 'j' is used to track the position in 's2', while 'n' and 'm' store the lengths of 's1' and 's2', respectively.

3. **Loop Start**
	```cpp
	    for (int i = 0; i < n && j < m; ++i)
	```
	A for loop starts, iterating through each character of 's1'. The loop continues as long as 'j' is less than the length of 's2' and 'i' is within the bounds of 's1'.

4. **Condition Check**
	```cpp
	        if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j])
	```
	A condition checks if the current character in 's1' is equal to the current character in 's2', or if they are consecutive characters in the alphabet (either 's1[i] + 1' or 's1[i] - 25' equals 's2[j]').

5. **Update Index**
	```cpp
	            ++j;
	```
	If the condition is true, increment 'j' to move to the next character in 's2'.

6. **Return Statement**
	```cpp
	    return j == m;
	```
	Return true if all characters in 's2' have been matched in sequence; otherwise, return false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of `str1`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only use a few extra variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/)

---
{{< youtube SfXj_8QoeL8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
