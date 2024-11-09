
+++
authors = ["grid47"]
title = "Leetcode 502: IPO"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 502: IPO in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ipo/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        vector<pair<int, int>> arr;
        priority_queue<int> pq;
        int n = capital.size();
        for(int i = 0; i < n; i++) {
            if(capital[i] <= w) {
                pq.push(profit[i]);
            } else {
                arr.push_back({capital[i], profit[i]});                
            }
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        int sum = w;
        while(k-- && !pq.empty()) {
            sum += pq.top();
            pq.pop();
            while(i < arr.size() && arr[i].first <= sum) {
                pq.push(arr[i].second);
                i++;
            }
        }
        return sum;
        /*
        
            i have a current capital
            i can pick all the the projects with lesser capital required
            
            from set of all projects available to pick
            choose the one with highest profit
            
            if that adds more possibilities expand the serach space
            
            then again choose the top guy
            
            repeat last two steps,
        
        */
        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/502.md" >}}
---
{{< youtube VFXfhB8vS94 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #508: Most Frequent Subtree Sum](https://grid47.xyz/posts/leetcode-508-most-frequent-subtree-sum-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
