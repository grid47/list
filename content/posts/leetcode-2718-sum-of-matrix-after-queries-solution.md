
+++
authors = ["grid47"]
title = "Leetcode 2718: Sum of Matrix After Queries"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2718: Sum of Matrix After Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-matrix-after-queries/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long res = 0;

        int seen[2][10001] = {};
        int cnt[2] = {n, n};

        for(int i = q.size() - 1; i >= 0; i--) {
            
            int type = q[i][0], id = q[i][1], val = q[i][2];
            
            if(!seen[type][id]) {
                seen[type][id] = 1;
                res += val * cnt[!type];
                --cnt[type];
            }
            
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2718.md" >}}
---
{{< youtube GgRr0TbbsO0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2719: Count of Integers](https://grid47.xyz/posts/leetcode-2719-count-of-integers-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}