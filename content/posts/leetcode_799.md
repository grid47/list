
+++
authors = ["Crafted by Me"]
title = "Leetcode 799: Champagne Tower"
date = "2022-08-26"
description = "Solution to Leetcode 799"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/champagne-tower/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currRow(1, poured);

        for(int i = 0; i <= query_row; i++) {
            vector<double> nextrow(i + 2, 0);
            for(int j = 0; j <= i; j++) {
                if(currRow[j] >= 1) {
                    nextrow[j]      += (currRow[j] - 1)/2.0;
                    nextrow[j + 1]  += (currRow[j] - 1)/2.0;
                    currRow[j]       = 1;
                }
            }
            if(i != query_row) currRow = nextrow;
        }
        return currRow[query_glass];
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/799.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

