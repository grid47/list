
+++
authors = ["Crafted by Me"]
title = "Leetcode 2373: Largest Local Values in a Matrix"
date = "2017-05-04"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

