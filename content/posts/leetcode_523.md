
+++
authors = ["Yasir"]
title = "Leetcode 523: Continuous Subarray Sum"
date = "2023-05-25"
description = "Solution to Leetcode 523"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/continuous-subarray-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum %= k;
            if (mp.count(sum))
            {
                if (i - mp[sum] > 1) 
                    return true;
            }
            else mp[sum] = i;
        }
        return false;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

