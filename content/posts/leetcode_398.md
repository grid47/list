
+++
authors = ["Crafted by Me"]
title = "Leetcode 398: Random Pick Index"
date = "2023-10-01"
description = "In-depth solution and explanation for Leetcode 398: Random Pick Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/random-pick-index/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        mp[nums[i]].push_back(i);
    }
    
    int pick(int target) { 
        int sz = mp[target].size();
        int res = mp[target][rand()%sz];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/398.md" >}}
---
{{< youtube 1rDRyxPcmvY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #399: Evaluate Division](https://grid47.xyz/posts/leetcode_399) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

