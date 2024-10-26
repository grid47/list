
+++
authors = ["Yasir"]
title = "Leetcode 667: Beautiful Arrangement II"
date = "2022-12-30"
description = "Solution to Leetcode 667"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/beautiful-arrangement-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for(int i = 1, j = n; i <= j; ) {
            if(k > 0) {
                res.push_back(k--%2? i++: j--);
            } else res.push_back(i++);
        }
        return res;
    }
};
{{< /highlight >}}

