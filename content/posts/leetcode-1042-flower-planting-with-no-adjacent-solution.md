
+++
authors = ["grid47"]
title = "Leetcode 1042: Flower Planting With No Adjacent"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1042: Flower Planting With No Adjacent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flower-planting-with-no-adjacent/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> res(n, 0);
        vector<vector<int>> gph(n);
        for(vector<int> &p: paths) {
            gph[p[0]-1].push_back(p[1]-1);
            gph[p[1]-1].push_back(p[0]-1);
        }
        for(int i = 0; i < n; i++) {
            int colors[5] = {};
            for(int j: gph[i]) {
                colors[res[j]] = 1;
            }
            for(int c = 4; c > 0; c--)
                if(!colors[c])
                    res[i] = c;
            
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1042.md" >}}
---
{{< youtube 63xMlAAvEnA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1043: Partition Array for Maximum Sum](https://grid47.xyz/posts/leetcode-1043-partition-array-for-maximum-sum-solution/) |
| --- |
