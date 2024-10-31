
+++
authors = ["Crafted by Me"]
title = "Leetcode 1162: As Far from Land as Possible"
date = "2021-08-27"
description = "Solution to Leetcode 1162"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/as-far-from-land-as-possible/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1) {
                q.push(make_pair(i, j));
                grid[i][j] = 0;
            } else grid[i][j] = -1;

        if(q.empty() || q.size() == n * n) return -1;
        
        int dir[] = {0, 1, 0, -1, 0};
        int mx = 1;
        while(!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = tmp.first + dir[i], y = tmp.second + dir[i + 1];
                if(x < 0 || y < 0 || x == n || y == n || grid[x][y] != -1)
                    continue;
                cout << grid[tmp.first][tmp.second] << " ";
                grid[x][y] = grid[tmp.first][tmp.second] + 1;
                q.push(make_pair(x, y));
                mx = max(mx, grid[x][y]);
            }
        }
        return mx;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

