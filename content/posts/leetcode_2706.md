
+++
authors = ["Crafted by Me"]
title = "Leetcode 2706: Buy Two Chocolates"
date = "2017-06-05"
description = "Solution to Leetcode 2706"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/buy-two-chocolates/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        int l1 = 200, l2 = 200;
        for(int i = 0; i < p.size(); i++) {
            if(p[i] < l1) {
                l2 = l1;
                l1 = p[i];
            } else if(p[i] < l2) {
                l2 = p[i];
            }
        }
        
        if(l1 + l2 <= m) return m - l1 - l2;
        return m;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

