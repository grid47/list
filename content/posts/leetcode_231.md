
+++
authors = ["Crafted by Me"]
title = "Leetcode 231: Power of Two"
date = "2024-03-16"
description = "In-depth solution and explanation for Leetcode 231: Power of Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/power-of-two/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & (n - 1));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/231.md" >}}
---
{{< youtube lGxiqzurnNU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #232: Implement Queue using Stacks](https://grid47.xyz/posts/leetcode_232) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

