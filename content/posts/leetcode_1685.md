
+++
authors = ["Crafted by Me"]
title = "Leetcode 1685: Sum of Absolute Differences in a Sorted Array"
date = "2019-03-23"
description = "Solution to Leetcode 1685"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int z = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            z += nums[i] - nums[0];
        vector<int> ans(n, 0);
        ans[0] = z;
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube WYe644djV30 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

