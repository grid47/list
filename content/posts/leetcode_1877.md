
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1877: Minimize Maximum Pair Sum in Array"
date = "2019-09-11"
description = "Solution to Leetcode 1877"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minPairSum(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = 0; i < n / 2; ++i)
            res = max(res, A[i] + A[n - i - 1]);
        return res;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

