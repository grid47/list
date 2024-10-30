
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1319: Number of Operations to Make Network Connected"
date = "2021-03-22"
description = "Solution to Leetcode 1319"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

