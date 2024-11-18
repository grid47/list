
+++
authors = ["grid47"]
title = "Leetcode 684: Redundant Connection"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 684: Redundant Connection in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "FXWRE67PLL0"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/684.webp"
+++



[`Problem Link`](https://leetcode.com/problems/redundant-connection/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/684.webp" 
    alt="A graph where redundant connections are detected and softly glowing to indicate the loop."
    caption="Solution to LeetCode 684: Redundant Connection Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n + 1, 0);
        for(int i = 0; i < n + 1; i++)
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF* uf = new UF(n);
        for(int i = 0; i < n; i++)
            if(!uf->uni(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        return edges[0];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/684.md" >}}
---
{{< youtube FXWRE67PLL0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #686: Repeated String Match](https://grid47.xyz/leetcode/solution-686-repeated-string-match/) |
| --- |
