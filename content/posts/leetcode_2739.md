
+++
authors = ["Crafted by Me"]
title = "Leetcode 2739: Total Distance Traveled"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2739: Total Distance Traveled in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/total-distance-traveled/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distanceTraveled(int mt, int at) {        
        int net = 0;
        
        while(mt > 0) {
            int red = min(5, mt);
            mt -= red;
            net += red * 10;
            if(red == 5 && at > 0) {
                mt += 1;
                at--;
            }
        }
        
        return net;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2739.md" >}}
---
{{< youtube h7FESSswnR8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2740: Find the Value of the Partition](https://grid47.xyz/posts/leetcode_2740) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
