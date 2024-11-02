
+++
authors = ["Crafted by Me"]
title = "Leetcode 778: Swim in Rising Water"
date = "2022-09-16"
description = "Solution to Leetcode 778"
tags = [
    
]
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

