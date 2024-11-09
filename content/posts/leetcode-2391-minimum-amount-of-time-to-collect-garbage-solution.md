
+++
authors = ["grid47"]
title = "Leetcode 2391: Minimum Amount of Time to Collect Garbage"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2391: Minimum Amount of Time to Collect Garbage in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {}, res = 0;        
        for(int i = 0; i < garbage.size(); i++) {
            res += garbage[i].size();
            for(char c : garbage[i])
                last[c] = i;
        }

        for(int j = 1; j < travel.size(); j++)
            travel[j] += travel[j - 1];
        
        for(int c : "PGM")
        if(last[c])
        res += travel[last[c] - 1];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2391.md" >}}
---
{{< youtube gpjKAXQpOMM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2395: Find Subarrays With Equal Sum](https://grid47.xyz/posts/leetcode-2391-minimum-amount-of-time-to-collect-garbage-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
