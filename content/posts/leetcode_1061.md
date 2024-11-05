
+++
authors = ["Crafted by Me"]
title = "Leetcode 1061: Lexicographically Smallest Equivalent String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1061: Lexicographically Smallest Equivalent String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1062: Longest Repeating Substring](https://grid47.xyz/posts/leetcode_1062) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

