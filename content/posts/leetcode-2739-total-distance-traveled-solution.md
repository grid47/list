
+++
authors = ["grid47"]
title = "Leetcode 2739: Total Distance Traveled"
date = "2024-02-07"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2740: Find the Value of the Partition](https://grid47.xyz/posts/leetcode-2740-find-the-value-of-the-partition-solution/) |
| --- |
