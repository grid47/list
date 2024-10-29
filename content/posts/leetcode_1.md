
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1: Two Sum"
date = "2024-10-29"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

