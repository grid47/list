
+++
authors = ["Yasir"]
title = "Leetcode 839: Similar String Groups"
date = "2022-07-11"
description = "Solution to Leetcode 839"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/similar-string-groups/description/)

---

**Code:**

{{< highlight html >}}
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

