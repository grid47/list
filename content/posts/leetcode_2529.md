
+++
authors = ["Crafted by Me"]
title = "Leetcode 2529: Maximum Count of Positive Integer and Negative Integer"
date = "2016-11-29"
description = "Solution to Leetcode 2529"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0) pos++;
            else if(nums[i] < 0) neg++;
        return max(pos, neg);
    }
};
{{< /highlight >}}


---
{{< youtube 4uhvXmOp5Do >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

