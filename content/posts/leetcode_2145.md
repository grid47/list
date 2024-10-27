
+++
authors = ["Yasir"]
title = "Leetcode 2145: Count the Hidden Sequences"
date = "2018-12-14"
description = "Solution to Leetcode 2145"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-hidden-sequences/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numberOfArrays(vector<int>& diff, long lower, long upper) {
        // last - fist of n + 1 seq
        
        long mn = 0, mx = 0, x = 0;

        for(int k : diff) {
            x += k;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        int sum = mx - mn;
        if (upper - lower < sum)
            return 0;
        else {
            
            return (int)(upper - lower) - sum + 1;
            
        }
        
    }
};
{{< /highlight >}}

