
+++
authors = ["Crafted by Me"]
title = "Leetcode 1925: Count Square Sum Triples"
date = "2019-07-27"
description = "In-depth solution and explanation for Leetcode 1925: Count Square Sum Triples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-square-sum-triples/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriples(int n) {
    vector<bool> squares(n * n + 1);
    for (int i = 1; i <= n; ++i)
        squares[i * i] = true;
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; i * i + j * j <= n * n; ++j)
            res += squares[i * i + j * j] * 2;
    return res;
}
};
{{< /highlight >}}


---


| Next : [LeetCode #1926: Nearest Exit from Entrance in Maze](grid47.xyz/leetcode_1926) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

