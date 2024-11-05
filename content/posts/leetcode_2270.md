
+++
authors = ["Crafted by Me"]
title = "Leetcode 2270: Number of Ways to Split Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2270: Number of Ways to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-split-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int waysToSplitArray(vector<int>& in) {
        
        
        // partial_sum(nums.begin(), nums.end(), nums.begin());
        
        int n = in.size(), res = 0;

        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
        nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] >= nums[n - 1] - nums[i]) res++;
        }
        
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube XdsMrB7WRUw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2271: Maximum White Tiles Covered by a Carpet](https://grid47.xyz/posts/leetcode_2271) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

