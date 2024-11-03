
+++
authors = ["Crafted by Me"]
title = "Leetcode 2894: Divisible and Non-divisible Sums Difference"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2894: Divisible and Non-divisible Sums Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                res -= i;
            } else {
                res += i;
            }
        }
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2895: Minimum Processing Time](https://grid47.xyz/posts/leetcode_2895) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

