
+++
authors = ["Crafted by Me"]
title = "Leetcode 2520: Count the Digits That Divide a Number"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2520: Count the Digits That Divide a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        for (int n = num; n > 0; n /= 10)
            res += num % (n % 10) == 0;
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube 7SHHsS5kPJ8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2521: Distinct Prime Factors of Product of Array](https://grid47.xyz/posts/leetcode_2521) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

