
+++
authors = ["Crafted by Me"]
title = "Leetcode 2706: Buy Two Chocolates"
date = "2017-06-06"
description = "In-depth solution and explanation for Leetcode 2706: Buy Two Chocolates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

