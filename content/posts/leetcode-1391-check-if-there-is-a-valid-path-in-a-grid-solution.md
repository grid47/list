
+++
authors = ["grid47"]
title = "Leetcode 1391: Check if There is a Valid Path in a Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1391: Check if There is a Valid Path in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<vector<int>>> dir{    { { 0, 1}, { 0, -1} },
                       { { 1, 0}, {-1,  0} },
                       { { 0,-1}, { 1,  0} },
                       { { 0, 1}, { 1,  0} },
                       { {0, -1}, {-1,  0} },
                       { { 0, 1}, {-1,  0} },
                  };
    
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector(n, false));
        
        queue<vector<int>> q;
        q.push(vector<int>{0, 0});
        visited[0][0] = true;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                vector<int> cur = q.front();
                q.pop();
                
                if(cur[0] == m - 1 && cur[1] == n - 1) return true;
                
                int num = grid[cur[0]][cur[1]];
                
                for(vector<int> go : dir[num - 1]) {
                    int x = cur[0] + go[0], y = cur[1] + go[1];
                    
                    if (x <  0 || y <  0 ||
                        x >= m || y >= n || visited[x][y])
                        continue;
                    
                    int ret = grid[x][y];
                    for(vector<int> rev : dir[ret - 1]) {
                        if((cur[0] == x + rev[0] && cur[1] == y + rev[1]) ||
                           (cur[1] == x + rev[0] && cur[0] == y + rev[1])) {
                            q.push(vector<int>{x, y});
                            visited[x][y] = true;
                        }
                    }   
                }
            }
            
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1391.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1395: Count Number of Teams](https://grid47.xyz/posts/leetcode-1395-count-number-of-teams-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}