
+++
authors = ["Yasir"]
title = "Leetcode 713: Subarray Product Less Than K"
date = "2022-11-14"
description = "Solution to Leetcode 713"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarray-product-less-than-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        long long prod = 1;
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            
            while(prod >= k && j <= i) {
                prod /= nums[j++];
            }
            
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

