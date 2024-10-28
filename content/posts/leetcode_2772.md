
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero"
date = "2017-03-28"
description = "Solution to Leetcode 2772"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

