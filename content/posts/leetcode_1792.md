
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1792: Maximum Average Pass Ratio"
date = "2019-12-03"
description = "Solution to Leetcode 1792"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

