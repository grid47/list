
+++
authors = ["grid47"]
title = "Leetcode 524: Longest Word in Dictionary through Deleting"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 524: Longest Word in Dictionary through Deleting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/524.webp"
youtube = "tvaZ8-WobKE"
youtube_upload_date="2019-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tvaZ8-WobKE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/524.webp" 
    alt="A string where characters are deleted to form the longest word from a dictionary, with each step glowing softly."
    caption="Solution to LeetCode 524: Longest Word in Dictionary through Deleting Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string s and a string array dictionary, return the longest string from the dictionary that can be formed by deleting some characters of s. If there are multiple valid words, return the longest word with the smallest lexicographical order. If no valid word exists, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s and an array of strings dictionary.
- **Example:** `s = 'xyzzabca', dictionary = ['abc', 'xy', 'zz', 'xyz']`
- **Constraints:**
	- 1 <= s.length <= 1000
	- 1 <= dictionary.length <= 1000
	- 1 <= dictionary[i].length <= 1000
	- s and dictionary[i] consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the longest word in the dictionary that can be formed from the string s. If there are multiple such words, return the lexicographically smallest one. If no valid word can be formed, return an empty string.
- **Example:** `'abc', 'c'`
- **Constraints:**
	- The output should be a string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check each word in the dictionary to see if it can be formed by deleting characters from s and then return the longest, lexicographically smallest one.

- 1. Iterate through each word in the dictionary.
- 2. For each word, check if it can be formed by deleting some characters from s by maintaining a pointer for both strings.
- 3. Track the longest valid word found and update if a new word with a longer length or smaller lexicographical order is found.
- 4. Return the valid word or an empty string if no valid word is found.
{{< dots >}}
### Problem Assumptions ✅
- The input strings are valid and consist of lowercase English letters only.
- We assume that all words in the dictionary are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'xyzzabca', dictionary = ['abc', 'xy', 'zz', 'xyz']`  \
  **Explanation:** The word 'abc' can be formed from s by deleting 'x', 'y', 'z', and 'z'. The other words cannot be formed.

- **Input:** `s = 'abc', dictionary = ['a', 'b', 'c']`  \
  **Explanation:** 'c' is the longest valid word that can be formed from s.

- **Input:** `s = 'abcxyz', dictionary = ['ax', 'bc', 'xyz']`  \
  **Explanation:** 'ax' can be formed from s and is the longest, lexicographically smallest word.

{{< dots >}}
## Approach 🚀
The approach involves iterating over each word in the dictionary and checking if it can be formed from s by deleting characters. The key operation is maintaining a pointer for both the string and the word being checked.

### Initial Thoughts 💭
- The task is a typical string matching problem where we are allowed to delete characters from s.
- The solution needs to efficiently check if a word can be formed from s and track the longest, lexicographically smallest result.
{{< dots >}}
### Edge Cases 🌐
- Handle empty string s or an empty dictionary.
- The solution should efficiently handle the case where s and the dictionary contain the maximum number of elements (1000).
- If no word can be formed, return an empty string.
- The solution should run in O(n * m) time, where n is the length of s and m is the total length of all words in the dictionary.
{{< dots >}}
## Code 💻
```cpp
string findLongestWord(string s, vector<string>& d) {
    
    string ans;
    for(int i = 0; i < d.size(); i++) {
        
        int pi = 0, pj = 0;
        
        for(; pi < s.size() && pj < d[i].size(); pi++) {
            pj += s[pi] == d[i][pj];
        }
        
        if(pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
            ans = d[i];
        
    }
    return ans;
}
```

This function finds the longest word in the dictionary `d` that can be formed by deleting some characters of the string `s`. If there are multiple words with the same length, it returns the lexicographically largest word.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string findLongestWord(string s, vector<string>& d) {
	```
	Defines the function `findLongestWord` that takes a string `s` and a vector of strings `d`, and returns the longest word from `d` that can be formed by deleting some characters from `s`.

2. **Variable Initialization**
	```cpp
	    string ans;
	```
	Initializes the variable `ans` to store the result, which will be the longest word found from the dictionary `d`.

3. **Looping through Dictionary**
	```cpp
	    for(int i = 0; i < d.size(); i++) {
	```
	Starts a loop to iterate through each word in the dictionary `d`.

4. **Variable Initialization**
	```cpp
	        int pi = 0, pj = 0;
	```
	Initializes two variables `pi` and `pj`, which represent the current indices in the string `s` and the current word `d[i]` being checked, respectively.

5. **Matching Loop**
	```cpp
	        for(; pi < s.size() && pj < d[i].size(); pi++) {
	```
	Starts a loop to iterate through the string `s` and the current word `d[i]` simultaneously. It continues as long as both indices are within the bounds of `s` and `d[i]`.

6. **Character Matching**
	```cpp
	            pj += s[pi] == d[i][pj];
	```
	Increments the index `pj` if the characters `s[pi]` and `d[i][pj]` match. This helps in checking if `d[i]` is a subsequence of `s`.

7. **Subsequence Validity and Lexicographical Check**
	```cpp
	        if(pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
	```
	Checks if `d[i]` is a subsequence of `s` (i.e., if `pj` equals the length of `d[i]`), and if it is, compares it with the current longest word `ans` to ensure that the longest and lexicographically largest word is selected.

8. **Assign Longest Word**
	```cpp
	            ans = d[i];
	```
	If the current word `d[i]` is a valid subsequence and is either longer or lexicographically larger than `ans`, it updates `ans` with `d[i]`.

9. **Return Result**
	```cpp
	    return ans;
	```
	Returns the longest word found from `d` that can be formed by deleting characters from `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m), where n is the length of s and m is the total length of all dictionary words.
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

In the worst case, we check every word in the dictionary against the entire string s.

### Space Complexity 💾
- **Best Case:** O(1), if no valid word is found.
- **Worst Case:** O(m), where m is the total length of all words in the dictionary.

Space complexity is determined by the dictionary size and the string s, with no extra space used apart from variables for tracking results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/)

---
{{< youtube tvaZ8-WobKE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
