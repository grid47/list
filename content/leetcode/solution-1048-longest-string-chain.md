
+++
authors = ["grid47"]
title = "Leetcode 1048: Longest String Chain"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1048: Longest String Chain in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","String","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mB13CkhSe3A"
youtube_upload_date="2020-02-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mB13CkhSe3A/maxresdefault.webp"
comments = true
+++



---
You are given an array of words, where each word consists of lowercase English letters. A wordA is considered a predecessor of wordB if you can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB. A word chain is a sequence of words such that each word is a predecessor of the next one. Your task is to find the length of the longest word chain that can be formed from the given list of words.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of words, each consisting of lowercase English letters.
- **Example:** `Input: words = ["a", "ab", "abc", "abcd"]`
- **Constraints:**
	- 1 <= words.length <= 1000
	- 1 <= words[i].length <= 16
	- words[i] only consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest possible word chain that can be formed from the list of words.
- **Example:** `Output: 4`
- **Constraints:**
	- The answer will always be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the longest word chain by checking if a word can be a predecessor of another.

- 1. Sort the words based on their lengths.
- 2. Use dynamic programming to track the longest chain ending at each word.
- 3. For each word, try to form a predecessor by removing one character at a time and check if the resulting word exists in the previous words of the list.
- 4. The result is the maximum length of all possible word chains.
{{< dots >}}
### Problem Assumptions ✅
- Each word consists of lowercase English letters only.
- The words are provided in an array, and their lengths vary.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ["a", "ab", "abc", "abcd"]`  \
  **Explanation:** In this example, we can form the word chain ["a", "ab", "abc", "abcd"]. Each word is a predecessor of the next, resulting in a chain length of 4.

- **Input:** `Input: words = ["xbc", "pcxbcf", "xb", "cxbc", "pcxbc"]`  \
  **Explanation:** In this example, all words can be arranged into the word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"], resulting in a chain length of 5.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we can use dynamic programming and sorting to form the longest word chain.

### Initial Thoughts 💭
- The problem involves finding the longest sequence of words where each word can be transformed into the next by adding one character.
- Sorting the words by length allows us to progressively check possible predecessors for each word.
- A dynamic programming approach is well-suited to track the longest chain ending at each word.
{{< dots >}}
### Edge Cases 🌐
- If there are no words, the longest word chain length is 0.
- For large inputs, the algorithm will efficiently compute the longest word chain due to the dynamic programming approach.
- If all words are of the same length, no word can be a predecessor of another, and the longest chain length is 1.
- The number of words is guaranteed to be at most 1000, and each word has a length of at most 16 characters.
{{< dots >}}
## Code 💻
```cpp

static bool cmp(string &a, string &b) {
    return a.size() < b.size();
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), cmp);
    
    map<string, int> dp;

    int mx = 1;
    
    for(int i = 0; i < words.size(); i++) {
        string w = words[i];
        for(int j = 0; j < w.size(); j++) {
            string w1 = w.substr(0, j) + w.substr(j + 1);
            dp[w] = max(dp[w], dp.count(w1)? dp[w1] + 1: 1);
        }
        mx = max(mx, dp[w]);
    }
    
    return mx;
}
```

This function finds the longest string chain in a list of words, where each word in the chain can be formed by removing one character from the previous word. It uses dynamic programming and sorting to efficiently find the solution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	static bool cmp(string &a, string &b) {
	```
	Define a static comparison function 'cmp' that compares the size of two strings. This function is used for sorting the words in increasing order of their lengths.

2. **Comparison Logic**
	```cpp
	    return a.size() < b.size();
	```
	Return true if the size of string 'a' is smaller than that of string 'b', otherwise return false. This is used to sort the words in ascending order of their lengths.

3. **Function Definition**
	```cpp
	int longestStrChain(vector<string>& words) {
	```
	Define the function 'longestStrChain' which takes a vector of strings 'words' and returns the length of the longest string chain.

4. **Sorting**
	```cpp
	    sort(words.begin(), words.end(), cmp);
	```
	Sort the 'words' vector in increasing order of word length using the comparison function 'cmp'.

5. **Variable Declaration**
	```cpp
	    map<string, int> dp;
	```
	Declare a map 'dp' where each key is a word, and the value is the length of the longest chain ending with that word.

6. **Variable Initialization**
	```cpp
	    int mx = 1;
	```
	Initialize 'mx' to 1, which will store the length of the longest string chain found so far.

7. **Loop Through Words**
	```cpp
	    for(int i = 0; i < words.size(); i++) {
	```
	Start a for loop that iterates through each word in the sorted 'words' vector.

8. **Assign Word**
	```cpp
	        string w = words[i];
	```
	Assign the current word in the iteration to the variable 'w'.

9. **Loop Through Word Characters**
	```cpp
	        for(int j = 0; j < w.size(); j++) {
	```
	Start an inner loop that iterates through each character of the current word 'w'.

10. **Create Substring**
	```cpp
	            string w1 = w.substr(0, j) + w.substr(j + 1);
	```
	Create a new string 'w1' by removing the character at index 'j' from the string 'w'. This helps in checking if the current word can form a chain with a previous word.

11. **Update DP Map**
	```cpp
	            dp[w] = max(dp[w], dp.count(w1)? dp[w1] + 1: 1);
	```
	Update the value of 'dp[w]' by checking if a smaller word 'w1' exists in the map 'dp'. If it does, the chain length is increased by 1. Otherwise, it starts a new chain with length 1.

12. **Update Maximum Chain Length**
	```cpp
	        mx = max(mx, dp[w]);
	```
	Update the maximum chain length 'mx' by comparing it with the current chain length stored in 'dp[w]'.

13. **Return Result**
	```cpp
	    return mx;
	```
	Return the value of 'mx', which is the length of the longest string chain.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we check all possible predecessors for each word, leading to a time complexity of O(n^2) where n is the number of words.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the map of longest chain lengths.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-string-chain/description/)

---
{{< youtube mB13CkhSe3A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
