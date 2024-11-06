
+++
authors = ["Crafted by Me"]
title = "Leetcode 899: Orderly Queue"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 899: Orderly Queue in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Sorting"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/orderly-queue/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        /*
        create a q
        add first in a pq
        pick one move to back of q 
        
        if all 'a' & one 'b' is there move the b to back of q
        
        lower index with higher weight poped first from the window
        
        if net weight of window decreses when pulling out the weak and adding next
        go for it else stop - wrong
        dp
        
        math string sort
        
        index of first smallest, then select window and 
        
        if first 20m does not forms a theory,
        look answer understand it and code.
        
        failed
        
        */
        
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        
        string mn = s;
        for(int i = 0; i < s.size(); i++)
            mn = min(mn, s.substr(i) + s.substr(0, i));
        return mn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/899.md" >}}
---
{{< youtube TBSxujyNd6M >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #900: RLE Iterator](https://grid47.xyz/posts/leetcode_900) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
