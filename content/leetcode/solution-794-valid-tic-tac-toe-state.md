
+++
authors = ["grid47"]
title = "Leetcode 794: Valid Tic-Tac-Toe State"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 794: Valid Tic-Tac-Toe State in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/794.webp"
youtube = "5IGbZyPgjP0"
youtube_upload_date="2024-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/5IGbZyPgjP0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/valid-tic-tac-toe-state/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/794.webp" 
    alt="A Tic-Tac-Toe board where valid states are checked, with valid states softly glowing as they’re found."
    caption="Solution to LeetCode 794: Valid Tic-Tac-Toe State Problem"
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
{{< youtube 5IGbZyPgjP0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #795: Number of Subarrays with Bounded Maximum](https://grid47.xyz/leetcode/solution-795-number-of-subarrays-with-bounded-maximum/) |
| --- |