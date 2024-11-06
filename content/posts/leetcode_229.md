
+++
authors = ["Crafted by Me"]
title = "Leetcode 229: Majority Element II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 229: Majority Element II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/majority-element-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            std::vector<int> result;
    int n = nums.size();

    if (n == 0) return result;

    int cnt1 = 0, cnt2 = 0;
    int cnd1 = 0, cnd2 = 0;

    for (int i = 0; i < n; i++) {
        int val = nums[i];

        if (val == cnd1) cnt1++;
        else if (val == cnd2) cnt2++;
        else if (cnt1 == 0) { cnt1 = 1; cnd1 = val; }
        else if (cnt2 == 0) { cnt2 = 1; cnd2 = val; }
        else { cnt1--; cnt2--; }
    }

    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int val = nums[i];

        if (val == cnd1) cnt1++;
        else if (val == cnd2) cnt2++;
    }

    n = n / 3;

    if (cnt1 > n) result.push_back(cnd1);
    if (cnt2 > n) result.push_back(cnd2);

    return result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/229.md" >}}
---
{{< youtube Eua-UrQ_ANo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #230: Kth Smallest Element in a BST](https://grid47.xyz/posts/leetcode_230) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

