
+++
authors = ["Crafted by Me"]
title = "Leetcode 2018: Check if Word Can Be Placed In Crossword"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2018: Check if Word Can Be Placed In Crossword in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool same(vector<char> &row, int start, int end, string &s) {
        
        if(end - start + 1 != s.size()) return false;
        
        int i = 0, n = s.size();
        while(i < n && (row[start + i] == ' ' || row[start + i] == s[i])) {
            i++;
        }
        if(i == n) return true;
        i = 0;
        while(i < n && (row[end - i] == ' ' || row[end - i] == s[i]))
              i++;
        if(i == n) return true;             
             
        return false;
    }
    
    bool match(vector<vector<char>> &mtx, string &word) {
        int n = mtx[0].size();
        for(auto &row: mtx) {
            for(int i = 0; i < n; ) {
                int start;
                while(i < n && row[i] == '#') i++;
                start = i;
                while(i < n && row[i] != '#') i++;
                if(same(row, start, i - 1, word))
                    return true;
            }
        }

        return false;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> trns(n, vector<char>(m));
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            trns[j][i] = board[i][j];
        
        return match(trns, word) || match(board, word);
    }
};
{{< /highlight >}}


---
{{< youtube l28OqpotdbU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2019: The Score of Students Solving Math Expression](https://grid47.xyz/posts/leetcode_2019) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

