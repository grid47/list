
+++
authors = ["grid47"]
title = "Leetcode 893: Groups of Special-Equivalent Strings"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 893: Groups of Special-Equivalent Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "tbtXPKkA2Zw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/groups-of-special-equivalent-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string, string>> s;
        for(const auto& w: words) {
            pair<string, string> p;
            for(int i = 0; i < w.size(); i++) {
                if (i % 2) p.first  += w[i];
                else       p.second += w[i];
            }
            sort(p.first.begin(), p.first.end());
            sort(p.second.begin(), p.second.end());
            s.insert(p);
        }
        return s.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/893.md" >}}
---
{{< youtube tbtXPKkA2Zw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #894: All Possible Full Binary Trees](https://grid47.xyz/leetcode/solution-894-all-possible-full-binary-trees/) |
| --- |
