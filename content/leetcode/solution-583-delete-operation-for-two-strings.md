
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement:

The problem at hand is to compute the minimum number of operations required to convert one string, `word1`, into another string, `word2`. The allowed operations are:
1. Insert a character.
2. Delete a character.
3. Replace a character.

This is a classical problem known as **edit distance** or **Levenshtein distance**. The task is to find the minimum number of such operations to transform `word1` into `word2`.

### Approach:

To solve this problem efficiently, we use **Dynamic Programming (DP)**. Specifically, the idea is to break the problem down into smaller subproblems, where each subproblem is a pair of substrings of `word1` and `word2`.

The minimum number of operations required to convert a substring of `word1` to a substring of `word2` can be calculated based on three main choices:
- **Insertion**: Add a character to `word1`.
- **Deletion**: Remove a character from `word1`.
- **Substitution**: Replace a character in `word1` to match `word2`.

In this solution, we use a technique called **Longest Common Subsequence (LCS)**. The LCS of two strings is the longest sequence that appears in both strings in the same order. The idea is that the minimum number of operations can be determined by considering how much of the two strings are common. Once we know the LCS, the remaining operations are determined by the characters not part of the LCS.

### Code Breakdown (Step by Step):

#### Step 1: Initialize DP Table
```cpp
int m = word1.size(), n = word2.size();
vector<vector<int>> dp(m + 1, vector<int>(n + 1));
```
- The lengths of the two strings `word1` and `word2` are stored in `m` and `n`, respectively.
- We then initialize a 2D DP table `dp` of size `(m + 1) x (n + 1)` where each cell `dp[i][j]` represents the length of the LCS of the substrings `word1[0...i-1]` and `word2[0...j-1]`.

#### Step 2: Fill DP Table
```cpp
for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j] + 1;
        else dp[i+1][j+1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
```
- The nested loops iterate through all pairs of characters from `word1` and `word2`.
- If the characters `word1[i]` and `word2[j]` are equal, we increment the LCS value at `dp[i+1][j+1]` by 1 from the diagonal value `dp[i][j]` because this character contributes to the common subsequence.
- If the characters are not equal, we take the maximum of the values from the cell above (`dp[i][j+1]`) or the cell to the left (`dp[i+1][j]`). This is because we either delete a character from `word1` or insert a character into `word1` to make the substrings equal.

#### Step 3: Calculate the Minimum Edit Distance
```cpp
return word1.size() + word2.size() - 2 * dp[m][n];
```
- After the DP table is filled, the value `dp[m][n]` represents the length of the Longest Common Subsequence (LCS) of `word1` and `word2`.
- The minimum number of operations is calculated by subtracting twice the LCS length from the total length of both strings. This is because each unmatched character in `word1` and `word2` must either be deleted or inserted to match the other string.
- Specifically, the formula is:
  \[
  \text{Minimum Edit Distance} = \text{len(word1)} + \text{len(word2)} - 2 \times \text{LCS length}
  \]
  
  This formula works because the characters that are part of the LCS don't need any operations; they remain in both strings. The remaining characters (those not in the LCS) require insertions or deletions.

### Complexity:

#### Time Complexity:
- **O(m * n)**: The algorithm uses a DP table of size `(m + 1) x (n + 1)` where `m` and `n` are the lengths of `word1` and `word2`, respectively. Filling each cell in the DP table takes constant time, so the overall time complexity is O(m * n).

#### Space Complexity:
- **O(m * n)**: The space complexity is also O(m * n) because we need to store the DP table with dimensions `(m + 1) x (n + 1)`.

### Conclusion:

This solution provides an efficient way to calculate the minimum number of operations needed to transform one string into another using the edit distance concept, particularly focusing on the relationship with the **Longest Common Subsequence (LCS)**. 

By utilizing Dynamic Programming, we efficiently compute the solution in O(m * n) time and space. This approach is optimal and scales well for typical string sizes, making it suitable for a wide range of input cases.

Overall, the solution is both time-efficient and space-efficient, offering a clear path to solving the edit distance problem with great accuracy. By breaking down the problem into subproblems of LCS, we can ensure that the solution is robust and handles various edge cases effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-operation-for-two-strings/description/)

---
{{< youtube tpALbrFWg5U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
