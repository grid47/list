
+++
authors = ["Yasir"]
title = "Leetcode 794: Valid Tic-Tac-Toe State"
date = "2022-08-27"
description = "Solution to Leetcode 794"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-tic-tac-toe-state/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool xwin = false, owin = false;
        vector<int> rows(3, 0), cols(3, 0);
        int diag = 0, antidiag = 0, turns = 0;

        for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 'X') {
                turns++, cols[j]++, rows[i]++;
                if(i == j) diag++;
                if(i + j == 2) antidiag++;
            } else if(board[i][j] == 'O') {
                turns--, cols[j]--, rows[i]--;
                if(i == j) diag--;
                if(i + j == 2) antidiag--;
            }      
        }

        xwin =  rows[0] == 3 || cols[0] == 3 || 
                rows[1] == 3 || cols[1] == 3 ||
                rows[2] == 3 || cols[2] == 3 ||
                diag == 3 || antidiag == 3;
        owin =  rows[0] == -3 || cols[0] == -3 || 
                rows[1] == -3 || cols[1] == -3 ||
                rows[2] == -3 || cols[2] == -3 ||
                diag == -3 || antidiag == -3;

        if(xwin && turns == 0 || owin && turns == 1)
            return false;
        
        return (turns == 0 || turns == 1) && (!xwin || !owin);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

