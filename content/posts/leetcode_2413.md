
+++
authors = ["Crafted by Me"]
title = "Leetcode 2413: Smallest Even Multiple"
date = "2018-03-26"
description = "In-depth solution and explanation for Leetcode 2413: Smallest Even Multiple in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-even-multiple/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0? n: n * 2;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2414: Length of the Longest Alphabetical Continuous Substring](https://grid47.xyz/posts/leetcode_2414) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

