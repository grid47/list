
+++
authors = ["grid47"]
title = "Leetcode 2451: Odd String Difference"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2451: Odd String Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/odd-string-difference/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    string difference(string& s) {
        string d;
        
        for (int i = 0; i < s.size() - 1; i++) {
            d += s[i + 1] - s[i];
        }
        
        return d;
    }
public:
    string oddString(vector<string>& words) {
        int  n = words[0].size();
        unordered_map<string, vector<string>> mp;
        for (auto &it : words) {
            mp[difference(it)].push_back(it);
        }
        
        for (auto &it : mp) {
            if (it.second.size() == 1) return it.second[0];
        }
        
        return "";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2451.md" >}}
---
{{< youtube mxdN0xJiJDc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2452: Words Within Two Edits of Dictionary](https://grid47.xyz/posts/leetcode-2452-words-within-two-edits-of-dictionary-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}