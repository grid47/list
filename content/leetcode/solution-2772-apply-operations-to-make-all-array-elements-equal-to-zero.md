
+++
authors = ["grid47"]
title = "Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero"
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkArray(vector<int>& A, int k) {
        int cur = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (cur > A[i])
                return false;
            A[i] -= cur;
            cur += A[i];
            if (i >= k - 1)
                cur -= A[i - k + 1];
        }
        return cur == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2772.md" >}}
---
{{< youtube xpjC9rt9xsM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2778: Sum of Squares of Special Elements ](https://grid47.xyz/leetcode/solution-2778-sum-of-squares-of-special-elements/) |
| --- |
