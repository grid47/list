
+++
authors = ["Crafted by Me"]
title = "Leetcode 2389: Longest Subsequence With Limited Sum"
date = "2018-04-19"
description = "In-depth solution and explanation for Leetcode 2389: Longest Subsequence With Limited Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

