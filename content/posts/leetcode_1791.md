
+++
authors = ["Yasir"]
title = "Leetcode 1791: Find Center of Star Graph"
date = "2019-12-03"
description = "Solution to Leetcode 1791"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-center-of-star-graph/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
};
{{< /highlight >}}

