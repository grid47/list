
+++
authors = ["Yasir"]
title = "Leetcode 2389: Longest Subsequence With Limited Sum"
date = "2018-04-14"
description = "Solution to Leetcode 2389"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> answerQueries(vector<int> A, vector<int>& queries) {
        sort(A.begin(), A.end());
        vector<int> res;
        for (int i = 1; i < A.size(); ++i)
            A[i] += A[i - 1];
        for (int& q: queries)
            res.push_back(upper_bound(A.begin(), A.end(), q) - A.begin());
        return res;
    }
};
{{< /highlight >}}

