
+++
authors = ["Crafted by Me"]
title = "Leetcode 1833: Maximum Ice Cream Bars"
date = "2018-10-26"
description = "Solution to Leetcode 1833"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

