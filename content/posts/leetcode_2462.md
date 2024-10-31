
+++
authors = ["Crafted by Me"]
title = "Leetcode 2462: Total Cost to Hire K Workers"
date = "2018-02-04"
description = "Solution to Leetcode 2462"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

