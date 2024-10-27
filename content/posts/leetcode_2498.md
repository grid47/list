
+++
authors = ["Yasir"]
title = "Leetcode 2498: Frog Jump II"
date = "2017-12-26"
description = "Solution to Leetcode 2498"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/frog-jump-ii/description/)

---

**Code:**

{{< highlight html >}}
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

