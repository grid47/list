
+++
authors = ["Yasir"]
title = "Leetcode 3169: Count Days Without Meetings"
date = "2016-02-24"
description = "Solution to Leetcode 3169"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-days-without-meetings/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& mt) {
        int net = days;
        int n = mt.size();
        sort(mt.begin(), mt.end());
        vector<int> tuned;
        vector<int> pt = mt[0];
        if(n == 1) return net - (pt[1] - pt[0] + 1);
        for(int i = 1; i < n; i++) {
            if (mt[i][0] <= pt[1])
                pt[1] = max(pt[1], mt[i][1]);
            else {
                net -= pt[1] - pt[0] + 1;
                pt = mt[i];
            }
            if(i + 1 == n) net -= pt[1] - pt[0] + 1;
        }
        return net;
    }
};
{{< /highlight >}}

