
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 886: Possible Bipartition"
date = "2022-05-28"
description = "Solution to Leetcode 886"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/possible-bipartition/description/)

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
    bool possibleBipartition(int n, vector<vector<int>>& dlk) {
        UF* uf = new UF(n + 1);
        vector<vector<int>> gph(n + 1);
        for(int i = 0; i < dlk.size(); i++) {
            gph[dlk[i][0]].push_back(dlk[i][1]);
            gph[dlk[i][1]].push_back(dlk[i][0]);            
        }

        for(int i = 1; i <= n; i++) {
            for(int x: gph[i]) {
                if(uf->find(x) == uf->find(i)) return false;
                uf->uni(gph[i][0], x);
            }
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

