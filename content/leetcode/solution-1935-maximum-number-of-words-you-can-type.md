
+++
authors = ["grid47"]
title = "Leetcode 1935: Maximum Number of Words You Can Type"
date = "2024-04-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1935: Maximum Number of Words You Can Type in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "FLMJwdw9Kqc"
youtube_upload_date="2021-07-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FLMJwdw9Kqc/maxresdefault.webp"
comments = true
+++



---
You are given a string 'text' consisting of words separated by a single space and a string 'brokenLetters' containing the broken keys on a malfunctioning keyboard. Return the number of words in 'text' that can be fully typed using the working keys.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings: 'text' containing words separated by spaces, and 'brokenLetters' containing distinct lowercase English letters.
- **Example:** `text = "apple orange", brokenLetters = "a"`
- **Constraints:**
	- 1 <= text.length <= 10^4
	- 0 <= brokenLetters.length <= 26
	- text consists of words separated by a single space without leading or trailing spaces.
	- Each word only consists of lowercase English letters.
	- brokenLetters consists of distinct lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of words in 'text' that can be fully typed using the working keys.
- **Example:** `1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the number of words in 'text' that do not contain any broken letters.

- Iterate over each word in 'text'.
- For each word, check if it contains any letter from 'brokenLetters'.
- If a word can be fully typed (contains no broken letters), increment the count.
{{< dots >}}
### Problem Assumptions ✅
- The text string is guaranteed to have words separated by single spaces.
- The brokenLetters string can be empty, which means all letters are usable.
{{< dots >}}
## Examples 🧩
- **Input:** `text = "apple orange", brokenLetters = "a"`  \
  **Explanation:** The word 'apple' cannot be typed because it contains the broken letter 'a', but 'orange' can be typed. Hence, the output is 1.

{{< dots >}}
## Approach 🚀
We will process each word and check if it contains any broken letter. If it doesn't, we increment the count.

### Initial Thoughts 💭
- We need to check each word in the text for broken letters.
- We can use a set to store the broken letters and efficiently check if any letter in a word is broken.
{{< dots >}}
### Edge Cases 🌐
- If 'brokenLetters' is empty, all words are typeable.
- The solution must handle the maximum length of the text efficiently.
- If a word is empty (which shouldn't occur as per constraints), it should be considered typeable.
- The solution must run in O(n) time where n is the length of the text string.
{{< dots >}}
## Code 💻
```cpp
int canBeTypedWords(string text, string brokenLetters) {
    bool broken[26] = {};
    for (auto ch : brokenLetters)
        broken[ch - 'a'] = true;
    int res = 0, cnt = 0;
    for (auto ch : text)
        if (ch == ' ') {
            res += cnt == 0;
            cnt = 0;
        }
        else
            cnt += broken[ch - 'a'];
    return res + (cnt == 0);
}
```

This function calculates how many words in a given text can be typed without using any of the broken letters. The broken letters are provided as a string `brokenLetters`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Header**
	```cpp
	int canBeTypedWords(string text, string brokenLetters) {
	```
	Defines the function `canBeTypedWords`, which takes two strings: `text` (the input text) and `brokenLetters` (the letters that cannot be used). It returns an integer representing how many words can be typed without using any broken letters.

2. **Array Initialization**
	```cpp
	    bool broken[26] = {};
	```
	Initializes a boolean array `broken[26]` to mark which letters are broken. The array is of size 26, corresponding to each letter of the alphabet.

3. **Loop Through Broken Letters**
	```cpp
	    for (auto ch : brokenLetters)
	```
	Loops through each character in the `brokenLetters` string to mark the broken letters in the `broken` array.

4. **Mark Broken Letters**
	```cpp
	        broken[ch - 'a'] = true;
	```
	Marks the respective index of the `broken` array as `true` for each broken letter in the `brokenLetters` string.

5. **Variable Initialization**
	```cpp
	    int res = 0, cnt = 0;
	```
	Initializes two variables: `res` (the result to count valid words) and `cnt` (the counter for broken letters in a word).

6. **Loop Through Text**
	```cpp
	    for (auto ch : text)
	```
	Starts a loop that iterates through each character in the input string `text`.

7. **Space Character Check**
	```cpp
	        if (ch == ' ') {
	```
	Checks if the current character is a space, indicating the end of a word.

8. **Valid Word Check**
	```cpp
	            res += cnt == 0;
	```
	If the word contains no broken letters (`cnt == 0`), increments the result `res`.

9. **Reset Counter**
	```cpp
	            cnt = 0;
	```
	Resets the `cnt` variable to 0 to start counting broken letters for the next word.

10. **Non-Space Character Check**
	```cpp
	        else
	```
	Handles the case when the current character is not a space (i.e., it's part of a word).

11. **Broken Letter Count**
	```cpp
	            cnt += broken[ch - 'a'];
	```
	Increments the `cnt` variable if the current character is a broken letter.

12. **Return Statement**
	```cpp
	    return res + (cnt == 0);
	```
	Returns the final count of valid words, adding 1 if the last word is valid (i.e., `cnt == 0`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of characters in the text, because we need to check each character against the broken letters.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k), where k is the number of distinct broken letters (at most 26).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/)

---
{{< youtube FLMJwdw9Kqc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
