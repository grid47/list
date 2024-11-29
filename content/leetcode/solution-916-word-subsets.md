
+++
authors = ["grid47"]
title = "Leetcode 916: Word Subsets"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 916: Word Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given two arrays of strings `words1` and `words2`, find all the strings in `words1` that are universal. A string from `words1` is considered universal if it contains all the letters of every string in `words2`, including multiplicity. Each string in `words2` is a subset of the string from `words1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays of strings `words1` and `words2`.
- **Example:** `Input: words1 = ["hello", "world", "goodbye", "example"], words2 = ["h", "e", "l"]`
- **Constraints:**
	- 1 <= words1.length, words2.length <= 10^4
	- 1 <= words1[i].length, words2[i].length <= 10
	- words1[i] and words2[i] consist only of lowercase English letters.
	- All the strings in words1 are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing all the strings from `words1` that are universal, which means they contain all the letters from every string in `words2`.
- **Example:** `Output: ["hello", "goodbye"]`
- **Constraints:**
	- The output should be an array of strings from `words1`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify strings from `words1` that are universal, meaning they contain all the characters (with correct multiplicity) of each string in `words2`.

- Count the frequency of each character in all strings of `words2`.
- For each string in `words1`, count its characters and check if it contains the required characters with at least the same multiplicity as in `words2`.
- If a string meets the criteria, include it in the result.
{{< dots >}}
### Problem Assumptions ✅
- We assume that the input arrays contain valid strings and that all the strings in `words1` are unique.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words1 = ["hello", "world", "goodbye", "example"], words2 = ["h", "e", "l"]`  \
  **Explanation:** For this example, the string "hello" contains all the characters in `words2` ('h', 'e', and 'l') with the correct multiplicity, so it's a valid answer. The string "world" does not contain all characters required by `words2`, so it's not a valid answer. The string "goodbye" is also valid as it contains all the characters required by `words2`.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we first calculate the required frequencies for all characters in `words2`. Then, we check each string in `words1` to see if it meets these frequency requirements. If a string contains the necessary characters in the correct amounts, we add it to the result.

### Initial Thoughts 💭
- We need to check the frequency of each character in both `words1` and `words2`.
- The size of the arrays is large, so the solution must be efficient.
- Using frequency counting for each string and comparing these counts for every word in `words1` should be an efficient approach.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that both arrays will have at least one string, so no need to handle empty inputs.
- The solution should efficiently handle cases where both `words1` and `words2` have up to 10^4 strings.
- If `words2` contains strings with characters that do not appear in any string in `words1`, no strings from `words1` will be valid.
- The constraints ensure that the input will always contain valid strings and the solution must work within the given bounds.
{{< dots >}}
## Code 💻
```cpp
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> frq(26, 0);
    for(auto s: words2) {
        vector<int> tmp(26, 0);
        for(char c: s) {
            tmp[c - 'a']++;
            frq[c - 'a'] = max(frq[c - 'a'], tmp[c-'a']);
        }
    }
    vector<string> res;
    for(auto s: words1) {
        vector<int> tmp(26, 0);
        for(char c: s) tmp[c - 'a']++;
        int flag = true;
        for(int i = 0; i < 26; i++) {
            if(tmp[i] < frq[i]) {
                flag = false;
                break;
            }
        }
        if(flag) res.push_back(s);
    }
    return res;
}
```

The function 'wordSubsets' finds words in 'words1' that are supersets of all the words in 'words2'. It checks if all character frequencies required by 'words2' are present in each word in 'words1'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
	```
	Define the function 'wordSubsets' which takes two vectors of strings, 'words1' and 'words2', and returns a vector of strings representing words from 'words1' that are supersets of the words in 'words2'.

2. **Variable Initialization**
	```cpp
	    vector<int> frq(26, 0);
	```
	Initialize a vector 'frq' to keep track of the maximum frequency required for each letter ('a' to 'z') across all words in 'words2'.

3. **Looping**
	```cpp
	    for(auto s: words2) {
	```
	Loop through each word in 'words2' to compute the required frequency of each character.

4. **Variable Initialization**
	```cpp
	        vector<int> tmp(26, 0);
	```
	For each word in 'words2', initialize a temporary frequency vector 'tmp' to count the occurrences of each letter.

5. **Character Frequency Counting**
	```cpp
	        for(char c: s) {
	```
	Iterate through each character of the current word in 'words2'.

6. **Frequency Counting**
	```cpp
	            tmp[c - 'a']++;
	```
	Update the frequency count for the current character in the temporary frequency vector 'tmp'.

7. **Frequency Comparison**
	```cpp
	            frq[c - 'a'] = max(frq[c - 'a'], tmp[c-'a']);
	```
	Update the global frequency vector 'frq' to store the maximum frequency encountered for each character across all words in 'words2'.

8. **Variable Initialization**
	```cpp
	    vector<string> res;
	```
	Initialize an empty vector 'res' to store the valid words from 'words1' that meet the criteria.

9. **Looping**
	```cpp
	    for(auto s: words1) {
	```
	Loop through each word in 'words1' to check if it is a valid superset of the words in 'words2'.

10. **Variable Initialization**
	```cpp
	        vector<int> tmp(26, 0);
	```
	Initialize a temporary frequency vector 'tmp' to count the characters in the current word from 'words1'.

11. **Character Frequency Counting**
	```cpp
	        for(char c: s) tmp[c - 'a']++;
	```
	Count the occurrences of each character in the current word from 'words1'.

12. **Flag Initialization**
	```cpp
	        int flag = true;
	```
	Initialize a flag to 'true', which will be used to check if the current word is a valid superset.

13. **Frequency Comparison**
	```cpp
	        for(int i = 0; i < 26; i++) {
	```
	Iterate over each character in the alphabet to compare the frequencies of characters in the current word from 'words1' with the required frequencies stored in 'frq'.

14. **Condition Checking**
	```cpp
	            if(tmp[i] < frq[i]) {
	```
	If the current word does not meet the required frequency for any character, set the flag to 'false'.

15. **Flag Update**
	```cpp
	                flag = false;
	```
	Set the flag to 'false' if the current word does not contain enough of the character 'i' compared to 'words2'.

16. **Loop Exit**
	```cpp
	                break;
	```
	Exit the loop early if any character in the word does not satisfy the frequency condition.

17. **Adding Valid Words**
	```cpp
	        if(flag) res.push_back(s);
	```
	If the word is a valid superset (flag is true), add it to the result vector 'res'.

18. **Return Statement**
	```cpp
	    return res;
	```
	Return the vector 'res' containing all valid words from 'words1' that are supersets of the words in 'words2'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where n is the length of `words1` and m is the length of `words2`
- **Average Case:** O(n + m)
- **Worst Case:** O(n * k + m * k), where k is the average length of strings in `words1` and `words2`

The time complexity is linear in terms of the size of the input arrays, with an additional factor for processing each character in the strings.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1) for the frequency array of size 26

The space complexity is constant due to the frequency array for each character and the result array which holds the universal strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/word-subsets/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
