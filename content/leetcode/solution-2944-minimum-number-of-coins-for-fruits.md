
+++
authors = ["grid47"]
title = "Leetcode 2944: Minimum Number of Coins for Fruits"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2944: Minimum Number of Coins for Fruits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Queue","Heap (Priority Queue)","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_Zt6ADHF8nE"
youtube_upload_date="2023-11-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_Zt6ADHF8nE/maxresdefault.webp"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2944.md" >}}
---
{{< youtube _Zt6ADHF8nE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2946: Matrix Similarity After Cyclic Shifts](https://grid47.xyz/leetcode/solution-2946-matrix-similarity-after-cyclic-shifts/) |
| --- |
