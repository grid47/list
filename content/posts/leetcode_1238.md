
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1238: Circular Permutation in Binary Representation"
date = "2021-06-10"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
