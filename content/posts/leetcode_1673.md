
+++
authors = ["Yasir"]
title = "Leetcode 1673: Find the Most Competitive Subsequence"
date = "2020-03-30"
description = "Solution to Leetcode 1673"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-most-competitive-subsequence/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        vector<int> stk;
        for(int i = 0; i < nums.size(); i++) {

            while (!stk.empty()          &&
                 stk.back() > nums[i] &&
                (stk.size() + nums.size() - (i + 1)) >= k )
                stk.pop_back();

            if(stk.size() < k)
                stk.push_back(nums[i]);

        }
        
        return stk;
        
    }
};
{{< /highlight >}}

