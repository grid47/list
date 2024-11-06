
+++
authors = ["Crafted by Me"]
title = "Leetcode 2871: Split Array Into Maximum Number of Subarrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2871: Split Array Into Maximum Number of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, cur = 0;
        for (int n : nums) {
            cur = cur == 0 ? n : cur & n;
            res += cur == 0;
        }
        return max(1, res);
    }
};
{{< /highlight >}}


---
{{< youtube xgzsBxfu8Ew >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2872: Maximum Number of K-Divisible Components](https://grid47.xyz/posts/leetcode_2872) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
