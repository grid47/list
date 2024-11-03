
+++
authors = ["Crafted by Me"]
title = "Leetcode 1673: Find the Most Competitive Subsequence"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1673: Find the Most Competitive Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1673.md" >}}
---
{{< youtube GBJFxSD3B_s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1674: Minimum Moves to Make Array Complementary](https://grid47.xyz/posts/leetcode_1674) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

