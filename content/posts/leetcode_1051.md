
+++
authors = ["Yasir"]
title = "Leetcode 1051: Height Checker"
date = "2021-12-12"
description = "Solution to Leetcode 1051"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/height-checker/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int heightChecker(vector<int>& h) {

        auto m = max_element(h.begin(), h.end());

        vector<int> exp(*m + 1);

        for (int height : h) exp[height]++;

        int res = 0;

        for (int j = 1, i = 0; j < exp.size(); j++)
            while (exp[j]--) res += (h[i++] != j);

        return res;

    }
};
{{< /highlight >}}

