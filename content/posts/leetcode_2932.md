
+++
authors = ["Yasir"]
title = "Leetcode 2932: Maximum Strong Pair XOR I"
date = "2016-10-18"
description = "Solution to Leetcode 2932"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-strong-pair-xor-i/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            if((nums[j] - nums[i] <= nums[i]) && (res <= (nums[i] ^ nums[j]))){
                // cout << nums[i] << " " << nums[j] << "\n";
                res = max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }
};
{{< /highlight >}}

