
+++
authors = ["grid47"]
title = "Leetcode 1160: Find Words That Can Be Formed by Characters"
date = "2024-07-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1160: Find Words That Can Be Formed by Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "riRpJLMdrXs"
youtube_upload_date="2022-06-28"
youtube_thumbnail="https://i.ytimg.com/vi/riRpJLMdrXs/maxresdefault.jpg"
comments = true
+++



---
You are given an array of strings `words` and a string `chars`. A string is considered 'good' if it can be formed using characters from `chars` where each character can be used at most once. Your task is to return the sum of the lengths of all 'good' strings in `words`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings `words` and a string `chars`.
- **Example:** `Input: words = ["dog", "cat", "bat", "tree"], chars = "atagcbd"`
- **Constraints:**
	- 1 <= words.length <= 1000
	- 1 <= words[i].length, chars.length <= 100
	- words[i] and chars consist of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the sum of lengths of all good strings in the array `words`.
- **Example:** `Output: 6`
- **Constraints:**
	- The output should be the total length of all 'good' strings.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the total length of all good strings in `words` that can be formed using characters from `chars`.

- Create a frequency array for the characters in `chars`.
- For each word in `words`, check if it can be formed using characters from `chars`.
- If the word can be formed, add its length to the result.
{{< dots >}}
### Problem Assumptions ✅
- Each character in `chars` can be used at most once to form a word.
- The characters in `chars` and `words` are all lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ["dog", "cat", "bat", "tree"], chars = "atagcbd"`  \
  **Explanation:** The strings 'dog' and 'cat' can be formed using characters from 'atagcbd'. The total length is 3 + 3 = 6.

{{< dots >}}
## Approach 🚀
We will use a greedy approach to check each word in `words` and see if it can be formed using characters from `chars`. If so, we will sum the lengths of the valid words.

### Initial Thoughts 💭
- We need to check if each word can be formed by using each character in `chars` at most once.
- A simple way to solve this is by counting the frequency of each character in both `chars` and each word in `words`.
{{< dots >}}
### Edge Cases 🌐
- If `words` is empty, the result should be 0.
- Ensure the solution handles the upper limit of 1000 words efficiently.
- If `chars` contains fewer characters than required to form a word, that word should be excluded.
- Handle both small and large inputs within time limits.
{{< dots >}}
## Code 💻
```cpp
int countCharacters(vector<string>& words, string chars) {
    int cnt[26] = {}, res = 0;
    for (auto ch : chars) 
        ++cnt[ch - 'a'];
    for (auto &w : words) {
        int cnt1[26] = {}, match = true;
        for (auto ch : w)
        if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
            match = false;
            break;
        }
        if (match) 
            res += w.size();
    }
    return res;
}
```

This function `countCharacters` takes a list of words and a string of available characters (`chars`). It counts how many characters in each word can be constructed from the available characters in `chars`, using the characters only once. If a word can be constructed, its length is added to the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int countCharacters(vector<string>& words, string chars) {
	```
	Define the function `countCharacters` that takes a list of words and a string of available characters, then returns the sum of the lengths of the words that can be formed with the available characters.

2. **Variable Initialization**
	```cpp
	    int cnt[26] = {}, res = 0;
	```
	Initialize an array `cnt` of size 26 to count the occurrences of each character in the string `chars`, and a variable `res` to store the result (sum of lengths of valid words).

3. **Count Characters in Available String**
	```cpp
	    for (auto ch : chars) 
	```
	Iterate over each character in the string `chars` to populate the `cnt` array with the frequency of each character.

4. **Update Character Count**
	```cpp
	        ++cnt[ch - 'a'];
	```
	Increment the corresponding index in the `cnt` array for each character in `chars`. The index is determined by the character's ASCII value.

5. **Loop Through Words**
	```cpp
	    for (auto &w : words) {
	```
	Loop through each word in the `words` list to check if it can be formed using the characters in `chars`.

6. **Variable Initialization for Word**
	```cpp
	        int cnt1[26] = {}, match = true;
	```
	Initialize a temporary array `cnt1` to track the frequency of characters in the current word, and a boolean flag `match` to track if the word can be formed with the available characters.

7. **Loop Through Characters of Word**
	```cpp
	        for (auto ch : w)
	```
	Loop through each character in the current word `w`.

8. **Check Character Count**
	```cpp
	        if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
	```
	For each character in the word, increment its count in the `cnt1` array. If the count exceeds the available count in `cnt` (meaning the word cannot be formed), set `match` to false.

9. **Flag Word as Unmatchable**
	```cpp
	            match = false;
	```
	If the word cannot be formed due to insufficient characters, set the `match` flag to `false`.

10. **Break Loop on Mismatch**
	```cpp
	            break;
	```
	Exit the inner loop early if a mismatch is found, as the word cannot be formed.

11. **Add Word Length to Result**
	```cpp
	        if (match) 
	```
	If the word can be formed (i.e., `match` is `true`), add its length to the result `res`.

12. **Update Result**
	```cpp
	            res += w.size();
	```
	Add the length of the current valid word to the result `res`.

13. **Return Result**
	```cpp
	    return res;
	```
	Return the final result `res`, which is the total length of all words that can be formed from the characters in `chars`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

In the worst case, we check each word in `words` against all characters in `chars`, where `n` is the number of words and `m` is the length of the words.

### Space Complexity 💾
- **Best Case:** O(26)
- **Worst Case:** O(26)

The space complexity is constant since we only store a fixed number of frequencies for each character (26 letters).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/)

---
{{< youtube riRpJLMdrXs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
