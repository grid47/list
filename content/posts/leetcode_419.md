
+++
authors = ["Crafted by Me"]
title = "Leetcode 419: Battleships in a Board"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 419: Battleships in a Board in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/battleships-in-a-board/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return 0;
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
 cnt += (board[i][j] == 'X') && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'); 

        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/419.md" >}}
---
{{< youtube gKhvVHd8ihI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #421: Maximum XOR of Two Numbers in an Array](https://grid47.xyz/posts/leetcode_421) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
