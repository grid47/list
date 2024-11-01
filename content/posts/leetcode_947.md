
+++
authors = ["Crafted by Me"]
title = "Leetcode 947: Most Stones Removed with Same Row or Column"
date = "2022-03-31"
description = "Solution to Leetcode 947"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/)

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UF* uf = new UF(n);
        map<int, int> x, y;
        for(int i = 0; i < n; i++) {
            int p = stones[i][0];
            int q = stones[i][1];
            if(x.count(p)) {
                uf->uni(x[p], i);
            }
            if(y.count(q)) {
                uf->uni(y[q], i);
            }
            x[p] = i;
            y[q] = i;
        }
        return n - uf->cnt;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/947.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

