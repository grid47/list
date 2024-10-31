
+++
authors = ["Crafted by Me"]
title = "Leetcode 1765: Map of Highest Peak"
date = "2020-01-02"
description = "Solution to Leetcode 1765"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/map-of-highest-peak/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, 0)), vis(m, vector<int>(n, 0));
        
        queue<vector<int>> q;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(isWater[i][j] == 1)
                q.push({i, j});
        
        int rot[] = {0, 1, 0, -1, 0};
        
        int cur = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                if(vis[it[0]][it[1]]) continue;
                vis[it[0]][it[1]] = 1;
                
                ans[it[0]][it[1]] = cur;
                
                for(int i = 0; i < 4; i++) {
                    int x = it[0] + rot[i], y = it[1] + rot[i + 1];
                    if(x < 0 || y < 0 || x == m || y == n || vis[x][y]) continue;
                    q.push({x, y});
                }
            }
            cur++;
        }
        return ans;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

