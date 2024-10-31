
+++
authors = ["Crafted by Me"]
title = "Leetcode 990: Satisfiability of Equality Equations"
date = "2022-02-15"
description = "Solution to Leetcode 990"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/satisfiability-of-equality-equations/description/)

---

{{< youtube d3MkgeCo8l4 >}}

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
    bool equationsPossible(vector<string>& eqn) {
        UF* uf = new UF(26);
        for(int i = 0; i < eqn.size(); i++) {
            int a = eqn[i][0] - 'a';
            int b = eqn[i][3] - 'a';
            if(eqn[i][1] == '=')
                uf->uni(a, b);
        }
        for(int i = 0; i < eqn.size(); i++) {
            int a = eqn[i][0] - 'a';
            int b = eqn[i][3] - 'a';
            if(eqn[i][1] == '!')
                if(uf->find(a) == uf->find(b))
                    return false;
        }        
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/990.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

