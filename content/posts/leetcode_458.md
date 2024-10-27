
+++
authors = ["Yasir"]
title = "Leetcode 458: Poor Pigs"
date = "2023-07-28"
description = "Solution to Leetcode 458"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/poor-pigs/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int poorPigs(int bckt, int die, int test) {
        int pigs = 0;
        
        while(pow((test/die + 1), pigs) < bckt) pigs++;
         
        return pigs;        
    }
};
{{< /highlight >}}

