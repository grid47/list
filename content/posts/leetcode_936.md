
+++
authors = ["Crafted by Me"]
title = "Leetcode 936: Stamping The Sequence"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 936: Stamping The Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Queue"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stamping-the-sequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        
        int turns = -1, net = 0;
        while(turns) {
            turns = 0;
            for(int sz = stamp.size(); sz > 0; sz--) {
                for(int i = 0; i <= stamp.size() - sz; i++) {
                    string key = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
                    auto pos = target.find(key);
                    while(pos != string::npos) {
                        res.push_back(pos);
                        turns += sz;
                        fill(target.begin() + pos, target.begin() + pos + stamp.size(), '*');
                        pos = target.find(key);
                    }
                }
            }
            // cout << turns << " ";
            net += turns;
        }

        reverse(res.begin(), res.end());
        return net == target.size()? res: vector<int>{};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/936.md" >}}
---
{{< youtube 2QN_0tfvB_E >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #937: Reorder Data in Log Files](https://grid47.xyz/posts/leetcode_937) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
