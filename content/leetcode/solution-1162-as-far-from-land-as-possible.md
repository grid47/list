
+++
authors = ["grid47"]
title = "Leetcode 1162: As Far from Land as Possible"
date = "2024-07-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1162: As Far from Land as Possible in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "fjxb1hQfrZk"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1162.md" >}}
---
{{< youtube fjxb1hQfrZk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1170: Compare Strings by Frequency of the Smallest Character](https://grid47.xyz/leetcode/solution-1170-compare-strings-by-frequency-of-the-smallest-character/) |
| --- |
