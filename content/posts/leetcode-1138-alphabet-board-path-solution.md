
+++
authors = ["grid47"]
title = "Leetcode 1138: Alphabet Board Path"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1138: Alphabet Board Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/alphabet-board-path/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int x = 0, y = 0;
        for(auto ch: target) {
            int x1 = (ch - 'a') %5, y1 = (ch - 'a') / 5;
            res +=  string(max(0, y-y1), 'U') +
                    string(max(0, x1-x), 'R') +
                    string(max(0, x-x1), 'L') +
                    string(max(0, y1-y), 'D') + '!';
            x = x1, y = y1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1138.md" >}}
---
{{< youtube rk-aB4rEOyU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1139: Largest 1-Bordered Square](https://grid47.xyz/posts/leetcode-1139-largest-1-bordered-square-solution/) |
| --- |
