
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 857: Minimum Cost to Hire K Workers"
date = "2022-06-26"
description = "Solution to Leetcode 857"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& wage, int k) {
        /*
        
        [ sum(quality) / (quality of min wage) ] * min(wage), should be minimised
        
        */
        
        int n = q.size();
        
        vector<pair<double, int>> worker;
        for(int i = 0; i < n; i++) {
            worker.push_back({(double) wage[i]/q[i], q[i]});
        }
        sort(worker.begin(), worker.end());
        
        priority_queue<int> pq;
        int netq = 0;
        for(int i = 0; i < k; i++) {
            pq.push(worker[i].second);
            netq += worker[i].second;
        }
        
        double mn = netq * worker[k - 1].first;
        
        for(int i = k; i < n; i++) {
            netq -= pq.top();
            pq.pop();
            pq.push(worker[i].second);
            netq += worker[i].second;
            
            double res = netq * worker[i].first;
            mn = min(mn, res);
        }
                      
        return mn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/857.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
