
+++
authors = ["Yasir"]
title = "Leetcode 974: Subarray Sums Divisible by K"
date = "2022-02-26"
description = "Solution to Leetcode 974"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), sum = 0;        
        vector<int> frq(k, 0);
        frq[0] = 1;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            int rm = sum % k;
            if(rm < 0) rm += k;            
            res += frq[rm];
            frq[rm]++;
        }
        return res;
    }
};
{{< /highlight >}}

