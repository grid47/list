
+++
authors = ["Crafted by Me"]
title = "Leetcode 1250: Check If It Is a Good Array"
date = "2021-06-01"
description = "In-depth solution and explanation for Leetcode 1250: Check If It Is a Good Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-it-is-a-good-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd = nums[0];
        for(int i = 1; i < nums.size(); i++)
            gcd = __gcd(gcd, nums[i]);
        return gcd == 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1250.md" >}}
---


| Next : [LeetCode #1251: Average Selling Price](grid47.xyz/leetcode_1251) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

