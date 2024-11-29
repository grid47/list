
+++
authors = ["grid47"]
title = "Leetcode 583: Delete Operation for Two Strings"
date = "2024-09-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 583: Delete Operation for Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/583.webp"
youtube = "tpALbrFWg5U"
youtube_upload_date="2021-05-07"
youtube_thumbnail="https://i.ytimg.com/vi/tpALbrFWg5U/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/583.webp" 
    alt="Two strings where characters are deleted, with each deletion softly glowing as it happens."
    caption="Solution to LeetCode 583: Delete Operation for Two Strings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same. In one step, you can delete exactly one character in either string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two strings, word1 and word2, which consist of only lowercase English letters.
- **Example:** `Input: word1 = "fish", word2 = "dish"`
- **Constraints:**
	- 1 <= word1.length, word2.length <= 500
	- word1 and word2 consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The minimum number of steps (deletions) needed to make word1 and word2 the same.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the number of deletions required to make both strings identical.

- Use dynamic programming to calculate the length of the longest common subsequence (LCS) of the two strings.
- The minimum deletions required is the total length of both strings minus twice the length of the LCS.
{{< dots >}}
### Problem Assumptions ✅
- Both strings are non-empty.
- The strings only contain lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: word1 = "fish", word2 = "dish"`  \
  **Explanation:** You need to delete one 'f' from word1 and one 'd' from word2 to make them the same.

- **Input:** `Input: word1 = "chat", word2 = "mat"`  \
  **Explanation:** You need to delete one 'c' from word1 and one 'm' from word2 to make them the same.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming to find the longest common subsequence (LCS) between the two strings.

### Initial Thoughts 💭
- The LCS will give us the longest sequence that both strings share.
- By deleting the characters not in the LCS, we can make both strings identical.
- We need to calculate the LCS and then determine how many characters need to be deleted from both strings.
{{< dots >}}
### Edge Cases 🌐
- Both strings are guaranteed to be non-empty, so no need to handle empty strings.
- The input size can go up to 500 characters, so the solution must be efficient.
- If both strings are already identical, return 0.
- The solution must have a time complexity of O(m*n), where m and n are the lengths of the two strings.
{{< dots >}}
## Code 💻
```cpp
int minDistance(string word1, string word2) {
    // lcs
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j] + 1;
        else dp[i+1][j+1] = max(dp[i][j + 1], dp[i + 1][j]);
    }

    return word1.size() + word2.size() - 2 * dp[m][n];
}
```

This function calculates the minimum number of operations required to convert `word1` into `word2`. It uses dynamic programming and relies on finding the longest common subsequence (LCS) between the two words to compute the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minDistance(string word1, string word2) {
	```
	Declares the function `minDistance`, which takes two strings as input and returns the minimum number of operations required to convert one string into the other.

2. **Variable Initialization**
	```cpp
	    int m = word1.size(), n = word2.size();
	```
	Initializes the variables `m` and `n`, which store the lengths of `word1` and `word2`, respectively.

3. **Matrix Initialization**
	```cpp
	    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	```
	Initializes a 2D dynamic programming table `dp` with dimensions `(m+1) x (n+1)`, where each cell `dp[i][j]` will hold the length of the longest common subsequence (LCS) for substrings `word1[0..i-1]` and `word2[0..j-1]`.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Starts an outer loop that iterates over each character of `word1`.

5. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Starts an inner loop that iterates over each character of `word2`.

6. **LCS Condition Check**
	```cpp
	        if(word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j] + 1;
	```
	If the characters at `word1[i]` and `word2[j]` match, it increments the LCS length by 1 and stores the result in `dp[i+1][j+1]`.

7. **LCS Update on Mismatch**
	```cpp
	        else dp[i+1][j+1] = max(dp[i][j + 1], dp[i + 1][j]);
	```
	If the characters at `word1[i]` and `word2[j]` do not match, it updates `dp[i+1][j+1]` by taking the maximum value between `dp[i][j+1]` (LCS without the current character of `word1`) and `dp[i+1][j]` (LCS without the current character of `word2`).

8. **Final Calculation**
	```cpp
	    return word1.size() + word2.size() - 2 * dp[m][n];
	```
	Returns the minimum number of operations needed to convert `word1` into `word2`. This is calculated by subtracting twice the length of the LCS (found in `dp[m][n]`) from the total lengths of `word1` and `word2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m*n)
- **Average Case:** O(m*n)
- **Worst Case:** O(m*n)

We use dynamic programming to calculate the LCS, which requires O(m*n) time where m and n are the lengths of the two strings.

### Space Complexity 💾
- **Best Case:** O(m*n)
- **Worst Case:** O(m*n)

The space complexity is O(m*n) due to the DP table.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-operation-for-two-strings/description/)

---
{{< youtube tpALbrFWg5U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
