
+++
authors = ["grid47"]
title = "Leetcode 990: Satisfiability of Equality Equations"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 990: Satisfiability of Equality Equations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "d3MkgeCo8l4"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/satisfiability-of-equality-equations/description/)

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
---
{{< youtube d3MkgeCo8l4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #991: Broken Calculator](https://grid47.xyz/leetcode/solution-991-broken-calculator/) |
| --- |
