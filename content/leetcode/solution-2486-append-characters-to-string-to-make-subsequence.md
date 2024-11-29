
+++
authors = ["grid47"]
title = "Leetcode 2486: Append Characters to String to Make Subsequence"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2486: Append Characters to String to Make Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gKDmO8ZLRD8"
youtube_upload_date="2024-06-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gKDmO8ZLRD8/maxresdefault.webp"
comments = true
+++



---
You are given two strings, s and t, consisting only of lowercase English letters. Your task is to determine the minimum number of characters that need to be appended to the end of string s so that string t becomes a subsequence of s. A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two strings s and t consisting only of lowercase English letters.
- **Example:** `s = "hello", t = "world"`
- **Constraints:**
	- 1 <= s.length, t.length <= 10^5
	- Both s and t consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of characters that need to be appended to the end of string s so that t becomes a subsequence of s.
- **Example:** `Output: 4`
- **Constraints:**
	- The returned value will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum number of characters to append to make t a subsequence of s.

- 1. Initialize a pointer to iterate through string t.
- 2. Iterate through string s, and whenever a character in s matches the current character in t, move the pointer of t forward.
- 3. At the end, if all characters of t are found in s, return the difference between the length of t and the number of matched characters.
- 4. If not all characters of t are found in s, return the difference between the length of t and the number of matched characters.
{{< dots >}}
### Problem Assumptions ✅
- The solution assumes that both strings s and t contain only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "hello", t = "world"`  \
  **Explanation:** For s = "hello" and t = "world", we need to append 'w', 'o', 'r', 'l', 'd' to the end of s to make t a subsequence of s.

- **Input:** `s = "abcdef", t = "ace"`  \
  **Explanation:** For s = "abcdef" and t = "ace", no characters need to be appended since t is already a subsequence of s.

- **Input:** `s = "a", t = "abc"`  \
  **Explanation:** For s = "a" and t = "abc", we need to append 'b', 'c' to the end of s to make t a subsequence of s.

{{< dots >}}
## Approach 🚀
We will use a two-pointer approach to efficiently find the subsequence. One pointer will iterate through string s, and the other pointer will iterate through string t. As we go through s, we will try to match characters from t.

### Initial Thoughts 💭
- We need to find how much of t is already a subsequence of s.
- If we can match all characters of t in s, we won't need to append anything.
- The key idea is to use the fact that matching characters in s with t can be tracked using a pointer on t. If the pointer reaches the end of t, it means t is already a subsequence of s.
{{< dots >}}
### Edge Cases 🌐
- If t is empty, no characters need to be appended to s.
- For large strings (length up to 10^5), the solution must run in linear time O(n).
- If t is longer than s, all characters of t must be appended.
- The solution must handle inputs of size up to 10^5 efficiently.
{{< dots >}}
## Code 💻
```cpp
int appendCharacters(string s, string t) {
    int j = 0;
    for(int i = 0; i < s.size() && j < t.size(); i++) {
        j += s[i] == t[j];
    }
    return t.size()-j;
}
```

This function returns the minimum number of characters that need to be appended to string `s` to make it equal to string `t`. It checks the longest prefix of `t` that matches a suffix of `s`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int appendCharacters(string s, string t) {
	```
	This line defines the function `appendCharacters`, which takes two strings `s` and `t`, and returns an integer representing the number of characters to be appended to `s` to form `t.

2. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	Here, we initialize the variable `j` to 0. This will be used to track how many characters of `t` match the suffix of `s`.

3. **Loop for Matching Characters**
	```cpp
	    for(int i = 0; i < s.size() && j < t.size(); i++) {
	```
	This `for` loop iterates through each character of string `s`, while `j` is less than the length of string `t`. It tries to find a matching suffix of `s` that corresponds to a prefix of `t`.

4. **Character Comparison**
	```cpp
	        j += s[i] == t[j];
	```
	This line compares the characters at the current position in both strings `s` and `t`. If they match, `j` is incremented. `j` thus keeps track of the length of the matching prefix of `t`.

5. **Return Statement**
	```cpp
	    return t.size()-j;
	```
	After the loop ends, we return the difference between the size of `t` and `j`. This represents the number of characters that need to be appended to `s` to make it equal to `t`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of string s, as we only need to iterate through s once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a few variables for tracking pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/)

---
{{< youtube gKDmO8ZLRD8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
