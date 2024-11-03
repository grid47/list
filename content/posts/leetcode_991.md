
+++
authors = ["Crafted by Me"]
title = "Leetcode 991: Broken Calculator"
date = "2022-02-15"
description = "In-depth solution and explanation for Leetcode 991: Broken Calculator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue >= target) return startValue - target;
        
        if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);
        
        return 1 + brokenCalc(startValue, target +1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/991.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #992: Subarrays with K Different Integers](https://grid47.xyz/posts/leetcode_992) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

