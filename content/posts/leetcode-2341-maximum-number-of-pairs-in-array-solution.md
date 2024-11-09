
+++
authors = ["grid47"]
title = "Leetcode 2341: Maximum Number of Pairs in Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2341: Maximum Number of Pairs in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  // even counter
  vector<int> numberOfPairs(vector<int>& nums) {
      int cnt[101] = {}, pairs = 0;
      for (int n : nums)
          pairs += ++cnt[n] % 2 == 0 ? 1 : 0;
      return { pairs, (int)nums.size() - pairs * 2 };
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2341.md" >}}
---
{{< youtube 9KeeDZ6tcy4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2342: Max Sum of a Pair With Equal Sum of Digits](https://grid47.xyz/posts/leetcode-2342-max-sum-of-a-pair-with-equal-sum-of-digits-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
