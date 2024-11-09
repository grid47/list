
+++
authors = ["grid47"]
title = "Leetcode 839: Similar String Groups"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 839: Similar String Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Depth-First Search","Breadth-First Search","Union Find"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/similar-string-groups/description/)

---
**Code:**

{{< highlight cpp >}}
class UF {
    public:
    int n;
    vector<int> par;
    int grp;
    UF(int n) {
        grp = n;
        par.resize(n);
        for(int i =0; i < n; i++)
            par[i] = i;
    }
    bool join(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p != q) {
            grp--;
            par[p] = q;
            return true;
        }
        return false;
    }
    
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
};


class Solution {
public:
bool similar(string &a, string &b) {
    int n = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i] && ++n > 2)
            return false;
    return true;
}

int numSimilarGroups(vector<string>& A) {
    UF ds(A.size());
    for (int i = 0; i < A.size(); i++)
        for (int j = i + 1; j < A.size(); j++)
            if (similar(A[i], A[j]))
                ds.join(i, j);
    return ds.grp;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/839.md" >}}
---
{{< youtube SbLsabsSFt0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #840: Magic Squares In Grid](https://grid47.xyz/posts/leetcode-839-similar-string-groups-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
