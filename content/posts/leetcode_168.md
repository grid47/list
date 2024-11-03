
+++
authors = ["Crafted by Me"]
title = "Leetcode 168: Excel Sheet Column Title"
date = "2024-05-18"
description = "In-depth solution and explanation for Leetcode 168: Excel Sheet Column Title in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/excel-sheet-column-title/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int mod;
        while(columnNumber > 0) {
            mod = --columnNumber % 26;
            char x = ('A' + mod);
            res = x + res;
            columnNumber /= 26;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/168.md" >}}
---
{{< youtube X_vJDpCCuoA >}}

"| 169: Majority Element |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

