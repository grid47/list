
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2934: Minimum Operations to Maximize Last Elements in Arrays"
date = "2016-10-17"
description = "Solution to Leetcode 2934"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        int dp1 = 0, dp2 = 0, n = A.size(), mi = min(A[n - 1], B[n - 1]), ma = max(A[n - 1], B[n - 1]);
        for (int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            if (max(a, b) > ma) return -1;
            if (min(a, b) > mi) return -1;
            if (a > A[n - 1] || b > B[n - 1]) dp1++;
            if (a > B[n - 1] || b > A[n - 1]) dp2++;
        }
        return min(dp1, dp2);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

