
+++
authors = ["grid47"]
title = "Leetcode 1575: Count All Possible Routes"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1575: Count All Possible Routes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Memoization"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-all-possible-routes/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int n, mod = (int) 1e9 + 7;
    vector<vector<int>> mem;
    vector<int> loc;
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        n = loc.size();
        this->loc = loc;
        mem.resize(n, vector<int>(fuel + 1, -1));
        return dfs(start, finish, fuel);
    }
    
    int dfs(int st, int ed, int rm) {
        if(rm < 0) return 0;

        if(mem[st][rm] != -1) return mem[st][rm];

        long ans = (st == ed);
        for(int i = 0; i < n ; i++) {
            if(i != st)
            ans = (ans + dfs(i, ed, rm - abs(loc[i] - loc[st]))) % mod;
        }

        return mem[st][rm] = ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1575.md" >}}
---
{{< youtube Uu3gRJu46MQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers](https://grid47.xyz/posts/leetcode-1577-number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
