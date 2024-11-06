
+++
authors = ["Crafted by Me"]
title = "Leetcode 2462: Total Cost to Hire K Workers"
date = "2024-11-01"
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


---
{{< youtube 4hb3bZS1o1o >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2463: Minimum Total Distance Traveled](https://grid47.xyz/posts/leetcode_2463) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
