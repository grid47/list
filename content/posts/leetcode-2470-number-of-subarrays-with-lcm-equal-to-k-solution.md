
+++
authors = ["grid47"]
title = "Leetcode 2470: Number of Subarrays With LCM Equal to K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2470: Number of Subarrays With LCM Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && k % nums[j] == 0; j++) {
                nums[i] = (nums[i] * nums[j] / __gcd(nums[i], nums[j]));
                cnt += nums[i] == k;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2470.md" >}}
---
{{< youtube xT-O9YJrwh4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2471: Minimum Number of Operations to Sort a Binary Tree by Level](https://grid47.xyz/posts/leetcode-2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}