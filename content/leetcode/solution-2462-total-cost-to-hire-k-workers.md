
+++
authors = ["grid47"]
title = "Leetcode 2462: Total Cost to Hire K Workers"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2462: Total Cost to Hire K Workers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Heap (Priority Queue)","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/total-cost-to-hire-k-workers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        long long cost = 0;
        int n = costs.size();
        int l = cand - 1, r = n - cand; // inclusive
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        if(l >= r) {
            for(int i = 0; i < n; i++)
                pq.push({costs[i], i});
            
            while(k--) {
                cost += pq.top()[0];
                pq.pop();
            }
            return cost;
        }
        
        
        int i = 0;
        while(i <= l) {
            pq.push({costs[i], i});
            i++;
        }
        
        i = n - 1;
        
        while(i >= r) {
            pq.push({costs[i], i});
            i--;
        }
        
        while(k--) {
            auto it = pq.top();
            pq.pop();
            cost += it[0];
            if(it[1] <= l && l < r - 1) {
                l++;
                pq.push({costs[l], l});
            } else if(it[1] >= r && l < r - 1) {
                r--;
                pq.push({costs[r], r});
            }
            
        }
        return cost;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2462.md" >}}
---
{{< youtube 4hb3bZS1o1o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2465: Number of Distinct Averages](https://grid47.xyz/leetcode/solution-2465-number-of-distinct-averages/) |
| --- |
