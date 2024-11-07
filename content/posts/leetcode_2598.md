
+++
authors = ["Crafted by Me"]
title = "Leetcode 2598: Smallest Missing Non-negative Integer After Operations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2598: Smallest Missing Non-negative Integer After Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[(nums[i] < 0? (nums[i] % value + value)%value: nums[i]%value)]++;
        }
        int idx = 0, mn = INT_MAX;
        for(int i = 0; i < value; i++) {
            if(mp[i] < mn) {
                idx = i;
                mn = mp[i];
            }
        }
        return mn * value + idx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2598.md" >}}
---
{{< youtube NztQwlNn1XA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2600: K Items With the Maximum Sum](https://grid47.xyz/posts/leetcode_2600) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
