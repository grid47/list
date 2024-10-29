
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1051: Height Checker"
date = "2021-12-14"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

