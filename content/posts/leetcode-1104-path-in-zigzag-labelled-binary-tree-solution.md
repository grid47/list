
+++
authors = ["grid47"]
title = "Leetcode 1104: Path In Zigzag Labelled Binary Tree"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1104: Path In Zigzag Labelled Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {

public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        res.push_back(label);
        int level = log2(label);

        while (level != 0) {
            int left = pow(2 , (level - 1));
            int right = pow(2 , level) - 1;
            label = left + ( right- label / 2);

            res.push_back(label);
            level -= 1;
        }

        int num = res.size();
        reverse(res.begin(), res.end());

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1104.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1105: Filling Bookcase Shelves](https://grid47.xyz/posts/leetcode-1105-filling-bookcase-shelves-solution/) |
| --- |
