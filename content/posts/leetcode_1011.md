
+++
authors = ["Crafted by Me"]
title = "Leetcode 1011: Capacity To Ship Packages Within D Days"
date = "2021-01-25"
description = "Solution to Leetcode 1011"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

