
+++
authors = ["Yasir"]
title = "Leetcode 36: Valid Sudoku"
date = "2024-09-23"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

