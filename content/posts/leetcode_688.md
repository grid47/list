
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 688: Knight Probability in Chessboard"
date = "2022-12-12"
description = "Solution to Leetcode 688"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/knight-probability-in-chessboard/description/)

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

