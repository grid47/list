
+++
authors = ["grid47"]
title = "Leetcode 935: Knight Dialer"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #936: Stamping The Sequence](https://grid47.xyz/posts/leetcode-935-knight-dialer-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
