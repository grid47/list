
+++
authors = ["Yasir"]
title = "Leetcode 826: Most Profit Assigning Work"
date = "2022-07-24"
description = "Solution to Leetcode 826"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-profit-assigning-work/description/)

---

**Code:**

{{< highlight html >}}
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

