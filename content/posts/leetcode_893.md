
+++
authors = ["Yasir"]
title = "Leetcode 893: Groups of Special-Equivalent Strings"
date = "2022-05-18"
description = "Solution to Leetcode 893"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/groups-of-special-equivalent-strings/description/)

---

**Code:**

{{< highlight html >}}
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

