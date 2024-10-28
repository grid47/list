
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 724: Find Pivot Index"
date = "2022-11-05"
description = "Solution to Leetcode 724"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-pivot-index/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++) {
            right -= nums[i];
            if(right == left) return i;
            left  += nums[i];
        }
        return -1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

