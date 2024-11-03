
+++
authors = ["Crafted by Me"]
title = "Leetcode 633: Sum of Square Numbers"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 633: Sum of Square Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Math","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-square-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right) {
            long res = left * left + right * right;
            if(res < c)
            left++;
            else if(res > c) 
            right--;
            else return true;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/633.md" >}}
---
{{< youtube B0UrG_X2faA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #634: Find the Derangement of An Array](https://grid47.xyz/posts/leetcode_634) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

