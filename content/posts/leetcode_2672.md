
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2672: Number of Adjacent Elements With the Same Color"
date = "2017-07-07"
description = "Solution to Leetcode 2672"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    int c[100003] = {}, adj = 0;
    vector<int> res;
    for (const auto &q : queries) {
        int i = q[0] + 1, color_i = q[1];
        if (c[i])
            adj -= (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
        c[i] = color_i;
        adj += (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
        res.push_back(adj);
    }
    return res;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

