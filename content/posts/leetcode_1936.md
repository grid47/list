
+++
authors = ["Crafted by Me"]
title = "Leetcode 1936: Add Minimum Number of Rungs"
date = "2019-07-15"
description = "Solution to Leetcode 1936"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-minimum-number-of-rungs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int rec(int cur, int idx, int dist, vector<int> &node) {
        if(cur + dist >= node[node.size() - 1]) return 0;
        
        if(cur + dist < node[idx]) {
            cur += dist;
            return 1 + rec(cur, idx, dist, node);
            
        } else {
            cur = node[idx];
            return rec(cur, idx + 1, dist, node);
        }
    }
    
    int addRungs(vector<int>& node, int dist) {
        int cur = 0, idx = 0, res = 0;
        
        int prv = 0;
        
        for(int i = 0; i < node.size(); i++) {
            if(node[i] - prv > dist) {
                res += (node[i] - prv - 1) / dist;
            }
            prv = node[i];
        }
        
        // while(cur + dist < node[node.size() - 1]) {
        //     if(cur + dist < node[idx]) {
        //         cur += dist;
        //         res++;
        //     } else {
        //         cur = node[idx];
        //         idx++;
        //     }
        // }
        
        return res;//rec(cur, idx, dist, node);
        
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

