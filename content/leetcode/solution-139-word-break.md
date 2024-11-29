
+++
authors = ["grid47"]
title = "Leetcode 139: Word Break"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 139: Word Break in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming","Trie","Memoization"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/139.webp"
youtube = "t0svbzZ1PWM"
youtube_upload_date="2021-04-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/t0svbzZ1PWM/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/139.webp" 
    alt="A string breaking into glowing segments, with each segment leading to a valid word in a dictionary."
    caption="Solution to LeetCode 139: Word Break Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string s and a dictionary of words wordDict, return true if s can be segmented into a space-separated sequence of one or more words from the dictionary. The same word in the dictionary can be reused multiple times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s and a list of words wordDict.
- **Example:** `Input: s = 'applepie', wordDict = ['apple', 'pie']`
- **Constraints:**
	- 1 <= s.length <= 300
	- 1 <= wordDict.length <= 1000
	- 1 <= wordDict[i].length <= 20
	- s and wordDict[i] consist of only lowercase English letters.
	- All strings in wordDict are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether the string s can be segmented into words from the dictionary wordDict.
- **Example:** `Output: true`
- **Constraints:**
	- The output is true if s can be segmented into valid words from wordDict, otherwise false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if the string s can be segmented into words from the dictionary wordDict.

- 1. Use dynamic programming to check if the string can be segmented.
- 2. Iterate through the string s and use a memoization technique to avoid redundant calculations.
- 3. For each substring of s, check if it exists in the wordDict and recursively check if the rest of the string can be segmented.
{{< dots >}}
### Problem Assumptions ✅
- The wordDict contains only lowercase English words.
- The input string s and words in wordDict are non-empty and consist of lowercase letters only.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'applepie', wordDict = ['apple', 'pie']`  \
  **Explanation:** The string 'applepie' can be split into 'apple' and 'pie', both of which are present in the dictionary, hence the answer is true.

{{< dots >}}
## Approach 🚀
The approach involves dynamic programming and memoization to determine if the string can be segmented into words from the dictionary.

### Initial Thoughts 💭
- This is a classical dynamic programming problem where we try to break the string down into smaller valid substrings.
- We will need to track which parts of the string have already been checked to avoid redundant work.
{{< dots >}}
### Edge Cases 🌐
- If s is an empty string, return true since it trivially satisfies the condition.
- For large inputs, the solution must efficiently handle strings up to 300 characters and wordDict with up to 1000 entries.
- Consider strings where no valid segmentation is possible, such as 'banana' with dictionary ['apple', 'pie'].
- Ensure that the solution uses dynamic programming or other efficient methods to handle large inputs within the given constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> memo;
bool wordBreak(string s, vector<string>& dict) {
    map<string, bool> mp;
    for(string d: dict)
        mp[d] = true;
    memo.resize(s.size(), -1);
    return bt(s, 0, mp);
}

bool bt(string s, int idx, map<string, bool> &mp) {
    
    if(idx == s.size()) return true;
    
    if(memo[idx] != -1) return memo[idx];
    
    for(int i = idx; i < s.size(); i++) {
        if(mp.count(s.substr(idx, i - idx + 1)) && bt(s, i + 1, mp))
            return memo[idx] = true;
    }
    
    return memo[idx] = false;
}

```

This code is an implementation of the Word Break problem, where a string is checked to see if it can be segmented into words from a given dictionary. It uses dynamic programming with memoization and recursion to optimize the process.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> memo;
	```
	A vector `memo` is declared to store the results of subproblems for dynamic programming. It will store -1 for uncalculated indices and a boolean value for each index after it is processed.

2. **Function Definition (wordBreak)**
	```cpp
	bool wordBreak(string s, vector<string>& dict) {
	```
	This is the main function `wordBreak`, which checks if the string `s` can be segmented using words from the dictionary `dict`.

3. **Dictionary Setup**
	```cpp
	    map<string, bool> mp;
	```
	A map `mp` is created to store the dictionary words as keys with their values set to `true`, for efficient look-up during segmentation.

4. **Populate Dictionary Map**
	```cpp
	    for(string d: dict)
	```
	This loop iterates over the dictionary `dict` and adds each word to the map `mp`.

5. **Set Map Values**
	```cpp
	        mp[d] = true;
	```
	The map `mp` is populated with each word from the dictionary as the key and `true` as the value to indicate that the word exists in the dictionary.

6. **Resize Memoization Vector**
	```cpp
	    memo.resize(s.size(), -1);
	```
	The `memo` vector is resized to the size of the string `s` and initialized with -1 to indicate that no positions have been processed yet.

7. **Recursive Call (bt)**
	```cpp
	    return bt(s, 0, mp);
	```
	The `bt` function is called with the initial index `0` and the map `mp` to start checking if the string `s` can be segmented from the beginning.

8. **Helper Function Definition (bt)**
	```cpp
	bool bt(string s, int idx, map<string, bool> &mp) {
	```
	This is the definition of the helper function `bt`, which recursively checks if the string can be segmented from index `idx` onward.

9. **Base Case (end of string)**
	```cpp
	    if(idx == s.size()) return true;
	```
	If the current index `idx` is equal to the length of the string `s`, it means the entire string has been successfully segmented, so return `true`.

10. **Check Memoization**
	```cpp
	    if(memo[idx] != -1) return memo[idx];
	```
	If the value at `memo[idx]` is not -1, it means this subproblem has already been solved, so return the stored result.

11. **Start Loop (check substrings)**
	```cpp
	    for(int i = idx; i < s.size(); i++) {
	```
	This loop checks all possible substrings starting from the current index `idx`.

12. **Check Substring in Dictionary**
	```cpp
	        if(mp.count(s.substr(idx, i - idx + 1)) && bt(s, i + 1, mp))
	```
	If the substring from `idx` to `i` exists in the dictionary (checked via `mp.count`) and the remaining part of the string can be segmented (recursively checked using `bt`), proceed.

13. **Memoize True**
	```cpp
	            return memo[idx] = true;
	```
	If a valid segmentation is found, store the result as `true` in `memo[idx]` and return `true`.

14. **Memoize False**
	```cpp
	    return memo[idx] = false;
	```
	If no valid segmentation is found after checking all substrings, store the result as `false` in `memo[idx]` and return `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), where n is the length of the string. This occurs when we have to check all substrings of the string.
- **Average Case:** O(n^2) in most cases.
- **Worst Case:** O(n^2) in the worst case, where n is the length of the string.

In the worst case, each substring of s must be checked, leading to a time complexity of O(n^2).

### Space Complexity 💾
- **Best Case:** O(n), where n is the length of the string.
- **Worst Case:** O(n), where n is the length of the string. This is due to the space needed for memoization.

The space complexity is O(n) due to the storage needed for the memoization array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/word-break/description/)

---
{{< youtube t0svbzZ1PWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
