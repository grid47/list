
+++
authors = ["Yasir"]
title = "Leetcode 991: Broken Calculator"
date = "2022-02-09"
description = "Solution to Leetcode 991"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/broken-calculator/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue >= target) return startValue - target;
        
        if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);
        
        return 1 + brokenCalc(startValue, target +1);
    }
};
{{< /highlight >}}

