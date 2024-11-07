
+++
authors = ["Crafted by Me"]
title = "Leetcode 2944: Minimum Number of Coins for Fruits"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2944: Minimum Number of Coins for Fruits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Queue","Heap (Priority Queue)","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCoins(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && (q.front() + 1) * 2 < i + 1)
                q.pop_front();
            while (!q.empty() && dp[q.back()] + A[q.back()] >= dp[i] + A[i])
                q.pop_back();
            q.push_back(i);
            dp[i + 1] = dp[q.front()] + A[q.front()];
        }
        return dp[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2944.md" >}}
---
{{< youtube _Zt6ADHF8nE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2946: Matrix Similarity After Cyclic Shifts](https://grid47.xyz/posts/leetcode_2946) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
