
+++
authors = ["Crafted by Me"]
title = "Leetcode 2145: Count the Hidden Sequences"
date = "2018-12-19"
description = "In-depth solution and explanation for Leetcode 2145: Count the Hidden Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

