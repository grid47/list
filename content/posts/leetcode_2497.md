
+++
authors = ["Yasir"]
title = "Leetcode 2497: Maximum Star Sum of a Graph"
date = "2017-12-27"
description = "Solution to Leetcode 2497"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/)

---

**Code:**

{{< highlight html >}}
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

