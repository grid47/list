
+++
authors = ["Crafted by Me"]
title = "Leetcode 529: Minesweeper"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 529: Minesweeper in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minesweeper/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int row = click[0], col = click[1];
        if(board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            int cnt = 0;
            for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) continue;
                int x = row + i, y = col + j;
                if(x < 0 || y < 0 || x >= m || y >= n)    continue;
                if(board[x][y] == 'M' || board[x][y] == 'X') cnt++;
            }
            if (cnt > 0) board[row][col] = '0' + cnt;
            else {
                board[row][col] = 'B';
                for(int i = -1; i <= 1; i++)
                for(int j = -1; j <= 1; j++) {
                    if(i == 0 && j == 0) continue;
                    int x = row + i, y = col + j;
                    if(x < 0 || y < 0 || x >= m || y >= n)    continue;
                    vector<int> arr;
                    arr.push_back(x);
                    arr.push_back(y);

                    if(board[x][y] == 'E') updateBoard(board, arr);
                }
            }
        }
        return board;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/529.md" >}}
---
{{< youtube zPmuqLKPbE8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #530: Minimum Absolute Difference in BST](https://grid47.xyz/posts/leetcode_530) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

