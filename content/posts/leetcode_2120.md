
+++
authors = ["Yasir"]
title = "Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid"
date = "2019-01-08"
description = "Solution to Leetcode 2120"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/)

---

**Code:**

{{< highlight html >}}
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

