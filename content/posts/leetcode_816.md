
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 816: Ambiguous Coordinates"
date = "2022-08-06"
description = "Solution to Leetcode 816"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ambiguous-coordinates/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> res;
        for (int i = 1; i < n - 2; ++i) {
            vector<string> A = f(S.substr(1, i)), B = f(S.substr(i + 1, n - 2 - i));
            for (auto & a : A) for (auto & b : B) res.push_back("(" + a + ", " + b + ")");
        }
        return res;
    }
    vector<string> f(string S) {
        int n = S.size();
        if (n == 0 || (n > 1 && S[0] == '0' && S[n - 1] == '0')) return {};
        if (n > 1 && S[0] == '0') return {"0." + S.substr(1)};
        if (n == 1 || S[n - 1] == '0') return {S};
        vector<string> res = {S};
        for (int i = 1; i < n; ++i) res.push_back(S.substr(0, i) + '.' + S.substr(i));
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/816.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
