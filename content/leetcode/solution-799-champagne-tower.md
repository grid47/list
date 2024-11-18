
+++
authors = ["grid47"]
title = "Leetcode 799: Champagne Tower"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 799: Champagne Tower in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/champagne-tower/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/799.webp" 
    alt="A tower of champagne glasses where the champagne is poured, each glass softly glowing as it fills."
    caption="Solution to LeetCode 799: Champagne Tower Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube LQ8TuG_QADM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #802: Find Eventual Safe States](https://grid47.xyz/leetcode/solution-802-find-eventual-safe-states/) |
| --- |
