
+++
authors = ["grid47"]
title = "Leetcode 1072: Flip Columns For Maximum Number of Equal Rows"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1072: Flip Columns For Maximum Number of Equal Rows in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mtx) {
        unordered_map<string, int> mp;
        for(auto x: mtx) {
            string s = "";
            int top = x[0];
            for(int i = 0; i < x.size(); i++) {
                if(x[i] == top) s += '1';
                else s += '0';
            }
            mp[s]++;
        }
        int res = 0;
        for(auto [k, v]: mp)
            res = max(res, v);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1072.md" >}}
---
{{< youtube xj3ltfSh9Io >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1073: Adding Two Negabinary Numbers](https://grid47.xyz/posts/leetcode-1073-adding-two-negabinary-numbers-solution/) |
| --- |
