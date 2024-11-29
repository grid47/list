
+++
authors = ["grid47"]
title = "Leetcode 1784: Check if Binary String Has at Most One Segment of Ones"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1784: Check if Binary String Has at Most One Segment of Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "CRjRphrOkNA"
youtube_upload_date="2021-03-07"
youtube_thumbnail="https://i.ytimg.com/vi/CRjRphrOkNA/maxresdefault.jpg"
comments = true
+++



---
Given a binary string s without leading zeros, return true if the string contains at most one contiguous block of 1s. Otherwise, return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string s that does not have leading zeros. The string is made up of '0's and '1's.
- **Example:** `s = '101'`
- **Constraints:**
	- 1 <= s.length <= 100
	- s[i] is either '0' or '1'
	- s[0] is '1'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the string contains at most one contiguous block of '1's. Otherwise, return false.
- **Example:** `Input: s = '111', Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if there is only one contiguous block of '1's in the string.

- 1. Search for the substring '01' in the string.
- 2. If the substring '01' is found, return false since there are multiple blocks of '1's.
- 3. If no such substring is found, return true as the '1's form one contiguous block.
{{< dots >}}
### Problem Assumptions ✅
- The binary string s starts with a '1'.
- The string contains only '0's and '1's.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = '101'`  \
  **Explanation:** The ones in the string are not contiguous, as there is a '0' between them. Hence, the result is false.

- **Input:** `Input: s = '111'`  \
  **Explanation:** The ones form a single contiguous block, so the result is true.

{{< dots >}}
## Approach 🚀
We can simply check for the presence of the substring '01' in the string. If it exists, it indicates that the '1's are not contiguous.

### Initial Thoughts 💭
- The problem can be solved by checking for the '01' substring.
- The solution relies on recognizing that once the first block of '1's ends, if another '1' starts after a '0', the blocks are separate.
{{< dots >}}
### Edge Cases 🌐
- Input string s will not be empty as per the constraints.
- Ensure that the solution handles strings of maximum length (100 characters).
- If the string contains only one '1', it should return true.
- The string must contain at least one '1' due to the constraint that s[0] is '1'.
{{< dots >}}
## Code 💻
```cpp
bool checkOnesSegment(string s) {

    // without leading zeros mean starting with 1s
    // if another set of one comes, there be definitely a 01
    // thats all
    return string::npos == s.find("01");
}
```

This function checks if a string `s` consists of a single contiguous segment of 1's, without any interruptions or leading zeros. It returns `true` if the string only contains a single set of 1's, and `false` otherwise.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkOnesSegment(string s) {
	```
	Define the function `checkOnesSegment`, which takes a string `s` as input and returns a boolean indicating whether the string contains a single contiguous segment of 1's.

2. **Return Statement**
	```cpp
	    return string::npos == s.find("01");
	```
	The function checks if the string 's' contains the substring '01' (indicating a break in the segment of 1's). If '01' is found, the function returns `false`. Otherwise, it returns `true`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we perform a single scan of the string to find the substring.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since no additional space is required apart from the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/)

---
{{< youtube CRjRphrOkNA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
