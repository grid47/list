
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 3137: Minimum Number of Operations to Make Word K-Periodic"
date = "2016-03-30"
description = "Solution to Leetcode 3137"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        
        int n = s.size();
        map<string, int> mp;
        
        for(int i = 0; i < n / k; i++) {
            mp[s.substr(i * k, k)]++;
        }
        
        int lg = 0, net = 0;
        for(auto it: mp) {
            lg = max(lg, it.second);
            net += it.second;
        }
        
        return net - lg;
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

