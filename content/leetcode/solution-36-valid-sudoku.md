
+++
authors = ["grid47"]
title = "Leetcode 36: Valid Sudoku"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 36: Valid Sudoku in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-sudoku/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/36.webp" 
    alt="A soft grid of numbers and symbols, gently highlighting valid sequences."
    caption="Solution to LeetCode 36: Valid Sudoku Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #38: Count and Say](https://grid47.xyz/leetcode/solution-38-count-and-say/) |
| --- |
