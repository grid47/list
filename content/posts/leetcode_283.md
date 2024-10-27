
+++
authors = ["Yasir"]
title = "Leetcode 283: Move Zeroes"
date = "2024-01-19"
description = "Solution to Leetcode 283"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/move-zeroes/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                swap(nums[i], nums[j]), j++;
        }
        while(j < nums.size())
            nums[j++] = 0;
    }
};
{{< /highlight >}}

