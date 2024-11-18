
+++
authors = ["grid47"]
title = "Leetcode 1011: Capacity To Ship Packages Within D Days"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1011: Capacity To Ship Packages Within D Days in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 25000000;
        for(int w: weights)
        left = max(left, w);

        while(left < right) {
            int mid = (left + right) / 2;
            int need =1, cur = 0;
            for(int i = 0; i <  weights.size() && need <= days; cur += weights[i++])
                if(cur + weights[i] > mid)
                cur = 0, need++;
            if(need > days) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1011.md" >}}
---
{{< youtube ER_oLmdc-nw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1014: Best Sightseeing Pair](https://grid47.xyz/leetcode/solution-1014-best-sightseeing-pair/) |
| --- |
