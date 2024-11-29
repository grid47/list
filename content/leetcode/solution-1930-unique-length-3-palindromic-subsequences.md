
+++
authors = ["grid47"]
title = "Leetcode 1930: Unique Length-3 Palindromic Subsequences"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1930: Unique Length-3 Palindromic Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3THUt0vAFLU"
youtube_upload_date="2021-07-11"
youtube_thumbnail="https://i.ytimg.com/vi/3THUt0vAFLU/maxresdefault.jpg"
comments = true
+++



---
You are given a string s, and you need to return the number of unique palindromic subsequences of length 3 that are subsequences of s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single string s of length n.
- **Example:** `s = "aabca"`
- **Constraints:**
	- 3 <= s.length <= 10^5
	- s consists of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of unique palindromic subsequences of length 3 that appear in s.
- **Example:** `3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently count all unique palindromic subsequences of length 3.

- Use a frequency map to track the first and last occurrences of each character in the string.
- For each character, check if it forms a palindromic subsequence with other characters in between.
{{< dots >}}
### Problem Assumptions ✅
- All characters in the string are lowercase English letters.
- The string will always have at least 3 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "aabca"`  \
  **Explanation:** The three unique palindromic subsequences are 'aba', 'aaa', and 'aca', so the output is 3.

{{< dots >}}
## Approach 🚀
To count the palindromic subsequences, we can use a strategy that involves tracking first and last occurrences of characters and counting the valid subsequences.

### Initial Thoughts 💭
- The string can be very large, so an efficient solution is needed.
- We need to find a way to count palindromic subsequences without generating all possible subsequences.
{{< dots >}}
### Edge Cases 🌐
- If the string has fewer than 3 characters, the result should be 0.
- The solution should handle strings up to length 100,000 efficiently.
- If the string consists of only one character repeated, the number of palindromic subsequences could be larger.
- Consider the time complexity to be linear in the size of the string.
{{< dots >}}
## Code 💻
```cpp
int countPalindromicSubsequence(string num) {
    int n = num.size(), res = 0;        
    vector<int> fst(26,n), lst(26,0);
    for(int i = 0; i < n; i++) {
        fst[num[i]-'a']= min(fst[num[i]-'a'], i);
        lst[num[i]-'a'] = i;
    }
    for(int i = 0; i < 26; i++) {
if(fst[i] < lst[i]) res += unordered_set<char>(num.begin() + fst[i] + 1, num.begin() + lst[i]).size();
    }
    return res;        
}
```

This function computes the count of distinct palindromic subsequences in a given string `num`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Header**
	```cpp
	int countPalindromicSubsequence(string num) {
	```
	Defines the function `countPalindromicSubsequence`, which takes a string `num` and returns an integer representing the count of distinct palindromic subsequences.

2. **Variable Initialization**
	```cpp
	    int n = num.size(), res = 0;        
	```
	Initializes `n` to the length of the string `num` and `res` to store the count of palindromic subsequences.

3. **Vector Initialization**
	```cpp
	    vector<int> fst(26,n), lst(26,0);
	```
	Declares two vectors `fst` and `lst` to store the first and last occurrence indices of each character in the string `num`.

4. **For Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates through each character in the string `num`.

5. **First Occurrence Update**
	```cpp
	        fst[num[i]-'a']= min(fst[num[i]-'a'], i);
	```
	Updates the first occurrence of the character `num[i]` in the `fst` vector, ensuring it holds the smallest index.

6. **Last Occurrence Update**
	```cpp
	        lst[num[i]-'a'] = i;
	```
	Updates the last occurrence of the character `num[i]` in the `lst` vector with the current index.

7. **Second For Loop Start**
	```cpp
	    for(int i = 0; i < 26; i++) {
	```
	Starts a second loop that iterates over all possible characters (from 'a' to 'z').

8. **Palindrome Count Calculation**
	```cpp
	if(fst[i] < lst[i]) res += unordered_set<char>(num.begin() + fst[i] + 1, num.begin() + lst[i]).size();
	```
	For each character, if it appears more than once, calculates the number of distinct characters between its first and last occurrences, adding this count to `res`.

9. **Return Statement**
	```cpp
	    return res;        
	```
	Returns the total count of distinct palindromic subsequences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate over the string once to compute the first and last occurrences.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use constant space to store the first and last occurrences of characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/)

---
{{< youtube 3THUt0vAFLU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
