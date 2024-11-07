
+++
authors = ["Crafted by Me"]
title = "Leetcode 1074: Number of Submatrices That Sum to Target"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1074: Number of Submatrices That Sum to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix","Prefix Sum"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mtx, int post) {
        int res = 0, m = mtx.size(), n = mtx[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 1; j < n; j++)
        mtx[i][j] += mtx[i][j - 1];
        
        map<int, int> maap;
        // int res = 0;
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            int cur = 0;
            maap.clear();
            maap[0] = 1;
            for(int k = 0; k < m; k++) {
                cur += mtx[k][j] - ((i > 0) ? mtx[k][i - 1] : 0);
                res += maap[cur - post];
                maap[cur]++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1074.md" >}}
---
{{< youtube 43DRBP2DUHg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1079: Letter Tile Possibilities](https://grid47.xyz/posts/leetcode_1079) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
