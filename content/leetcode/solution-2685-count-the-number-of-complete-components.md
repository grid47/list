
+++
authors = ["grid47"]
title = "Leetcode 2685: Count the Number of Complete Components"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2685: Count the Number of Complete Components in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "J43LjwWYch4"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/J43LjwWYch4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-complete-components/description/)

---
**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> par, edge, rnk;
    UF(int n) {
        par.resize(n, 0);
        iota(par.begin(), par.end(), 0);
        edge.resize(n, 0);
        rnk.resize(n, 1);
    }
    
    bool join(int i, int j) {
        int p = find(i);
        int q = find(j);
        if(p != q) {
            if(rnk[p] > rnk[q]) {
                rnk[p]+=rnk[q];
                par[q] = p;
            } else {
                rnk[q]+=rnk[p];
                par[p] = q;         
            }
            int e = edge[p]+edge[q] + 1;
            edge[p] =e; // dge[q] + 1;
            edge[q] =e; // dge[p] + 1;            
            return true;
        }
        edge[q]++;
        return false;
    }
    int find(int p) {
        if(p == par[p]) return p;
        return par[p] = find(par[p]);
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UF uf = UF(n);
        for(auto e: edges) {
            uf.join(e[0], e[1]);
        }
        set<int> pk;
        int res = 0;
            // cout << "edges membercnt edgescal \n";         
        for(int i = 0; i < n; i++) {
            int par = uf.find(i);
            if(pk.count(par)) continue;
            pk.insert(par);
            int cnt = uf.edge[par];
            // cout << cnt << " " << uf.rnk[par] << " " << uf.rnk[par] * (uf.rnk[par] - 1) / 2 << "\n";
            if(uf.rnk[par] * (uf.rnk[par] - 1) / 2 == cnt) res++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2685.md" >}}
---
{{< youtube J43LjwWYch4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2696: Minimum String Length After Removing Substrings](https://grid47.xyz/leetcode/solution-2696-minimum-string-length-after-removing-substrings/) |
| --- |
