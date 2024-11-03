
+++
authors = ["Crafted by Me"]
title = "Leetcode 1473: Paint House III"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1473: Paint House III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/paint-house-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int m, n;
    vector<vector<int>> cost;
    vector<int> houses;
    vector<vector<vector<int>>> mem;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        this->m = m;
        this->n = n;
        this->houses = houses;
        this->cost = cost;

        mem.resize(m + 1, vector<vector<int>>(n + 3, vector<int>(m + 1, -1)));
        int ans = dp(0, -1, target);

        return ans >= INT_MAX? -1: ans;
    }

    long dp(int idx, int prv, int tgt) {

        if(idx == m && tgt == 0) return 0;
        if(tgt < 0 || idx == m) return INT_MAX;

        if(mem[idx][prv + 1][tgt] != -1) return mem[idx][prv + 1][tgt];
        
        long res = INT_MAX;
        if(houses[idx] != 0) {
            if(prv != houses[idx])
            res = min(res, dp(idx + 1, houses[idx], tgt - 1));
            else
            res = min(res, dp(idx + 1, prv, tgt));
        } else {
            for(int i = 1; i <= n; i++) {
                if(prv != i)
                res = min(res, cost[idx][i - 1] + dp(idx + 1, i, tgt - 1));
                else
                res = min(res, cost[idx][i - 1] + dp(idx + 1, i, tgt));
            }
        }

        return mem[idx][prv + 1][tgt] = res;
    }


};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1473.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1474: Delete N Nodes After M Nodes of a Linked List](https://grid47.xyz/posts/leetcode_1474) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

