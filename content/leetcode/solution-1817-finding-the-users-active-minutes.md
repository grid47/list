
+++
authors = ["grid47"]
title = "Leetcode 1817: Finding the Users Active Minutes"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1817: Finding the Users Active Minutes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pE6qW1KRl4A"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pE6qW1KRl4A/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/finding-the-users-active-minutes/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
        vector<int> res(k);
        for(auto &l : logs) 
        m[l[0]].insert(l[1]);
        for(auto &p: m)
        ++res[p.second.size() - 1];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1817.md" >}}
---
{{< youtube pE6qW1KRl4A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1818: Minimum Absolute Sum Difference](https://grid47.xyz/leetcode/solution-1818-minimum-absolute-sum-difference/) |
| --- |
