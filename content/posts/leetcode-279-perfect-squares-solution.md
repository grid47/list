
+++
authors = ["grid47"]
title = "Leetcode 279: Perfect Squares"
date = "2024-10-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 279: Perfect Squares in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/perfect-squares/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/279.webp" 
    alt="A series of glowing squares being formed from numbers, each square glowing brighter as it becomes perfect."
    caption="Solution to LeetCode 279: Perfect Squares Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSquares(int n) {
        vector<long> cnt(n + 1, INT_MAX);

        cnt[0] = 0;

        for(int i = 1; i <= n; i++)
        for(int j = 1; j * j <= i; j++)
            cnt[i] = min(cnt[i], cnt[i - j * j] + 1);

        return cnt[n];

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/279.md" >}}
---
{{< youtube HLZLwjzIVGo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #283: Move Zeroes](https://grid47.xyz/posts/leetcode-283-move-zeroes-solution/) |
| --- |
