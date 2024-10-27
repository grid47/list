
+++
authors = ["Yasir"]
title = "Leetcode 672: Bulb Switcher II"
date = "2022-12-26"
description = "Solution to Leetcode 672"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bulb-switcher-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int flipLights(int n, int m) {
        if(m==0) return 1;
        if(n==1) return 2;
        if(n==2&&m==1) return 3;
        if(n==2) return 4;
        if(m==1) return 4;
        if(m==2) return 7;
        if(m>=3) return 8;
        return 8;        
    }
};
{{< /highlight >}}

