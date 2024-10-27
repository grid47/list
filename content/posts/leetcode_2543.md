
+++
authors = ["Yasir"]
title = "Leetcode 2543: Check if Point Is Reachable"
date = "2017-11-11"
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

{{< highlight html >}}
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

