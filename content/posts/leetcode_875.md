
+++
authors = ["Crafted by Me"]
title = "Leetcode 875: Koko Eating Bananas"
date = "2021-06-10"
description = "Solution to Leetcode 875"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/koko-eating-bananas/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 0, r = 1000000000;
        while(l <= r) {
            int k = l + (r - l) / 2;
            double h = 0;
            for(int x: piles)
                h += ceil((double) x / k);
            
            if(h > H)   l = k + 1;
            else        r = k - 1;
        }
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/875.md" >}}
---
{{< youtube ceYZ5RgwQwQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

