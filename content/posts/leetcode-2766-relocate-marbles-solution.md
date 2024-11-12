
+++
authors = ["grid47"]
title = "Leetcode 2766: Relocate Marbles"
date = "2024-02-04"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2767: Partition String Into Minimum Beautiful Substrings](https://grid47.xyz/posts/leetcode-2767-partition-string-into-minimum-beautiful-substrings-solution/) |
| --- |
