
+++
authors = ["grid47"]
title = "Leetcode 2924: Find Champion II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2924: Find Champion II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-champion-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = -1, count = 0;
        vector<int> indegree(n, 0);
        for(auto e: edges) indegree[e[1]]++;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {count++; ans = i; }
        }
        return count > 1?-1:ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2924.md" >}}
---
{{< youtube axwSqMVQ1x4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2928: Distribute Candies Among Children I](https://grid47.xyz/posts/leetcode-2928-distribute-candies-among-children-i-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}