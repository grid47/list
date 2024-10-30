
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2543: Check if Point Is Reachable"
date = "2017-11-14"
description = "Solution to Leetcode 2543"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-point-is-reachable/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isReachable(int x, int y) {
        if(x == 1 && y == 1) return true;

        bool ans = false;
        if(y%2 == 0) return isReachable(x, y/2);        
        if(x%2 == 0) return isReachable(x/2, y);        
        if(x > y)    return isReachable(x - y, y);
        if(x < y)    return isReachable(x, y - x);        
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

