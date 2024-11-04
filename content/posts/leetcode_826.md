
+++
authors = ["Crafted by Me"]
title = "Leetcode 826: Most Profit Assigning Work"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 826: Most Profit Assigning Work in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-profit-assigning-work/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // zip difficulty and profit of jobs
        int N = profit.size(), res = 0, i = 0;
        
        vector<pair<int, int>> jobs;
        for(int i = 0; i < N; i++)
            jobs.push_back(make_pair(difficulty[i], profit[i]));
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int best =  0;
        for(int eff: worker) {
            while(i < N && eff >= jobs[i].first) {
                best = max(best, jobs[i++].second);
            }
            res += best;
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/826.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #827: Making A Large Island](https://grid47.xyz/posts/leetcode_827) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

