
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 398: Random Pick Index"
date = "2023-09-27"
description = "Solution to Leetcode 398"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

