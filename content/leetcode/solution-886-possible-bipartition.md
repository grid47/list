
+++
authors = ["grid47"]
title = "Leetcode 886: Possible Bipartition"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 886: Possible Bipartition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WIJa0GAC9Cg"
youtube_upload_date="2020-05-27"
youtube_thumbnail="https://i.ytimg.com/vi/WIJa0GAC9Cg/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/886.md" >}}
---
{{< youtube WIJa0GAC9Cg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #889: Construct Binary Tree from Preorder and Postorder Traversal](https://grid47.xyz/leetcode/solution-889-construct-binary-tree-from-preorder-and-postorder-traversal/) |
| --- |