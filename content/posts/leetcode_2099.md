
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2099: Find Subsequence of Length K With the Largest Sum"
date = "2019-02-01"
description = "Solution to Leetcode 2099"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v(nums.begin(), nums.end());
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
        int cnt = count(v.begin(), v.begin() + k, v[k - 1]);
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
            if((nums[i] > v[k - 1]) ||
               (nums[i] == v[k - 1] && (cnt-- > 0)))
                res.push_back(nums[i]);
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

