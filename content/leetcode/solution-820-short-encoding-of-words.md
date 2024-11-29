
+++
authors = ["grid47"]
title = "Leetcode 820: Short Encoding of Words"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 820: Short Encoding of Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/820.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/820.webp" 
    alt="A series of words encoded, with the shortest encoding glowing softly as it is created."
    caption="Solution to LeetCode 820: Short Encoding of Words Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of words, you are to return the length of the shortest reference string that can encode these words. The reference string consists of the words concatenated with a '#' character at the end, and indices are used to encode the words by identifying their position in the reference string. Each word is encoded by the substring in the reference string that starts at its position and ends at the next '#'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of words, where each word is a string of lowercase letters. Each word in the array has a length between 1 and 7 characters.
- **Example:** `Input: words = ["apple", "ple", "le"]`
- **Constraints:**
	- 1 <= words.length <= 2000
	- 1 <= words[i].length <= 7
	- words[i] consists of only lowercase letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the shortest reference string that can encode the given words.
- **Example:** `Output: 9`
- **Constraints:**
	- The output should be an integer representing the length of the shortest reference string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the shortest encoding of the words using a reference string. To do this, we can eliminate words that are suffixes of other words, and concatenate only the distinct prefixes of the words to form the reference string.

- Create a set of words to store unique words.
- For each word, check all possible suffixes and remove them from the set if they are also present.
- Finally, concatenate the remaining words, adding 1 for each '#' delimiter, and return the length of the concatenated string.
{{< dots >}}
### Problem Assumptions ✅
- All words are lowercase and have lengths between 1 and 7 characters.
- Words in the array are unique.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ["apple", "ple", "le"]`  \
  **Explanation:** The word 'ple' is a suffix of 'apple', and 'le' is a suffix of 'ple'. So, we can encode the words with 'apple#', which results in a total length of 9.

- **Input:** `Input: words = ["orange", "or", "ange"]`  \
  **Explanation:** Here, 'or' is a prefix of 'orange', and 'ange' is a suffix of 'orange'. The shortest encoding would be 'orange#', resulting in a total length of 7.

{{< dots >}}
## Approach 🚀
The key to solving this problem efficiently is to first remove suffixes that are redundant. If one word is a suffix of another, the shorter word does not need to be included in the final encoding.

### Initial Thoughts 💭
- Suffixes that are part of longer words don't need to be included separately.
- The reference string must end with a '#' character, so we need to account for that when calculating the total length.
- We should identify all words that are not suffixes of other words, as these will contribute to the final reference string.
{{< dots >}}
### Edge Cases 🌐
- If the input is an empty array, return 0 since there are no words to encode.
- For large arrays (up to 2000 words), the solution should handle them efficiently.
- Ensure that cases where all words are prefixes or suffixes of one another are handled correctly.
- The solution must handle arrays of up to 2000 words efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimumLengthEncoding(vector<string>& words) {

    unordered_set<string> s(words.begin(), words.end());
    
    for(string w: words)
    for(int i = 1; i < w.size(); i++)
        s.erase(w.substr(i));

    int res = 0;        
    for(string sk: s)
    res += (sk.size() + 1);
    
    return res;
}
```

This function calculates the minimum length encoding for a set of words by removing the suffixes of each word that appear in other words.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumLengthEncoding(vector<string>& words) {
	```
	The function `minimumLengthEncoding` is defined, which takes a vector of strings `words` as input and returns an integer representing the minimum length encoding.

2. **Set Initialization**
	```cpp
	    unordered_set<string> s(words.begin(), words.end());
	```
	An unordered set `s` is initialized with the elements from the `words` vector, ensuring all words are stored without duplicates.

3. **Outer Loop**
	```cpp
	    for(string w: words)
	```
	The outer loop iterates over each word `w` in the `words` vector.

4. **Inner Loop**
	```cpp
	    for(int i = 1; i < w.size(); i++)
	```
	The inner loop iterates over the characters in each word starting from index 1, essentially looking at suffixes of the word.

5. **Erase Suffix**
	```cpp
	        s.erase(w.substr(i));
	```
	The substring of `w` starting from index `i` is removed from the set `s`. This ensures that any word that is a suffix of another word is excluded from the encoding.

6. **Result Initialization**
	```cpp
	    int res = 0;        
	```
	The variable `res` is initialized to 0, which will be used to store the total length of the encoded string.

7. **Summing Lengths**
	```cpp
	    for(string sk: s)
	```
	The loop iterates over each string `sk` remaining in the set `s`.

8. **Calculate Encoding Length**
	```cpp
	    res += (sk.size() + 1);
	```
	For each string `sk`, its length is added to `res`, along with an additional 1 to account for the '#' character that separates each word in the encoding.

9. **Return Result**
	```cpp
	    return res;
	```
	The function returns the total length of the encoded string, which is the sum of the lengths of all the strings in the set `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of words.
- **Average Case:** O(n * m), where n is the number of words and m is the average length of the words.
- **Worst Case:** O(n * m), where n is the number of words and m is the average length of the words.

The time complexity is linear with respect to the number of words and the length of each word due to the need to check suffixes.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of words, when no suffixes need to be stored.
- **Worst Case:** O(n * m), where n is the number of words and m is the average length of the words, for storing the word set.

The space complexity is primarily determined by the size of the word set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/short-encoding-of-words/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
