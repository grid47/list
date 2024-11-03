
+++
authors = ["Crafted by Me"]
title = "Leetcode 40: Combination Sum II"
date = "2024-09-23"
description = "In-depth solution and explanation for Leetcode 40: Combination Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combination-sum-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<vector<int>, bool> mp;
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
               
        vector<vector<int>> ans;
        vector<int> tmp;
        mp.clear();
        sort(cand.begin(), cand.end());
         bt(ans, cand, 0, target, tmp);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &nums, int idx,
            int sum, vector<int> &tmp) {
        if(sum == 0) {
            ans.push_back(tmp);
            return;
        }
        if(sum < 0 || idx == nums.size()) return;
        
        for(int i = idx; i < nums.size(); i++) {
            if(i && i > idx && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            bt(ans, nums, i + 1, sum - nums[i], tmp);
            tmp.pop_back();
        }
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/40.md" >}}
---
{{< youtube FAjCxGNlxgk >}}

| Next : [LeetCode #41: First Missing Positive](grid47.xyz/leetcode_41) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

