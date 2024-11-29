
+++
authors = ["grid47"]
title = "Leetcode 2124: Check if All A's Appears Before All B's"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2124: Check if All A's Appears Before All B's in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "RgzM3HRkdp8"
youtube_upload_date="2022-01-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RgzM3HRkdp8/maxresdefault.webp"
comments = true
+++



---
You are given a string consisting of only the characters 'a' and 'b'. Your task is to determine if all occurrences of 'a' appear before all occurrences of 'b' in the string. If that is the case, return true; otherwise, return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s consisting of only the characters 'a' and 'b'.
- **Example:** `s = 'aaaabbb'`
- **Constraints:**
	- 1 <= s.length <= 100
	- s[i] is either 'a' or 'b'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if every 'a' appears before every 'b' in the string. Otherwise, return false.
- **Example:** `Input: 'aaabbb' -> Output: true`
- **Constraints:**
	- The input string will contain only 'a' and 'b'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if all 'a' characters in the string appear before all 'b' characters.

- Check if the substring 'ba' exists in the string.
- If 'ba' is found, return false. Otherwise, return true.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only 'a' and 'b'.
- There will be at least one character in the string.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 'aaaabbb'`  \
  **Explanation:** In this case, all the 'a's appear before the 'b's, so we return true.

- **Input:** `Input: 'abab'`  \
  **Explanation:** Here, an 'a' appears after a 'b', so we return false.

{{< dots >}}
## Approach 🚀
To solve this problem, check if the substring 'ba' exists in the input string. If it does, it means there is a 'b' before an 'a', which violates the condition.

### Initial Thoughts 💭
- We only need to check if the substring 'ba' is present in the string.
- If 'ba' is found in the string, return false. Otherwise, return true.
{{< dots >}}
### Edge Cases 🌐
- An empty string is not a valid input according to the problem constraints.
- Ensure that the solution works for strings with up to 100 characters.
- Strings that consist only of 'a's or 'b's will automatically return true.
- The solution should handle the maximum string length efficiently.
{{< dots >}}
## Code 💻
```cpp
bool checkString(string s) {
    return s.find("ba")==string::npos;
}
```

This function checks if the string contains the substring 'ba'. It returns true if 'ba' is not found in the string, otherwise false.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkString(string s) {
	```
	This line defines a function named checkString, which takes a string 's' as input and returns a boolean value.

2. **String Search**
	```cpp
	    return s.find("ba")==string::npos;
	```
	This line searches for the substring 'ba' in the input string 's'. If 'ba' is not found, the function returns true; otherwise, it returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We check if 'ba' exists in the string, which takes O(n) time, where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/)

---
{{< youtube RgzM3HRkdp8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
