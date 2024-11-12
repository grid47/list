
+++
authors = ["grid47"]
title = "Leetcode 935: Knight Dialer"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 935: Knight Dialer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/knight-dialer/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int knightDialer(int n) {
        long long res = 0;
        vector<vector<long long>> arr(4, vector<long long>(3, -1));
        vector<vector<vector<long long>>> mem(n + 1, arr);

        for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        {
            res = (res + path(i, j, n, mem))% mod;
        }
        return res;
    }

long long path(int i, int j, int n, vector<vector<vector<long long>>> &mem) {
        
        if(i < 0 || j < 0|| i >= 4 || j >= 3 || (i==3 && j !=1))
            return 0;

        if(mem[n][i][j] != -1) return mem[n][i][j] % mod;

        if (n == 1) return 1;

        mem[n][i][j] = path(i -1 , j -2, n - 1, mem) % mod +
                  path(i -1 , j +2, n - 1, mem) % mod +
                  path(i -2 , j -1, n - 1, mem) % mod +
                  path(i -2 , j +1, n - 1, mem) % mod +
                  path(i +1 , j -2, n - 1, mem) % mod +
                  path(i +1 , j +2, n - 1, mem) % mod +
                  path(i +2 , j -1, n - 1, mem) % mod +
                  path(i +2 , j +1, n - 1, mem) % mod;
        return mem[n][i][j];
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/935.md" >}}
---
{{< youtube vlsUUm_qqsY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #938: Range Sum of BST](https://grid47.xyz/posts/leetcode-938-range-sum-of-bst-solution/) |
| --- |
