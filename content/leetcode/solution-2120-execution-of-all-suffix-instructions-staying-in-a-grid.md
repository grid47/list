
+++
authors = ["grid47"]
title = "Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid"
date = "2024-04-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Xf_naKzI_ZI"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        int m = s.size(), h = m + n, v = m + n;
        vector<int> hor((h + m) * 2, m), ver((h +m) * 2, m), res(m);
        for(int i = m - 1; i >= 0; i--) {
            hor[h] = ver[v] = i;
            h += s[i] == 'L' ? 1 : s[i] == 'R'? -1 : 0;
            v += s[i] == 'U' ? 1 : s[i] == 'D'? -1 : 0;
            res[i] = min({  m, hor[h - st[1] - 1], hor[h - st[1] + n],
                               ver[v - st[0] - 1], ver[v - st[0] + n]  }) - i;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2120.md" >}}
---
{{< youtube Xf_naKzI_ZI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2121: Intervals Between Identical Elements](https://grid47.xyz/leetcode/solution-2121-intervals-between-identical-elements/) |
| --- |
