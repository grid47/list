
+++
authors = ["Crafted by Me"]
title = "Leetcode 90: Subsets II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 90: Subsets II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation"]
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
---
{{< youtube Vn2v6ajA7U0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #91: Decode Ways](https://grid47.xyz/posts/leetcode_91) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

