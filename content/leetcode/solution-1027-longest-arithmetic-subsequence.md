
+++
authors = ["grid47"]
title = "Leetcode 1027: Longest Arithmetic Subsequence"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1027: Longest Arithmetic Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "-NIlLdVKBFs"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<unordered_map<int, int>> mp;
        mp.resize(n);
        int res = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = nums[j] - nums[i];
                if(mp[j].count(d)) mp[i][d] = max(mp[i][d], mp[j][d] + 1);
                else mp[i][d] = max(mp[i][d], 2);
                res = max(mp[i][d], res);
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1027.md" >}}
---
{{< youtube -NIlLdVKBFs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1029: Two City Scheduling](https://grid47.xyz/leetcode/solution-1029-two-city-scheduling/) |
| --- |
