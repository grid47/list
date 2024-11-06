
+++
authors = ["Crafted by Me"]
title = "Leetcode 2073: Time Needed to Buy Tickets"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2073: Time Needed to Buy Tickets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int res = 0, key = nums[k];
        for(int i = 0; i < nums.size(); i++) {
          res += min(key - (i > k), nums[i]);
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube cVmS9N6kf2Y >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2074: Reverse Nodes in Even Length Groups](https://grid47.xyz/posts/leetcode_2074) |
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
