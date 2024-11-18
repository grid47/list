
+++
authors = ["grid47"]
title = "Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for(int i = 1; i < colors.size() - 1; i++) {
            if(colors[i - 1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A') a++;
                else b++;
            }
        }
        return a > b;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2038.md" >}}
---
{{< youtube 03zIcb12PKo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2039: The Time When the Network Becomes Idle](https://grid47.xyz/leetcode/solution-2039-the-time-when-the-network-becomes-idle/) |
| --- |
