
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 458: Poor Pigs"
date = "2023-07-30"
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

{{< highlight cpp >}}
class Solution {
public:
    int poorPigs(int bckt, int die, int test) {
        int pigs = 0;
        
        while(pow((test/die + 1), pigs) < bckt) pigs++;
         
        return pigs;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/458.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

