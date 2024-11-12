
+++
authors = ["grid47"]
title = "Leetcode 970: Powerful Integers"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 970: Powerful Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powerful-integers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 1; i <= bound; i *= x) {
            for(int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/970.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #971: Flip Binary Tree To Match Preorder Traversal](https://grid47.xyz/posts/leetcode-971-flip-binary-tree-to-match-preorder-traversal-solution/) |
| --- |
