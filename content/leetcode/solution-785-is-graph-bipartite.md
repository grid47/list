
+++
authors = ["grid47"]
title = "Leetcode 785: Is Graph Bipartite?"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 785: Is Graph Bipartite? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/785.webp"
youtube = "j69Of_2nfRA"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/j69Of_2nfRA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/is-graph-bipartite/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/785.webp" 
    alt="A graph where bipartiteness is checked, with the two sets glowing softly as they are separated."
    caption="Solution to LeetCode 785: Is Graph Bipartite? Problem"
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
    bool isBipartite(vector<vector<int>>& gph) {
        int n = gph.size();
          UF* uf = new UF(n);

        for(int i = 0; i < n; i++) {
            for(int x: gph[i]) {
                if(uf->find(x) == uf->find(i)) return false;
                uf->uni(gph[i][0], x);
            }
        }
        return true;      
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/785.md" >}}
---
{{< youtube j69Of_2nfRA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #786: K-th Smallest Prime Fraction](https://grid47.xyz/leetcode/solution-786-k-th-smallest-prime-fraction/) |
| --- |
