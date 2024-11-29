
+++
authors = ["grid47"]
title = "Leetcode 791: Custom Sort String"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 791: Custom Sort String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/791.webp"
youtube = "HQ4U24lRar8"
youtube_upload_date="2021-03-06"
youtube_thumbnail="https://i.ytimg.com/vi/HQ4U24lRar8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/791.webp" 
    alt="A string being sorted according to custom rules, with each valid sorting step glowing softly."
    caption="Solution to LeetCode 791: Custom Sort String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string order that specifies a custom order of characters, and a string s that contains the characters you need to permute. The task is to rearrange the characters of s so that they follow the order specified in the string order. If a character appears in order, it must appear in s in the same relative order. Any characters from s that don't appear in order can be arranged in any position.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings: order and s.
- **Example:** `order = 'zyx', s = 'abcxyz'`
- **Constraints:**
	- 1 <= order.length <= 26
	- 1 <= s.length <= 200
	- order and s consist of lowercase English letters.
	- All characters in order are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string that is a permutation of s, where the characters are arranged according to the order given by the string order. If a character does not appear in order, it can appear in any position.
- **Example:** `Output: 'zyxcba'`
- **Constraints:**
	- The output should be a valid permutation of the characters of s.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to permute the string s based on the order of characters provided in order.

- Create a mapping of each character in order to its position.
- Sort the string s using this mapping to ensure that characters in s appear in the same order as in order.
- Characters not in order can be placed in any position in s.
{{< dots >}}
### Problem Assumptions ✅
- The input strings are valid, and characters in order appear only once.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: order = 'abc', s = 'bca'`  \
  **Explanation:** The characters 'a', 'b', and 'c' must be arranged in the order specified by order. Therefore, the output should be 'abc'.

- **Input:** `Input: order = 'zyx', s = 'abcxyz'`  \
  **Explanation:** The characters 'x', 'y', and 'z' must appear in the order 'z', 'y', 'x' as per order, while 'a', 'b', and 'c' can appear in any order.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a sorting algorithm that compares the characters based on their position in the order string.

### Initial Thoughts 💭
- The characters in order dictate the relative order of characters in s.
- Characters not found in order can appear in any order in the result.
- We can use a map to track the order of characters, then sort the string s accordingly.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since both order and s are non-empty.
- For larger strings up to length 200, ensure that sorting remains efficient.
- If s contains characters not found in order, they can be arranged in any position.
- Ensure that the final string is a valid permutation of s, respecting the order of characters that appear in order.
{{< dots >}}
## Code 💻
```cpp
string customSortString(string o, string s) {
    
    unordered_map<char, int> mp;
    for(int i = 0; i < o.size(); i++)
        mp[o[i]] = i + 1;
    
    sort(s.begin(), s.end(), [&](char a, char b) {
        return mp[a] < mp[b];
    });
    
    return s;
}
```

This function customSortString sorts a string 's' based on the order defined by string 'o'. The characters in 's' are sorted according to their position in 'o'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string customSortString(string o, string s) {
	```
	The function 'customSortString' is defined with two string parameters: 'o' (the custom order) and 's' (the string to be sorted).

2. **Map Initialization**
	```cpp
	    unordered_map<char, int> mp;
	```
	An unordered_map 'mp' is created to store the position of each character in the string 'o', with the character as the key and its position as the value.

3. **Map Population**
	```cpp
	    for(int i = 0; i < o.size(); i++)
	```
	A loop iterates through each character in string 'o'.

4. **Map Population**
	```cpp
	        mp[o[i]] = i + 1;
	```
	Each character in 'o' is mapped to a position (i+1) in the unordered_map 'mp'. The positions are 1-based.

5. **Sorting**
	```cpp
	    sort(s.begin(), s.end(), [&](char a, char b) {
	```
	The string 's' is sorted using the 'sort' function. The comparison function is a lambda that compares the characters based on their position in 'mp'.

6. **Comparison Function**
	```cpp
	        return mp[a] < mp[b];
	```
	The lambda function compares two characters 'a' and 'b' based on their positions in the map 'mp'. It ensures characters are ordered according to their custom positions in 'o'.

7. **Return Statement**
	```cpp
	    return s;
	```
	The sorted string 's' is returned as the output of the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the length of s.
- **Average Case:** O(n log n), since sorting dominates the complexity.
- **Worst Case:** O(n log n), where n is the length of s.

Sorting the characters based on the custom order requires O(n log n) time, where n is the length of the string s.

### Space Complexity 💾
- **Best Case:** O(n), since we need space to store the sorted version of s.
- **Worst Case:** O(n), where n is the length of s, for storing the result of the sorted string.

The space complexity is O(n) due to the storage of the sorted string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/custom-sort-string/description/)

---
{{< youtube HQ4U24lRar8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
