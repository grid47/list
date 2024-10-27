
+++
authors = ["Yasir"]
title = "Leetcode 799: Champagne Tower"
date = "2022-08-21"
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

{{< highlight html >}}
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

