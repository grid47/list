
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1992: Find All Groups of Farmland"
date = "2019-05-18"
description = "Solution to Leetcode 1992"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

