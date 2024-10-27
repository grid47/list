
+++
authors = ["Yasir"]
title = "Leetcode 1833: Maximum Ice Cream Bars"
date = "2019-10-22"
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

{{< highlight html >}}
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

