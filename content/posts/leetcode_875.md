
+++
authors = ["Yasir"]
title = "Leetcode 875: Koko Eating Bananas"
date = "2022-06-05"
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

{{< highlight html >}}
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

