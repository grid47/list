
+++
authors = ["Yasir"]
title = "Leetcode 2302: Count Subarrays With Score Less Than K"
date = "2018-07-10"
description = "Solution to Leetcode 2302"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, j = 0, res = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            while(sum * (i - j + 1) >= k) sum -= nums[j++];
            
            res += (i - j + 1);
        }
        
        return res;
    }
};
{{< /highlight >}}

