
+++
authors = ["Yasir"]
title = "Leetcode 1253: Reconstruct a 2-Row Binary Matrix"
date = "2021-05-24"
description = "Solution to Leetcode 1253"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& cs) {
        vector<vector<int>> res(2, vector<int>(cs.size()));
        for(int i = 0; i < cs.size(); u -= res[0][i], l -= res[1][i], i++) {
            res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u);
            res[1][i] = cs[i] == 2 || (cs[i] == 1 && !res[0][i]);
        }
        return u == 0 && l == 0 ? res : vector<vector<int>>();
    }
};
{{< /highlight >}}

