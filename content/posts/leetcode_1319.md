
+++
authors = ["Crafted by Me"]
title = "Leetcode 1319: Number of Operations to Make Network Connected"
date = "2021-03-24"
description = "In-depth solution and explanation for Leetcode 1319: Number of Operations to Make Network Connected in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n, 0);
        for(int i = 0; i < n; i++)
            chd[i] = i;
        cnt = n;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            chd[i] = j;
            cnt--;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == chd[x]) return x;
        return chd[x] = find(chd[x]);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& grid) {
        UF* uf = new UF(n);
        for(int i = 0; i < grid.size(); i++)
            uf->uni(grid[i][0], grid[i][1]);
        return grid.size() < n - 1? -1:uf->cnt - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1319.md" >}}
---
{{< youtube vyXBp3S6-y4 >}}

| Next : [LeetCode #1320: Minimum Distance to Type a Word Using Two Fingers](grid47.xyz/leetcode_1320) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

