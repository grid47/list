
+++
authors = ["grid47"]
title = "Leetcode 1081: Smallest Subsequence of Distinct Characters"
date = "2024-07-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1081: Smallest Subsequence of Distinct Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string res = "";

        vector<int> in(26, 0), seen(26, 0);
        for (int i = 0; i < n; i++)
            in[s[i] - 'a'] = i;

        vector<int> stk;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (seen[c]++ > 0) continue;
            while (!stk.empty() && stk.back() > c && i < in[stk.back()]) {
                seen[stk.back()] = 0;
                stk.pop_back();
            }
            stk.push_back(c);
        }

        for (int i = 0; i < stk.size(); i++)
            res += ('a' + stk[i]);

        return res;
    }
};

// that problem was there were
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1081.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1090: Largest Values From Labels](https://grid47.xyz/leetcode/solution-1090-largest-values-from-labels/) |
| --- |
