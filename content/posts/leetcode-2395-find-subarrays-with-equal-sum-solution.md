
+++
authors = ["grid47"]
title = "Leetcode 2395: Find Subarrays With Equal Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2395: Find Subarrays With Equal Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-subarrays-with-equal-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 1; i < nums.size(); ++i)
        if(!s.insert(nums[i - 1] + nums[i]).second)
            return true;
    return false;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2395.md" >}}
---
{{< youtube 1v-XTlRvUvU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2396: Strictly Palindromic Number](https://grid47.xyz/posts/leetcode-2396-strictly-palindromic-number-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}