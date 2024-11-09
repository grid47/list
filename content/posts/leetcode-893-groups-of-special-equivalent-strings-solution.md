
+++
authors = ["grid47"]
title = "Leetcode 893: Groups of Special-Equivalent Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 893: Groups of Special-Equivalent Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #894: All Possible Full Binary Trees](https://grid47.xyz/posts/leetcode-893-groups-of-special-equivalent-strings-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
