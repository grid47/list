
+++
authors = ["grid47"]
title = "Leetcode 1361: Validate Binary Tree Nodes"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1361: Validate Binary Tree Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Union Find","Graph","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Mw67DTgUEqk"
youtube_upload_date="2023-10-17"
youtube_thumbnail="https://i.ytimg.com/vi/Mw67DTgUEqk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/validate-binary-tree-nodes/description/)

---
**Code:**

{{< highlight cpp >}}
class UF {
    
    public:
    
    vector<int> chd, rnk;
    int net;
    
    UF (int n) {
        chd.resize(n);
        rnk.resize(n, 0);
        for(int i = 0; i < n; i++) {
            chd[i] = i; }
        net = n;
    }
    
    bool uni(int i, int j) {
        int x = find(i);
        int y = find(j);
        if((x == y) || (y != j)) return false;
        
        chd[y] = x;
        net--;
        
       /* if(x != y) {
            if(rnk[x] < rnk[y]) {
                
                chd[x] = y;
                rnk[y]++;
                
            } else {
                
                chd[y] = x;
                rnk[x]++;
                
            }
            net--;
            return true;
        }
        cout << x << y;*/
       return true;
    }
    
    int find(int x) {
        if(chd[x] != x) {
           chd[x] = find(chd[x]);
        }
        return chd[x];
    }
    
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        UF uf = UF(n);
        for(int i = 0; i < n; i++) {
            if(lc[i] >= 0) {
                
if(!uf.uni(i, lc[i])) 
    return false; 
                
            }
            if(rc[i] >= 0) {
 
if(!uf.uni(i, rc[i])) 
    return false; 
                
            }
        }
        cout << uf.net;
        return uf.net == 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1361.md" >}}
---
{{< youtube Mw67DTgUEqk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1362: Closest Divisors](https://grid47.xyz/leetcode/solution-1362-closest-divisors/) |
| --- |