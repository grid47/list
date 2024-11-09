
+++
authors = ["grid47"]
title = "Leetcode 2577: Minimum Time to Visit a Cell In a Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2577: Minimum Time to Visit a Cell In a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Graph","Heap (Priority Queue)","Matrix","Shortest Path"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    
    int minimumTime(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1; // concept of two and fro does not work at (0,0);
        vis.resize(m, vector<bool>(n, false));
                
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        int dir[] = {0, 1, 0, -1, 0};
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t = it[0], i = it[1], j = it[2];
            if(i == (m - 1) && j == (n - 1)) return t;
            if(vis[i][j]) continue;
            vis[i][j] = true;
            for(int k = 0; k < 4; k++) {
                int p = i + dir[k], q = j + dir[k + 1];
                if(p < 0 || q < 0 || p >= m || q >= n || vis[p][q])
                    continue;
                int w = ((grid[p][q] - t) % 2 == 0);
                pq.push({max(w + grid[p][q], t + 1), p, q});
            }
        }
        
        
        return -1;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2577.md" >}}
---
{{< youtube iIDBYfHJaBY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2578: Split With Minimum Sum](https://grid47.xyz/posts/leetcode-2578-split-with-minimum-sum-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
