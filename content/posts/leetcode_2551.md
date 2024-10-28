
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2551: Put Marbles in Bags"
date = "2017-11-04"
description = "Solution to Leetcode 2551"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/put-marbles-in-bags/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    long long putMarbles(vector<int>& weights, int k) {
        
        vector<int> diff;
        int n = weights.size();
        for(int i = 1; i < n; i++)
            diff.push_back(weights[i] + weights[i - 1]);
        
        sort(diff.begin(), diff.end());
        
        long long ma = 0, mi = 0;
        for(int i = 0; i + 1 < k && i < diff.size(); i++) {
            mi += diff[i];
            ma += diff[n - 2 - i];
        }
        
        return ma - mi;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

