
+++
authors = ["Crafted by Me"]
title = "Leetcode 1487: Making File Names Unique"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1487: Making File Names Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/making-file-names-unique/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> mp;
        
        for(int i = 0; i < names.size(); i++) {
            
            if(mp.count(names[i])) {
                int k = mp[names[i]];
                while(mp.count(names[i] + "(" + to_string(k) + ")")) {
                    k++;
                    mp[names[i]]++;
                }
                mp[names[i]]++;
                names[i] = names[i] + "(" + to_string(k) + ")";
            }

            mp[names[i]] = 1;
        }
        return names;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1487.md" >}}
---
{{< youtube B9hKZonstN0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1488: Avoid Flood in The City](https://grid47.xyz/posts/leetcode_1488) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

