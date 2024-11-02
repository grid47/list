
+++
authors = ["Crafted by Me"]
title = "Leetcode 1958: Check if Move is Legal"
date = "2018-06-23"
description = "Solution to Leetcode 1958"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-move-is-legal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char cur) {

        int m = board.size(), n = board[0].size();

        int dir[] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
        
        for(int d = 0; d < 9; d++) {
            for(int x = 1; ; x++) {
                int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
                if(i < 0 || j < 0 || i == 8 || j == 8|| board[i][j] == '.')
                    break;
                if(board[i][j] == cur) {
                    if(x > 1) return true;
                    
                    break;
                }
            }
        }

    
        return false;        
    }
};
{{< /highlight >}}


---
{{< youtube KxK33AcQZpQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

