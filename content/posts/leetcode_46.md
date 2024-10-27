
+++
authors = ["Yasir"]
title = "Leetcode 46: Permutations"
date = "2024-09-12"
description = "Solution to Leetcode 46"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/permutations/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, bool> mp;
        vector<vector<int>> ans;
        vector<int> tmp;
        bt(ans, tmp, nums, 0, mp);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, int idx, map<int, bool> &mp) {
        if(idx == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) continue;
            mp[nums[i]] = true;
            tmp.push_back(nums[i]);
            bt(ans, tmp, nums, idx + 1, mp);
            tmp.pop_back();
            mp.erase(nums[i]);
        }
    }
};
{{< /highlight >}}

