
+++
authors = ["grid47"]
title = "Leetcode 2730: Find the Longest Semi-Repetitive Substring"
date = "2024-02-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2730: Find the Longest Semi-Repetitive Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "x_tHB_M7a_g"
youtube_upload_date="2023-06-10"
youtube_thumbnail="https://i.ytimg.com/vi/x_tHB_M7a_g/maxresdefault.jpg"
comments = true
+++



---
You are given a string s consisting of digits from '0' to '9'. A string is called semi-repetitive if there is at most one pair of adjacent identical digits. Your task is to return the length of the longest semi-repetitive substring of s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string s consisting of digits from 0 to 9.
- **Example:** `s = '33342'`
- **Constraints:**
	- 1 <= s.length <= 50
	- Each character of s is a digit from '0' to '9'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest semi-repetitive substring of s.
- **Example:** `4`
- **Constraints:**
	- The result will be an integer value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the longest semi-repetitive substring by ensuring there is at most one adjacent pair of identical digits.

- Traverse the string and track adjacent identical digits.
- If more than one adjacent identical pair is found, adjust the substring to remove excess pairs.
- Keep track of the maximum length of the semi-repetitive substrings.
{{< dots >}}
### Problem Assumptions ✅
- The input string is always a valid sequence of digits.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** For s = '33342', the longest semi-repetitive substring is '3334' since it contains only one adjacent same digit pair (33).

- **Input:** `Example 2`  \
  **Explanation:** For s = '1223', the longest semi-repetitive substring is '1223' as there is at most one adjacent same digit pair.

- **Input:** `Example 3`  \
  **Explanation:** For s = '11122233', the longest semi-repetitive substring is '111', which only contains one adjacent same digit pair.

{{< dots >}}
## Approach 🚀
The approach is to iterate through the string and check for adjacent pairs of identical digits. Adjust the window size to maintain at most one such pair.

### Initial Thoughts 💭
- We can use a sliding window approach to track the longest substring with at most one adjacent identical digit pair.
- The sliding window approach will allow us to efficiently track and adjust the substring as we traverse the string.
{{< dots >}}
### Edge Cases 🌐
- There are no empty strings since the string length is always at least 1.
- Strings near the upper limit (length 50) should be handled efficiently.
- Consider strings that are already semi-repetitive or contain repeated digits like '111'.
- The string length is bounded between 1 and 50, which allows for linear time solutions.
{{< dots >}}
## Code 💻
```cpp
int longestSemiRepetitiveSubstring(string s) {
    
    vector<int> sem(10, 0);
    int cnt = 0;
    
    int j = 0, len = 1;        
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) {
            cnt++;
            sem[s[i] - '0']++;
        }
        while(cnt > 1 && j < i) {
            if(s[j] == s[j + 1]) {
                sem[s[j] - '0']--;
                cnt--;
            }
            j++;
        }
        len = max(len, i - j + 1);
    }
    return len;
}
```

This function finds the length of the longest semi-repetitive substring in a given string `s`. A semi-repetitive substring is a substring that contains at most one pair of consecutive identical characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestSemiRepetitiveSubstring(string s) {
	```
	The function `longestSemiRepetitiveSubstring` is defined, taking a string `s` and returning the length of the longest semi-repetitive substring.

2. **Array Initialization**
	```cpp
	    vector<int> sem(10, 0);
	```
	An array `sem` is initialized with 10 elements, all set to 0. This array tracks the count of each digit (0-9) in the current substring.

3. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable `cnt` is initialized to 0. It counts the number of consecutive characters in the substring that are identical.

4. **Variable Initialization**
	```cpp
	    int j = 0, len = 1;        
	```
	Two variables are initialized: `j`, the starting index of the current substring, and `len`, the length of the longest semi-repetitive substring, initially set to 1.

5. **Loop Start**
	```cpp
	    for(int i = 1; i < s.size(); i++) {
	```
	A loop starts, iterating through the string `s` from index 1 to the end.

6. **Condition Check**
	```cpp
	        if(s[i] == s[i - 1]) {
	```
	If the current character is the same as the previous character, the substring may have a duplicate character.

7. **Counter Update**
	```cpp
	            cnt++;
	```
	The `cnt` variable is incremented to indicate that a consecutive duplicate character has been found.

8. **Array Update**
	```cpp
	            sem[s[i] - '0']++;
	```
	The corresponding digit in the `sem` array is incremented to track the number of occurrences of that digit in the current substring.

9. **While Loop Start**
	```cpp
	        while(cnt > 1 && j < i) {
	```
	A while loop starts, ensuring that only one pair of consecutive identical characters is allowed. If more than one is found, the substring needs to be adjusted by moving the starting index `j`.

10. **Condition Check**
	```cpp
	            if(s[j] == s[j + 1]) {
	```
	If the characters at positions `j` and `j + 1` are identical, the substring has more than one consecutive identical character.

11. **Array Update**
	```cpp
	                sem[s[j] - '0']--;
	```
	The corresponding digit count in the `sem` array is decreased as the character at index `j` is excluded from the substring.

12. **Counter Update**
	```cpp
	                cnt--;
	```
	The `cnt` variable is decremented as one of the duplicate characters is removed.

13. **Variable Update**
	```cpp
	            j++;
	```
	The starting index `j` is incremented to shrink the current window and continue checking for valid substrings.

14. **Length Update**
	```cpp
	        len = max(len, i - j + 1);
	```
	The length of the current valid substring is calculated and compared to the previous maximum length. The longest length is stored in `len`.

15. **Return Statement**
	```cpp
	    return len;
	```
	The function returns the length of the longest semi-repetitive substring.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we only traverse the string once with two pointers.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only use a few integer variables and no additional data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/)

---
{{< youtube x_tHB_M7a_g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
