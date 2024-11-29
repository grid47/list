
+++
authors = ["grid47"]
title = "Leetcode 2108: Find First Palindromic String in the Array"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2108: Find First Palindromic String in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "4JA5MW772N0"
youtube_upload_date="2024-02-13"
youtube_thumbnail="https://i.ytimg.com/vi/4JA5MW772N0/maxresdefault.jpg"
comments = true
+++



---
Given a list of words, return the first word that is a palindrome. A palindrome is a word that reads the same forwards and backwards. If no palindromic word is found, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of strings, words, where each string consists of lowercase English letters.
- **Example:** `words = ["hello", "level", "world"]`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 100
	- words[i] consists only of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the first palindromic word from the input array. If no such word exists, return an empty string.
- **Example:** `For words = ["hello", "level", "world"], the output should be "level".`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the first word in the array that is palindromic by checking if each word is equal to its reverse.

- Iterate through each word in the array.
- For each word, check if it reads the same forward and backward.
- Return the first word that satisfies the condition. If no word satisfies the condition, return an empty string.
{{< dots >}}
### Problem Assumptions ✅
- All strings are lowercase English letters.
- The solution must identify palindromes efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: words = ["hello", "level", "world"]`  \
  **Explanation:** The first palindromic word is "level", as it is the first word in the list that reads the same forward and backward.

- **Input:** `Example 2: words = ["apple", "banana", "radar"]`  \
  **Explanation:** The first palindromic word is "radar".

- **Input:** `Example 3: words = ["dog", "cat"]`  \
  **Explanation:** There are no palindromic words in the array, so the output is an empty string.

{{< dots >}}
## Approach 🚀
The problem requires iterating over the list of words and checking if each word is a palindrome. A palindrome is a word that reads the same backward as forward.

### Initial Thoughts 💭
- We can check if a word is a palindrome by comparing the word to its reverse.
- Since the constraints are small (up to 100 words, each with up to 100 characters), the solution can use a straightforward approach of checking each word.
- The solution is simple and works in O(n*m) time where n is the number of words and m is the average length of the words.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the function should return an empty string.
- If the input contains many long strings (up to the maximum constraints), the function should still operate efficiently.
- A single-character word is always a palindrome.
- The solution should handle up to 100 words, each with up to 100 characters.
{{< dots >}}
## Code 💻
```cpp
string firstPalindrome(vector<string>& words) {
    for (auto &w : words)
        if (w == string(rbegin(w), rend(w)))
            return w;
    return "";
}
```

This function checks if a given list of words contains a palindrome and returns the first one. If no palindrome is found, it returns an empty string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string firstPalindrome(vector<string>& words) {
	```
	Define the function `firstPalindrome` that takes a vector of strings as an argument.

2. **Loop Start**
	```cpp
	    for (auto &w : words)
	```
	Start a loop to iterate through each word in the `words` vector.

3. **Condition Check**
	```cpp
	        if (w == string(rbegin(w), rend(w)))
	```
	Check if the current word `w` is equal to its reverse (using reverse iterators).

4. **Return Statement**
	```cpp
	            return w;
	```
	If a palindrome is found, return the current word `w`.

5. **Return Statement**
	```cpp
	    return "";
	```
	If no palindrome is found after checking all words, return an empty string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n*m)
- **Worst Case:** O(n*m)

The time complexity is O(n*m) where n is the number of words and m is the average length of the words.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the solution only requires a few additional variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/)

---
{{< youtube 4JA5MW772N0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
