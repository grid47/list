
+++
authors = ["grid47"]
title = "Leetcode 2506: Count Pairs Of Similar Strings"
date = "2024-03-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2506: Count Pairs Of Similar Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uWSEfo1DlwY"
youtube_upload_date="2022-12-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uWSEfo1DlwY/maxresdefault.webp"
comments = true
+++



---
You are given a list of words, where each word consists of lowercase English letters. Two words are considered similar if they contain the exact same set of unique characters, regardless of the order. Your task is to count how many pairs of words (i, j) satisfy the condition where both words have the same set of unique characters. Return the count of such pairs (i, j) where 0 ≤ i < j ≤ len(words) - 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of words, where each word is a string of lowercase English letters.
- **Example:** `["aba", "aabb", "abcd", "bac", "aabc"]`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 100
	- words[i] consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the number of pairs (i, j) where the words[i] and words[j] have the same set of unique characters.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count pairs of words that consist of the same set of unique characters.

- For each word in the input list, calculate a unique bitmask representing the set of characters in the word.
- Use a map to store the frequency of each unique bitmask.
- For each word's bitmask, find how many previous words have the same bitmask, indicating that the two words are similar.
- Count the number of such pairs and return the total count.
{{< dots >}}
### Problem Assumptions ✅
- The input list will not contain any null or empty words.
- Each word consists only of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `["aba", "aabb", "abcd", "bac", "aabc"]`  \
  **Explanation:** In this example, the words 'aba' and 'aabb' are similar because they consist of the characters 'a' and 'b', and the words 'bac' and 'aabc' are similar because they consist of 'a', 'b', and 'c'. Therefore, there are 2 such pairs.

{{< dots >}}
## Approach 🚀
The approach uses bitwise operations to efficiently represent and compare the set of characters in each word.

### Initial Thoughts 💭
- Each word can be represented by a bitmask where each bit represents a character from 'a' to 'z'.
- If two words have the same bitmask, they contain the same set of characters, regardless of order.
{{< dots >}}
### Edge Cases 🌐
- If the input list is empty, the result should be 0.
- If the input list has the maximum number of words (100), ensure that the solution efficiently handles this size.
- Words with only one character should also be handled correctly.
- Ensure that words containing only distinct characters are correctly identified as similar if another word contains the same characters.
{{< dots >}}
## Code 💻
```cpp
int similarPairs(vector<string>& words) {
		int ans = 0; 
		unordered_map<int, int> freq; 
		for (auto& word : words) {
			int mask = 0; 
			for (auto& c : word) mask |= 1 << (c-'a'); 
			ans += freq[mask]++; 
		}
		return ans;         
}
```

This function finds the number of similar pairs in a list of words. Two words are considered similar if they contain the same set of unique characters, regardless of order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int similarPairs(vector<string>& words) {
	```
	Defines the function `similarPairs` which takes a reference to a vector of strings `words` and returns the number of similar pairs.

2. **Variable Initialization**
	```cpp
			int ans = 0; 
	```
	Initializes a variable `ans` to store the count of similar pairs. The initial value is 0.

3. **Data Structure Initialization**
	```cpp
			unordered_map<int, int> freq; 
	```
	Declares an unordered map `freq` where the key is an integer (representing a unique bitmask) and the value is the frequency of that bitmask.

4. **Loop Structure**
	```cpp
			for (auto& word : words) {
	```
	Begins a loop that iterates over each word in the input vector `words`.

5. **Variable Initialization**
	```cpp
				int mask = 0; 
	```
	Initializes a variable `mask` to 0. This will be used to create a bitmask representing the unique characters in the current word.

6. **Loop Structure**
	```cpp
				for (auto& c : word) mask |= 1 << (c-'a'); 
	```
	Inner loop that iterates over each character `c` in the word. It updates the `mask` by setting the corresponding bit for the character (using bitwise operations).

7. **Map Manipulation**
	```cpp
				ans += freq[mask]++; 
	```
	Increments `ans` by the frequency of the current `mask` in the `freq` map, then updates the frequency of `mask` in the map.

8. **Loop Structure**
	```cpp
			}
	```
	Ends the loop that processes each word in the `words` vector.

9. **Return Statement**
	```cpp
			return ans;         
	```
	Returns the total count of similar pairs stored in `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m), where n is the number of words and m is the average length of the words.
- **Average Case:** O(n * m), since we have to process each word individually.
- **Worst Case:** O(n * m), where n is the number of words and m is the maximum length of the words.

The complexity comes from processing each word and storing its bitmask, as well as looking up bitmask frequencies in the hashmap.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of words.
- **Worst Case:** O(n), since we need to store the bitmask frequencies for each word.

The space complexity is proportional to the number of words and the number of distinct bitmasks.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-pairs-of-similar-strings/description/)

---
{{< youtube uWSEfo1DlwY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
