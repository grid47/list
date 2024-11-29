
+++
authors = ["grid47"]
title = "Leetcode 1684: Count the Number of Consistent Strings"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1684: Count the Number of Consistent Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "CFa2TgIHMN0"
youtube_upload_date="2024-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/CFa2TgIHMN0/maxresdefault.jpg"
comments = true
+++



---
You are given a string `allowed` consisting of distinct characters, and an array of strings `words`. A string is consistent if all characters in the string appear in the string `allowed`. Return the number of consistent strings in the array `words`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `allowed` and an array `words`.
- **Example:** `allowed = 'abc', words = ['a', 'ab', 'abc', 'abcd', 'bc']`
- **Constraints:**
	- 1 <= words.length <= 10^4
	- 1 <= allowed.length <= 26
	- 1 <= words[i].length <= 10
	- The characters in allowed are distinct.
	- words[i] and allowed contain only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of consistent strings in the array `words`.
- **Example:** `Output: 5`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many strings in the array `words` consist solely of characters from the `allowed` string.

- Initialize a variable to store the count of consistent strings.
- Create a boolean array to track which characters are allowed.
- Iterate through each string in `words` and check if all its characters are present in the `allowed` string.
- For each word, if any character is not in the `allowed` string, it is not consistent, so skip counting it.
- Return the count of consistent strings.
{{< dots >}}
### Problem Assumptions ✅
- The string `allowed` contains distinct lowercase English characters.
- All input strings and arrays will be valid as per the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: allowed = 'abc', words = ['a', 'ab', 'abc', 'abcd', 'bc']`  \
  **Explanation:** All strings are consistent because they contain only characters from 'abc'.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to check if each string in the array `words` contains only characters that are present in the `allowed` string.

### Initial Thoughts 💭
- The `allowed` string has a small length (at most 26 characters), so we can use a boolean array to efficiently check for membership.
- We need to check each word in `words` for consistency by checking if every character in the word exists in the `allowed` string.
{{< dots >}}
### Edge Cases 🌐
- If `words` is empty, the answer should be 0.
- For large arrays of strings (`words.length` up to 10^4), ensure the solution is efficient.
- If `allowed` is empty, no words can be consistent.
- The solution should handle the maximum input size within reasonable time limits.
{{< dots >}}
## Code 💻
```cpp
int countConsistentStrings(string allowed, vector<string>& words) {
    int res = words.size();
    bool mp[26] = {};
    for (char c: allowed) mp[c - 'a'] = true;
    for (string word: words) {
        for (char c: word) if (!mp[c - 'a']) {
            res--;
            break;
        }
    }
    return res;        
}
```

This function counts how many strings in the 'words' vector consist only of characters that are present in the 'allowed' string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countConsistentStrings(string allowed, vector<string>& words) {
	```
	Define the function 'countConsistentStrings' that takes an allowed string and a vector of words as input and returns the count of words consisting only of allowed characters.

2. **Variable Initialization**
	```cpp
	    int res = words.size();
	```
	Initialize the result variable 'res' to the number of words in the 'words' vector, as each word is initially assumed to be consistent.

3. **Array Initialization**
	```cpp
	    bool mp[26] = {};
	```
	Declare and initialize a boolean array 'mp' of size 26 to track which characters are allowed, where each index corresponds to a letter of the alphabet.

4. **Loop Through Allowed Characters**
	```cpp
	    for (char c: allowed) mp[c - 'a'] = true;
	```
	Loop through each character in the 'allowed' string and mark its corresponding index in the 'mp' array as 'true' to indicate that the character is allowed.

5. **Loop Through Words**
	```cpp
	    for (string word: words) {
	```
	Start a loop to process each word in the 'words' vector.

6. **Loop Through Word Characters**
	```cpp
	        for (char c: word) if (!mp[c - 'a']) {
	```
	Loop through each character of the current word and check if it is allowed by referencing the 'mp' array. If a character is not allowed, exit the loop.

7. **Decrement Result**
	```cpp
	            res--;
	```
	If a character in the word is not allowed, decrement the 'res' variable since this word is not consistent with the allowed characters.

8. **Break Loop**
	```cpp
	            break;
	```
	Exit the inner loop once an invalid character is found in the word to stop further processing of that word.

9. **Return Statement**
	```cpp
	    return res;        
	```
	Return the final value of 'res', which represents the count of words that are consistent with the allowed characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m), where n is the number of words and m is the length of the longest word.
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

The time complexity is O(n * m), where n is the number of words and m is the length of the longest word.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only use a fixed-size boolean array of length 26.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-consistent-strings/description/)

---
{{< youtube CFa2TgIHMN0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
