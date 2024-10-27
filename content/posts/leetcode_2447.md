
+++
authors = ["Yasir"]
title = "Leetcode 2447: Number of Subarrays With GCD Equal to K"
date = "2018-02-15"
description = "Solution to Leetcode 2447"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    int subarrayGCD(vector<int>& nums, int k) {        
        int cnt = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && nums[j] % k == 0; j++) {
                nums[i] = __gcd(nums[i], nums[j]);
                cnt += (nums[i] == k);
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

