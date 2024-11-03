
+++
authors = ["Crafted by Me"]
title = "Leetcode 2652: Sum Multiples"
date = "2017-07-30"
description = "In-depth solution and explanation for Leetcode 2652: Sum Multiples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-multiples/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            if((i % 3 == 0) || (i% 5 == 0) || (i % 7 == 0))
                sum += i;
        return sum;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2653: Sliding Subarray Beauty](https://grid47.xyz/posts/leetcode_2653) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

