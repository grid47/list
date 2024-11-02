
+++
authors = ["Crafted by Me"]
title = "Leetcode 2761: Prime Pairs With Target Sum"
date = "2016-04-11"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

