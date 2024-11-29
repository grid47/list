
+++
authors = ["grid47"]
title = "Leetcode 1002: Find Common Characters"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1002: Find Common Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QEESBA2Q_88"
youtube_upload_date="2024-06-05"
youtube_thumbnail="https://i.ytimg.com/vi/QEESBA2Q_88/maxresdefault.jpg"
comments = true
+++



---
Given a list of words, return an array of characters that appear in all words. The output should include duplicates of characters as they appear in each word, and the answer can be returned in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of words where each word is a string of lowercase English letters.
- **Example:** `words = ['apple', 'grape', 'maple']`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 100
	- words[i] consists of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of characters that appear in all words of the list. The characters should appear as many times as they appear in each word, and can be in any order.
- **Example:** `['p', 'e', 'l']`
- **Constraints:**
	- The output array will only contain lowercase English letters.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the characters that appear in all words, taking into account their frequency in each word.

- Create a frequency array to track the minimum number of occurrences of each character across all words.
- Iterate through each word, updating the frequency array to reflect the minimum occurrences of each character.
- Generate the result by adding characters to the output list according to their minimum frequency.
{{< dots >}}
### Problem Assumptions ✅
- The input list contains valid words with lowercase English letters only.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ['hello', 'cello', 'mellow']`  \
  **Explanation:** The common characters between all words are 'e', 'l', and 'l', which appear at least once in each word.

- **Input:** `Input: words = ['blue', 'clue', 'glue']`  \
  **Explanation:** The common characters are 'l', 'u', and 'e', appearing at least once in each word.

{{< dots >}}
## Approach 🚀
The problem can be solved by using frequency counts for each character in every word and comparing them to find the minimum occurrences for each character across all words.

### Initial Thoughts 💭
- We need to track the occurrences of each character in every word and update the result accordingly.
- This problem can be tackled by using a frequency array and iterating over the words to find common characters.
{{< dots >}}
### Edge Cases 🌐
- If the input is an empty list, return an empty result array.
- The solution should efficiently handle the maximum input size with up to 100 words and 100 characters per word.
- If there are no common characters between the words, return an empty result.
- The solution should avoid unnecessary complexity and optimize for large inputs.
{{< dots >}}
## Code 💻
```cpp
vector<string> commonChars(vector<string>& words) {
    vector<int> frq(26, INT_MAX);
    for(string& s: words) {
        vector<int> cnt(26, 0);
        for(char x: s) cnt[x - 'a']++;

        for(int i = 0; i < 26; i++)
        frq[i] = min(frq[i], cnt[i]);
    }

    vector<string> res;
    for(int i = 0; i < 26; i++)
    for(int j = 0; j < frq[i]; j++)
        res.push_back(string(1, 'a' + i));

    return res;
}
```

This function finds common characters among multiple strings in a list. It counts the occurrences of each character in every word and updates the frequency array to keep track of the minimum count of each character across all strings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> commonChars(vector<string>& words) {
	```
	Defines the function `commonChars` which takes a vector of strings and returns a vector of strings containing the common characters among them.

2. **Frequency Initialization**
	```cpp
	    vector<int> frq(26, INT_MAX);
	```
	Initializes a frequency vector `frq` of size 26, where each element represents the maximum possible count of each character ('a' to 'z'). The frequency is set to `INT_MAX` to ensure that the first comparison will set the correct minimum frequency.

3. **Loop Over Words**
	```cpp
	    for(string& s: words) {
	```
	Iterates over each word in the input list `words`.

4. **Count Frequency in Word**
	```cpp
	        vector<int> cnt(26, 0);
	```
	For each word, a `cnt` vector is initialized to count the occurrences of each character in the word.

5. **Character Counting**
	```cpp
	        for(char x: s) cnt[x - 'a']++;
	```
	Iterates over each character in the current word and updates the corresponding count in the `cnt` vector based on the character's position in the alphabet.

6. **Frequency Update**
	```cpp
	        for(int i = 0; i < 26; i++)
	```
	Loops through all 26 characters of the alphabet.

7. **Min Frequency Update**
	```cpp
	        frq[i] = min(frq[i], cnt[i]);
	```
	For each character, updates the frequency vector `frq` by taking the minimum count of the character between the current word and the previous words.

8. **Result Initialization**
	```cpp
	    vector<string> res;
	```
	Initializes an empty vector `res` to store the result, which will be the common characters.

9. **Loop Over Characters**
	```cpp
	    for(int i = 0; i < 26; i++)
	```
	Iterates over each character (from 'a' to 'z').

10. **Add Common Characters**
	```cpp
	    for(int j = 0; j < frq[i]; j++)
	```
	For each character, adds the character to the result vector `res` based on its minimum frequency (how many times it appears in all the words).

11. **Push Character to Result**
	```cpp
	        res.push_back(string(1, 'a' + i));
	```
	Creates a string from the character (using its ASCII value) and adds it to the result vector `res`.

12. **Result Return**
	```cpp
	    return res;
	```
	Returns the vector `res`, which contains all the common characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

The time complexity is O(n * m), where n is the number of words and m is the maximum length of a word, since we process each character in each word.

### Space Complexity 💾
- **Best Case:** O(26)
- **Worst Case:** O(26)

The space complexity is O(26) for the frequency arrays used to track the minimum counts of characters, as there are only 26 possible lowercase English letters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-common-characters/description/)

---
{{< youtube QEESBA2Q_88 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
