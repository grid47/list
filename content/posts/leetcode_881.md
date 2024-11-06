
+++
authors = ["Crafted by Me"]
title = "Leetcode 881: Boats to Save People"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 881: Boats to Save People in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/boats-to-save-people/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int lo = 0, hi = people.size() - 1;
        int boats = 0;
        while(lo <= hi) {
            
            if(people[lo] + people[hi] <= limit) {
                lo += 1;
                hi -= 1;
            } else hi -= 1;
            
            boats++;
        }
        
        return boats;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/881.md" >}}
---
{{< youtube FygGZScawYs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #882: Reachable Nodes In Subdivided Graph](https://grid47.xyz/posts/leetcode_882) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

