
+++
authors = ["grid47"]
title = "Leetcode 816: Ambiguous Coordinates"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 816: Ambiguous Coordinates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Enumeration"]
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
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #817: Linked List Components](https://grid47.xyz/posts/leetcode-817-linked-list-components-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}