
+++
authors = ["grid47"]
title = "Leetcode 1833: Maximum Ice Cream Bars"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1833: Maximum Ice Cream Bars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "40qxrlPwBMM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-ice-cream-bars/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0;
        for(int i = 0; i < costs.size(); i++) {
            sum += costs[i];
            if(sum == coins)
                return i +1;
            if(sum > coins)
                return i;
        }
        return costs.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1833.md" >}}
---
{{< youtube 40qxrlPwBMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1834: Single-Threaded CPU](https://grid47.xyz/leetcode/solution-1834-single-threaded-cpu/) |
| --- |
