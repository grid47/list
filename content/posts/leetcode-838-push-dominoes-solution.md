
+++
authors = ["grid47"]
title = "Leetcode 838: Push Dominoes"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 838: Push Dominoes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/push-dominoes/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        string res = "";
        for(int i = 0, j = 1; j < d.length(); j++) {
            if(d[j] == '.') continue;
            int middle = j - i - 1;
            if(i > 0) 
                res += d[i];
            if(d[i] == d[j])
                res += string(middle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                res += string(middle, '.');
            else 
                res += string(middle/2, 'R') + string(middle%2, '.') + string(middle/2, 'L');
            i = j;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/838.md" >}}
---
{{< youtube 0_XmKkgHSdI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #840: Magic Squares In Grid](https://grid47.xyz/posts/leetcode-840-magic-squares-in-grid-solution/) |
| --- |
