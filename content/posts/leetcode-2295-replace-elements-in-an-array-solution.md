
+++
authors = ["grid47"]
title = "Leetcode 2295: Replace Elements in an Array"
date = "2024-03-22"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2295.md" >}}
---
{{< youtube xiY9ORyGnDk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2299: Strong Password Checker II](https://grid47.xyz/posts/leetcode-2299-strong-password-checker-ii-solution/) |
| --- |
