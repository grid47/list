
+++
authors = ["grid47"]
title = "Leetcode 2210: Count Hills and Valleys in an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2210: Count Hills and Valleys in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHillValley(vector<int>& nums) {
      int res = 0;
        for(int j = 0, i = 1; i < nums.size() - 1; i++)
          if ((nums[j] < nums[i] && nums[i] > nums[i + 1]) ||
              (nums[j] > nums[i] && nums[i] < nums[i + 1])) {
                res++;
                j = i;
              }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2210.md" >}}
---
{{< youtube I9ZXvpleMDk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2211: Count Collisions on a Road](https://grid47.xyz/posts/leetcode-2210-count-hills-and-valleys-in-an-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
