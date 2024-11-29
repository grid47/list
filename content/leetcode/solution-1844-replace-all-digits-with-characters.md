
+++
authors = ["grid47"]
title = "Leetcode 1844: Replace All Digits with Characters"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1844: Replace All Digits with Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "L5P6zYBLP3s"
youtube_upload_date="2021-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/L5P6zYBLP3s/maxresdefault.webp"
comments = true
+++



---
You are given a string s with lowercase English letters at even indices and digits at odd indices. For each odd index i, replace the digit s[i] with the result of the operation shift(s[i-1], s[i]), where shift(c, x) returns the xth character after c. Return the modified string after replacing all digits.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string where even indices contain lowercase English letters and odd indices contain digits.
- **Example:** `s = 'a1c1e1'`
- **Constraints:**
	- 1 <= s.length <= 100
	- s consists only of lowercase English letters and digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the modified string where the digits at odd indices are replaced with the result of the shift operation.
- **Example:** `abcdef`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Replace digits at odd indices with the result of the shift operation based on the character at the previous even index.

- Iterate through the string, starting from index 1 (odd indices).
- For each odd index i, calculate the result of shift(s[i-1], s[i]) and replace s[i] with the result.
- Return the modified string after processing all odd indices.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always have characters at even indices that are lowercase English letters, and digits at odd indices.
- The shift will not exceed the character 'z'.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'a1c1e1'`  \
  **Explanation:** The digits are replaced by applying the shift function to the characters at the even indices. 'a' becomes 'b', 'c' becomes 'd', and 'e' becomes 'f'.

{{< dots >}}
## Approach 🚀
The solution iterates through the string and applies the shift operation for each digit at an odd index, using the character at the previous even index.

### Initial Thoughts 💭
- The operation shift(c, x) is simple and can be computed easily for each odd index.
- We can modify the string in a single pass through the input string.
{{< dots >}}
### Edge Cases 🌐
- The input string will always contain at least one character, so empty input is not a valid case.
- The solution must handle inputs with a length of up to 100 characters efficiently.
- Strings with digits that do not change the characters (e.g., 'z9y8x7w6') should be handled correctly.
- The string will always be valid according to the input constraints.
{{< dots >}}
## Code 💻
```cpp
string replaceDigits(string s) {
for (auto i = 1; i < s.size(); i += 2)
    s[i] += s[i - 1] - '0';
    return s;
}
```

This function replaces digits in the string `s` by adding the value of the previous character (assumed to be a letter) to the digit, effectively transforming characters at even indices.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string replaceDigits(string s) {
	```
	Defines the function `replaceDigits`, which takes a string `s` and modifies it by adjusting its characters based on their neighbors.

2. **For Loop**
	```cpp
	for (auto i = 1; i < s.size(); i += 2)
	```
	Starts a loop that iterates over the string `s`, specifically at the odd indices (1, 3, 5, ...).

3. **String Modification**
	```cpp
	    s[i] += s[i - 1] - '0';
	```
	For each character at an odd index `i`, adds the value of the previous character (at index `i - 1`) to it. This is done by subtracting the character '0' to convert the digit into an integer.

4. **Return Statement**
	```cpp
	    return s;
	```
	Returns the modified string `s` after processing all the relevant characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the string once, where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only modify the string in place and do not require additional space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-all-digits-with-characters/description/)

---
{{< youtube L5P6zYBLP3s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
