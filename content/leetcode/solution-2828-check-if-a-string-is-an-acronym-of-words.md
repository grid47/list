
+++
authors = ["grid47"]
title = "Leetcode 2828: Check if a String Is an Acronym of Words"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2828: Check if a String Is an Acronym of Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "GcgV-AtAmkg"
youtube_upload_date="2023-08-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/GcgV-AtAmkg/maxresdefault.webp"
comments = true
+++



---
Given an array of strings `words` and a string `s`, determine if `s` is an acronym of `words`. The string `s` is considered an acronym of `words` if it can be formed by concatenating the first character of each string in `words` in order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `words` of strings and a string `s`.
- **Example:** `For example, `words = ['orange', 'pear', 'grape']` and `s = 'opg'``
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 10
	- 1 <= s.length <= 100
	- words[i] and s consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if `s` is an acronym of `words`, otherwise return `false`.
- **Example:** `For `words = ['dog', 'cat', 'fish']` and `s = 'dcf'`, the output is `true`.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the string `s` matches the concatenation of the first characters from each string in `words`.

- Initialize an empty string to store the acronym.
- For each word in `words`, add its first character to the acronym string.
- Compare the acronym with `s` and return `true` if they match, otherwise return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The input strings only contain lowercase English letters.
- The solution should work within the constraints for both the `words` array and string `s`.
{{< dots >}}
## Examples 🧩
- **Input:** `For `words = ['orange', 'pear', 'grape']` and `s = 'opg'``  \
  **Explanation:** The first characters of the words 'orange', 'pear', and 'grape' are 'o', 'p', and 'g', respectively. Hence, `s = 'opg'` is the acronym.

{{< dots >}}
## Approach 🚀
The solution involves creating the acronym by concatenating the first characters of the strings in `words` and comparing it with `s`.

### Initial Thoughts 💭
- The task is simple: extract the first letter of each word and compare it with the given string `s`.
- By iterating over the list of words and constructing the acronym, we can efficiently check if `s` matches.
{{< dots >}}
### Edge Cases 🌐
- An empty input for `words` would not happen due to the problem constraints.
- Ensure that the algorithm can handle the maximum input size of `words`.
- Handle cases where `s` has fewer characters than the total number of words.
- The solution should run efficiently within the time and space constraints for the given problem.
{{< dots >}}
## Code 💻
```cpp
bool isAcronym(vector<string>& words, string s) {
    string res = "";
    for(string w: words)
        res += w[0];
    return s == res;
}
```

This function checks if the given string 's' is an acronym formed by the first letter of each word in the 'words' vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isAcronym(vector<string>& words, string s) {
	```
	The function 'isAcronym' is defined, taking a vector of strings 'words' and a string 's'. It checks whether 's' is an acronym formed by the first letter of each word in 'words'.

2. **Variable Initialization**
	```cpp
	    string res = "";
	```
	A string variable 'res' is initialized as an empty string. This variable will store the concatenated first letters of each word in the 'words' vector.

3. **Loop Start**
	```cpp
	    for(string w: words)
	```
	A for loop is initiated, iterating over each word 'w' in the 'words' vector. This loop will extract the first character of each word.

4. **Concatenate First Letter**
	```cpp
	        res += w[0];
	```
	The first character of each word 'w' is concatenated to the 'res' string, effectively forming the acronym.

5. **Return Statement**
	```cpp
	    return s == res;
	```
	The function compares the formed acronym 'res' with the input string 's'. If they are equal, it returns true; otherwise, false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the `words` array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of words, as we store the acronym string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/)

---
{{< youtube GcgV-AtAmkg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
