
+++
authors = ["grid47"]
title = "Leetcode 1754: Largest Merge Of Two Strings"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1754: Largest Merge Of Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YB-A6OUj98o"
youtube_upload_date="2021-02-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/YB-A6OUj98o/maxresdefault.webp"
comments = true
+++



---
You are given two strings, `word1` and `word2`. You need to construct a string `merge` by choosing characters from both strings. At each step, you can either append the first character of `word1` to `merge` (if `word1` is non-empty) or append the first character of `word2` to `merge` (if `word2` is non-empty). The goal is to form the lexicographically largest string possible from these choices.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings, `word1` and `word2`, both consisting of lowercase English letters.
- **Example:** `Input: word1 = 'abcde', word2 = 'acd'`
- **Constraints:**
	- 1 <= word1.length, word2.length <= 3000
	- word1 and word2 consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically largest merge string you can construct.
- **Example:** `Output: 'abcdeacd'`
- **Constraints:**
	- The resulting string is guaranteed to be lexicographically the largest possible merge.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the lexicographically largest merge string, we need to make the optimal choice at each step of picking from `word1` or `word2`.

- 1. Compare the first characters of `word1` and `word2`.
- 2. If the character in `word1` is larger, append it to `merge`. Otherwise, append the character from `word2`.
- 3. If one string becomes empty, append the remaining characters from the other string to `merge`.
{{< dots >}}
### Problem Assumptions ✅
- Both `word1` and `word2` are non-empty strings consisting of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: word1 = 'abcd', word2 = 'acef'`  \
  **Explanation:** At each step, we compare the first characters of `word1` and `word2`. The largest lexicographical choice is appended to `merge`. The result is 'abcdeaf'.

- **Input:** `Input: word1 = 'abc', word2 = 'aaa'`  \
  **Explanation:** Here, we always take from `word1` as its characters are larger than those in `word2`, resulting in 'abcaaa'.

{{< dots >}}
## Approach 🚀
The approach involves comparing the first characters of both strings and greedily choosing the lexicographically larger one, ensuring the largest possible merge string.

### Initial Thoughts 💭
- We can use a greedy approach to always select the larger character between the two strings at each step.
- The solution is based on the principle of comparing characters in a lexicographical manner.
{{< dots >}}
### Edge Cases 🌐
- If either `word1` or `word2` is empty, simply return the other string.
- The solution should handle cases where `word1` and `word2` are close to 3000 characters in length.
- If both strings are identical, the result is the string concatenated to itself.
- The solution should perform efficiently with the maximum input size.
{{< dots >}}
## Code 💻
```cpp
string largestMerge(string w1, string w2) {
    if (w1 == "" || w2 == "")
        return w1 + w2;
    else if (w1 < w2)
        return w2[0] + largestMerge(w1, w2.substr(1));
    else return w1[0] + largestMerge(w1.substr(1), w2);
}
```

The function generates the lexicographically largest merge of two strings by recursively comparing and selecting characters from the inputs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string largestMerge(string w1, string w2) {
	```
	Declares the recursive function to create the largest lexicographical merge of two strings.

2. **Base Case**
	```cpp
	    if (w1 == "" || w2 == "")
	```
	Checks if either string is empty, which serves as the base case for recursion.

3. **Return Statement**
	```cpp
	        return w1 + w2;
	```
	If one string is empty, appends the other string and ends the recursion.

4. **Conditional Check**
	```cpp
	    else if (w1 < w2)
	```
	Checks if the first string is lexicographically smaller than the second string.

5. **Recursive Call**
	```cpp
	        return w2[0] + largestMerge(w1, w2.substr(1));
	```
	Appends the first character of `w2` and makes a recursive call with the remaining part of `w2`.

6. **Recursive Call**
	```cpp
	    else return w1[0] + largestMerge(w1.substr(1), w2);
	```
	Appends the first character of `w1` and makes a recursive call with the remaining part of `w1`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where n is the length of `word1` and m is the length of `word2`.
- **Average Case:** O(n + m), as each character from both strings is processed once.
- **Worst Case:** O(n + m), where n and m are the lengths of the strings.

The time complexity is linear in the sum of the lengths of the two strings, as each character is processed once.

### Space Complexity 💾
- **Best Case:** O(n + m), as the space used is proportional to the length of the result string.
- **Worst Case:** O(n + m), where n and m are the lengths of `word1` and `word2`.

The space complexity is linear, as the merge string needs to store all the characters from both input strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-merge-of-two-strings/description/)

---
{{< youtube YB-A6OUj98o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
