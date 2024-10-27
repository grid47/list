
+++
authors = ["Yasir"]
title = "Leetcode 3100: Water Bottles II"
date = "2016-05-03"
description = "Solution to Leetcode 3100"
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

{{< highlight html >}}
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

