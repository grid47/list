
+++
authors = ["Yasir"]
title = "Leetcode 645: Set Mismatch"
date = "2023-01-21"
description = "Solution to Leetcode 645"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/set-mismatch/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        for(int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            ans[1] ^= (i+1) ^ val;
            if (nums[val-1] < 0) ans[0] = val;
            else nums[val-1] = -nums[val-1];
        }
        ans[1] ^= ans[0];
        return ans;        
    }
};
{{< /highlight >}}

