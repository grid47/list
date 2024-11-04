
+++
authors = ["Crafted by Me"]
title = "Leetcode 1685: Sum of Absolute Differences in a Sorted Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1685: Sum of Absolute Differences in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int z = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            z += nums[i] - nums[0];
        vector<int> ans(n, 0);
        ans[0] = z;
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1685.md" >}}
---
{{< youtube WYe644djV30 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1686: Stone Game VI](https://grid47.xyz/posts/leetcode_1686) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

