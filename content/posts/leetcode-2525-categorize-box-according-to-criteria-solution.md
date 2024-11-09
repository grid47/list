
+++
authors = ["grid47"]
title = "Leetcode 2525: Categorize Box According to Criteria"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2525: Categorize Box According to Criteria in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/categorize-box-according-to-criteria/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        double v = (double) length * width * height;
        if(length >= 10000 || width >= 10000 || 
           height >= 10000 || v >= 1000000000)
            bulky = true;
        if(mass >= 100)
            heavy = true;
        string category;
            if(bulky && heavy)
                category = "Both";
            else if (!bulky && !heavy)
                category = "Neither";
            else if (bulky)
                category = "Bulky";
            else if (heavy)
                category = "Heavy";
        return category;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2525.md" >}}
---
{{< youtube dIciftyQXHo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2526: Find Consecutive Integers from a Data Stream](https://grid47.xyz/posts/leetcode-2526-find-consecutive-integers-from-a-data-stream-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
