
+++
authors = ["Crafted by Me"]
title = "Leetcode 2766: Relocate Marbles"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2766: Relocate Marbles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/relocate-marbles/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> mp;  
        for(auto n: nums) mp[n] = 1;
        for(int i = 0; i < moveFrom.size(); ++i){
            if(mp[moveFrom[i]] && moveFrom[i] != moveTo[i]) {
                mp[moveTo[i]] = 1;  mp[moveFrom[i]] = 0;
            }
        }
        vector<int> ans;
        for(auto m: mp) if(m.second) ans.push_back(m.first);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2766.md" >}}
---
{{< youtube bH2EmMR5jpU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2767: Partition String Into Minimum Beautiful Substrings](https://grid47.xyz/posts/leetcode_2767) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
