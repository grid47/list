
+++
authors = ["Crafted by Me"]
title = "Leetcode 3100: Water Bottles II"
date = "2016-05-08"
description = "In-depth solution and explanation for Leetcode 3100: Water Bottles II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/water-bottles-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxBottlesDrunk(int bot, int ex) {
        
        int full = bot;
        int empty = 0;
        int drunk = 0;
        
        
        while((empty + full) >= ex) {
            drunk   += full;
            empty   += full;
            full     = 0;
            while(empty >= ex) {
                empty   -= ex;
                full    += 1;
                ex      += 1;                
            }
        }
        
        return drunk + full;
        
    }
};
{{< /highlight >}}


---


"| 3101: Count Alternating Subarrays |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

