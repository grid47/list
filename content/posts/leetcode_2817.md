
+++
authors = ["Crafted by Me"]
title = "Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint"
date = "2016-02-15"
description = "Solution to Leetcode 2817"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
    set<int> s;
    int res = INT_MAX;
    for (int i = x; i < nums.size() && res > 0; ++i) {
        s.insert(nums[i - x]);
        auto it = s.upper_bound(nums[i]);
        if (it != begin(s))
            res = min(res, nums[i] - *prev(it));
        if (it != end(s))
            res = min(res, *it - nums[i]);
    }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

