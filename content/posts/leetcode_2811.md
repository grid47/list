
+++
authors = ["Yasir"]
title = "Leetcode 2811: Check if it is Possible to Split Array"
date = "2017-02-17"
description = "Solution to Leetcode 2811"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] + nums[i + 1] >= m)
                return true;
        return nums.size() < 3;        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

