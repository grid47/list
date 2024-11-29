
+++
authors = ["grid47"]
title = "Leetcode 567: Permutation in String"
date = "2024-09-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 567: Permutation in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Two Pointers","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/567.webp"
youtube = "quSfR-uwkZU"
youtube_upload_date="2024-03-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/quSfR-uwkZU/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/567.webp" 
    alt="A string where permutations are checked, each valid permutation softly glowing as it is found."
    caption="Solution to LeetCode 567: Permutation in String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two strings s1 and s2, return true if s2 contains any permutation of s1 as a substring, otherwise return false. In other words, check if one of the permutations of s1 exists as a substring within s2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, s1 and s2.
- **Example:** `Input: s1 = "abc", s2 = "eidbacooo"`
- **Constraints:**
	- 1 <= s1.length, s2.length <= 10^4
	- s1 and s2 consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value: true if a permutation of s1 exists as a substring in s2, false otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The result should be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if any permutation of string s1 is a substring of s2.

- Create frequency count arrays for s1 and s2.
- Iterate through s2, adjusting the frequency array of the current window of size equal to the length of s1.
- If the frequency arrays of s1 and the current window of s2 match, return true.
- If no such match is found after checking all windows of s2, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input strings s1 and s2 will only contain lowercase letters.
- The solution should handle edge cases like when s1 is larger than s2.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s1 = "abc", s2 = "eidbacooo"`  \
  **Explanation:** The string s2 contains a permutation of s1, such as "cba" within the substring "eidbacooo".

- **Input:** `Input: s1 = "abc", s2 = "eidboaoo"`  \
  **Explanation:** There is no permutation of s1 in s2, hence the result is false.

{{< dots >}}
## Approach 🚀
The approach is to use a sliding window technique along with frequency counting to efficiently check for a permutation of s1 within s2.

### Initial Thoughts 💭
- By using a sliding window of size equal to the length of s1, we can avoid checking each substring of s2 individually and instead maintain a frequency count for the current window.
- We need to adjust the sliding window by adding the next character and removing the old character from the frequency count. If the counts match the frequency of s1, we have found a permutation.
{{< dots >}}
### Edge Cases 🌐
- The input strings s1 and s2 will always have a length of at least 1, as per the problem constraints.
- The solution should efficiently handle large inputs up to the maximum limit of 10^4 characters.
- If s1 is longer than s2, the result should be false.
- The solution should be efficient enough to handle inputs near the upper bound of the input size.
{{< dots >}}
## Code 💻
```cpp
bool checkInclusion(string s1, string s2) {
    vector<int> p1(26, 0), p2(26, 0);
    for(char x: s1) p1[x-'a']++;
    for(int i = 0; i < s2.size(); i++) {
        if(i >= s1.size()) p2[s2[i - s1.size()] - 'a']--;
        p2[s2[i] - 'a']++;
        if(p1 == p2) return true;
    }
    return false;
}
```

The function `checkInclusion` checks if a permutation of string `s1` is a substring of string `s2`. It uses a sliding window and frequency counts for efficient comparison.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkInclusion(string s1, string s2) {
	```
	Defines the function `checkInclusion` that takes two strings `s1` and `s2` and returns `true` if any permutation of `s1` is a substring of `s2`.

2. **Frequency Array Initialization**
	```cpp
	    vector<int> p1(26, 0), p2(26, 0);
	```
	Initializes two frequency arrays, `p1` and `p2`, each of size 26 (for each letter of the alphabet). `p1` will store the character counts for `s1`, and `p2` will store the character counts for the current window in `s2`.

3. **Populate Frequency Array for s1**
	```cpp
	    for(char x: s1) p1[x-'a']++;
	```
	Populates the frequency array `p1` with the counts of each character in `s1`.

4. **Sliding Window Loop**
	```cpp
	    for(int i = 0; i < s2.size(); i++) {
	```
	Begins iterating over `s2`, using a sliding window approach to compare the character frequencies of substrings of `s2` with `s1`.

5. **Slide Window - Remove Left Character**
	```cpp
	        if(i >= s1.size()) p2[s2[i - s1.size()] - 'a']--;
	```
	Once the sliding window has reached the size of `s1`, the leftmost character of the window is removed by decrementing its count in `p2`.

6. **Slide Window - Add Right Character**
	```cpp
	        p2[s2[i] - 'a']++;
	```
	Adds the current character of `s2` (at index `i`) to the sliding window by incrementing its count in `p2`.

7. **Frequency Comparison**
	```cpp
	        if(p1 == p2) return true;
	```
	Compares the frequency arrays `p1` and `p2`. If they are equal, it means the current window in `s2` is a permutation of `s1`, and the function returns `true`.

8. **Return False**
	```cpp
	    return false;
	```
	If no permutation of `s1` was found in `s2`, the function returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the length of s2 due to the sliding window approach.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of space to store the frequency counts of s1 and the window.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/permutation-in-string/description/)

---
{{< youtube quSfR-uwkZU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
