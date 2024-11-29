
+++
authors = ["grid47"]
title = "Leetcode 318: Maximum Product of Word Lengths"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 318: Maximum Product of Word Lengths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/318.webp"
youtube = "dE88fgc73jQ"
youtube_upload_date="2021-05-27"
youtube_thumbnail="https://i.ytimg.com/vi/dE88fgc73jQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/318.webp" 
    alt="A set of words with glowing lengths, each word’s length highlighted to show the maximum product of word lengths."
    caption="Solution to LeetCode 318: Maximum Product of Word Lengths Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a list of words, return the maximum product of lengths of two words such that the two words do not share common letters. If no such pair exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of words, where each word consists of lowercase English letters.
- **Example:** `words = ["abc", "xyz", "foo", "bar", "pqr", "abcdef"]`
- **Constraints:**
	- 2 <= words.length <= 1000
	- 1 <= words[i].length <= 1000
	- words[i] consists of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum product of lengths of two words that do not share common letters.
- **Example:** `15`
- **Constraints:**
	- If no such pair exists, return 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum product of lengths of two words where the words do not share any common letters.

- For each word, calculate its bitmask where each bit represents whether a letter is present in the word.
- For each pair of words, check if the bitmasks do not overlap (i.e., they share no common letters).
- Calculate the product of the lengths of words that do not share any common letters, and track the maximum product.
{{< dots >}}
### Problem Assumptions ✅
- The words are non-empty and consist of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["abc", "xyz", "foo", "bar", "pqr", "abcdef"]`  \
  **Explanation:** The two words with no common letters are 'abc' and 'xyz'. The product of their lengths is 15, which is the maximum.

- **Input:** `words = ["a", "ab", "ac", "b", "bc"]`  \
  **Explanation:** The maximum product is 2, obtained by the words 'a' and 'bc'.

{{< dots >}}
## Approach 🚀
Use bitmasking to represent the letters in each word, and calculate the maximum product of lengths of words that do not share common letters.

### Initial Thoughts 💭
- Each word can be represented by a bitmask, where each bit represents a character.
- We can compare two words by checking if their bitmasks have no common bits set, indicating no common letters.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees at least two words in the input.
- The solution must efficiently handle up to 1000 words, each with a length up to 1000.
- If no words share no common letters, the answer should be 0.
- Ensure the solution has a time complexity of O(n^2) or better to handle the problem's input size.
{{< dots >}}
## Code 💻
```cpp
int maxProduct(vector<string>& words) {

    int len = words.size();
    vector<int> mask(len, 0);

    int res = 0;
    for(int i = 0; i < len; i++) {
        string word = words[i];
        int sz = word.size();
        for(int j = 0; j < sz; j++)
        mask[i] |= (1 << (word[j] - 'a'));

        for(int j = 0; j < i; j++) {
            if((mask[i] & mask[j]) == 0)
            res = max(res, int (words[i].size() * words[j].size() ));
        }
    }
    return res;
}
```

This function takes a vector of words and returns the maximum product of lengths of two words that do not share any common letters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxProduct(vector<string>& words) {
	```
	The function `maxProduct` accepts a vector of strings `words` as input and returns an integer representing the maximum product of lengths of two words that do not share common characters.

2. **Variable Initialization**
	```cpp
	    int len = words.size();
	```
	This line initializes `len` to hold the number of words in the vector.

3. **Variable Initialization**
	```cpp
	    vector<int> mask(len, 0);
	```
	A vector `mask` of integers is initialized, where each element corresponds to a word in the input and will hold a bitmask of the characters in that word.

4. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	The variable `res` is initialized to store the maximum product of lengths found during the iteration.

5. **Iteration**
	```cpp
	    for(int i = 0; i < len; i++) {
	```
	A loop is started to iterate over each word in the `words` vector.

6. **Variable Declaration**
	```cpp
	        string word = words[i];
	```
	For each iteration, the word at index `i` is extracted and stored in the variable `word`.

7. **Variable Declaration**
	```cpp
	        int sz = word.size();
	```
	The variable `sz` stores the length of the current word to assist with looping over its characters.

8. **Looping**
	```cpp
	        for(int j = 0; j < sz; j++)
	```
	This inner loop iterates over each character of the current word.

9. **Bit Manipulation**
	```cpp
	        mask[i] |= (1 << (word[j] - 'a'));
	```
	For each character, the corresponding bit in the `mask[i]` is set to 1. This represents the characters present in the word using a bitmask.

10. **Iteration**
	```cpp
	        for(int j = 0; j < i; j++) {
	```
	This loop compares the bitmask of the current word `i` with the words before it.

11. **Bitwise Operation**
	```cpp
	            if((mask[i] & mask[j]) == 0)
	```
	This condition checks whether the two words `i` and `j` share any common characters using a bitwise AND operation.

12. **Max Calculation**
	```cpp
	            res = max(res, int (words[i].size() * words[j].size() ));
	```
	If the words do not share any characters, the product of their lengths is calculated and stored in `res` if it is the maximum product found so far.

13. **Return**
	```cpp
	    return res;
	```
	The function returns the maximum product of word lengths found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to comparing each word with every other word.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the bitmasks of the words.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-of-word-lengths/description/)

---
{{< youtube dE88fgc73jQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
