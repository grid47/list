
+++
authors = ["Yasir"]
title = "Leetcode 1238: Circular Permutation in Binary Representation"
date = "2021-06-08"
description = "Solution to Leetcode 1238"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-permutation-in-binary-representation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        for(int i = 0; i < 1 << n; i++)
            res.push_back(start ^ i ^ i >> 1);
        return res;
    }
};
{{< /highlight >}}

