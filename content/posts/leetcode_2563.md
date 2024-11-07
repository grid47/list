
+++
authors = ["Crafted by Me"]
title = "Leetcode 2563: Count the Number of Fair Pairs"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2563: Count the Number of Fair Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            int l = lower - nums[i];
            int r = upper - nums[i];
            int u = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
            int b = max((int)(lower_bound(nums.begin(), nums.end(), l) - nums.begin()), i + 1);
            cnt +=  (u < b)? 0: u - b;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2563.md" >}}
---
{{< youtube Z9hOAQFSQ_I >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2564: Substring XOR Queries](https://grid47.xyz/posts/leetcode_2564) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
