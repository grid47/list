
+++
authors = ["Crafted by Me"]
title = "Leetcode 1061: Lexicographically Smallest Equivalent String"
date = "2021-12-07"
description = "Solution to Leetcode 1061"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> par;
    
    UF(int n) {
        par.resize(n, 0);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            if(i < j)   par[j] = i;
            else        par[i] = j;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
};


class Solution {
public:

    int cnv(char x) {
        return x - 'a';
    }

    string smallestEquivalentString(string s1, string s2, string base) {
        
        int n = s1.size();
        UF* uf = new UF(26);
        
        for(int i = 0; i < n; i++) {
            uf->uni(cnv(s1[i]), cnv(s2[i]));
            uf->uni(cnv(s2[i]), cnv(s1[i]));            
        }
        
        string res = "";
        for(int i = 0; i < base.size(); i++) {
            res += uf->find(cnv(base[i])) + 'a';
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1061.md" >}}
---
{{< youtube YQ-q0oydRl4 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

