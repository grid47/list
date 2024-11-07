
+++
authors = ["Crafted by Me"]
title = "Leetcode 565: Array Nesting"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 565: Array Nesting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/array-nesting/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int mxsize = 0;
        for(int i = 0; i < nums.size(); i++) {
            int size = 0;
            for(int k = i; nums[k] >= 0; size++) {
                int ak = nums[k];
                nums[k] = -1;
                k = ak;
            }
            mxsize = max(size, mxsize);
        }
        return mxsize;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/565.md" >}}
---
{{< youtube rl_hXXzvTiM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #567: Permutation in String](https://grid47.xyz/posts/leetcode_567) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
