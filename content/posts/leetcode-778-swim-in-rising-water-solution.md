
+++
authors = ["grid47"]
title = "Leetcode 778: Swim in Rising Water"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 778: Swim in Rising Water in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Depth-First Search","Breadth-First Search","Union Find","Heap (Priority Queue)","Matrix"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/swim-in-rising-water/description/)

---
**Code:**

{{< highlight cpp >}}
class cmp {
    public:
    bool operator() (vector<int> a, vector<int> b) {
        return a[2] > b[2];
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        
        int mx = 0;
        pq.push({0, 0, grid[0][0]});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dir[] = {0, 1, 0, -1, 0};
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            vis[it[0]][it[1]] = true;
            mx = max(mx, grid[it[0]][it[1]]);
            
            if(it[0] == m - 1 && it[1] == n -1)
                return mx;
            
            for(int i = 0; i < 4; i++) {
                int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y])
                    continue;
                
                pq.push({x, y, grid[x][y]});
            }
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/778.md" >}}
---
{{< youtube amvrKlMLuGY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #779: K-th Symbol in Grammar](https://grid47.xyz/posts/leetcode-779-k-th-symbol-in-grammar-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
