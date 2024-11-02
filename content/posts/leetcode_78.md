
+++
authors = ["Crafted by Me"]
title = "Leetcode 78: Subsets"
date = "2023-08-16"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/78.md" >}}
---
{{< youtube UP3dOYJa05s >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

