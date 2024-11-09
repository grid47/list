
+++
authors = ["grid47"]
title = "Leetcode 46: Permutations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 46: Permutations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/permutations/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/46.jpeg" 
    alt="A sequence of shimmering, rotating orbs, rearranging gently in endless variations."
    caption="Solution to LeetCode 46: Permutations Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #47: Permutations II](https://grid47.xyz/posts/leetcode_47) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
