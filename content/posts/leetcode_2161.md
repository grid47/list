
+++
authors = ["Crafted by Me"]
title = "Leetcode 2161: Partition Array According to Given Pivot"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2161: Partition Array According to Given Pivot in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-according-to-given-pivot/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high;
        for(auto num: nums) {
            if(num < pivot) low++;
            else if(num == pivot) same++;
        }
        high = low + same;
        same = low;
        low = 0;
        vector<int> res(nums.size(), 0);
        for(auto num: nums) {
            if(num < pivot) res[low++] = num;
            else if(num == pivot) res[same++] = num;
            else res[high++] = num;
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube Ie7eN2NAa6w >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2162: Minimum Cost to Set Cooking Time](https://grid47.xyz/posts/leetcode_2162) |
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
