
+++
authors = ["grid47"]
title = "Leetcode 1957: Delete Characters to Make Fancy String"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1957: Delete Characters to Make Fancy String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wdve85GSjO8"
youtube_upload_date="2021-08-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wdve85GSjO8/maxresdefault.webp"
comments = true
+++



---
Given a string s, you need to remove the minimum possible number of characters to ensure that no character appears three or more times consecutively in the resulting string. The output should be the final string after all necessary deletions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s consisting of lowercase English letters.
- **Example:** `s = "aaabbccaaa"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final string after removing the minimum possible characters so that no character appears three or more times consecutively.
- **Example:** `Output: "aabbcca"`
- **Constraints:**
	- The answer is guaranteed to be unique.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove characters in such a way that no character appears consecutively more than twice.

- Step 1: Start iterating through the string from the third character onward.
- Step 2: Keep track of the previous two characters, and ensure that the current character does not match both.
- Step 3: If the current character matches both of the previous two characters, skip it (i.e., remove it). Otherwise, add it to the result.
{{< dots >}}
### Problem Assumptions ✅
- The string will contain only lowercase English letters.
- The string may contain consecutive identical characters, which could require deletions.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "aaabbccaaa"`  \
  **Explanation:** In this example, we start with the string "aaabbccaaa". We remove the third 'a' to get "aabbccaaa", then remove the third 'a' again to get "aabbcca". The output is "aabbcca".

- **Input:** `Input: s = "abcde"`  \
  **Explanation:** Since no character appears three times consecutively, the string remains unchanged and the output is "abcde".

{{< dots >}}
## Approach 🚀
The approach is to iterate through the string and remove characters that would cause three consecutive identical characters.

### Initial Thoughts 💭
- This is a greedy problem where we can remove characters as we traverse through the string.
- We need to ensure that for any character, it doesn't appear three times in a row by checking the last two characters in the result.
{{< dots >}}
### Edge Cases 🌐
- The input string will always have at least one character, so this case doesn't need to be handled.
- For large strings, the solution must efficiently handle strings up to the maximum length of 100,000.
- If the string is already valid (i.e., no three consecutive identical characters), the solution should simply return the original string.
- The solution must be optimized to handle the upper constraint of 100,000 characters.
{{< dots >}}
## Code 💻
```cpp
string makeFancyString(string s) {
    int j = 2;
    for (int i = 2; i < s.size(); ++i)
        if (s[i] != s[j - 1] || s[i] != s[j - 2])
            s[j++] = s[i];
    s.resize(min(j, (int)s.size()));
    return s;
}
```

This function modifies a string by removing consecutive characters that appear more than twice in a row, ensuring no character repeats more than twice consecutively.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string makeFancyString(string s) {
	```
	This is the function header. It takes a string 's' and returns a modified version of 's' where no character appears more than twice consecutively.

2. **Variable Initialization**
	```cpp
	    int j = 2;
	```
	The variable 'j' is initialized to 2. It keeps track of the position where the next valid character should be placed in the string.

3. **Loop Initialization**
	```cpp
	    for (int i = 2; i < s.size(); ++i)
	```
	A loop starts at index 2 (since the first two characters are always valid). It iterates through the rest of the string.

4. **Condition Check**
	```cpp
	        if (s[i] != s[j - 1] || s[i] != s[j - 2])
	```
	This condition checks if the current character 's[i]' is not the same as the previous two characters. If it isn't, it is considered valid and can be added to the modified string.

5. **Character Assignment**
	```cpp
	            s[j++] = s[i];
	```
	If the character passes the condition, it is assigned to the position 'j', and 'j' is incremented.

6. **Resize String**
	```cpp
	    s.resize(min(j, (int)s.size()));
	```
	The string is resized to ensure it doesn't contain any extra characters beyond the valid ones. The new size is the minimum of 'j' or the original size of the string.

7. **Return Statement**
	```cpp
	    return s;
	```
	The modified string 's' is returned, now containing no consecutive characters that appear more than twice.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for the result string, which may be as large as the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/)

---
{{< youtube wdve85GSjO8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
