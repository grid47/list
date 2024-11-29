
+++
authors = ["grid47"]
title = "Leetcode 1616: Split Two Strings to Make Palindrome"
date = "2024-05-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1616: Split Two Strings to Make Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "s0UlCe7icxs"
youtube_upload_date="2020-10-11"
youtube_thumbnail="https://i.ytimg.com/vi/s0UlCe7icxs/maxresdefault.jpg"
comments = true
+++



---
You are given two strings, a and b, of the same length. You need to split both strings at the same index into two parts: one prefix and one suffix for each string. Then, check if concatenating one prefix from one string with the suffix of the other string forms a palindrome. Specifically, you need to check if either `aprefix + bsuffix` or `bprefix + asuffix` forms a palindrome.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, a and b, both of the same length.
- **Example:** `a = 'abc', b = 'cba'`
- **Constraints:**
	- 1 <= a.length, b.length <= 10^5
	- a.length == b.length
	- a and b consist of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to form a palindrome string by concatenating either `aprefix + bsuffix` or `bprefix + asuffix`. Otherwise, return false.
- **Example:** `For a = 'abc' and b = 'cba', the output would be true.`
- **Constraints:**
	- The output should be a boolean value, true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if it is possible to form a palindrome by choosing a split index for both strings and combining the corresponding parts.

- For each possible split point, split both strings into two parts: a prefix and a suffix.
- Check if either concatenation of `aprefix + bsuffix` or `bprefix + asuffix` forms a palindrome.
- Return true if either concatenation forms a palindrome, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- The two input strings are guaranteed to have the same length.
- You can split the strings at any valid index.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = 'abc', b = 'cba'`  \
  **Explanation:** In this case, we can split both strings at index 1: aprefix = 'a', asuffix = 'bc', bprefix = 'c', and bsuffix = 'ba'. Concatenating `aprefix + bsuffix = 'a' + 'ba' = 'aba'`, which is a palindrome.

- **Input:** `Input: a = 'ab', b = 'ba'`  \
  **Explanation:** Here, splitting the strings at index 1: aprefix = 'a', asuffix = 'b', bprefix = 'b', and bsuffix = 'a'. Concatenating `aprefix + bsuffix = 'a' + 'a' = 'aa'`, which is a palindrome.

- **Input:** `Input: a = 'abc', b = 'def'`  \
  **Explanation:** In this case, no matter how we split the strings, no combination of prefix and suffix will form a palindrome.

{{< dots >}}
## Approach 🚀
The approach involves iterating through all possible split points, checking the formed concatenations for palindrome properties.

### Initial Thoughts 💭
- We need to check both concatenations (`aprefix + bsuffix` and `bprefix + asuffix`) for each possible split.
- If a combination forms a palindrome, we return true; otherwise, we return false.
{{< dots >}}
### Edge Cases 🌐
- If either string is empty, the result should be false as there are no valid splits.
- For large strings, the approach needs to be efficient enough to handle up to 100,000 characters.
- Strings that are already palindromes can be split trivially.
- The algorithm needs to check possible splits efficiently.
{{< dots >}}
## Code 💻
```cpp
bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
}

bool check(string a, string b) {
    int i = 0, j = a.size() -1;
    while(i < j && a[i] == b[j])
    i++, j--;
    return isPalindrom(a, i, j) || isPalindrom(b, i, j);
}

bool isPalindrom(string a, int i , int j) {
    while(i < j && a[i] == a[j])
    i++, j--;
    return i >= j;
}
```

This solution checks if it's possible to form a palindrome by rearranging two given strings, `a` and `b`. The core logic uses helper functions to check if one string can match the reverse of the other, and to verify if a substring is a palindrome.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkPalindromeFormation(string a, string b) {
	```
	Define the function `checkPalindromeFormation` that takes two strings `a` and `b` and returns true if a palindrome can be formed by rearranging them.

2. **Function Logic**
	```cpp
	    return check(a, b) || check(b, a);
	```
	Call the `check` function for both possible combinations of the strings `a` and `b`. If either combination can form a palindrome, return true.

3. **Helper Function Definition**
	```cpp
	bool check(string a, string b) {
	```
	Define the helper function `check` that will determine if the strings `a` and `b` can form a palindrome by checking character matches from both ends.

4. **Variable Initialization**
	```cpp
	    int i = 0, j = a.size() -1;
	```
	Initialize two pointers `i` at the start of string `a` and `j` at the end to check for palindrome conditions.

5. **While Loop**
	```cpp
	    while(i < j && a[i] == b[j])
	```
	Use a while loop to compare characters of the two strings from both ends (`a[i]` with `b[j]`). Continue as long as they match.

6. **Pointer Adjustment**
	```cpp
	    i++, j--;
	```
	If characters match, move the pointers towards the center (`i++` and `j--`) to check the next pair of characters.

7. **Return Statement**
	```cpp
	    return isPalindrom(a, i, j) || isPalindrom(b, i, j);
	```
	Return the result of checking if either string from the updated pointers forms a palindrome using the helper function `isPalindrom`.

8. **Palindrome Check Function Definition**
	```cpp
	bool isPalindrom(string a, int i , int j) {
	```
	Define the function `isPalindrom` that checks whether the substring from index `i` to `j` in string `a` is a palindrome.

9. **While Loop**
	```cpp
	    while(i < j && a[i] == a[j])
	```
	Use a while loop to compare characters from both ends of the substring in string `a` (`a[i]` with `a[j]`). Continue as long as they match.

10. **Pointer Adjustment**
	```cpp
	    i++, j--;
	```
	If characters match, move the pointers towards the center (`i++` and `j--`) to check the next pair of characters.

11. **Return Statement**
	```cpp
	    return i >= j;
	```
	If the pointers have crossed or met, it means the substring is a palindrome. Return true, else false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The worst case occurs when we check palindrome properties at each split for strings of length n.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case for storing prefixes and suffixes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-two-strings-to-make-palindrome/description/)

---
{{< youtube s0UlCe7icxs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
