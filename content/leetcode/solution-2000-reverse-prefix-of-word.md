
+++
authors = ["grid47"]
title = "Leetcode 2000: Reverse Prefix of Word"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2000: Reverse Prefix of Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Stack"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jVRdLKA6t4k"
youtube_upload_date="2021-09-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jVRdLKA6t4k/maxresdefault.webp"
comments = true
+++



---
You are given a string 'word' and a character 'ch'. Reverse the portion of the string starting at index 0 and ending at the index of the first occurrence of 'ch'. If 'ch' is not found, return the original string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string 'word' and a character 'ch'. The length of the string is between 1 and 250 characters. The string consists of lowercase English letters.
- **Example:** `word = 'abcdefd', ch = 'd'`
- **Constraints:**
	- 1 <= word.length <= 250
	- word consists of lowercase English letters
	- ch is a lowercase English letter

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the resulting string after reversing the segment from index 0 to the first occurrence of 'ch'. If 'ch' is not found, return the original string.
- **Example:** `'dcbaefd'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse the substring from the start of the string to the first occurrence of the character 'ch'. If 'ch' is absent, return the string unchanged.

- 1. Find the first occurrence of 'ch' in the string.
- 2. If 'ch' is found, reverse the substring from index 0 to the index of the first occurrence of 'ch'.
- 3. If 'ch' is not found, return the original string.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always contain valid lowercase letters, and the character 'ch' is also a lowercase letter.
{{< dots >}}
## Examples 🧩
- **Input:** `word = 'abcdefd', ch = 'd'`  \
  **Explanation:** The first occurrence of 'd' is at index 3. The substring from index 0 to 3 is reversed, giving 'dcbaefd'.

- **Input:** `word = 'abcd', ch = 'z'`  \
  **Explanation:** 'z' does not exist in 'abcd', so no reversal is done and the original string is returned.

{{< dots >}}
## Approach 🚀
The solution finds the first occurrence of 'ch' and reverses the segment from index 0 to the first occurrence of 'ch'. If 'ch' is not found, the string remains unchanged.

### Initial Thoughts 💭
- We need to identify the index of the first occurrence of 'ch' and reverse the substring if it exists.
- This problem requires string manipulation and can be solved efficiently by utilizing Python's built-in string functions.
{{< dots >}}
### Edge Cases 🌐
- The input string always has at least one character.
- Handle strings up to the maximum length of 250 characters.
- If 'ch' is not found in the string, return the original string without modification.
- Ensure the string contains only lowercase letters and falls within the specified length range.
{{< dots >}}
## Code 💻
```cpp
string reversePrefix(string word, char ch) {
    auto p = word.find(ch);
    if (p != string::npos)
        reverse(begin(word), begin(word) + p + 1);
    return word;
}
```

This function takes a string `word` and a character `ch`, finds the position of `ch` in `word`, and reverses the substring from the beginning of `word` to the position of `ch`. If `ch` is not found, the word is returned unchanged.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string reversePrefix(string word, char ch) {
	```
	Defines the function `reversePrefix`, which takes a string `word` and a character `ch` and returns the modified string with the prefix reversed up to the character `ch`.

2. **Find Character**
	```cpp
	    auto p = word.find(ch);
	```
	Finds the position of the first occurrence of character `ch` in the string `word`. If `ch` is not found, `p` will be set to `string::npos`.

3. **Conditional Check**
	```cpp
	    if (p != string::npos)
	```
	Checks if the character `ch` was found in the string by comparing the position `p` with `string::npos`. If found, it proceeds to reverse the prefix.

4. **Reverse Operation**
	```cpp
	        reverse(begin(word), begin(word) + p + 1);
	```
	Reverses the substring of `word` from the beginning to the position of `ch` (inclusive). The `begin(word)` and `begin(word) + p + 1` specify the range to reverse.

5. **Return Statement**
	```cpp
	    return word;
	```
	Returns the modified string `word` after the reversal operation, or the original string if `ch` was not found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string. We search for the first occurrence of 'ch' and, if found, reverse the substring up to that point.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space needed to hold the string while performing the reversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-prefix-of-word/description/)

---
{{< youtube jVRdLKA6t4k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
