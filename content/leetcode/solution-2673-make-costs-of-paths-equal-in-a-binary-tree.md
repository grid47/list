
+++
authors = ["grid47"]
title = "Leetcode 2673: Make Costs of Paths Equal in a Binary Tree"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2673: Make Costs of Paths Equal in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "W62wT5Lem6E"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minIncrements(int n, vector<int>& A) {
        int res = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            int l = i * 2 + 1, r = i * 2 + 2;
            res += abs(A[l] - A[r]);
            A[i] += max(A[l], A[r]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2673.md" >}}
---
{{< youtube W62wT5Lem6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2678: Number of Senior Citizens](https://grid47.xyz/leetcode/solution-2678-number-of-senior-citizens/) |
| --- |
