
+++
authors = ["grid47"]
title = "Leetcode 395: Longest Substring with At Least K Repeating Characters"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 395: Longest Substring with At Least K Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Divide and Conquer","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/395.webp"
youtube = "bHZkCAcj3dc"
youtube_upload_date="2020-07-17"
youtube_thumbnail="https://i.ytimg.com/vi/bHZkCAcj3dc/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGMgZShMMA8=&rs=AOn4CLCuVJe9ynceDrU12Sdzi3WrnCQ1Pg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/395.webp" 
    alt="A string with glowing characters highlighting the longest substring with at least K repeating characters."
    caption="Solution to LeetCode 395: Longest Substring with At Least K Repeating Characters Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string `s` and an integer `k`, return the length of the longest substring of `s` such that the frequency of each character in this substring is greater than or equal to `k`. If no such substring exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` and an integer `k` where `s` is the given string and `k` is the minimum frequency of characters required in the substring.
- **Example:** `Input: s = 'aabbbc', k = 2`
- **Constraints:**
	- 1 <= s.length <= 10^4
	- s consists of only lowercase English letters.
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the length of the longest valid substring, where every character appears at least `k` times. If no such substring exists, return 0.
- **Example:** `Output: 5`
- **Constraints:**
	- The solution should return the length of the longest valid substring.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify and return the length of the longest substring where each character appears at least `k` times.

- Count the frequency of each character in the string.
- If a character appears less than `k` times, it cannot be part of the valid substring.
- Recursively divide the string into parts, ignoring characters that appear less than `k` times, and find the longest valid substring in the remaining parts.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` is valid and contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'aabbbc', k = 2`  \
  **Explanation:** The string can be split into two parts: 'aab' and 'bbc'. 'aab' is valid as 'a' appears 2 times, and 'bbc' is valid as 'b' appears 3 times. The longest valid substring is 'aabbb'.

- **Input:** `Input: s = 'abcde', k = 2`  \
  **Explanation:** None of the characters appear at least 2 times, so there is no valid substring. The output is 0.

{{< dots >}}
## Approach 🚀
The approach uses recursion to break down the string and check if each character meets the frequency requirement. We divide the string into substrings and solve each part independently.

### Initial Thoughts 💭
- We can count the frequency of each character in the string and recursively divide the string based on this frequency.
- The problem can be approached by dividing the string into smaller substrings where the characters meet the required frequency condition.
{{< dots >}}
### Edge Cases 🌐
- The input string will not be empty as it has a minimum length of 1.
- Ensure the solution handles input strings with lengths up to 10^4 efficiently.
- Handle cases where `k` is greater than the length of the string, resulting in no valid substrings.
- Handle cases where all characters are distinct and where all characters appear the same number of times.
{{< dots >}}
## Code 💻
```cpp
int longestSubstring(string s, int k) {
    if(s.size() == 0 || k > s.size()) return 0;
    if(k == 0) return s.size();

    unordered_map<char, int> mp;
    for(int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    int idx = 0;
    while(idx < s.size() && mp[s[idx]] >= k) idx++;
    if(idx == s.size()) return s.size();

    int left = longestSubstring(s.substr(0, idx), k);
    int right = longestSubstring(s.substr(idx + 1), k);

    return max(left, right);
}
```

The function `longestSubstring` solves the problem using a divide-and-conquer approach by recursively checking for the longest substring where every character appears at least `k` times. It uses a map to count character frequencies and divides the string based on characters that do not meet the frequency condition.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestSubstring(string s, int k) {
	```
	The function `longestSubstring` takes a string `s` and an integer `k`, and returns the length of the longest substring where each character appears at least `k` times.

2. **Edge Case Handling**
	```cpp
	    if(s.size() == 0 || k > s.size()) return 0;
	```
	This checks if the string is empty or if `k` is greater than the size of the string, returning 0 as there is no valid substring in such cases.

3. **Edge Case Handling**
	```cpp
	    if(k == 0) return s.size();
	```
	If `k` is 0, the entire string is a valid substring, so the function returns the size of the string.

4. **Character Frequency Calculation**
	```cpp
	    unordered_map<char, int> mp;
	```
	An unordered map `mp` is initialized to store the frequency of each character in the string `s`.

5. **Frequency Counting**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Iterating over the string to count the frequency of each character.

6. **Frequency Counting**
	```cpp
	        mp[s[i]]++;
	```
	Each character's frequency is incremented in the map.

7. **Identifying Invalid Character**
	```cpp
	    int idx = 0;
	```
	A variable `idx` is initialized to track the index where the string can no longer be split.

8. **Identifying Invalid Character**
	```cpp
	    while(idx < s.size() && mp[s[idx]] >= k) idx++;
	```
	The loop continues as long as characters at `s[idx]` appear at least `k` times. If a character fails this condition, `idx` is incremented.

9. **Base Case Check**
	```cpp
	    if(idx == s.size()) return s.size();
	```
	If `idx` reaches the end of the string, it means all characters meet the frequency requirement, so the function returns the size of the string.

10. **Recursion**
	```cpp
	    int left = longestSubstring(s.substr(0, idx), k);
	```
	Recursively call `longestSubstring` on the left part of the string, from the start to `idx`.

11. **Recursion**
	```cpp
	    int right = longestSubstring(s.substr(idx + 1), k);
	```
	Recursively call `longestSubstring` on the right part of the string, starting from `idx + 1`.

12. **Returning Result**
	```cpp
	    return max(left, right);
	```
	The function returns the maximum length of the valid substrings found in both the left and right parts.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n^2)

The time complexity is O(n) in the best and average cases when most characters meet the frequency requirement. In the worst case, the string might be split repeatedly.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the recursion stack and temporary storage for substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/)

---
{{< youtube bHZkCAcj3dc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
