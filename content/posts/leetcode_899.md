
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 899: Orderly Queue"
date = "2022-05-15"
description = "Solution to Leetcode 899"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

