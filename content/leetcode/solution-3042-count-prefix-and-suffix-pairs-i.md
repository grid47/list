
+++
authors = ["grid47"]
title = "Leetcode 3042: Count Prefix and Suffix Pairs I"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3042: Count Prefix and Suffix Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Trie","Rolling Hash","String Matching","Hash Function"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wDPL8oM9rO8"
youtube_upload_date="2024-02-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wDPL8oM9rO8/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed string array `words`. You need to determine the number of index pairs `(i, j)` such that `i < j` and the string at index `i` is both a prefix and a suffix of the string at index `j`. The function `isPrefixAndSuffix(str1, str2)` returns true if `str1` is both a prefix and a suffix of `str2`, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `words` of strings.
- **Example:** `words = ["ab", "abab", "abc", "ababc"]`
- **Constraints:**
	- 1 <= words.length <= 50
	- 1 <= words[i].length <= 10
	- words[i] consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the number of valid index pairs `(i, j)` where `i < j` and `isPrefixAndSuffix(words[i], words[j])` is true.
- **Example:** `For the input words = ["ab", "abab", "abc", "ababc"], the output is 1.`
- **Constraints:**
	- Return 0 if no such pairs exist.

{{< dots >}}
### Core Logic 🔍
**Goal:** The function should iterate through all pairs `(i, j)` with `i < j` and check whether the word at index `i` is both a prefix and a suffix of the word at index `j`. If this condition is met, the pair is valid, and the counter should be incremented.

- Iterate through all pairs of indices (i, j) with i < j.
- For each pair, check if the word at index i is a prefix and suffix of the word at index j.
- If both conditions are true, increment the counter.
- Finally, return the count.
{{< dots >}}
### Problem Assumptions ✅
- The input contains only lowercase English letters.
- Each word can be a valid prefix and suffix for another word in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["ab", "abab", "abc", "ababc"]`  \
  **Explanation:** In this case, the only valid pair is i = 0 and j = 1, because 'ab' is a prefix and suffix of 'abab'. The result is 1.

{{< dots >}}
## Approach 🚀
The approach is to iterate through all pairs of indices (i, j) with i < j and check if the string at index i is both a prefix and suffix of the string at index j.

### Initial Thoughts 💭
- Prefix and suffix matching should be checked efficiently.
- We can check if a string is a prefix of another string using substring matching, and similarly for suffix matching.
{{< dots >}}
### Edge Cases 🌐
- If words array is empty, return 0.
- For large inputs, ensure the algorithm performs efficiently.
- If no valid pairs exist, return 0.
- Handle cases with words of varying lengths efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<string> wds;

bool pre(int i, int j) {
    int p = 0, q = 0;
    if(wds[j].size() < wds[i].size()) return false;
    while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
        p++; q++;
    }
    return p == wds[i].size();
}

bool post(int i, int j) {
    int p = wds[i].size() - 1, q = wds[j].size() - 1;
    if(p > q) return false;
    while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
        p--; q--;
    }
    return p == -1;
}    

int countPrefixSuffixPairs(vector<string>& w) {
    wds = w;
    int n = w.size(), cnt = 0;
    
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
        if(pre(i, j) && post(i, j)) cnt++;
    
    return cnt;
    
}
```

This function counts pairs of strings in the input vector `w` where one string is a prefix of another and the other is a suffix of the first string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<string> wds;
	```
	Declares a global vector `wds` to store the input list of strings for processing in the `pre` and `post` functions.

2. **Function Definition**
	```cpp
	bool pre(int i, int j) {
	```
	Defines the helper function `pre` that checks if the string at index `i` is a prefix of the string at index `j`.

3. **Variable Initialization**
	```cpp
	    int p = 0, q = 0;
	```
	Initializes two variables `p` and `q` to iterate over the characters of the strings at indices `i` and `j` respectively.

4. **Size Check**
	```cpp
	    if(wds[j].size() < wds[i].size()) return false;
	```
	Checks if the string at index `j` is smaller than the string at index `i`. If true, returns `false` since the smaller string cannot be a prefix.

5. **Prefix Check Loop**
	```cpp
	    while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
	```
	Begins a loop that compares each character of both strings until either a mismatch is found or the end of one string is reached.

6. **Character Comparison**
	```cpp
	        p++; q++;
	```
	Increments the indices `p` and `q` to move to the next characters in both strings.

7. **Prefix Check Return**
	```cpp
	    return p == wds[i].size();
	```
	Returns `true` if the entire string at index `i` matches the beginning of the string at index `j` (i.e., string `i` is a prefix of string `j`).

8. **Function Definition**
	```cpp
	bool post(int i, int j) {
	```
	Defines the helper function `post` that checks if the string at index `i` is a suffix of the string at index `j`.

9. **Variable Initialization**
	```cpp
	    int p = wds[i].size() - 1, q = wds[j].size() - 1;
	```
	Initializes `p` and `q` to point to the last characters of the strings at indices `i` and `j`, respectively.

10. **Size Check**
	```cpp
	    if(p > q) return false;
	```
	Checks if the string at index `i` is larger than the string at index `j`. If true, returns `false` since the larger string cannot be a suffix.

11. **Suffix Check Loop**
	```cpp
	    while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
	```
	Begins a loop that compares each character of both strings from the end until either a mismatch is found or the beginning of one string is reached.

12. **Character Comparison**
	```cpp
	        p--; q--;
	```
	Decrements the indices `p` and `q` to move to the previous characters in both strings.

13. **Suffix Check Return**
	```cpp
	    return p == -1;
	```
	Returns `true` if the entire string at index `i` matches the end of the string at index `j` (i.e., string `i` is a suffix of string `j`).

14. **Function Definition**
	```cpp
	int countPrefixSuffixPairs(vector<string>& w) {
	```
	Defines the function `countPrefixSuffixPairs` that counts how many pairs of strings in the input vector `w` satisfy the prefix-suffix conditions.

15. **Copy Input List**
	```cpp
	    wds = w;
	```
	Copies the input vector `w` to the global `wds` for further processing.

16. **Variable Initialization**
	```cpp
	    int n = w.size(), cnt = 0;
	```
	Initializes `n` to the size of the input vector `w` and `cnt` to count the valid prefix-suffix pairs.

17. **Nested Loops**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Begins the outer loop to iterate over each string `i` in the input vector `w`.

18. **Inner Loop**
	```cpp
	    for(int j = i + 1; j < n; j++)
	```
	Begins the inner loop to iterate over each string `j` that comes after string `i` in the input vector `w`.

19. **Check Prefix-Suffix Pair**
	```cpp
	        if(pre(i, j) && post(i, j)) cnt++;
	```
	Checks if the strings `i` and `j` form a valid prefix-suffix pair. If true, increments the count `cnt`.

20. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the final count of valid prefix-suffix pairs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2 * m), where n is the number of words and m is the maximum length of a word.
- **Average Case:** O(n^2 * m).
- **Worst Case:** O(n^2 * m), where n is the number of words and m is the maximum length of a word.

We check all pairs of words and compare their prefixes and suffixes.

### Space Complexity 💾
- **Best Case:** O(1), as no extra space is required.
- **Worst Case:** O(n), where n is the number of words, for storing the array.

Space complexity is mainly determined by the space needed to store the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/)

---
{{< youtube wDPL8oM9rO8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
