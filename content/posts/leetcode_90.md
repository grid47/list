
+++
authors = ["Crafted by Me"]
title = "Leetcode 90: Subsets II"
date = "2024-08-04"
description = "Solution to Leetcode 90"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subsets-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<vector<int>, bool> mp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        mp.clear();
        bt(ans, tmp, nums, 0);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &tmp,
            vector<int> &nums, int idx) {
        
        if(idx == nums.size()) {

            if(!mp.count(tmp)) {
                ans.push_back(tmp);
                mp[tmp] = true;
            }
            return;
        }
        
        bt(ans, tmp, nums, idx + 1);
        
        tmp.push_back(nums[idx]);
        bt(ans, tmp, nums, idx + 1);
        tmp.pop_back();            
        
    }
    
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/90.md" >}}
- by gpt
        
---
{{< youtube Vn2v6ajA7U0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

