
+++
authors = ["grid47"]
title = "Leetcode 1436: Destination City"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1436: Destination City in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/destination-city/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> mp;
        for(auto s: paths)
            mp[s[0]] = s[1];
        
        string ans = paths[0][0];
        while(mp.count(ans)) {
            ans = mp[ans];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1436.md" >}}
---
{{< youtube Hi8vMnnTZHE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://grid47.xyz/posts/leetcode-1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit-solution/) |
| --- |
