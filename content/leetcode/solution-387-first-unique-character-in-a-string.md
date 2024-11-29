
+++
authors = ["grid47"]
title = "Leetcode 387: First Unique Character in a String"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 387: First Unique Character in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Queue","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/387.webp"
youtube = "nFiAUwTH0zY"
youtube_upload_date="2020-05-05"
youtube_thumbnail="https://i.ytimg.com/vi/nFiAUwTH0zY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/387.webp" 
    alt="A glowing string with the first unique character softly highlighted."
    caption="Solution to LeetCode 387: First Unique Character in a String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string s, find the index of the first character that does not repeat in the string. If all characters repeat, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s.
- **Example:** `s = "programming"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of only lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the first non-repeating character, or -1 if no such character exists.
- **Example:** `Output: 0`
- **Constraints:**
	- The index should be within the range of the string length.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the first non-repeating character efficiently.

- Create a frequency map of characters in the string.
- Traverse the string and check the frequency of each character.
- Return the index of the first character with a frequency of 1.
{{< dots >}}
### Problem Assumptions ✅
- The input string is valid and contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: "programming"`  \
  **Explanation:** The character 'p' at index 0 is the first non-repeating character in the string.

{{< dots >}}
## Approach 🚀
The approach is to use a frequency map to count the occurrences of each character in the string, then traverse the string again to find the first character with a frequency of 1.

### Initial Thoughts 💭
- A frequency map will help us track the count of each character efficiently.
- By iterating through the string twice, once to build the frequency map and once to find the first non-repeating character, we can solve the problem in O(n) time.
{{< dots >}}
### Edge Cases 🌐
- The input string will always have at least one character.
- Ensure that the solution runs efficiently for strings with lengths up to 100,000.
- For strings where all characters repeat, return -1.
- Ensure that the algorithm handles edge cases efficiently.
{{< dots >}}
## Code 💻
```cpp
int firstUniqChar(string s) {
    
    map<char, int> mp;
    for(char x: s) mp[x]++;
    
    for(int i = 0; i < s.size(); i++)
        if(mp[s[i]] == 1) return i;
    
    return -1;
}
```

This code finds the first non-repeating character in a string and returns its index. If no such character exists, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int firstUniqChar(string s) {
	```
	Define the function 'firstUniqChar' that takes a string 's' as input and returns the index of the first non-repeating character.

2. **Data Structure**
	```cpp
	    map<char, int> mp;
	```
	Declare a map 'mp' to store the frequency of each character in the string.

3. **Loop Iteration**
	```cpp
	    for(char x: s) mp[x]++;
	```
	Iterate through each character in the string 's' and increment its corresponding count in the map.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < s.size(); i++)
	```
	Iterate through the string 's' by index.

5. **Condition Check**
	```cpp
	        if(mp[s[i]] == 1) return i;
	```
	Check if the character at index 'i' in the string has a count of 1 in the map (i.e., it's non-repeating). If true, return the index 'i'.

6. **Return Statement**
	```cpp
	    return -1;
	```
	Return -1 if no non-repeating character is found in the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we iterate over the string twice.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the frequency map used to store character counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/first-unique-character-in-a-string/description/)

---
{{< youtube nFiAUwTH0zY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
