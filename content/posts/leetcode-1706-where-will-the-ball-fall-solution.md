
+++
authors = ["grid47"]
title = "Leetcode 1706: Where Will the Ball Fall"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1706: Where Will the Ball Fall in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/where-will-the-ball-fall/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < n; i++) {
            int i1 = i, i2;
            for(int j = 0; j < m; j++) {
                i2 = i1 + grid[j][i1];
                if(i2 <0 || i2 >= n || grid[j][i1] != grid[j][i2]) {
                    i1 = -1;
                    break;
                }
                i1 = i2;
            }
            res.push_back(i1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1706.md" >}}
---
{{< youtube QydaN-AVEAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1712: Ways to Split Array Into Three Subarrays](https://grid47.xyz/posts/leetcode-1712-ways-to-split-array-into-three-subarrays-solution/) |
| --- |
