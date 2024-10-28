
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1833: Maximum Ice Cream Bars"
date = "2019-10-23"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

