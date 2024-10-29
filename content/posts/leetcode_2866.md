
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2866: Beautiful Towers II"
date = "2016-12-25"
description = "Solution to Leetcode 2866"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/beautiful-towers-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& A) {
        int n = A.size();
        vector<long long> left(n), stack = {-1};
        long long res = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            while (stack.size() > 1 && A[stack.back()] > A[i]) {
                int j = stack.back();
                stack.pop_back();
                cur -= 1L * (j - stack.back()) * A[j];
            }
            cur += 1L * (i - stack.back()) * A[i];
            stack.push_back(i);
            left[i] = cur;
        }

        stack = {n};
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (stack.size() > 1 && A[stack.back()] > A[i]) {
                int j = stack.back();
                stack.pop_back();
                cur -= 1L * -(j - stack.back()) * A[j];
            }
            cur += 1L * -(i - stack.back()) * A[i];
            stack.push_back(i);
            res = max(res, left[i] + cur - A[i]);
        }

        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

