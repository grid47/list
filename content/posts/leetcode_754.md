
+++
authors = ["Crafted by Me"]
title = "Leetcode 754: Reach a Number"
date = "2022-10-10"
description = "In-depth solution and explanation for Leetcode 754: Reach a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reach-a-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
        long long sum = n * (n + 1) / 2;
        if (sum == target) return n;
        long long res = sum - target;
        if((res &1) == 0)   return n;
        else                return n + ((n&1)? 2: 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/754.md" >}}
---
{{< youtube K8yXBn4cCQs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #755: Pour Water](https://grid47.xyz/posts/leetcode_755) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

