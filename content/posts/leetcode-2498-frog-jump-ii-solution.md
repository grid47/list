
+++
authors = ["grid47"]
title = "Leetcode 2498: Frog Jump II"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2498: Frog Jump II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/frog-jump-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxJump(vector<int>& A) {
        int res = A[1] - A[0];
        int n = A.size();
        for(int i = 2; i < n; i++)
            res = max(res, A[i] - A[i - 2]);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2498.md" >}}
---
{{< youtube 7zFq991SKgQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2500: Delete Greatest Value in Each Row](https://grid47.xyz/posts/leetcode-2500-delete-greatest-value-in-each-row-solution/) |
| --- |
