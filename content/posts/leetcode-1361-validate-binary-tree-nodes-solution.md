
+++
authors = ["grid47"]
title = "Leetcode 1361: Validate Binary Tree Nodes"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1361: Validate Binary Tree Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Union Find","Graph","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1362: Closest Divisors](https://grid47.xyz/posts/leetcode-1362-closest-divisors-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
