
+++
authors = ["Crafted by Me"]
title = "Leetcode 2566: Maximum Difference by Remapping a Digit"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2566: Maximum Difference by Remapping a Digit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMaxDifference(int num) {
        int min_v = num, max_v = num;
        for (int i = 0; i < 10; ++i) {
            int lo = 0, hi = 0, mul = 1;
            for (int n = num; n; n /= 10) {
                bool replace = n % 10 == i;
                lo += (replace ? 0 : n % 10) * mul;
                hi += (replace ? 9 : n % 10) * mul;
                mul *= 10;
            }
            min_v = min(min_v, lo);
            max_v = max(max_v, hi);
        }
        return max_v - min_v;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2567: Minimum Score by Changing Two Elements](https://grid47.xyz/posts/leetcode_2567) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

