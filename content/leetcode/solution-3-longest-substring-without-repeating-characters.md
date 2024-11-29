
+++
authors = ["grid47"]
title = "Leetcode 3: Longest Substring Without Repeating Characters"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3: Longest Substring Without Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/3.webp"
youtube = "wiGpQwVHdE0"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/wiGpQwVHdE0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/3.webp" 
    alt="A flowing ribbon with distinct, colorful segments, twisting and avoiding repetition."
    caption="Solution to LeetCode 3: Longest Substring Without Repeating Characters Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string, determine the length of the longest substring that contains no repeating characters. The substring must consist of consecutive characters, and its length is to be returned as the output.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a single string 's'.
- **Example:** `s = "abcdeabc"`
- **Constraints:**
	- 0 <= s.length <= 50,000
	- s consists of English letters, digits, symbols, and spaces.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the length of the longest substring without repeating characters.
- **Example:** `5`
- **Constraints:**
	- The output must be a non-negative integer.
	- If the string is empty, return 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum length of a substring with unique characters from the given string.

- Use a sliding window approach with two pointers to track the current substring.
- Maintain a hash map to store the most recent index of each character.
- Move the right pointer to include new characters and adjust the left pointer to avoid duplicates.
- Keep track of the maximum length of the substring during the process.
- Return the maximum length found.
{{< dots >}}
### Problem Assumptions ✅
- The input is a valid string.
- Special characters, digits, and spaces are treated the same as letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abcdefabc"`  \
  **Explanation:** The longest substring without repeating characters is "abcdef" with a length of 6.

- **Input:** `s = "aaaaaa"`  \
  **Explanation:** The longest substring without repeating characters is "a" with a length of 1.

- **Input:** `s = "dvdf"`  \
  **Explanation:** The longest substring without repeating characters is "vdf" with a length of 3.

{{< dots >}}
## Approach 🚀
A sliding window technique with a hash map to efficiently find the longest substring without repeating characters.

### Initial Thoughts 💭
- Using a brute force approach would result in a quadratic time complexity, which is not efficient for large strings.
- A sliding window with a hash map can efficiently track the unique characters in the current substring.
- Track the current substring using two pointers and maintain the last seen index of each character to avoid revisiting characters.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, the output should be 0.
- The function should handle strings with the maximum length efficiently.
- Strings with all unique characters should return the length of the string.
- Strings with all identical characters should return 1.
- Handles a mix of letters, digits, symbols, and spaces.
{{< dots >}}
## Code 💻
```cpp
int lengthOfLongestSubstring(string s) {
    int prv = -1, len = 0;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++) {
        if(mp.count(s[i]))
            prv = max(prv, mp[s[i]]);
        mp[s[i]] = i;
        len = max(len, i - prv);
    }
    return len;
}
```

This code efficiently finds the length of the longest substring without repeating characters in a given string. It utilizes a sliding window approach with a hash map to keep track of character occurrences and their last indices.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int lengthOfLongestSubstring(string s) {
	```
	Declares a function `lengthOfLongestSubstring` that takes a string `s` as input and returns the length of the longest substring without repeating characters.

2. **Variable Initialization**
	```cpp
	    int prv = -1, len = 0;
	```
	Initializes two integer variables: `prv` to track the index of the last occurrence of a character, and `len` to store the length of the current longest substring.

3. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	Initializes an empty hash map `mp` to store characters as keys and their corresponding indices as values.

4. **Loop Initialization and Condition**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Starts a loop to iterate through each character in the string `s`.

5. **Character Check**
	```cpp
	        if(mp.count(s[i]))
	```
	Checks if the current character `s[i]` is already present in the hash map.

6. **Update Previous Index**
	```cpp
	            prv = max(prv, mp[s[i]]);
	```
	If the character is found, updates `prv` to the maximum of its current value and the previous index of the character.

7. **Update Character Index**
	```cpp
	        mp[s[i]] = i;
	```
	Updates the index of the current character in the hash map.

8. **Update Longest Substring Length**
	```cpp
	        len = max(len, i - prv);
	```
	Updates the `len` variable to the maximum of its current value and the length of the current substring, which is calculated as `i - prv`.

9. **Return Result**
	```cpp
	    return len;
	```
	Returns the length of the longest substring without repeating characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each character is processed at most twice: once when moving the right pointer and once when adjusting the left pointer.

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity depends on the size of the character set used in the string, where m is the maximum number of unique characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

---
{{< youtube wiGpQwVHdE0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
