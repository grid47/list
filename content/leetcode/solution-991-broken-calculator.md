
+++
authors = ["grid47"]
title = "Leetcode 991: Broken Calculator"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 991: Broken Calculator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/broken-calculator/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue >= target) return startValue - target;
        
        if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);
        
        return 1 + brokenCalc(startValue, target +1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/991.md" >}}
---
{{< youtube XIiLnBV664A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #994: Rotting Oranges](https://grid47.xyz/leetcode/solution-994-rotting-oranges/) |
| --- |
