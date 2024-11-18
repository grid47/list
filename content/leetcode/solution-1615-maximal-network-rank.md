
+++
authors = ["grid47"]
title = "Leetcode 1615: Maximal Network Rank"
date = "2024-05-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1615: Maximal Network Rank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximal-network-rank/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> inward(n, 0);
        map<int, set<int>> mp;
        for(auto it: roads) {
            inward[it[0]]++;
            inward[it[1]]++;
            mp[it[0]].insert(it[1]);
            mp[it[1]].insert(it[0]);
        }
        
        int mx = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                mx = max(mx, inward[i] + inward[j] - (mp.count(i) && mp[i].count(j)? 1: 0));
            }
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1615.md" >}}
---
{{< youtube WCfyVhtldoU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1616: Split Two Strings to Make Palindrome](https://grid47.xyz/leetcode/solution-1616-split-two-strings-to-make-palindrome/) |
| --- |
