
+++
authors = ["grid47"]
title = "Leetcode 1910: Remove All Occurrences of a Substring"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1910: Remove All Occurrences of a Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d74CJIqw268"
youtube_upload_date="2021-07-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d74CJIqw268/maxresdefault.webp"
comments = true
+++



---
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed. Find the leftmost occurrence of the substring part and remove it from s. Return s after removing all occurrences of part.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings: s and part. s is the main string, and part is the substring to be removed.
- **Example:** `s = "abcdefghabcxyz", part = "abc"`
- **Constraints:**
	- 1 <= s.length <= 1000
	- 1 <= part.length <= 1000
	- s and part consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string s after all occurrences of part have been removed.
- **Example:** `"defghxyz"`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To remove all occurrences of part from s, starting with the leftmost and continuing until no more occurrences remain.

- Iterate over the string s and remove the leftmost occurrence of part.
- After each removal, continue searching for the next occurrence of part.
- Repeat until no more occurrences of part exist in the string.
{{< dots >}}
### Problem Assumptions ✅
- The part substring will be checked for removal until no more occurrences exist.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abcdefghabcxyz", part = "abc"`  \
  **Explanation:** By removing 'abc' starting from index 0, then index 4, we are left with the string 'defghxyz'.

{{< dots >}}
## Approach 🚀
The approach involves repeatedly finding and removing the leftmost occurrence of part in s until no more instances of part are present.

### Initial Thoughts 💭
- We need an efficient method to perform substring search and removal.
- Using string search and manual removal will be the main technique.
{{< dots >}}
### Edge Cases 🌐
- If the string s or part is empty, handle gracefully.
- Ensure the solution works efficiently for the maximum string length of 1000.
- Handle cases where s and part are the same.
- s and part must be non-empty and contain lowercase English letters.
{{< dots >}}
## Code 💻
```cpp
string removeOccurrences(string s, string part) {
    string x = s;
    int m = part.size(), n = s.size(), i, j;
    for(i = 0, j = 0; i < n; i++) {
        x[j++] = s[i];
        if (j >= m && x.substr(j - m, m) == part)
            j -= m;
    }
    return x.substr(0, j);
}
```

This function removes all occurrences of a substring 'part' from string 's' by scanning through the string and adjusting the position accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string removeOccurrences(string s, string part) {
	```
	Define a function 'removeOccurrences' which takes two strings 's' and 'part' as input.

2. **Variable Initialization**
	```cpp
	    string x = s;
	```
	Initialize a new string 'x' with the value of string 's' to modify the string without affecting the original.

3. **Variable Declaration**
	```cpp
	    int m = part.size(), n = s.size(), i, j;
	```
	Declare and initialize the variables: 'm' for the length of 'part', 'n' for the length of 's', and 'i' and 'j' for loop indices.

4. **Loop Setup**
	```cpp
	    for(i = 0, j = 0; i < n; i++) {
	```
	Start a loop that iterates over each character of string 's'.

5. **Character Assignment**
	```cpp
	        x[j++] = s[i];
	```
	Copy each character from 's' to 'x', increasing the index 'j' as we progress through the string.

6. **Substring Check**
	```cpp
	        if (j >= m && x.substr(j - m, m) == part)
	```
	Check if the last 'm' characters of 'x' match the substring 'part'. If so, adjust the index 'j' to remove the matched part.

7. **Rollback Indices**
	```cpp
	            j -= m;
	```
	If the substring 'part' is found, roll back the index 'j' by 'm' to remove the last occurrence.

8. **Return Statement**
	```cpp
	    return x.substr(0, j);
	```
	Return the modified string 'x' up to the last valid character position 'j'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of string s.
- **Average Case:** O(n * m), where n is the length of s and m is the length of part.
- **Worst Case:** O(n * m), where n is the length of s and m is the length of part.

The best case occurs when no occurrences of part are found in s.

### Space Complexity 💾
- **Best Case:** O(1), if no new string is created during processing.
- **Worst Case:** O(n), where n is the length of string s.

We store the result string after performing all removals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/)

---
{{< youtube d74CJIqw268 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
