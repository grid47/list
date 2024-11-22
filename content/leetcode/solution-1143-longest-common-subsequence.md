
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The Longest Common Subsequence (LCS) problem involves finding the longest subsequence present in two given sequences (strings) that appears in both of them in the same order, but not necessarily consecutively. This problem is common in various fields, such as bioinformatics, version control, and text comparison.

**For example:**
Given two strings:
- `t1 = "abcde"`
- `t2 = "ace"`

The longest common subsequence is `"ace"`, which has a length of `3`.

### Approach
The solution uses a dynamic programming approach to construct a 2D table (`dp`) that stores the lengths of LCS for substrings of `t1` and `t2`. The key steps of the approach are:

1. **DP Table Initialization**: A 2D vector `dp` of size `(n1 + 1) x (n2 + 1)` is created, initialized with zeros. The extra row and column account for the base case where one of the strings is empty.

2. **Filling the DP Table**: The algorithm iterates through each character of both strings. If the characters match, the value in the table is updated to reflect the longest subsequence found so far. If they do not match, the algorithm takes the maximum length from either ignoring the current character of `t1` or `t2`.

3. **Returning the Result**: The value in `dp[n1][n2]` will hold the length of the longest common subsequence of the two strings.

### Code Breakdown (Step by Step)
Here’s a detailed breakdown of the code:

```cpp
class Solution {
public:
```
- **Line 1-2**: A class named `Solution` is defined, marking the beginning of the implementation.

```cpp
    int longestCommonSubsequence(string t1, string t2) {
```
- **Line 3**: The member function `longestCommonSubsequence` is defined, taking two strings `t1` and `t2` as input parameters.

```cpp
        int n1 = t1.size(), n2 = t2.size();
```
- **Line 4**: The lengths of the two strings are stored in `n1` and `n2`.

```cpp
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
```
- **Line 5**: A 2D vector `dp` is initialized with dimensions `(n1 + 1) x (n2 + 1)` and all elements set to `0`. This vector will hold the lengths of the longest common subsequences.

```cpp
        for(int i = 0; i < n1; i++)
            for(int j = 0; j < n2; j++)
```
- **Line 6-7**: Two nested loops are initiated to iterate through each character of the two strings, represented by indices `i` for `t1` and `j` for `t2`.

```cpp
                if(t1[i] == t2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
```
- **Line 8-9**: This condition checks if the current characters of `t1` and `t2` are equal. If they are, the current cell `dp[i + 1][j + 1]` is updated to be `1` plus the value from the diagonal cell `dp[i][j]`, indicating that the LCS has increased by one.

```cpp
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
```
- **Line 10-11**: If the characters are not equal, the current cell `dp[i + 1][j + 1]` is set to the maximum of the values from the cell directly above (`dp[i][j + 1]`) and the cell to the left (`dp[i + 1][j]`). This step effectively chooses the longer subsequence from either string up to the current point.

```cpp
        return dp[n1][n2];
    }
};
```
- **Line 12-14**: After filling the DP table, the length of the longest common subsequence, which is found at `dp[n1][n2]`, is returned as the final result. The class definition is closed.

### Complexity
- **Time Complexity**: The time complexity of this algorithm is \( O(n1 \times n2) \), where \( n1 \) and \( n2 \) are the lengths of the two strings. This is due to the nested loops iterating over each character of both strings.
  
- **Space Complexity**: The space complexity is also \( O(n1 \times n2) \) because of the storage required for the DP table. However, it can be optimized to \( O(\min(n1, n2)) \) if only two rows are kept in memory.

### Conclusion
The provided C++ solution efficiently computes the longest common subsequence of two strings using dynamic programming. By systematically building up the solution using previously computed results in a 2D table, the algorithm ensures optimal performance even for larger strings. This approach is widely applicable in various fields requiring string comparison, such as text processing, data comparison, and bioinformatics.


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-common-subsequence/description/)

---
{{< youtube MNykgz1_ONQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
