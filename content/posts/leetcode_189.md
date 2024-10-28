
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 189: Rotate Array"
date = "2024-04-23"
description = "Solution to Leetcode 189"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rotate-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        rev(nums, 0, nums.size() - 1);
        rev(nums, 0, k - 1);
        rev(nums, k, nums.size() - 1);
        
    }
    
    void rev(vector<int>& nums, int i, int j) {
        while(i <= j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

