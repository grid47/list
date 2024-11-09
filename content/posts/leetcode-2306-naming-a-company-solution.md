
+++
authors = ["grid47"]
title = "Leetcode 2306: Naming a Company"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2306: Naming a Company in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Enumeration"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/naming-a-company/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> count[26];
        for (auto& s: ideas)
            count[s[0] - 'a'].insert(s.substr(1));
        long long res = 0;
        for(int i = 0; i < 26; ++i)
            for(int j = i + 1; j < 26; ++j) {   
                long long c1 = 0L, c2 = 0L;
                for (auto& c: count[i])
                    if (!count[j].count(c)) c1++;
                for (auto& c: count[j])
                    if (!count[i].count(c)) c2++;
                res += c1 * c2;
            }
        return res * 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2306.md" >}}
---
{{< youtube NrHpgTScOcY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2309: Greatest English Letter in Upper and Lower Case](https://grid47.xyz/posts/leetcode-2309-greatest-english-letter-in-upper-and-lower-case-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
