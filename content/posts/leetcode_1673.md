
+++
authors = ["Crafted by Me"]
title = "Leetcode 1673: Find the Most Competitive Subsequence"
date = "2020-04-04"
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

{{< highlight cpp >}}
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


---
{{< youtube GBJFxSD3B_s >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

