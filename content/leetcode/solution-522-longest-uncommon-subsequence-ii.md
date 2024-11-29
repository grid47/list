
+++
authors = ["grid47"]
title = "Leetcode 522: Longest Uncommon Subsequence II"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 522: Longest Uncommon Subsequence II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/522.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/522.webp" 
    alt="Two strings where the longest uncommon subsequence is searched, and each valid subsequence glows softly."
    caption="Solution to LeetCode 522: Longest Uncommon Subsequence II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of strings strs, determine the length of the longest uncommon subsequence between them. An uncommon subsequence is a string that is a subsequence of one string but not the others. If no such subsequence exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings strs, where each string contains only lowercase English letters.
- **Example:** `strs = ['hello', 'world', 'wonder']`
- **Constraints:**
	- 2 <= strs.length <= 50
	- 1 <= strs[i].length <= 10
	- Each string consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest uncommon subsequence. If no uncommon subsequence exists, return -1.
- **Example:** `6, -1`
- **Constraints:**
	- The output should be an integer indicating the length of the longest uncommon subsequence.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the longest subsequence that is unique to one string in the array, and not a subsequence of any other string.

- 1. Iterate through each string in the array and check if it is a subsequence of any other string in the array.
- 2. If a string is not a subsequence of any other string, update the result with its length.
- 3. Return the length of the longest uncommon subsequence or -1 if none exist.
{{< dots >}}
### Problem Assumptions ✅
- The input will always consist of valid strings containing only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `strs = ['hello', 'world', 'wonder']`  \
  **Explanation:** In this case, 'wonder' is the longest uncommon subsequence as it is not a subsequence of any other string.

- **Input:** `strs = ['aaa', 'aaa', 'aa']`  \
  **Explanation:** There is no uncommon subsequence as all strings share subsequences of each other.

{{< dots >}}
## Approach 🚀
The approach involves comparing each string with others to find the longest string that does not appear as a subsequence of any other string.

### Initial Thoughts 💭
- We need to determine the longest uncommon subsequence by comparing each string with others.
- A brute force approach can be used to check subsequences, but optimizations can be considered for larger inputs.
{{< dots >}}
### Edge Cases 🌐
- An empty string array should return -1.
- The algorithm should be optimized to handle input arrays with 50 strings efficiently.
- Identical strings in the input will never produce an uncommon subsequence.
- The time complexity should be efficient for input sizes of up to 50 strings, each up to 10 characters long.
{{< dots >}}
## Code 💻
```cpp
int findLUSlength(vector<string>& strs) {
    if(strs.empty()) return -1;
    int rst = -1;
    for(auto i = 0; i < strs.size(); i++) {
        int j = 0;
        for(; j < strs.size(); j++) {
            if( i == j ) continue;
            if(LCS(strs[i], strs[j])) break;
        }
        if (j == strs.size())
        rst = max(rst, static_cast<int>(strs[i].size()));
    }
    return rst;
}

bool LCS(const string& a, const string& b) {
    if(b.size() < a.size()) return false;

    int i = 0;
    for(auto ch : b)
    if (i < a.size() && a[i] == ch) i++;

    return i == a.size();
}
```

This solution finds the length of the longest uncommon subsequence (LUS) among a list of strings. It uses the helper function LCS to check whether one string is a subsequence of another.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findLUSlength(vector<string>& strs) {
	```
	Defines the function `findLUSlength`, which takes a vector of strings and returns the length of the longest uncommon subsequence.

2. **Edge Case Handling**
	```cpp
	    if(strs.empty()) return -1;
	```
	Handles the edge case where the input list of strings is empty, returning -1 as there is no subsequence.

3. **Variable Initialization**
	```cpp
	    int rst = -1;
	```
	Initializes the result variable `rst` to -1, which will store the length of the longest uncommon subsequence.

4. **Outer Loop**
	```cpp
	    for(auto i = 0; i < strs.size(); i++) {
	```
	Iterates through each string in the `strs` vector to check against all other strings.

5. **Variable Initialization**
	```cpp
	        int j = 0;
	```
	Initializes a variable `j` that will be used in the inner loop to compare the current string with all other strings.

6. **Inner Loop**
	```cpp
	        for(; j < strs.size(); j++) {
	```
	Starts an inner loop that compares the current string `strs[i]` with each other string `strs[j]`.

7. **Skipping Same String**
	```cpp
	            if( i == j ) continue;
	```
	Skips comparison when the current string is being compared with itself.

8. **LCS Check**
	```cpp
	            if(LCS(strs[i], strs[j])) break;
	```
	Checks if `strs[i]` is a subsequence of `strs[j]` using the helper function `LCS`. If it is, breaks out of the loop.

9. **Condition to Update Result**
	```cpp
	        if (j == strs.size())
	```
	Checks if the inner loop completed without finding a common subsequence, meaning the string `strs[i]` is unique.

10. **Update Result**
	```cpp
	        rst = max(rst, static_cast<int>(strs[i].size()));
	```
	Updates the result variable `rst` to store the maximum length of the longest uncommon subsequence.

11. **Return Statement**
	```cpp
	    return rst;
	```
	Returns the length of the longest uncommon subsequence found.

12. **Helper Function Definition**
	```cpp
	bool LCS(const string& a, const string& b) {
	```
	Defines the helper function `LCS`, which checks if string `a` is a subsequence of string `b`.

13. **Subsequence Check**
	```cpp
	    if(b.size() < a.size()) return false;
	```
	Checks if string `b` is shorter than string `a`. If so, it cannot be a subsequence of `a`, so return false.

14. **Loop Through String b**
	```cpp
	    int i = 0;
	```
	Initializes a variable `i` to track the position in string `a`.

15. **Character Matching**
	```cpp
	    for(auto ch : b)
	```
	Iterates through each character `ch` in string `b`.

16. **Update Index i**
	```cpp
	    if (i < a.size() && a[i] == ch) i++;
	```
	If the current character `ch` in `b` matches the character at index `i` in `a`, increment `i`.

17. **Return Statement**
	```cpp
	    return i == a.size();
	```
	If the entire string `a` is matched in `b`, return true, indicating `a` is a subsequence of `b`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2 * m) where n is the number of strings and m is the average string length.
- **Average Case:** O(n^2 * m) where n is the number of strings and m is the average string length.
- **Worst Case:** O(n^2 * m) where n is the number of strings and m is the average string length.

In the worst case, we compare each string with every other string, resulting in a quadratic time complexity.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required for input.
- **Worst Case:** O(n * m), where n is the number of strings and m is the length of each string.

The space complexity is linear relative to the number of strings and their lengths.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
