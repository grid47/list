
+++
authors = ["Crafted by Me"]
title = "Leetcode 89: Gray Code"
date = "2024-08-05"
description = "In-depth solution and explanation for Leetcode 89: Gray Code in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/gray-code/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};

        for (int idx = 0; idx < n; idx++) {
            int sz = res.size();
            for (int jdx = sz - 1; jdx >= 0; jdx--)
                res.push_back(res[jdx] | (1 << idx));
        }

        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/89.md" >}}
---
{{< youtube k5UYQtKXJGo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #90: Subsets II](https://grid47.xyz/posts/leetcode_90) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

