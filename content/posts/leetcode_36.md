
+++
authors = ["Crafted by Me"]
title = "Leetcode 36: Valid Sudoku"
date = "2023-09-27"
description = "Solution to Leetcode 36"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-sudoku/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<string, bool> ma;
        
        for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.') {
                string key = "(";
                    key+=board[i][j];
                key+=")";
                if(ma.count(to_string(i)+key)) return false;
                else ma[to_string(i)+key] = true;
                // cout << to_string(i)+key;
                if(ma.count(key+to_string(j))) return false;
                else ma[key+to_string(j)] = true;
                // cout << key+to_string(j);
                int x = i / 3, y = j / 3;
                if(ma.count(to_string(x)+ key+ to_string(y))) return false;
                else ma[to_string(x)+ key+ to_string(y)] = true;
                // cout<< to_string(i)+ key+ to_string(j);
            }
        }
            return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/36.md" >}}
---
{{< youtube TjFXEUCMqI8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

