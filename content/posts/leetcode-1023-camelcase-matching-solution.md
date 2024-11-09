
+++
authors = ["grid47"]
title = "Leetcode 1023: Camelcase Matching"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1023: Camelcase Matching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Trie","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/camelcase-matching/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool> res;
        
        for(string q: queries) {
            
            bool ret = match(q, pattern);
            
            res.push_back(ret);
        }

        return res;
    }
    
    bool match(string q, string p) {
        
        int j = 0;
        
        for(int i = 0; i < q.size(); i++) {
            
            if(j < p.size()&&q[i] == p[j]) {
                j++;
                continue;
            }else if(q[i] >= 'A' && 
               q[i] <= 'Z')
                return false;               
               
        }
        
        return j == p.size();
        
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1023.md" >}}
---
{{< youtube h9I_yFNeMgo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1024: Video Stitching](https://grid47.xyz/posts/leetcode-1023-camelcase-matching-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
