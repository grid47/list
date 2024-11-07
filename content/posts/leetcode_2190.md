
+++
authors = ["Crafted by Me"]
title = "Leetcode 2190: Most Frequent Number Following Key In an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2190: Most Frequent Number Following Key In an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int mostFrequent(vector<int>& nums, int key) {
    int cnt[1001] = {}, res = 0;
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
            res = nums[i];
    return res;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2190.md" >}}
---
{{< youtube 0KHTVvSX7CE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2191: Sort the Jumbled Numbers](https://grid47.xyz/posts/leetcode_2191) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
