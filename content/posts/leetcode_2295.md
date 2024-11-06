
+++
authors = ["Crafted by Me"]
title = "Leetcode 2295: Replace Elements in an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2295: Replace Elements in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-elements-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& ops) {
        
        map<int, int> mp;
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
            mp[nums[i]] = i;
        
        for(auto it: ops) {
            int idx = mp[it[0]];
            mp.erase(it[0]);
            nums[idx] = it[1];
            mp[it[1]] = idx;
        }
        return nums;
    }
};
{{< /highlight >}}


---
{{< youtube xiY9ORyGnDk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2296: Design a Text Editor](https://grid47.xyz/posts/leetcode_2296) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

