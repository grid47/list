
+++
authors = ["Crafted by Me"]
title = "Leetcode 1491: Average Salary Excluding the Minimum and Maximum Salary"
date = "2019-10-03"
description = "Solution to Leetcode 1491"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double average(vector<int>& nums) {
        int n = nums.size();
        double sum = 0, mx = nums[0], mn = nums[0];
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mx = max((double)nums[i], mx);
            mn = min((double)nums[i], mn);
        }
        return (sum - mx - mn) / (n - 2);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

