
+++
authors = ["Yasir"]
title = "Leetcode 78: Subsets"
date = "2024-08-10"
description = "Solution to Leetcode 78"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subsets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> nums;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<vector<int>> ans;
        vector<int> tmp;
        bt(ans, tmp, 0);
        return ans;
    }
    
    void bt(vector<vector<int>> & ans, vector<int> &tmp, int idx) {
        if(idx == nums.size()) {
            ans.push_back(tmp);
            return;
        }

        
        bt(ans, tmp, idx + 1);
        
        tmp.push_back(nums[idx]);
        bt(ans, tmp, idx + 1);
        tmp.pop_back();
        
    }
};
{{< /highlight >}}

