
+++
authors = ["grid47"]
title = "Leetcode 2546: Apply Bitwise Operations to Make Strings Equal"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2546: Apply Bitwise Operations to Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9aTO0sRtL-s"
youtube_upload_date="2023-01-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/9aTO0sRtL-s/maxresdefault.webp"
comments = true
+++



---
You are given two binary strings `s` and `target` of the same length. You can perform an operation on `s` any number of times to transform it into `target`. The operation replaces two distinct indices with logical operations. Return `true` if it's possible to make `s` equal to `target`, otherwise return `false`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two binary strings `s` and `target` with the same length `n`. Each string consists of only '0's and '1's.
- **Example:** `s = '1101', target = '1011'`
- **Constraints:**
	- 2 <= n <= 10^5
	- s and target consist of only '0' and '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it is possible to transform `s` into `target` using the defined operation; otherwise return `false`.
- **Example:** `true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The task is to determine whether it's possible to make `s` equal to `target` by repeatedly applying the specified operation.

- 1. Check if both strings `s` and `target` contain at least one '1'.
- 2. If both strings contain '1' or both do not contain '1', return true.
- 3. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input strings `s` and `target` will always have the same length.
- Only binary strings (composed of '0' and '1') are considered.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '1101', target = '1011'`  \
  **Explanation:** In this case, the strings `s` and `target` can be transformed into one another using a series of operations, so the result is `true`.

- **Input:** `s = '1000', target = '1111'`  \
  **Explanation:** It is not possible to transform `s` into `target` because no sequence of operations will change the '0' in `s` to '1' independently.

{{< dots >}}
## Approach 🚀
The solution can be determined by checking whether both `s` and `target` contain at least one '1'. If both do or both do not, it is possible to transform `s` into `target`.

### Initial Thoughts 💭
- The key observation is that the operation preserves the presence of '1's in both strings.
- If both `s` and `target` contain at least one '1', the transformation is possible.
- We need to check if both strings have the same pattern in terms of the presence of '1's.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where `s` and `target` are minimal in size, i.e., 2 characters long.
- Ensure the solution can handle the upper constraint where `n` can be as large as 10^5.
- Consider cases where the strings `s` and `target` are identical or completely different.
- The solution needs to handle edge cases like strings with no '1' or where `s` and `target` differ significantly.
{{< dots >}}
## Code 💻
```cpp
bool makeStringsEqual(string s, string target) {
    
    return (s.find('1') != string::npos) == (target.find('1') != string::npos);
}
```

This code defines a function 'makeStringsEqual' that checks if two strings, 's' and 'target', contain the same number of occurrences of the character '1'. It uses the 'find' function to check for the presence of '1' in both strings and compares their results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool makeStringsEqual(string s, string target) {
	```
	The function 'makeStringsEqual' is defined to take two strings, 's' and 'target', and return a boolean value indicating whether both strings have the same presence of the character '1'.

2. **Return Statement**
	```cpp
	    return (s.find('1') != string::npos) == (target.find('1') != string::npos);
	```
	The function uses the 'find' method to check if the character '1' exists in both strings. If both strings either contain or do not contain the character '1', the function returns 'true'; otherwise, it returns 'false'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string.
- **Average Case:** O(n), since checking if '1' exists in both strings is linear.
- **Worst Case:** O(n), since checking for '1' in both strings is a linear operation.

The time complexity is O(n) since we need to scan both strings to check for '1'.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required in the solution.
- **Worst Case:** O(1), since we do not need any extra space apart from the input.

The space complexity is O(1), as the solution operates in constant space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/)

---
{{< youtube 9aTO0sRtL-s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
