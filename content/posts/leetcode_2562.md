
+++
authors = ["Crafted by Me"]
title = "Leetcode 2562: Find the Array Concatenation Value"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2562: Find the Array Concatenation Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-array-concatenation-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
  long long findTheArrayConcVal(vector<int>& nums) {
      long long res = 0, sz = nums.size();
      for (int i = 0, j = sz - 1; i <= j; ++i, --j)
          if (i < j)
              res += nums[i] * pow(10, (int)log10(nums[j]) + 1) + nums[j];
          else
              res += nums[i];
      return res;
  }
};
{{< /highlight >}}


---
{{< youtube OgX8lEhgW9g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2563: Count the Number of Fair Pairs](https://grid47.xyz/posts/leetcode_2563) |
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
