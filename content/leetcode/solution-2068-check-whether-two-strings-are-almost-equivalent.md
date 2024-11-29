
+++
authors = ["grid47"]
title = "Leetcode 2068: Check Whether Two Strings are Almost Equivalent"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2068: Check Whether Two Strings are Almost Equivalent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "l_KAgx9c8Mc"
youtube_upload_date="2021-11-13"
youtube_thumbnail="https://i.ytimg.com/vi/l_KAgx9c8Mc/maxresdefault.jpg"
comments = true
+++



---
You are given two strings, `word1` and `word2`, each of length `n`. The two strings are considered almost equivalent if the difference in frequency of each letter between `word1` and `word2` is at most 3. Return true if they are almost equivalent, or false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two strings of equal length `n` are provided as input. Each string consists of lowercase English letters.
- **Example:** `word1 = "abcd", word2 = "abdc"`
- **Constraints:**
	- 1 <= n <= 100
	- Both word1 and word2 consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the two strings are almost equivalent, otherwise return `false`.
- **Example:** `true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if the absolute frequency difference for each letter in the two strings is at most 3.

- Count the frequency of each letter in both strings.
- Calculate the absolute difference of the frequencies for each letter.
- If any difference exceeds 3, return false; otherwise, return true.
{{< dots >}}
### Problem Assumptions ✅
- Both input strings are of equal length.
{{< dots >}}
## Examples 🧩
- **Input:** `word1 = "abcd", word2 = "abdc"`  \
  **Explanation:** Both strings have identical characters, and the frequency difference for each letter is 0, which is within the allowed limit.

- **Input:** `word1 = "zzzz", word2 = "aaabb"`  \
  **Explanation:** The difference in the frequency of 'z' is 4, which exceeds the allowed limit of 3.

{{< dots >}}
## Approach 🚀
Count the frequency of each character in both strings, compute the difference in their frequencies, and check if any difference exceeds 3.

### Initial Thoughts 💭
- Both strings should be of the same length.
- We need to compare the frequencies of each character.
- An efficient solution would involve counting the frequencies of characters and comparing the differences for each letter.
{{< dots >}}
### Edge Cases 🌐
- If either string is empty, the function should return true.
- If the strings are at their maximum length (100), ensure that the solution works within the time constraints.
- If the strings are identical, the function should return true.
- Both strings must be the same length.
{{< dots >}}
## Code 💻
```cpp
bool checkAlmostEquivalent(string s, string t) {
    int cnt[26] = {};
    for (char c : s) cnt[c - 'a']++;
    for (char c : t) cnt[c - 'a']--;
    for (int i = 0; i < 26; ++i) {
        if (abs(cnt[i]) > 3) return false;
    }
    return true;
}
```

This function checks whether two input strings are almost equivalent. It compares the frequency of characters in both strings, and if the absolute difference in the frequency of any character exceeds 3, the function returns false.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkAlmostEquivalent(string s, string t) {
	```
	This line defines the function `checkAlmostEquivalent` that takes two strings as input and returns a boolean value.

2. **Array Initialization**
	```cpp
	    int cnt[26] = {};
	```
	An array `cnt` of size 26 is initialized to store the frequency of each letter in the input strings. The array is initialized with zero values.

3. **Count Characters in s**
	```cpp
	    for (char c : s) cnt[c - 'a']++;
	```
	This loop iterates through each character in string `s` and increments the corresponding index in the `cnt` array based on the character's ASCII value.

4. **Count Characters in t**
	```cpp
	    for (char c : t) cnt[c - 'a']--;
	```
	This loop iterates through each character in string `t` and decrements the corresponding index in the `cnt` array.

5. **Loop Over All Characters**
	```cpp
	    for (int i = 0; i < 26; ++i) {
	```
	This loop checks all indices of the `cnt` array (corresponding to each letter of the alphabet).

6. **Check Difference Exceeds 3**
	```cpp
	        if (abs(cnt[i]) > 3) return false;
	```
	If the absolute value of the count at any index in the `cnt` array exceeds 3, the function returns `false`, indicating the strings are not almost equivalent.

7. **Return True**
	```cpp
	    return true;
	```
	If no character's frequency difference exceeds 3, the function returns `true`, indicating the strings are almost equivalent.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we iterate over each string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We use constant space, as we only need an array of size 26 to store character frequencies.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/)

---
{{< youtube l_KAgx9c8Mc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
