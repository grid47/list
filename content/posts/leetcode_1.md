
+++
authors = ["Yasir"]
title = "Leetcode 1: Two Sum"
date = "2024-10-28"
description = "Solution to Leetcode 1"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/two-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                return { mp[nums[i]], i };
            } else {
                mp[target - nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

