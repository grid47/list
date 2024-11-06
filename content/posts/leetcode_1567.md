
+++
authors = ["Crafted by Me"]
title = "Leetcode 1567: Maximum Length of Subarray With Positive Product"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1567: Maximum Length of Subarray With Positive Product in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0, positive = 0, negative = 0;
        for(int x : nums) {
            if (x == 0) {
                positive = 0;
                negative = 0;
            }
            else if (x > 0) {
                positive++;
                negative = negative == 0 ? 0 : negative + 1;
            }
            else {
                int tmp  = positive;
                positive = negative == 0 ? 0 : negative + 1;
                negative = tmp + 1;
            }
            ans = max(ans, positive);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1567.md" >}}
---
{{< youtube bFer5PdsgpY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1568: Minimum Number of Days to Disconnect Island](https://grid47.xyz/posts/leetcode_1568) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
