
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2373: Largest Local Values in a Matrix"
date = "2018-05-01"
description = "Solution to Leetcode 2373"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-local-values-in-a-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
vector<vector<int>> largestLocal(vector<vector<int>>& g) {
    int n = g.size();
    vector<vector<int>> res(n - 2, vector<int>(n - 2));
    for (int i = 0; i < n - 2; ++i)
        for (int j = 0; j < n - 2; ++j)
            for (int ii = i; ii < i + 3; ++ii)
                for (int jj = j; jj < j + 3; ++jj)
                    res[i][j] = max(res[i][j], g[ii][jj]);
    return res;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

