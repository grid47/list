
+++
authors = ["grid47"]
title = "Leetcode 2706: Buy Two Chocolates"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2706: Buy Two Chocolates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/buy-two-chocolates/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        int l1 = 200, l2 = 200;
        for(int i = 0; i < p.size(); i++) {
            if(p[i] < l1) {
                l2 = l1;
                l1 = p[i];
            } else if(p[i] < l2) {
                l2 = p[i];
            }
        }
        
        if(l1 + l2 <= m) return m - l1 - l2;
        return m;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2706.md" >}}
---
{{< youtube BTzNimiQdW4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2707: Extra Characters in a String](https://grid47.xyz/leetcode/solution-2707-extra-characters-in-a-string/) |
| --- |
