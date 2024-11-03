
+++
authors = ["Crafted by Me"]
title = "Leetcode 2367: Number of Arithmetic Triplets"
date = "2018-05-11"
description = "In-depth solution and explanation for Leetcode 2367: Number of Arithmetic Triplets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-arithmetic-triplets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
    int cnt[201] = {}, res = 0;
    for (auto n : nums) {
        if (n >= 2 * diff)
            res += cnt[n - diff] && cnt[n - 2 * diff];
        cnt[n] = true;
    }
    return res;
  }
};
{{< /highlight >}}


---


"| 2368: Reachable Nodes With Restrictions |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

