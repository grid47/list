
+++
authors = ["Yasir"]
title = "Leetcode 2357: Make Array Zero by Subtracting Equal Amounts"
date = "2018-05-16"
description = "Solution to Leetcode 2357"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = 0, res = 0, diff;
        for(int i = 0; i < nums.size(); i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                res++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

