
+++
authors = ["grid47"]
title = "Leetcode 2389: Longest Subsequence With Limited Sum"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2389: Longest Subsequence With Limited Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2389.md" >}}
---
{{< youtube Lb4Dp6gwh6g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2390: Removing Stars From a String](https://grid47.xyz/posts/leetcode-2390-removing-stars-from-a-string-solution/) |
| --- |
