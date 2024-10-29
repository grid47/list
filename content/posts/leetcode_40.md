
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 40: Combination Sum II"
date = "2024-09-20"
description = "Solution to Leetcode 40"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

