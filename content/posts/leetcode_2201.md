
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2201: Count Artifacts That Can Be Extracted"
date = "2018-10-21"
description = "Solution to Leetcode 2201"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-artifacts-that-can-be-extracted/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        
        vector<vector<int>> grid(n, vector<int>(n, -1));
        
        int k = 0;
        for(auto it: artifacts) {
            k++;
            for(int i = it[0]; i <= it[2]; i++)
            for(int j = it[1]; j <= it[3]; j++)
                grid[i][j] = k;

        }
        
        set<int> cnt;
        for(auto it: dig)
            grid[it[0]][it[1]] = -1;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] != -1)
                cnt.insert(grid[i][j]);
        
        return k - cnt.size();
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
