
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 167: Two Sum II - Input Array Is Sorted"
date = "2024-05-15"
description = "Solution to Leetcode 167"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                ans[0] = mp[nums[i]] + 1;
                ans[1] = i + 1;
                return ans;
            } else {
                mp[target - nums[i]] = i;
            }
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

