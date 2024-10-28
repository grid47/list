
+++
authors = ["Yasir"]
title = "Leetcode 2461: Maximum Sum of Distinct Subarrays With Length K"
date = "2018-02-02"
description = "Solution to Leetcode 2461"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long sum = 0, ans = 0;
        int n = nums.size(), j = 0;
        
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            
            sum += nums[i];
            mp[nums[i]]++;
            
            while(i - j + 1 > k || mp[nums[i]] > 1) {
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            if((i - j + 1) == k) {
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

