
+++
authors = ["grid47"]
title = "Leetcode 1007: Minimum Domino Rotations For Equal Row"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1007: Minimum Domino Rotations For Equal Row in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        map<int, int> mp;
        vector<int> tc(7, 0), uc(7, 0);
        int n = top.size();
        for(int i = 0; i < n; i++) {
            if(bottom[i] != top[i]) {
                mp[bottom[i]]++;
                mp[top[i]]++;
            } else mp[top[i]]++;

            uc[bottom[i]]++;
            tc[top[i]]++;
        }
        
        vector<int> opt;
        for(auto it: mp) {
            if(it.second == n)
                opt.push_back(it.first);
        }
        if(opt.empty()) return -1;
        
        int res = INT_MAX;
        for(int x: opt) {
            if(uc[x] == n || tc[x] == n) return 0;
            res = min(res, n - uc[x]);
            res = min(res, n - tc[x]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1007.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1008: Construct Binary Search Tree from Preorder Traversal](https://grid47.xyz/posts/leetcode-1008-construct-binary-search-tree-from-preorder-traversal-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}