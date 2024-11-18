
+++
authors = ["grid47"]
title = "Leetcode 2201: Count Artifacts That Can Be Extracted"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2201: Count Artifacts That Can Be Extracted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "neXgYvigRcI"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2201.md" >}}
---
{{< youtube neXgYvigRcI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2202: Maximize the Topmost Element After K Moves](https://grid47.xyz/leetcode/solution-2202-maximize-the-topmost-element-after-k-moves/) |
| --- |
