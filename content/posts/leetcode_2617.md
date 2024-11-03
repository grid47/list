
+++
authors = ["Crafted by Me"]
title = "Leetcode 2617: Minimum Number of Visited Cells in a Grid"
date = "2017-09-03"
description = "In-depth solution and explanation for Leetcode 2617: Minimum Number of Visited Cells in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int minimumVisitedCells(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            if(i == m - 1 && j == n - 1) return d;
            pq.pop();
            for(int k = j + 1; k <= min(n - 1, j + grid[i][j]); k++) {
                if(dist[i][k] > d + 1) {
                    dist[i][k] = d + 1;
                    pq.push({d + 1, {i, k}});
                    if(i == m - 1 && k == n - 1) return d + 1;                    
                }
            }
            for(int k = i + 1; k <= min(m - 1, i + grid[i][j]); k++) {
                if(dist[k][j] > d + 1) {
                    dist[k][j] = d + 1;
                    pq.push({d + 1, {k, j}});
                    if(k == m - 1 && j == n - 1) return d + 1;                     
                }
            }            
        }
        return -1;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2618: Check if Object Instance of Class](grid47.xyz/leetcode_2618) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

