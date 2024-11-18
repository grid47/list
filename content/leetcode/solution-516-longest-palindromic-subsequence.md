
+++
authors = ["grid47"]
title = "Leetcode 516: Longest Palindromic Subsequence"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 516: Longest Palindromic Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "v6Ous7ofbMs"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/516.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindromic-subsequence/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/516.webp" 
    alt="A string where the longest palindromic subsequence is highlighted, glowing as it mirrors itself."
    caption="Solution to LeetCode 516: Longest Palindromic Subsequence Problem"
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
    string str;
    vector<vector<int>> memo;
    int dp(int i, int j) {
        if(i == j) return 1;
        if(i == j - 1) return str[i] == str[j]? 2: 1;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int ans = 0;
        if(str[i] == str[j]) {
            ans = 2 + dp(i + 1, j - 1);
        } else {
            ans = max(dp(i + 1, j), dp(i, j - 1));
        }
        return memo[i][j] = ans;
    }
    
    int longestPalindromeSubseq(string s) {
        str = s;
        int n = s.size();
        memo.resize(n, vector<int>(n, -1));
        return dp(0, n - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/516.md" >}}
---
{{< youtube v6Ous7ofbMs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #518: Coin Change II](https://grid47.xyz/leetcode/solution-518-coin-change-ii/) |
| --- |
