
+++
authors = ["grid47"]
title = "Leetcode 125: Valid Palindrome"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 125: Valid Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/125.webp"
youtube = "jJXJ16kPFWg"
youtube_upload_date="2021-10-11"
youtube_thumbnail="https://i.ytimg.com/vi/jJXJ16kPFWg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/125.webp" 
    alt="A string of letters that glow in perfect symmetry, forming a calm and balanced palindrome."
    caption="Solution to LeetCode 125: Valid Palindrome Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
A string is considered a palindrome if, after converting all uppercase letters to lowercase and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include both letters and numbers. Given a string s, return true if it is a palindrome, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s that consists of printable ASCII characters.
- **Example:** `Input: s = 'Was it a car or a cat I saw?'`
- **Constraints:**
	- 1 <= s.length <= 2 * 10^5
	- s consists only of printable ASCII characters

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value, true if the string is a palindrome, otherwise false.
- **Example:** `Output: true`
- **Constraints:**
	- The string is considered a palindrome if it reads the same when ignoring non-alphanumeric characters and case differences.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the given string is a palindrome after ignoring non-alphanumeric characters and converting all letters to lowercase.

- Initialize two pointers, one at the start (i = 0) and one at the end (j = s.length() - 1).
- While the two pointers have not crossed each other, check the characters at both pointers.
- If the character at pointer i is not alphanumeric, move i forward.
- If the character at pointer j is not alphanumeric, move j backward.
- If the characters at i and j are equal (ignoring case), move both pointers inward.
- If any character comparison fails, return false.
- If the loop completes without finding any mismatches, return true.
{{< dots >}}
### Problem Assumptions ✅
- The string will always contain at least one character.
- We will only work with printable ASCII characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'Was it a car or a cat I saw?'`  \
  **Explanation:** After removing non-alphanumeric characters and converting to lowercase, the string becomes 'wasitacaroracatisaw', which is the same forward and backward, so the answer is true.

- **Input:** `Input: s = 'race a car'`  \
  **Explanation:** After removing non-alphanumeric characters and converting to lowercase, the string becomes 'raceacar', which is not the same forward and backward, so the answer is false.

- **Input:** `Input: s = ' '`  \
  **Explanation:** After removing non-alphanumeric characters, the string becomes an empty string, which is considered a palindrome, so the answer is true.

{{< dots >}}
## Approach 🚀
We use two pointers to compare the characters of the string from both ends, ignoring non-alphanumeric characters and case differences. The process continues until we check all characters or find a mismatch.

### Initial Thoughts 💭
- Using two pointers is an efficient way to check for palindrome properties.
- We need to account for both case insensitivity and ignoring non-alphanumeric characters.
{{< dots >}}
### Edge Cases 🌐
- The input can be an empty string, which is considered a palindrome.
- The solution must handle inputs with up to 200,000 characters efficiently.
- Strings with only non-alphanumeric characters should be considered palindromes as they become empty after removal.
- Ensure that the input string is within the specified length.
{{< dots >}}
## Code 💻
```cpp

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i <= j) {
        if(!isalnum(s[i])) {
            i++; continue;
        }
        if(!isalnum(s[j])) {
            j--; continue;
        }
        if(tolower(s[i]) == tolower(s[j])) {
            i++, j--;
        } else return false;
    }
    return true;
}
```

This function checks if a given string is a palindrome, ignoring non-alphanumeric characters and case sensitivity.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isPalindrome(string s) {
	```
	Declare a function to determine if the input string is a valid palindrome.

2. **Variable Initialization**
	```cpp
	    int i = 0, j = s.size() - 1;
	```
	Initialize two pointers: `i` at the start of the string and `j` at the end.

3. **Loop Iteration**
	```cpp
	    while(i <= j) {
	```
	Start a loop to check characters from both ends of the string.

4. **Conditional Check**
	```cpp
	        if(!isalnum(s[i])) {
	```
	Check if the current character at the start pointer is non-alphanumeric.

5. **Pointer Update**
	```cpp
	            i++; continue;
	```
	Move the start pointer forward and skip the current character if it's non-alphanumeric.

6. **Conditional Check**
	```cpp
	        if(!isalnum(s[j])) {
	```
	Check if the current character at the end pointer is non-alphanumeric.

7. **Pointer Update**
	```cpp
	            j--; continue;
	```
	Move the end pointer backward and skip the current character if it's non-alphanumeric.

8. **Comparison**
	```cpp
	        if(tolower(s[i]) == tolower(s[j])) {
	```
	Compare the lowercase versions of the characters at both pointers.

9. **Pointer Update**
	```cpp
	            i++, j--;
	```
	Move both pointers closer to the center if the characters match.

10. **Return Statement**
	```cpp
	        } else return false;
	```
	Return false if the characters do not match.

11. **Return Statement**
	```cpp
	    return true;
	```
	Return true if all character pairs matched, confirming the string is a palindrome.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each character of the string at most once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only store a few variables (pointers) regardless of the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-palindrome/description/)

---
{{< youtube jJXJ16kPFWg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
