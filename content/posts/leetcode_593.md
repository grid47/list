
+++
authors = ["Yasir"]
title = "Leetcode 593: Valid Square"
date = "2023-03-14"
description = "Solution to Leetcode 593"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-square/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int d(vector<int> p, vector<int> q) {
        return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s({d(p1, p2), d(p2, p3), d(p3, p4), d(p4, p1), d(p1, p3), d(p2, p4)});
        return !s.count(0) && s.size() == 2;
    }
};
{{< /highlight >}}

