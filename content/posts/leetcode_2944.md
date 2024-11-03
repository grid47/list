
+++
authors = ["Crafted by Me"]
title = "Leetcode 2944: Minimum Number of Coins for Fruits"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2944: Minimum Number of Coins for Fruits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCoins(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && (q.front() + 1) * 2 < i + 1)
                q.pop_front();
            while (!q.empty() && dp[q.back()] + A[q.back()] >= dp[i] + A[i])
                q.pop_back();
            q.push_back(i);
            dp[i + 1] = dp[q.front()] + A[q.front()];
        }
        return dp[n];
    }
};
{{< /highlight >}}


---
{{< youtube _Zt6ADHF8nE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2945: Find Maximum Non-decreasing Array Length](https://grid47.xyz/posts/leetcode_2945) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

