
+++
authors = ["grid47"]
title = "Leetcode 390: Elimination Game"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 390: Elimination Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/elimination-game/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/390.webp" 
    alt="A series of elements being eliminated one by one, with each eliminated element glowing as it is removed."
    caption="Solution to LeetCode 390: Elimination Game Problem"
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
    int lastRemaining(int n) {
        bool left = true;
        int rm = n;
        int step = 1;
        int head = 1;
        while(rm > 1) {
            if(left || rm % 2 == 1) {
                head += step;
            }
            rm /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/390.md" >}}
---
{{< youtube 0U5Lenn_vMo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #392: Is Subsequence](https://grid47.xyz/posts/leetcode-392-is-subsequence-solution/) |
| --- |
