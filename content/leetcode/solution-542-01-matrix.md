
+++
authors = ["grid47"]
title = "Leetcode 542: 01 Matrix"
date = "2024-09-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 542: 01 Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/542.webp"
youtube = "1xuLfxgT7yo"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/1xuLfxgT7yo/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/01-matrix/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/542.webp" 
    alt="A matrix where cells of 1s and 0s are arranged, with the shortest distance for 1s to 0s glowing softly."
    caption="Solution to LeetCode 542: 01 Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] == 0)
            q.push({i, j});
        
        int dis = 0;
        vector<vector<int>> vis;
        vis.resize(m, vector<int>(n, 0));
        int dir[] = {0, 1, 0, -1, 0};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();                
                if(vis[it[0]][it[1]]) continue;
                mat[it[0]][it[1]] = dis;
                vis[it[0]][it[1]] = 1;

                for(int i = 0; i < 4; i++) {
                    int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                    if(x < 0 || y < 0 || x == m || y == n)
                        continue;
                    if(!vis[x][y])
                        q.push({x, y});
                }
            }
            dis++;
        }
        return mat;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/542.md" >}}
---
{{< youtube 1xuLfxgT7yo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #543: Diameter of Binary Tree](https://grid47.xyz/leetcode/solution-543-diameter-of-binary-tree/) |
| --- |