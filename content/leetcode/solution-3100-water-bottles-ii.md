
+++
authors = ["grid47"]
title = "Leetcode 3100: Water Bottles II"
date = "2024-01-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3100: Water Bottles II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Ll_mTkG1rEc"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/water-bottles-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxBottlesDrunk(int bot, int ex) {
        
        int full = bot;
        int empty = 0;
        int drunk = 0;
        
        
        while((empty + full) >= ex) {
            drunk   += full;
            empty   += full;
            full     = 0;
            while(empty >= ex) {
                empty   -= ex;
                full    += 1;
                ex      += 1;                
            }
        }
        
        return drunk + full;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3100.md" >}}
---
{{< youtube Ll_mTkG1rEc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3101: Count Alternating Subarrays](https://grid47.xyz/leetcode/solution-3101-count-alternating-subarrays/) |
| --- |
