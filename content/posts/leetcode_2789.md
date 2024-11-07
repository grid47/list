
+++
authors = ["Crafted by Me"]
title = "Leetcode 2789: Largest Element in an Array after Merge Operations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2789: Largest Element in an Array after Merge Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxArrayValue(vector<int>& in) {

        int n = in.size();        
        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
            nums[i] = in[i];

        long long res = nums[n - 1];
        
        for(int i = n - 1; i >= 0; i--) {
            res = max(res, (long long)nums[i]);
            if(i > 0 && nums[i] >= nums[i - 1]) {
                nums[i - 1] += nums[i];
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2789.md" >}}
---
{{< youtube wbXDrozEtOs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2790: Maximum Number of Groups With Increasing Length](https://grid47.xyz/posts/leetcode_2790) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
