
+++
authors = ["grid47"]
title = "Leetcode 1319: Number of Operations to Make Network Connected"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1319: Number of Operations to Make Network Connected in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1325: Delete Leaves With a Given Value](https://grid47.xyz/posts/leetcode-1325-delete-leaves-with-a-given-value-solution/) |
| --- |
