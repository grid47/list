
+++
authors = ["grid47"]
title = "Leetcode 688: Knight Probability in Chessboard"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 688: Knight Probability in Chessboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/knight-probability-in-chessboard/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/688.webp" 
    alt="A chessboard where the knight’s possible moves are calculated, with the highest probability glowing softly."
    caption="Solution to LeetCode 688: Knight Probability in Chessboard Problem"
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
    int n;
    vector<vector<vector<double>>> memo;
    double knightProbability(int n, int k, int row, int col) {
        this->n = n;
        memo.resize(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
        return dfs(k, row, col);
    }
    
    double dfs(int k, int i, int j) {

        if(i < 0 || j < 0 || i >= n || j >= n) return 0;
        if(k == 0) return 1;
        if(memo[k][i][j] != 0 ) return memo[k][i][j];

        double res = 0;

        res += 0.125 * dfs(k - 1, i + 1, j - 2);
        res += 0.125 * dfs(k - 1, i + 1, j + 2);
        res += 0.125 * dfs(k - 1, i + 2, j + 1);
        res += 0.125 * dfs(k - 1, i + 2, j - 1);
        res += 0.125 * dfs(k - 1, i - 1, j + 2);
        res += 0.125 * dfs(k - 1, i - 1, j - 2);
        res += 0.125 * dfs(k - 1, i - 2, j + 1);
        res += 0.125 * dfs(k - 1, i - 2, j - 1);

        return memo[k][i][j] = res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/688.md" >}}
---
{{< youtube hNovJsUbNjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #692: Top K Frequent Words](https://grid47.xyz/leetcode/solution-692-top-k-frequent-words/) |
| --- |
