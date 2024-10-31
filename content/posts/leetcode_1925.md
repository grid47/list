
+++
authors = ["Crafted by Me"]
title = "Leetcode 1925: Count Square Sum Triples"
date = "2019-07-26"
description = "Solution to Leetcode 1925"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-square-sum-triples/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriples(int n) {
    vector<bool> squares(n * n + 1);
    for (int i = 1; i <= n; ++i)
        squares[i * i] = true;
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; i * i + j * j <= n * n; ++j)
            res += squares[i * i + j * j] * 2;
    return res;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

