
+++
authors = ["grid47"]
title = "Leetcode 36: Valid Sudoku"
date = "2024-11-01"
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
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/36.jpeg" 
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #38: Count and Say](https://grid47.xyz/posts/leetcode-38-count-and-say-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}