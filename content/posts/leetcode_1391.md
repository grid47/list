
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1391: Check if There is a Valid Path in a Grid"
date = "2021-01-07"
description = "Solution to Leetcode 1391"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

