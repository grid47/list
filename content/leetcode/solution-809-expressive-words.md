
+++
authors = ["grid47"]
title = "Leetcode 809: Expressive Words"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 809: Expressive Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/809.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/809.webp" 
    alt="A string of words where expressive words glow softly, highlighting their expressive nature."
    caption="Solution to LeetCode 809: Expressive Words Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string s and a list of query words. Each word in the query list is said to be 'stretchy' if it can be transformed into string s by extending groups of adjacent letters. You can extend a group of letters (e.g., 'a', 'bb', 'ccc') as long as its length is at least 3. For example, if s = 'heeellooo', you could extend 'e' and 'o' to make 'hello' stretchy. Return the number of query strings that can be stretched to become s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with two inputs: a string s and an array of words. Each word in the array will be checked to see if it can be transformed into s by the described operations.
- **Example:** `Input: s = 'aaaabbbb', words = ['ab', 'aaaabbbb', 'aaabbbbb']`
- **Constraints:**
	- 1 <= s.length, words.length <= 100
	- 1 <= words[i].length <= 100
	- s and words[i] consist of lowercase letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing how many words in the query list can be transformed into string s through the described operations.
- **Example:** `Output: 2`
- **Constraints:**
	- The result is an integer count.

{{< dots >}}
### Core Logic 🔍
**Goal:** The task is to determine if each word in the query list can be transformed into string s by extending adjacent letter groups according to the given rules.

- For each word in the query list, iterate through its characters and compare them to the corresponding characters in s.
- Check if groups of adjacent characters in both the word and s can be extended by applying the transformation rules.
- Count how many words can be transformed into s.
{{< dots >}}
### Problem Assumptions ✅
- Words in the query list are non-empty and consist only of lowercase letters.
- The transformation is only possible if groups of characters can be extended by at least 3 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'heeellooo', words = ['hello', 'hi', 'helo']`  \
  **Explanation:** The word 'hello' can be stretched by extending 'e' to 'ee' and 'o' to 'ooo' to match s. The word 'hi' cannot be stretched to match s because it doesn't contain any repeated groups. The word 'helo' cannot match s because the group 'll' is not large enough to be extended.

{{< dots >}}
## Approach 🚀
The approach involves checking if each word can be transformed into string s by matching groups of adjacent characters and applying the extension operation when possible.

### Initial Thoughts 💭
- We need to check if a word can match s by extending certain groups.
- This requires comparing groups of characters and verifying if they can be expanded as per the given transformation rules.
- We can use a helper function to check if a word is stretchy by comparing character groups.
{{< dots >}}
### Edge Cases 🌐
- If s is an empty string, no words can be stretched to match it.
- Handle cases where the length of s or the words in the query list is large, ensuring the algorithm runs efficiently.
- If a word contains no repeated characters, it can't be stretched.
- The algorithm must work efficiently even when s and words have the maximum allowed length.
{{< dots >}}
## Code 💻
```cpp
int expressiveWords(string s, vector<string>& words) {
    int res = 0;
    for(auto &w : words)
        if(check(s, w))
            res++;
    return res;
}

bool check(string s, string w) {
    int n = s.size(), m = w.size(), j = 0;
    for(int i = 0; i < n; i++)
        if(j < m && s[i] == w[j]) j++;
        else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
        else if (i > 0 && i < n - 1 && s[i -1] == s[i] && s[i] == s[i +1]);
        else return false;
    return j == m;
}

```

This code defines a function `expressiveWords` which counts how many words from a list can be formed by expanding characters from a given string `s` based on certain conditions, and a helper function `check` that verifies if a word can be formed using such expansions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	int expressiveWords(string s, vector<string>& words) {
	```
	This line defines the function `expressiveWords` which takes a string `s` and a vector of strings `words` as parameters.

2. **Variable Declaration**
	```cpp
	    int res = 0;
	```
	This line initializes an integer `res` to 0, which will hold the count of words that can be formed by expanding characters of `s`.

3. **Loop**
	```cpp
	    for(auto &w : words)
	```
	This line starts a loop that iterates through each word `w` in the `words` vector.

4. **Conditional Check**
	```cpp
	        if(check(s, w))
	```
	This line calls the `check` function to determine if the word `w` can be formed by expanding characters of string `s`.

5. **Increment Counter**
	```cpp
	            res++;
	```
	If the `check` function returns true, this line increments the result counter `res`.

6. **Return Statement**
	```cpp
	    return res;
	```
	This line returns the final count of words that can be formed by expanding characters of string `s`.

7. **Function Definition**
	```cpp
	bool check(string s, string w) {
	```
	This line defines the helper function `check` which takes two strings `s` and `w` as parameters and checks if `w` can be constructed from `s`.

8. **Variable Declaration**
	```cpp
	    int n = s.size(), m = w.size(), j = 0;
	```
	This line initializes the lengths of strings `s` and `w` as `n` and `m`, and a counter `j` to track progress through `w`.

9. **Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This line starts a loop that iterates over each character of string `s`.

10. **Character Matching**
	```cpp
	        if(j < m && s[i] == w[j]) j++;
	```
	If the current character in `s` matches the current character in `w`, `j` is incremented to check the next character in `w`.

11. **Character Expansion Check**
	```cpp
	        else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
	```
	This checks if there is a valid expansion of characters in `s`, where three consecutive characters in `s` are the same.

12. **Character Expansion Check**
	```cpp
	        else if (i > 0 && i < n - 1 && s[i -1] == s[i] && s[i] == s[i +1]);
	```
	This checks for another valid expansion, where two adjacent characters in `s` are the same and are surrounded by the same character.

13. **Failure Condition**
	```cpp
	        else return false;
	```
	If none of the previous conditions hold, this returns false, indicating that `w` cannot be formed by expanding characters of `s`.

14. **Final Check**
	```cpp
	    return j == m;
	```
	Finally, the function returns true if `j` has reached the length of `w`, indicating that all characters of `w` have been matched in `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of s, for simple cases where the word matches immediately.
- **Average Case:** O(m * n) where m is the number of words in the query list and n is the length of s, since each word is checked individually.
- **Worst Case:** O(m * n), where m is the number of words in the query list and n is the length of the longest word.

The time complexity is mainly determined by checking each word in the query list against s.

### Space Complexity 💾
- **Best Case:** O(1), if no extra space is required.
- **Worst Case:** O(m) where m is the number of words in the query list, since we store each word temporarily during processing.

The space complexity depends on the number of words being processed at once.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/expressive-words/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
