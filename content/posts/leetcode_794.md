
+++
authors = ["Crafted by Me"]
title = "Leetcode 794: Valid Tic-Tac-Toe State"
date = "2022-08-31"
description = "In-depth solution and explanation for Leetcode 794: Valid Tic-Tac-Toe State in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/794.md" >}}
---


"| 795: Number of Subarrays with Bounded Maximum |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

