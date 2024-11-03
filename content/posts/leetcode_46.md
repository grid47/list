
+++
authors = ["Crafted by Me"]
title = "Leetcode 46: Permutations"
date = "2024-09-17"
description = "In-depth solution and explanation for Leetcode 46: Permutations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/46.md" >}}
---
{{< youtube s7AvT7cGdSo >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

