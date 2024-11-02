
+++
authors = ["Crafted by Me"]
title = "Leetcode 2656: Maximum Sum With Exactly K Elements "
date = "2017-07-26"
description = "Solution to Leetcode 2656"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int i = *max_element(nums.begin(), nums.end());
        return i * k + k * (k - 1) / 2;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

