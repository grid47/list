
+++
authors = ["grid47"]
title = "Leetcode 738: Monotone Increasing Digits"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 738: Monotone Increasing Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/monotone-increasing-digits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string n_str = to_string(n);

        int marker = n_str.size();

        for(int i = n_str.size() - 1; i > 0; i--) {
            if(n_str[i] < n_str[i - 1]) {
                marker = i;
                n_str[i-1] = n_str[i - 1] - 1;
            }
        }

        for(int i = marker; i < n_str.size(); i++)
            n_str[i]= '9';

        return stoi(n_str);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/738.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #739: Daily Temperatures](https://grid47.xyz/posts/leetcode-739-daily-temperatures-solution/) |
| --- |
