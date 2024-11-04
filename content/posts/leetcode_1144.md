
+++
authors = ["Crafted by Me"]
title = "Leetcode 1144: Decrease Elements To Make Array Zigzag"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1144: Decrease Elements To Make Array Zigzag in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size(), left, right;
        vector<int> res(2, 0);
        for(int i = 0; i < n; i++) {

            left  = ( i     > 0 ) ? nums[i - 1] : 1001;
            right = ( i + 1 < n ) ? nums[i + 1] : 1001;

            res[i % 2] += max(0, nums[i] - min(left, right) + 1);
        }

        return min(res[0], res[1]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1144.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1145: Binary Tree Coloring Game](https://grid47.xyz/posts/leetcode_1145) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

