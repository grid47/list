
+++
authors = ["grid47"]
title = "Leetcode 1143: Longest Common Subsequence"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1143: Longest Common Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MNykgz1_ONQ"
youtube_upload_date="2024-06-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MNykgz1_ONQ/maxresdefault.webp"
comments = true
+++



---
Given two strings text1 and text2, return the length of their longest common subsequence. A subsequence is a sequence that can be derived from the string by deleting some characters without changing the order of the remaining characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings text1 and text2. The characters in each string are lowercase English letters.
- **Example:** `Input: text1 = 'apple', text2 = 'applause'`
- **Constraints:**
	- 1 <= text1.length, text2.length <= 1000
	- text1 and text2 consist of only lowercase English characters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest common subsequence between text1 and text2.
- **Example:** `Output: 5`
- **Constraints:**
	- The output will be a single integer representing the length of the longest common subsequence.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the length of the longest common subsequence by comparing characters of both strings and using dynamic programming to store the results of overlapping subproblems.

- 1. Create a 2D DP table to store the lengths of longest common subsequences for different substrings.
- 2. Iterate through both strings. If characters match, add 1 to the value of the previous common subsequence.
- 3. If characters do not match, take the maximum length from either of the previous two subsequences.
- 4. The final value in the DP table will be the length of the longest common subsequence.
{{< dots >}}
### Problem Assumptions ✅
- Both text1 and text2 will consist only of lowercase English characters.
- The length of both text1 and text2 will be between 1 and 1000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: text1 = 'apple', text2 = 'applause'`  \
  **Explanation:** In this example, the longest common subsequence between 'apple' and 'applause' is 'apple', which has a length of 5.

- **Input:** `Input: text1 = 'happy', text2 = 'sad'`  \
  **Explanation:** In this example, the longest common subsequence between 'happy' and 'sad' is 'a', which has a length of 1.

- **Input:** `Input: text1 = 'cat', text2 = 'dog'`  \
  **Explanation:** In this example, there is no common subsequence between 'cat' and 'dog', so the result is 0.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming to calculate the longest common subsequence by comparing characters and storing results for overlapping subproblems.

### Initial Thoughts 💭
- The problem can be efficiently solved using dynamic programming with a 2D table.
- The key observation is that we need to store intermediate results to avoid redundant calculations, which makes dynamic programming a good choice.
{{< dots >}}
### Edge Cases 🌐
- The case where one of the strings is empty should be handled by returning 0.
- The algorithm must be optimized to handle large inputs efficiently (up to 1000 characters).
- The case where both strings are the same should return the length of the string.
- Ensure that the DP table is initialized correctly and that the algorithm runs within the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
int longestCommonSubsequence(string t1, string t2) {
    int n1 = t1.size(), n2 = t2.size();
    vector<vector<int>> dp(n1 +1, vector<int>(n2+1, 0));
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n2; j++)
            if(t1[i] == t2[j])
                dp[i+1][j+1] = dp[i][j] +1;
    else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    
    return dp[n1][n2];
}
```

This function computes the length of the longest common subsequence (LCS) between two strings `t1` and `t2`. It uses dynamic programming to fill a 2D table `dp` where each cell `dp[i][j]` represents the length of the LCS of the substrings `t1[0...i-1]` and `t2[0...j-1]`. The function returns `dp[n1][n2]`, which holds the length of the LCS of the entire strings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestCommonSubsequence(string t1, string t2) {
	```
	This defines the function `longestCommonSubsequence`, which takes two input strings `t1` and `t2` and returns the length of their longest common subsequence.

2. **Variable Declaration**
	```cpp
	    int n1 = t1.size(), n2 = t2.size();
	```
	This declares two integer variables `n1` and `n2`, which store the lengths of the input strings `t1` and `t2` respectively.

3. **Matrix Initialization**
	```cpp
	    vector<vector<int>> dp(n1 +1, vector<int>(n2+1, 0));
	```
	This initializes a 2D vector `dp` of size `(n1+1) x (n2+1)`, where each element is initialized to 0. This matrix will be used to store the length of the longest common subsequence for substrings of `t1` and `t2`.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n1; i++)
	```
	This begins a loop that iterates over each character of the first string `t1`.

5. **Inner Loop**
	```cpp
	        for(int j = 0; j < n2; j++)
	```
	This begins an inner loop that iterates over each character of the second string `t2`.

6. **Condition Check**
	```cpp
	            if(t1[i] == t2[j])
	```
	This checks if the characters `t1[i]` and `t2[j]` are equal.

7. **Dynamic Programming Update**
	```cpp
	                dp[i+1][j+1] = dp[i][j] +1;
	```
	If the characters are equal, this updates the value of `dp[i+1][j+1]` to `dp[i][j] + 1`, meaning that the LCS length for this pair of substrings is extended by 1.

8. **Else Condition**
	```cpp
	    else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
	```
	If the characters are not equal, this sets `dp[i+1][j+1]` to the maximum of `dp[i][j+1]` and `dp[i+1][j]`, representing the longest subsequence found by excluding either the current character of `t1` or `t2`.

9. **Return Statement**
	```cpp
	    return dp[n1][n2];
	```
	This returns the value stored in `dp[n1][n2]`, which holds the length of the longest common subsequence of the entire strings `t1` and `t2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

The time complexity is O(n * m) where n is the length of text1 and m is the length of text2.

### Space Complexity 💾
- **Best Case:** O(n * m)
- **Worst Case:** O(n * m)

The space complexity is O(n * m) due to the DP table storing intermediate results for all substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-common-subsequence/description/)

---
{{< youtube MNykgz1_ONQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
