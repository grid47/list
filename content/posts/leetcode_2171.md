
+++
authors = ["Yasir"]
title = "Leetcode 2171: Removing Minimum Number of Magic Beans"
date = "2018-11-18"
description = "Solution to Leetcode 2171"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long sum = accumulate(begin(beans), end(beans), 0L);
        sort(beans.begin(), beans.end());
        long long res = LLONG_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, sum - (long long) (n - i) * beans[i]);
        
        return res;
    }
};
{{< /highlight >}}

