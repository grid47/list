
+++
authors = ["grid47"]
title = "Leetcode 1011: Capacity To Ship Packages Within D Days"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1014: Best Sightseeing Pair](https://grid47.xyz/posts/leetcode-1011-capacity-to-ship-packages-within-d-days-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
