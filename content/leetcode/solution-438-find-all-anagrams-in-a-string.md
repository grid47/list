
+++
authors = ["grid47"]
title = "Leetcode 438: Find All Anagrams in a String"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 438: Find All Anagrams in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/438.webp"
youtube = "G8xtZy0fDKg"
youtube_upload_date="2021-11-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/G8xtZy0fDKg/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/438.webp" 
    alt="A glowing string where anagrams light up and form matching groups as they are found."
    caption="Solution to LeetCode 438: Find All Anagrams in a String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two strings, s and p. Return the list of start indices of all the anagrams of string p in string s. An anagram of p is a rearrangement of the characters of p, and the start indices should be returned in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, s and p, where s is the main string and p is the string whose anagrams are to be found.
- **Example:** `"cbaebabacd", "abc"`
- **Constraints:**
	- 1 <= s.length, p.length <= 3 * 10^4
	- s and p consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers representing the starting indices of all the anagrams of p found in s.
- **Example:** `[0, 6]`
- **Constraints:**
	- The result should be an array of integers, and the indices can be in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently find all the starting indices where anagrams of string p appear in string s.

- 1. Use a sliding window approach to check each substring of s that has the same length as p.
- 2. Compare the character frequencies of the current substring in s with the character frequencies of p.
- 3. If they match, store the starting index of the substring as an answer.
{{< dots >}}
### Problem Assumptions ✅
- Both strings s and p consist only of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `"cbaebabacd", "abc"`  \
  **Explanation:** In this example, the substrings that are anagrams of 'abc' in 'cbaebabacd' are 'cba' at index 0 and 'bac' at index 6.

- **Input:** `"abab", "ab"`  \
  **Explanation:** Here, the substrings 'ab', 'ba', and 'ab' are all anagrams of 'ab' in 'abab', appearing at indices 0, 1, and 2 respectively.

{{< dots >}}
## Approach 🚀
The sliding window technique can be used to check substrings of s for anagrams of p. We will maintain a frequency count of characters in the current window and compare it with the frequency count of p.

### Initial Thoughts 💭
- We need to compare character frequencies in s and p efficiently to find anagrams.
- The sliding window approach with two frequency arrays can help us avoid recomputing the character frequencies for every substring from scratch.
{{< dots >}}
### Edge Cases 🌐
- If either string s or p is empty, return an empty array.
- For very large strings, ensure that the solution runs efficiently within the given time constraints.
- Handle cases where p is larger than s (in which case no anagrams can exist).
- Handle edge cases such as empty strings or when p is longer than s.
{{< dots >}}
## Code 💻
```cpp
vector<int> findAnagrams(string s, string p) {
    vector<int> pc(26, 0), sc(26, 0);
    for(char x: p)
        pc[x-'a']++;
    
    vector<int> ans;
    for(int i = 0; i < s.size(); i++) {
        if(i >= p.size()) {
            sc[s[i - p.size()] - 'a']--;
        }
        sc[s[i]-'a']++;
        if(sc == pc) ans.push_back(i - p.size() +1);
    }
    return ans;
}
```

This function identifies all starting indices of substrings in 's' that are anagrams of 'p' using a sliding window technique. It compares frequency counts of characters in the current window with the target string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> findAnagrams(string s, string p) {
	```
	Defines the function to find starting indices of substrings in 's' that are anagrams of 'p'.

2. **Variable Initialization**
	```cpp
	    vector<int> pc(26, 0), sc(26, 0);
	```
	Initializes two frequency count vectors, one for the target string 'p' (pc) and another for the current window in 's' (sc).

3. **Loop Through Target**
	```cpp
	    for(char x: p)
	```
	Iterates over each character in the string 'p' to build its frequency count vector.

4. **Frequency Update**
	```cpp
	        pc[x-'a']++;
	```
	Increments the frequency of the character in the vector for 'p'.

5. **Result Storage**
	```cpp
	    vector<int> ans;
	```
	Declares a vector to store the starting indices of anagram substrings.

6. **Sliding Window Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Starts a loop to traverse through each character in the string 's' with a sliding window.

7. **Window Size Check**
	```cpp
	        if(i >= p.size()) {
	```
	Checks if the current index exceeds the size of 'p' to adjust the sliding window.

8. **Update Frequency**
	```cpp
	            sc[s[i - p.size()] - 'a']--;
	```
	Decrements the frequency count of the character that is sliding out of the window.

9. **Update Frequency**
	```cpp
	        sc[s[i]-'a']++;
	```
	Increments the frequency count of the character entering the sliding window.

10. **Comparison Check**
	```cpp
	        if(sc == pc) ans.push_back(i - p.size() +1);
	```
	Checks if the frequency count of the current window matches 'p'. If true, adds the starting index to the result.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the result vector containing the starting indices of all valid anagram substrings.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of string s. This occurs when the first window is already an anagram of p.
- **Average Case:** O(n), where n is the length of s, because the sliding window approach allows us to process each character in s only once.
- **Worst Case:** O(n), since the time complexity does not increase with the number of anagrams found.

The sliding window approach ensures that we only need to scan each character of s once, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(k), since we always store the frequency of characters in the alphabet.
- **Worst Case:** O(k), where k is the size of the alphabet (26 for lowercase English letters). This is the space required for the frequency arrays.

The space complexity is O(k), where k is the constant number of lowercase English letters, so it is independent of the size of the input strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)

---
{{< youtube G8xtZy0fDKg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
