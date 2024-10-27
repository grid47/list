
+++
authors = ["Yasir"]
title = "Leetcode 419: Battleships in a Board"
date = "2023-09-05"
description = "Solution to Leetcode 419"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/battleships-in-a-board/description/)

---

**Code:**

{{< highlight html >}}
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

