
+++
authors = ["Yasir"]
title = "Leetcode 2761: Prime Pairs With Target Sum"
date = "2017-04-07"
description = "Solution to Leetcode 2761"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/prime-pairs-with-target-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:

    vector<vector<int>> findPrimePairs(int n) {

        vector<int> net(n + 1, true);
        net[1] = false;
        for(int i = 2; i < n / 2 + 1; i++)
        for(int j = 2; j * i < n; j++)
            net[j * i] = false;

        map<int, int> mp;
        vector<vector<int>> res;

        for(int i = 1; i < n / 2 + 1; i++)
            if(net[i] && net[n - i]) 
            res.push_back({i, n - i});

        return res;
    }
};
{{< /highlight >}}

