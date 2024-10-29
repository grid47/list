
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2567: Minimum Score by Changing Two Elements"
date = "2017-10-20"
description = "Solution to Leetcode 2567"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n - 3] - nums[0];
        int b = nums[n - 1] - nums[2];
        int c = nums[n - 2] - nums[1];
        return min({a, b, c});
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

