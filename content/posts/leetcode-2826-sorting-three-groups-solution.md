
+++
authors = ["grid47"]
title = "Leetcode 2826: Sorting Three Groups"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2826: Sorting Three Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sorting-three-groups/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& A) {
        int a = 0, b = 0, c = 0;
        for (int x: A) {
            a += x != 1;
            b = min(a, b + (x != 2));
            c = min(b, c + (x != 3));
        }
        return c;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2826.md" >}}
---
{{< youtube Q3wrIhMmpfA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2828: Check if a String Is an Acronym of Words](https://grid47.xyz/posts/leetcode-2828-check-if-a-string-is-an-acronym-of-words-solution/) |
| --- |
