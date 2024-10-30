
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1685: Sum of Absolute Differences in a Sorted Array"
date = "2020-03-21"
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
{{< youtube WYe644djV30 >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

