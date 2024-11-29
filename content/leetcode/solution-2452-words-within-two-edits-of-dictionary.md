
+++
authors = ["grid47"]
title = "Leetcode 2452: Words Within Two Edits of Dictionary"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2452: Words Within Two Edits of Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "99KTTNdlKns"
youtube_upload_date="2022-10-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/99KTTNdlKns/maxresdefault.webp"
comments = true
+++



---
You are given two arrays of strings, 'queries' and 'dictionary', where each word has the same length. A word from the 'queries' array can be transformed into a word from the 'dictionary' array by making at most two edits. An edit involves changing any character in the word to another letter. Your task is to find all words from 'queries' that, after making at most two edits, can match some word in 'dictionary'. Return the words in the same order they appear in the 'queries'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays, 'queries' and 'dictionary', where each element in both arrays is a string of lowercase English letters.
- **Example:** `queries = ["hello", "world", "clue", "blue"], dictionary = ["blow", "hole", "blue"]`
- **Constraints:**
	- 1 <= queries.length, dictionary.length <= 100
	- n == queries[i].length == dictionary[j].length
	- 1 <= n <= 100
	- All queries[i] and dictionary[j] are composed of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of words from 'queries' that can be transformed into a word from 'dictionary' with at most two edits.
- **Example:** `Output: ["hello", "blue"]`
- **Constraints:**
	- The result list should contain the words in the same order they appear in 'queries'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find all words in 'queries' that can match some word from 'dictionary' after at most two edits.

- 1. For each word in 'queries', compare it to each word in 'dictionary'.
- 2. Count the number of character mismatches between the words.
- 3. If the number of mismatches is less than or equal to two, add the word from 'queries' to the result list.
- 4. Return the result list containing all the words from 'queries' that match some word in 'dictionary'.
{{< dots >}}
### Problem Assumptions ✅
- The words in 'queries' and 'dictionary' are all valid lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `queries = ["hello", "world", "clue", "blue"], dictionary = ["blow", "hole", "blue"]`  \
  **Explanation:** The word 'hello' from queries can become 'blow' in the dictionary with one edit ('h' to 'b'). 'world' cannot match any word from the dictionary with two or fewer edits. 'clue' can become 'blue' with one edit ('c' to 'b'). Thus, the result is ["hello", "blue"].

- **Input:** `queries = ["apple", "grape", "melon"], dictionary = ["apricot", "grape", "mole"]`  \
  **Explanation:** The word 'apple' cannot match any word from the dictionary with at most two edits. 'grape' matches with 'grape' in the dictionary (no edits needed). 'melon' can be changed to 'mole' with one edit ('n' to 'e'). Hence, the result is ["grape", "melon"].

{{< dots >}}
## Approach 🚀
We will compare each word from 'queries' to each word from 'dictionary'. If a word from 'queries' can match a word from 'dictionary' after at most two edits, it will be added to the result list.

### Initial Thoughts 💭
- The task involves counting character mismatches and ensuring the number of mismatches is at most two.
- We can compare each word in 'queries' with each word in 'dictionary' and count mismatches in O(n) time for each pair of words.
{{< dots >}}
### Edge Cases 🌐
- If 'queries' or 'dictionary' is empty, return an empty result list.
- The solution should handle the case where both 'queries' and 'dictionary' contain the maximum allowed number of words and word length.
- If all words in 'queries' are already present in 'dictionary', no edits are needed, and the solution should correctly handle this case.
- Ensure the solution handles the constraint of word lengths efficiently, particularly when they are close to the maximum value of 100.
{{< dots >}}
## Code 💻
```cpp
vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> res;
    for(auto &q: queries)
    for(auto &d: dictionary)
    if(inner_product(begin(q), end(q), begin(d), 0, plus<int>(), not_equal_to<char>()) < 3) {
        res.push_back(q);
        break;
    }
    return res;
}
```

This function compares words from two lists (queries and dictionary) and returns the words from `queries` that differ from at most two characters compared to any word in `dictionary`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
	```
	Defines the `twoEditWords` function that takes two vectors of strings: `queries` and `dictionary`, and returns a vector of strings containing words from `queries` that differ by at most 2 characters from any word in `dictionary`.

2. **Variable Initialization**
	```cpp
	    vector<string> res;
	```
	Initializes an empty vector `res` to store the result of words from `queries` that meet the specified condition.

3. **Outer Loop**
	```cpp
	    for(auto &q: queries)
	```
	Starts an outer loop to iterate over each word `q` in the `queries` list.

4. **Inner Loop**
	```cpp
	    for(auto &d: dictionary)
	```
	Starts an inner loop to iterate over each word `d` in the `dictionary` list.

5. **Comparison Condition**
	```cpp
	    if(inner_product(begin(q), end(q), begin(d), 0, plus<int>(), not_equal_to<char>()) < 3) {
	```
	Uses `inner_product` to compare characters between the two words `q` and `d`. The condition checks if the number of different characters between the two words is less than 3.

6. **Add to Result**
	```cpp
	        res.push_back(q);
	```
	If the condition is satisfied (i.e., the words differ by fewer than 3 characters), the word `q` is added to the result vector `res`.

7. **Break Statement**
	```cpp
	        break;
	```
	Breaks the inner loop once a match is found, as we only need one match to add the word `q` to the result.

8. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result vector `res`, which contains all the words from `queries` that matched the condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

For each word in 'queries' (n words), we compare it to each word in 'dictionary' (m words), and each comparison takes O(n) time where n is the length of the words.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is determined by the space used to store the result list, which can have up to 'n' elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/)

---
{{< youtube 99KTTNdlKns >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
