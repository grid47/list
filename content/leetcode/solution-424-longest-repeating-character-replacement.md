
+++
authors = ["grid47"]
title = "Leetcode 424: Longest Repeating Character Replacement"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 424: Longest Repeating Character Replacement in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/424.webp"
youtube = "tkNWKvxI3mU"
youtube_upload_date="2024-03-09"
youtube_thumbnail="https://i.ytimg.com/vi/tkNWKvxI3mU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/424.webp" 
    alt="A string with a character being replaced to form the longest substring, glowing softly with each change."
    caption="Solution to LeetCode 424: Longest Repeating Character Replacement Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string s consisting of uppercase English letters and an integer k. You can change any character in the string to any other uppercase English character, but you are allowed to perform this operation at most k times. The goal is to find the length of the longest substring that contains the same letter after performing at most k character changes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s containing only uppercase English letters and an integer k, which represents the maximum number of changes you can make to the string.
- **Example:** `Input: s = "AABACDAB", k = 2`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 0 <= k <= s.length
	- s consists only of uppercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the length of the longest substring that can be formed by making at most k changes to the input string.
- **Example:** `Output: 5`
- **Constraints:**
	- The output is a single integer value representing the length of the longest substring with repeating characters after at most k changes.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest substring containing the same letter, using at most k changes to transform the string.

- Initialize a map to track the frequency of characters in the current window of the string.
- Iterate through the string, expanding the window from the right side by incrementing the pointer.
- If the length of the current window minus the count of the most frequent character exceeds k, shrink the window from the left side.
- Keep track of the maximum length of the window where the condition is satisfied.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains only uppercase English letters, and it is guaranteed that k is non-negative and less than or equal to the length of the string.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: s = "AABACDAB", k = 2`  \
  **Explanation:** In this case, we can change the two 'C's to 'A's, forming the substring 'AAAAA' which has a length of 5. This is the longest substring with repeating characters, so the output is 5.

- **Input:** `Example 2: Input: s = "ABAB", k = 2`  \
  **Explanation:** Here, we can change two 'A's to 'B's or two 'B's to 'A's. This will result in the substring 'BBBB' or 'AAAA', both of which have a length of 4. Hence, the output is 4.

{{< dots >}}
## Approach 🚀
The approach is to use the sliding window technique to find the longest substring where we can change at most k characters to make all characters the same. We expand the window while keeping track of the most frequent character in the current window.

### Initial Thoughts 💭
- A sliding window can efficiently track the frequency of characters and adjust the window size based on the number of changes allowed.
- By using the most frequent character in the window, we minimize the number of changes needed to make the rest of the characters the same.
{{< dots >}}
### Edge Cases 🌐
- The input string will always have a length of at least 1, so there is no need to handle an empty string.
- For large input strings, ensure that the solution runs in linear time relative to the length of the string.
- If k is 0, the longest substring will be the length of the longest contiguous substring with repeating characters in the original string.
- The solution should efficiently handle large inputs with up to 100,000 characters.
{{< dots >}}
## Code 💻
```cpp
int characterReplacement(string s, int k) {
    map<char, int> ma;
    int res = 0, j = 0, mx = 0;
    for(int i =  0; i < s.size(); i++) {
        ma[s[i]]++;
        mx = max(mx, ma[s[i]]);
        if(i - j + 1 > mx + k) {
            ma[s[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    return res;
}
```

The `characterReplacement` function solves the problem of finding the longest substring in a given string `s` that can be converted into a single character string by changing at most `k` characters. It uses the sliding window technique with two pointers and a frequency map to track the number of characters in the current window.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int characterReplacement(string s, int k) {
	```
	This line declares the function `characterReplacement`, which takes the input string `s` and an integer `k` representing the maximum number of allowed character replacements.

2. **Frequency Map Initialization**
	```cpp
	    map<char, int> ma;
	```
	This line initializes a frequency map `ma` that will store the count of each character in the current window of the string.

3. **Variable Initialization**
	```cpp
	    int res = 0, j = 0, mx = 0;
	```
	Here, three variables are initialized: `res` to track the maximum length of valid substring found, `j` as the start of the window, and `mx` to store the frequency of the most common character in the current window.

4. **Sliding Window Loop**
	```cpp
	    for(int i =  0; i < s.size(); i++) {
	```
	This loop iterates over the string `s` using the variable `i` to represent the end of the current window.

5. **Frequency Update**
	```cpp
	        ma[s[i]]++;
	```
	This line increments the frequency of the character at position `i` in the map `ma`.

6. **Max Frequency Update**
	```cpp
	        mx = max(mx, ma[s[i]]);
	```
	This line updates `mx`, the frequency of the most common character in the current window, by comparing it with the frequency of the character at position `i`.

7. **Window Size Check**
	```cpp
	        if(i - j + 1 > mx + k) {
	```
	This condition checks if the size of the current window exceeds the allowed limit, which is the frequency of the most common character plus `k` (the number of character replacements).

8. **Character Removal from Window**
	```cpp
	            ma[s[j]]--;
	```
	If the window size exceeds the limit, the character at the start of the window (`s[j]`) is removed by decrementing its frequency in the map.

9. **Start Pointer Increment**
	```cpp
	            j++;
	```
	This increments `j`, effectively shrinking the window from the left to restore the valid window size.

10. **Result Update**
	```cpp
	        res = max(res, i - j + 1);
	```
	This updates `res` with the maximum length of the valid window found so far.

11. **Return Statement**
	```cpp
	    return res;
	```
	This returns the maximum length of the substring found that can be turned into a string of one character by replacing at most `k` characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input string.
- **Average Case:** O(n), since the sliding window ensures a linear scan through the string.
- **Worst Case:** O(n), as the window size adjustment requires only constant time operations for each character.

The time complexity is linear because we process each character in the string at most twice: once for expansion and once for contraction.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is needed except for the sliding window.
- **Worst Case:** O(1), since the space used by the frequency map is bounded by the number of distinct characters (constant size).

The space complexity is constant because we only use a small amount of extra space to track the frequency of characters in the window.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

---
{{< youtube tkNWKvxI3mU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
