
+++
authors = ["grid47"]
title = "Leetcode 826: Most Profit Assigning Work"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 826: Most Profit Assigning Work in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #831: Masking Personal Information](https://grid47.xyz/leetcode/solution-831-masking-personal-information/) |
| --- |
