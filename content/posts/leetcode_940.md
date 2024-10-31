
+++
authors = ["Crafted by Me"]
title = "Leetcode 940: Distinct Subsequences II"
date = "2022-04-06"
description = "Solution to Leetcode 940"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distinct-subsequences-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distinctSubseqII(string S) {
        int endsWith[26] = {}, mod = 1e9 + 7;
        auto lambda = [&](int s, int i) {return (s + i) % mod; };
        for (char c : S)
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1, lambda);
        return accumulate(begin(endsWith), end(endsWith), 0, lambda);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/940.md" >}}

---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

