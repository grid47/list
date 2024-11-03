
+++
authors = ["Crafted by Me"]
title = "Leetcode 857: Minimum Cost to Hire K Workers"
date = "2022-06-29"
description = "In-depth solution and explanation for Leetcode 857: Minimum Cost to Hire K Workers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube f879mUH6vJk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #858: Mirror Reflection](https://grid47.xyz/posts/leetcode_858) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

