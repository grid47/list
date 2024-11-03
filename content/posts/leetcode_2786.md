
+++
authors = ["Crafted by Me"]
title = "Leetcode 2786: Visit Array Positions to Maximize Score"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2786: Visit Array Positions to Maximize Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxScore(vector<int>& n, int x) {
        long long eve = n[0] - (n[0] % 2 ? x : 0);
        long long odd = n[0] - (n[0] % 2 ? 0 : x);
        for (int i = 1; i < n.size(); ++i)
            if (n[i] % 2)   odd = n[i] + max(odd, eve - x);
            else            eve = n[i] + max(eve, odd - x);
        return max(eve, odd);
    }
};
{{< /highlight >}}


---
{{< youtube JtogyeIxGWE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2787: Ways to Express an Integer as Sum of Powers](https://grid47.xyz/posts/leetcode_2787) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

