
+++
authors = ["Yasir"]
title = "Leetcode 940: Distinct Subsequences II"
date = "2022-04-01"
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

{{< highlight html >}}
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

