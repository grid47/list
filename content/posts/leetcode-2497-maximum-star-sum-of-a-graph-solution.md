
+++
authors = ["grid47"]
title = "Leetcode 2497: Maximum Star Sum of a Graph"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2497: Maximum Star Sum of a Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Graph","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<priority_queue<int>> grid(n);
        
        for(auto it: edges) {
            grid[it[0]].push(vals[it[1]]);
            grid[it[1]].push(vals[it[0]]);
        }
        
        int sum = INT_MIN;
        for(int i = 0; i < n; i++) {
            int net = vals[i];
            int tmp = k;
            sum = max(net, sum);            
            while(tmp-- && !grid[i].empty()) {
                net += grid[i].top();
                grid[i].pop();
                sum = max(net, sum);                
            }
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2497.md" >}}
---
{{< youtube fmTiTN7Raek >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2498: Frog Jump II](https://grid47.xyz/posts/leetcode-2498-frog-jump-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}