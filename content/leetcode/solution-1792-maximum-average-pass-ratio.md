
+++
authors = ["grid47"]
title = "Leetcode 1792: Maximum Average Pass Ratio"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1792: Maximum Average Pass Ratio in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZjydWQCVg80"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi/ZjydWQCVg80/maxresdefault.jpg"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1796: Second Largest Digit in a String](https://grid47.xyz/leetcode/solution-1796-second-largest-digit-in-a-string/) |
| --- |