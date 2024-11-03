
+++
authors = ["Crafted by Me"]
title = "Leetcode 2866: Beautiful Towers II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2866: Beautiful Towers II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2867: Count Valid Paths in a Tree](https://grid47.xyz/posts/leetcode_2867) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

