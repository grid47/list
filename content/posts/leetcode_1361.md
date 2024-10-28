
+++
authors = ["Yasir"]
title = "Leetcode 1361: Validate Binary Tree Nodes"
date = "2021-02-06"
description = "Solution to Leetcode 1361"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/validate-binary-tree-nodes/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

