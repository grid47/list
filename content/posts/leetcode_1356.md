
+++
authors = ["Crafted by Me"]
title = "Leetcode 1356: Sort Integers by The Number of 1 Bits"
date = "2021-02-15"
description = "In-depth solution and explanation for Leetcode 1356: Sort Integers by The Number of 1 Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/)

---

**Code:**

{{< highlight cpp >}}
// class cmp {
//     public:
//     bool operator() (int a, int b) {
//         int x = __builtin_popcount(a);
//         int y = __builtin_popcount(b);
//         if(x == y) return a < b;
//         return x < y;
//     }
// };

bool cmp(int a, int b) {
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        if(x == y) return a < b;
        return x < y;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), cmp);

        return arr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1356.md" >}}
---


"| 1357: Apply Discount Every n Orders |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

