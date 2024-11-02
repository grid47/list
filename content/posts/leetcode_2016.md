
+++
authors = ["Crafted by Me"]
title = "Leetcode 2016: Maximum Difference Between Increasing Elements"
date = "2019-04-27"
description = "Solution to Leetcode 2016"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], res = -1;
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

