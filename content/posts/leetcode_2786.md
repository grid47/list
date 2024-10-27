
+++
authors = ["Yasir"]
title = "Leetcode 2786: Visit Array Positions to Maximize Score"
date = "2017-03-13"
description = "Solution to Leetcode 2786"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long maxScore(vector<int>& n, int x) {
        long long eve = n[0] - (n[0] % 2 ? x : 0);
        long long odd = n[0] - (n[0] % 2 ? 0 : x);
        for (int i = 1; i < n.size(); ++i)
            if (n[i] % 2)   odd = n[i] + max(odd, eve - x);
            else            eve = n[i] + max(eve, odd - x);
        return max(eve, odd);
    }
};
{{< /highlight >}}

