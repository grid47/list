
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2295: Replace Elements in an Array"
date = "2018-07-20"
description = "Solution to Leetcode 2295"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-elements-in-an-array/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& ops) {
        
        map<int, int> mp;
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
            mp[nums[i]] = i;
        
        for(auto it: ops) {
            int idx = mp[it[0]];
            mp.erase(it[0]);
            nums[idx] = it[1];
            mp[it[1]] = idx;
        }
        return nums;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

