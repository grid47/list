
+++
authors = ["grid47"]
title = "Leetcode 1992: Find All Groups of Farmland"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1992: Find All Groups of Farmland in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "R2mf-nBCWV4"
youtube_upload_date="2021-09-04"
youtube_thumbnail="https://i.ytimg.com/vi/R2mf-nBCWV4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-all-groups-of-farmland/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(land[i][j] == 1) {
                vector<int> tmp = {i, j, i, j};
                dfs(land, i, j, tmp);
               ans.push_back(tmp); 
            }

        }
        return ans;
    }
    
    void dfs(vector<vector<int>> &land, int i, int j, vector<int> &tmp) {

        if(land[i][j] != 1) return;
        
        land[i][j] = 0;
        
        tmp[2] = max(tmp[2], i);
        tmp[3] = max(tmp[3], j);
        
        if(j + 1 < n)
        dfs(land, i, j + 1, tmp);
            
        if(i + 1 < m)
        dfs(land, i + 1, j, tmp);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1992.md" >}}
---
{{< youtube R2mf-nBCWV4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1993: Operations on Tree](https://grid47.xyz/leetcode/solution-1993-operations-on-tree/) |
| --- |