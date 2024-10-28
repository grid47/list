
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2740: Find the Value of the Partition"
date = "2017-04-29"
description = "Solution to Leetcode 2740"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-value-of-the-partition/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[1] - nums[0];
        for(int i = 1; i < nums.size(); i++) {
            res = min(nums[i] - nums[i - 1], res);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

