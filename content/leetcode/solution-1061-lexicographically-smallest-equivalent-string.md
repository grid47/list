
+++
authors = ["grid47"]
title = "Leetcode 1061: Lexicographically Smallest Equivalent String"
date = "2024-07-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1061: Lexicographically Smallest Equivalent String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "YQ-q0oydRl4"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1072: Flip Columns For Maximum Number of Equal Rows](https://grid47.xyz/leetcode/solution-1072-flip-columns-for-maximum-number-of-equal-rows/) |
| --- |
