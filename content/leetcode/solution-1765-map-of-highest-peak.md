
+++
authors = ["grid47"]
title = "Leetcode 1765: Map of Highest Peak"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1765: Map of Highest Peak in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1765.md" >}}
---
{{< youtube 0BNHd7a_ozc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1768: Merge Strings Alternately](https://grid47.xyz/leetcode/solution-1768-merge-strings-alternately/) |
| --- |
