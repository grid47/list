
+++
authors = ["grid47"]
title = "Leetcode 5: Longest Palindromic Substring"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 5: Longest Palindromic Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/5.webp"
youtube = "XYQecbcd6_c"
youtube_upload_date="2020-08-10"
youtube_thumbnail="https://i.ytimg.com/vi/XYQecbcd6_c/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/5.webp" 
    alt="A mirror reflecting a glowing word, with symmetry and balance radiating outward."
    caption="Solution to LeetCode 5: Longest Palindromic Substring Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string, find and return the longest palindromic substring in it. A palindrome is a word that reads the same forward and backward. The substring must be contiguous within the original string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string 's'.
- **Example:** `s = "racecar"`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists of only digits and English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the longest palindromic substring from the input string.
- **Example:** `"aceca"`
- **Constraints:**
	- The returned substring must be the longest palindromic substring found.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently find the longest substring that is a palindrome.

- Iterate over each character in the string as the center of the potential palindrome.
- Expand outwards from the center for both odd and even length palindromes.
- Keep track of the longest palindrome found during this process.
{{< dots >}}
### Problem Assumptions ✅
- The input string is valid and contains at least one character.
- The palindrome may be a single character if no longer palindromes are found.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "bananas"`  \
  **Explanation:** The longest palindromic substring is "anana" with a length of 5.

- **Input:** `s = "civic"`  \
  **Explanation:** The entire string "civic" is a palindrome, and it is the longest one.

- **Input:** `s = "hello"`  \
  **Explanation:** The longest palindromic substring is "e" with a length of 1.

{{< dots >}}
## Approach 🚀
A center-expansion approach can be used to identify palindromes around each character in the string.

### Initial Thoughts 💭
- We can treat each character as a potential center for a palindrome.
- Palindromes can either have odd or even lengths, so we must check both possibilities.
- Instead of checking all possible substrings, we can expand from the center, which reduces the number of comparisons needed.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, return an empty string.
- The solution should efficiently handle strings up to the length of 1000.
- Strings with no palindrome longer than 1 character should return a single character.
- Strings that are themselves palindromes should return the entire string.
- The string only contains printable characters.
{{< dots >}}
## Code 💻
```cpp
int lo, len;
string longestPalindrome(string s) {
    len = 0;
    
    for(int i = 0; i < s.size(); i++) {
        pal(s, i, i);
        pal(s, i, i + 1);
    }
    return s.substr(lo, len);
}

void pal(string &s, int i, int j) {
    while(i >= 0 && j <= s.size() && s[i] == s[j]) {
        i--;
        j++;
    }
    if(len < j - i - 1) {
        lo = i + 1;
        len = j - i - 1;
    }
}
```

This code implements a function to find the longest palindromic substring in a given string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int lo, len;
	```
	Declare and initialize variables `lo` and `len` to store the starting index and length of the longest palindrome found so far.

2. **Function Declaration**
	```cpp
	string longestPalindrome(string s) {
	```
	Declare the `longestPalindrome` function, which takes a string `s` as input and returns the longest palindromic substring.

3. **Initialization**
	```cpp
	    len = 0;
	```
	Initialize `len` to 0, as we haven't found a palindrome yet.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Iterate over each character in the string `s`.

5. **Function Call**
	```cpp
	        pal(s, i, i);
	```
	Call the `pal` function to check for odd-length palindromes centered at index `i`.

6. **Function Call**
	```cpp
	        pal(s, i, i + 1);
	```
	Call the `pal` function to check for even-length palindromes centered between indices `i` and `i+1`.

7. **Return Value**
	```cpp
	    return s.substr(lo, len);
	```
	Return the longest palindrome substring found.

8. **Function Declaration**
	```cpp
	void pal(string &s, int i, int j) {
	```
	Declare the `pal` function to check for palindromes around a given center.

9. **Loop Iteration**
	```cpp
	    while(i >= 0 && j <= s.size() && s[i] == s[j]) {
	```
	Expand the palindrome as long as the characters at indices `i` and `j` match.

10. **Index Update**
	```cpp
	        i--;
	```
	Decrement `i` to move to the previous character.

11. **Index Update**
	```cpp
	        j++;
	```
	Increment `j` to move to the next character.

12. **Conditional Check**
	```cpp
	    if(len < j - i - 1) {
	```
	Check if the current palindrome is longer than the previously found longest palindrome.

13. **Variable Assignment**
	```cpp
	        lo = i + 1;
	```
	Update `lo` to store the starting index of the new longest palindrome.

14. **Variable Assignment**
	```cpp
	        len = j - i - 1;
	```
	Update `len` to store the length of the new longest palindrome.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we may need to expand around each character in the string, which results in a time complexity of O(n^2).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of extra space for variables like the longest palindrome's start position and length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-palindromic-substring/description/)

---
{{< youtube XYQecbcd6_c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
