
+++
authors = ["grid47"]
title = "Leetcode 459: Repeated Substring Pattern"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 459: Repeated Substring Pattern in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/459.webp"
youtube = "p92_kEjyJAo"
youtube_upload_date="2020-09-04"
youtube_thumbnail="https://i.ytimg.com/vi/p92_kEjyJAo/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGUgYShMMA8=&rs=AOn4CLCIMqAUIe8EdHdk18s3dwcMWJj5hw"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/459.webp" 
    alt="A string where repeated substrings softly glow, showing the patterns and repetitions clearly."
    caption="Solution to LeetCode 459: Repeated Substring Pattern Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string, determine if it can be formed by repeating a substring of itself multiple times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s`.
- **Example:** `s = 'abab'`
- **Constraints:**
	- 1 <= s.length <= 10^4
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the string can be constructed by repeating a substring multiple times, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean indicating whether the string can be repeated from a substring.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if a non-empty substring exists that can be repeated to form the string.

- 1. Concatenate the string with itself to find potential repeating substrings.
- 2. Check if the original string appears in the concatenated string, excluding the first and last character.
- 3. If found, return true, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- The input string is non-empty and consists only of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abab'`  \
  **Explanation:** The string 'abab' can be formed by repeating the substring 'ab'.

- **Input:** `s = 'abcabcabc'`  \
  **Explanation:** The string 'abcabcabc' can be formed by repeating the substring 'abc'.

{{< dots >}}
## Approach 🚀
The solution involves checking if the string can be formed by repeating a substring using string manipulation.

### Initial Thoughts 💭
- By concatenating the string with itself, we create potential repeated patterns.
- If the string is repeatable, we can find the original string within the concatenated version, excluding the first and last character.
{{< dots >}}
### Edge Cases 🌐
- An empty string is not allowed as per the constraints.
- Ensure that the solution works efficiently for strings up to the maximum length of 10^4.
- Consider strings that are already repeating, such as 'ababab'.
- Handle large inputs efficiently with time complexity O(n).
{{< dots >}}
## Code 💻
```cpp
bool repeatedSubstringPattern(string str) {
    return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
}
```

The function `repeatedSubstringPattern` checks whether a string can be formed by repeating a substring. It concatenates the string to itself, then looks for the original string within the modified string, returning `true` if found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool repeatedSubstringPattern(string str) {
	```
	Defines the `repeatedSubstringPattern` function, which takes a string `str` and returns a boolean indicating whether the string can be formed by repeating a substring.

2. **String Manipulation**
	```cpp
	    return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
	```
	Concatenates the string `str` with itself and uses the `substr` method to remove the first and last characters. Then, it checks if the original string exists within the modified string. If found, it returns `true`, indicating the string can be formed by repeating a substring.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we only perform a string concatenation and search operation.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the concatenation of the string with itself.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/repeated-substring-pattern/description/)

---
{{< youtube p92_kEjyJAo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
