
+++
authors = ["Crafted by Me"]
title = "Leetcode 893: Groups of Special-Equivalent Strings"
date = "2022-05-24"
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

