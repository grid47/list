
+++
authors = ["Yasir"]
title = "Leetcode 930: Binary Subarrays With Sum"
date = "2022-04-11"
description = "Solution to Leetcode 930"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal -1);
    }
    
    int atmost(vector<int> &nums, int s) {
        if(s < 0) return 0;
        int res = 0, j = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            s -= nums[i];
            while(s < 0) s += nums[j++];
            res += (i - j + 1);
        }
        return res;
    }
    
};
{{< /highlight >}}

