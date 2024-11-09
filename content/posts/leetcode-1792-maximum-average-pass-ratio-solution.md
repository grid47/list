
+++
authors = ["grid47"]
title = "Leetcode 1792: Maximum Average Pass Ratio"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1792: Maximum Average Pass Ratio in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-average-pass-ratio/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [&](double pass, double total) {
            return (pass + 1)/(total +1) -(pass/ total);
        };

        double total = 0;
        priority_queue<pair<double, array<int, 2>>> pq;
        for(auto &c: classes) {
            total += (double) c[0]/c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }

        while(extraStudents--) {
            auto [addedProfit, c] = pq.top(); pq.pop();
            total += addedProfit;
            pq.push({profit(c[0] + 1, c[1] + 1), {c[0] +1, c[1] +1}});
        }
        return total/ classes.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1792.md" >}}
---
{{< youtube ZjydWQCVg80 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1793: Maximum Score of a Good Subarray](https://grid47.xyz/posts/leetcode-1792-maximum-average-pass-ratio-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
