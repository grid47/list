
+++
authors = ["grid47"]
title = "Leetcode 792: Number of Matching Subsequences"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 792: Number of Matching Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Binary Search","Dynamic Programming","Trie","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/792.webp"
youtube = "0zMujz5SYoE"
youtube_upload_date="2020-08-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0zMujz5SYoE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/792.webp" 
    alt="A sequence where matching subsequences are counted, with each match glowing softly as it is found."
    caption="Solution to LeetCode 792: Number of Matching Subsequences Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string s and an array of strings words. Your task is to determine how many words from the array are subsequences of the string s. A subsequence of a string is derived by deleting some or no characters from the original string without altering the order of the remaining characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s and an array of strings words.
- **Example:** `s = 'abcdefg', words = ['abc', 'abd', 'ac', 'bfg', 'gfg']`
- **Constraints:**
	- 1 <= s.length <= 5 * 10^4
	- 1 <= words.length <= 5000
	- 1 <= words[i].length <= 50
	- s and words[i] consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of words in words that are subsequences of the string s.
- **Example:** `Output: 3`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check whether each word in the words array is a subsequence of the string s.

- Create a mapping of each character's position in s for fast look-up.
- For each word in words, try to find the characters in order using the precomputed mapping.
- If all characters of the word are found in order in s, it is considered a subsequence.
{{< dots >}}
### Problem Assumptions ✅
- Both s and words contain only lowercase letters.
- The length of words[i] will not exceed 50 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abcdefg', words = ['abc', 'abd', 'ac', 'bfg', 'gfg']`  \
  **Explanation:** The words 'abc', 'abd', and 'ac' are subsequences of s, while 'bfg' and 'gfg' are not.

- **Input:** `Input: s = 'ahjkslmn', words = ['ahjl', 'ajl', 'hks', 'lsmn']`  \
  **Explanation:** The words 'ahjl', 'ajl', and 'hks' are subsequences of s. 'lsmn' is not.

{{< dots >}}
## Approach 🚀
To solve this problem, we can precompute the indices of each character in the string s for efficient look-up and then use a binary search to check if each word is a subsequence.

### Initial Thoughts 💭
- Checking if a word is a subsequence can be done efficiently by precomputing positions of characters in s.
- Binary search can speed up the process of finding the next character in the subsequence.
- By creating a list of positions for each character in s and using binary search, we can check each word in O(word.length * log(s.length)) time.
{{< dots >}}
### Edge Cases 🌐
- Empty strings should not be considered valid inputs.
- For larger strings and word arrays, the solution should still perform efficiently within the given constraints.
- If a word is empty or if s contains repeated characters, handle accordingly.
- Ensure that the length of words does not exceed 5000 and words[i] does not exceed 50 characters.
{{< dots >}}
## Code 💻
```cpp
int numMatchingSubseq(string s, vector<string>& words) {
    int n = s.size();
    vector<vector<int>> srch(26);

    for(int i = 0; i < s.size(); i++)
        srch[s[i] - 'a'].push_back(i);
    
    int res = 0;
    
    for(string word : words) {
        int x = -1;
        bool found = true;

        for(char c : word) {
            auto it = upper_bound(srch[c - 'a'].begin(), srch[c - 'a'].end(), x);
            if(it == srch[c - 'a'].end()) {
                found = false;
                break;
            } else x = *it;
        }
        
        if(found) res++;
    }
            
    return res;
}
```

This function takes a string `s` and a list of `words`, and counts how many of the words in `words` are subsequences of `s`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numMatchingSubseq(string s, vector<string>& words) {
	```
	The function `numMatchingSubseq` takes two parameters: a string `s` and a vector of strings `words`. The goal is to check how many words in `words` are subsequences of the string `s`.

2. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	The variable `n` stores the size of the string `s`.

3. **Data Structure Setup**
	```cpp
	    vector<vector<int>> srch(26);
	```
	A 2D vector `srch` is initialized to store the indices of each character in the string `s`. The 26 represents the number of letters in the English alphabet.

4. **Loop Setup**
	```cpp
	    for(int i = 0; i < s.size(); i++)
	```
	This loop iterates over each character of string `s`.

5. **Index Storage**
	```cpp
	        srch[s[i] - 'a'].push_back(i);
	```
	For each character `s[i]`, the index `i` is stored in the corresponding vector in `srch`. The character is converted to an index using `s[i] - 'a'`.

6. **Result Initialization**
	```cpp
	    int res = 0;
	```
	The variable `res` is initialized to 0. It will store the count of matching subsequences.

7. **Word Loop**
	```cpp
	    for(string word : words) {
	```
	This loop iterates over each word in the vector `words`.

8. **Initialization for Word Search**
	```cpp
	        int x = -1;
	```
	The variable `x` is initialized to -1, which represents the position of the last character found in string `s` during the subsequence check.

9. **Match Flag**
	```cpp
	        bool found = true;
	```
	The variable `found` is initialized as `true`. It will be set to `false` if the word is not a subsequence.

10. **Character Loop**
	```cpp
	        for(char c : word) {
	```
	This loop iterates over each character `c` in the current word.

11. **Search for Next Character**
	```cpp
	            auto it = upper_bound(srch[c - 'a'].begin(), srch[c - 'a'].end(), x);
	```
	For each character `c`, the function `upper_bound` is used to find the first index in `srch[c - 'a']` that is greater than `x`. This ensures the characters in `word` appear in order in `s`.

12. **Check for Match**
	```cpp
	            if(it == srch[c - 'a'].end()) {
	```
	If no valid index is found (i.e., the word cannot be a subsequence), set `found` to `false`.

13. **Flag Update**
	```cpp
	                found = false;
	```
	The `found` flag is set to `false` because the character `c` is not found in the required order in string `s`.

14. **Break Loop**
	```cpp
	                break;
	```
	Exit the loop as no further characters of the word can be matched.

15. **Update Search Index**
	```cpp
	            } else x = *it;
	```
	If a matching index is found, update `x` to this index for the next character search.

16. **Increment Result**
	```cpp
	        if(found) res++;
	```
	If the word is a subsequence, increment the result count `res`.

17. **Return Result**
	```cpp
	    return res;
	```
	Return the final count of matching subsequences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log m), where n is the length of s and m is the average length of the words.
- **Average Case:** O(n log m), where n is the length of s and m is the average length of the words.
- **Worst Case:** O(n log m), where n is the length of s and m is the average length of the words.

The time complexity depends on the length of the string s and the average length of the words, with a logarithmic factor due to binary search.

### Space Complexity 💾
- **Best Case:** O(n), where n is the length of s.
- **Worst Case:** O(n), where n is the length of s for storing character positions.

The space complexity is O(n) due to the storage of character positions for each letter in s.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-matching-subsequences/description/)

---
{{< youtube 0zMujz5SYoE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
