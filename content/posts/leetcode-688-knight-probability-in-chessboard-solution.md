
+++
authors = ["grid47"]
title = "Leetcode 688: Knight Probability in Chessboard"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 688: Knight Probability in Chessboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
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
---
{{< youtube hNovJsUbNjo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #689: Maximum Sum of 3 Non-Overlapping Subarrays](https://grid47.xyz/posts/leetcode-689-maximum-sum-of-3-non-overlapping-subarrays-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
