
+++
authors = ["grid47"]
title = "Leetcode 2734: Lexicographically Smallest String After Substring Operation"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2734: Lexicographically Smallest String After Substring Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wvExCULvlqU"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wvExCULvlqU/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting of lowercase English letters. You can perform the operation of replacing every letter of a selected non-empty substring with the preceding letter in the alphabet. Your task is to return the lexicographically smallest string possible after performing the operation.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` of lowercase English letters.
- **Example:** `s = 'efghi'`
- **Constraints:**
	- 1 <= s.length <= 3 * 10^5
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest string that can be obtained after performing the operation.
- **Example:** `Output: 'defgh'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the lexicographically smallest string by selecting and performing the operation on a substring.

- Find the first non-'a' character and perform the operation on it and all following characters.
- Stop the operation when you encounter 'a' or the end of the string.
{{< dots >}}
### Problem Assumptions ✅
- All characters in the string are lowercase English letters.
- The string length is at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'efghi'`  \
  **Explanation:** The operation is performed on the first two characters 'e' and 'f', changing them to 'd' and 'e', respectively. The result is 'defgh'.

- **Input:** `s = 'abc'`  \
  **Explanation:** No operation is needed because the string is already lexicographically smallest.

- **Input:** `s = 'bcde'`  \
  **Explanation:** The operation is performed on the substring 'b' and 'c', changing 'b' to 'a'. The result is 'abde'.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating over the string and applying the operation on the first non-'a' characters, reducing them by 1.

### Initial Thoughts 💭
- We need to find the first character that is not 'a' and apply the operation on it.
- If the string is all 'a's, we need to change the last character to 'z'.
- Start iterating from the beginning, and when encountering the first non-'a' character, apply the operation.
{{< dots >}}
### Edge Cases 🌐
- The string contains only 'a's.
- The string has the maximum allowed length.
- The string has no non-'a' characters.
- The input string is always non-empty.
{{< dots >}}
## Code 💻
```cpp
string smallestString(string s) {
    int i = 0;
    while(i < s.size() && s[i] == 'a') i++;
    if(i >= s.size()) { s[s.size()-1] = 'z'; return s; }
    while(i < s.size() && s[i] != 'a') { s[i]--; i++; }
    return s;
}
```

This function takes a string `s` and modifies it to form the lexicographically smallest string. It decreases characters that are not 'a' until it encounters an 'a' or the end of the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string smallestString(string s) {
	```
	This is the function definition of `smallestString`, which takes a string `s` as input and returns the modified string.

2. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	An integer variable `i` is initialized to 0. This will be used to iterate through the string `s`.

3. **Loop - Check 'a'**
	```cpp
	    while(i < s.size() && s[i] == 'a') i++;
	```
	The function enters a while-loop to skip all the leading 'a' characters in the string by incrementing `i` until a non-'a' character is found.

4. **Condition - All 'a'**
	```cpp
	    if(i >= s.size()) { s[s.size()-1] = 'z'; return s; }
	```
	If `i` reaches the end of the string, meaning all characters were 'a', the last character is set to 'z' and the modified string `s` is returned.

5. **Loop - Decrease Non-'a'**
	```cpp
	    while(i < s.size() && s[i] != 'a') { s[i]--; i++; }
	```
	This while-loop iterates through the string starting from the first non-'a' character and decreases each character until an 'a' is encountered or the string ends.

6. **Return Statement**
	```cpp
	    return s;
	```
	After modifying the string, the function returns the modified string `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the string.
- **Average Case:** O(n) because we iterate over the string once.
- **Worst Case:** O(n) since we need to process all characters in the string.

The time complexity is linear because we process each character once.

### Space Complexity 💾
- **Best Case:** O(1) when no operations are required.
- **Worst Case:** O(1) since only a few variables are used.

The space complexity is constant because we don't use any extra space proportional to the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/)

---
{{< youtube wvExCULvlqU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
