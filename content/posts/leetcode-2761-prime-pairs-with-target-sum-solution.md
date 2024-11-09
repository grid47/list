
+++
authors = ["grid47"]
title = "Leetcode 2761: Prime Pairs With Target Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2761: Prime Pairs With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Enumeration","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/prime-pairs-with-target-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    vector<vector<int>> findPrimePairs(int n) {

        vector<int> net(n + 1, true);
        net[1] = false;
        for(int i = 2; i < n / 2 + 1; i++)
        for(int j = 2; j * i < n; j++)
            net[j * i] = false;

        map<int, int> mp;
        vector<vector<int>> res;

        for(int i = 1; i < n / 2 + 1; i++)
            if(net[i] && net[n - i]) 
            res.push_back({i, n - i});

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2761.md" >}}
---
{{< youtube rEM1dS0cKFc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2762: Continuous Subarrays](https://grid47.xyz/posts/leetcode-2761-prime-pairs-with-target-sum-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
