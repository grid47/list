
+++
authors = ["grid47"]
title = "Leetcode 2138: Divide a String Into Groups of Size k"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2138: Divide a String Into Groups of Size k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "J_aEpIkTv4k"
youtube_upload_date="2022-01-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/J_aEpIkTv4k/maxresdefault.webp"
comments = true
+++



---
Given a string `s` and an integer `k`, partition the string into groups of size `k`. If the last group has fewer than `k` characters, append a `fill` character to complete it. Return an array of the groups.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` of lowercase English letters, an integer `k` representing the group size, and a `fill` character to complete the last group if necessary.
- **Example:** `Input: s = "hello", k = 3, fill = "z"`
- **Constraints:**
	- 1 <= s.length <= 100
	- 1 <= k <= 100
	- fill is a lowercase English letter.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of strings, each representing a group formed by partitioning the input string `s` into parts of size `k`, with the last group potentially filled using the `fill` character.
- **Example:** `Output: ["hel", "loz"]`
- **Constraints:**
	- The returned array will have as many elements as necessary to divide the string into groups of size `k`.

{{< dots >}}
### Core Logic 🔍
**Goal:** Partition the string into groups and handle the last group by appending the `fill` character if necessary.

- Initialize an empty list for the result.
- Iterate through the string and divide it into groups of size `k`.
- If the last group contains fewer than `k` characters, append `fill` characters to complete it.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only lowercase English letters.
- The input values for `k` and `fill` are valid.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "hello", k = 3, fill = "z"`  \
  **Explanation:** The string is divided into two groups. The first group is 'hel'. The second group is 'lo', but since the length is less than `k`, we append 'z' to make it 'loz'.

{{< dots >}}
## Approach 🚀
To solve the problem, iterate through the string in steps of size `k`, create the groups, and handle the last group by filling it if necessary.

### Initial Thoughts 💭
- We need to divide the string into smaller chunks of size `k`. The last chunk may need additional characters to complete.
- Using a simple loop with string slicing or manual indexing will help form the groups. Special attention is needed for the last group to ensure it is filled properly.
{{< dots >}}
### Edge Cases 🌐
- An empty string should return an empty list of groups.
- Test cases with maximum string lengths should be handled efficiently.
- When `k` is 1, each group is just a single character of the string.
- Ensure that the number of groups and the size of the last group are computed correctly.
{{< dots >}}
## Code 💻
```cpp
vector<string> divideString(string s, int k, char fill) {
    vector<string> res((s.size() + k - 1) / k, string(k, fill));
    for (int i = 0; i < s.size(); ++i)
        res[i / k][i % k] = s[i];
    return res;
}
```

This function divides a string `s` into a 2D vector of strings, where each string has a length `k`. If the string `s` is shorter than `k` for the last part, it fills it with the specified `fill` character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> divideString(string s, int k, char fill) {
	```
	This is the function definition for `divideString`. It takes three parameters: a string `s`, an integer `k` (the size of each chunk), and a character `fill` to pad the chunks if necessary.

2. **Initialization**
	```cpp
	    vector<string> res((s.size() + k - 1) / k, string(k, fill));
	```
	This line initializes a vector `res` with enough rows to store the divided strings. The size of each row is `k`, and it is filled with the `fill` character. The number of rows is calculated by dividing the size of the input string by `k` and rounding up.

3. **Iteration**
	```cpp
	    for (int i = 0; i < s.size(); ++i)
	```
	This loop iterates over each character in the input string `s`.

4. **Filling the Matrix**
	```cpp
	        res[i / k][i % k] = s[i];
	```
	This line places the character `s[i]` into the appropriate position in the 2D vector `res`. The row is determined by `i / k` and the column by `i % k`.

5. **Return**
	```cpp
	    return res;
	```
	Once all characters have been placed into the vector, the function returns the 2D vector `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in relation to the size of the string, as we process each character exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is also linear, as we store the result array, which has a size proportional to the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/)

---
{{< youtube J_aEpIkTv4k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
