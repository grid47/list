
+++
authors = ["grid47"]
title = "Leetcode 2018: Check if Word Can Be Placed In Crossword"
date = "2024-04-19"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2018.md" >}}
---
{{< youtube l28OqpotdbU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2019: The Score of Students Solving Math Expression](https://grid47.xyz/posts/leetcode-2019-the-score-of-students-solving-math-expression-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
