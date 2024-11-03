
+++
authors = ["Crafted by Me"]
title = "Leetcode 2201: Count Artifacts That Can Be Extracted"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2201: Count Artifacts That Can Be Extracted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2202: Maximize the Topmost Element After K Moves](https://grid47.xyz/posts/leetcode_2202) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

