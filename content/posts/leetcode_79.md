
+++
authors = ["Crafted by Me"]
title = "Leetcode 79: Word Search"
date = "2024-08-14"
description = "Solution to Leetcode 79"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-search/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<bool>> vis;
    int m, n;
    string w;
    bool exist(vector<vector<char>>& board, string word) {
        this->w = word;
        this->grid = board;
        this->m = board.size();
        this->n = board[0].size();

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(w.size() == 1 && grid[i][j] == w[0])
                return true;
            else {
                vis.resize(m, vector<bool>(n, false));
                if(dfs(i, j, 0))
                return true;
            }

        return false;
    }
    
    bool dfs(int i, int j, int idx) {
        if(idx == w.size()) return true;
        if(grid[i][j] != w[idx] || vis[i][j]) {
            return false;
        }
        vis[i][j] = true;
        bool ans = false;
        
            if(i > 0) ans |= dfs(i - 1, j, idx + 1);
            if(j > 0) ans |= dfs(i, j - 1, idx + 1);
        if(i < m - 1) ans |= dfs(i + 1, j, idx + 1);
        if(j < n - 1) ans |= dfs(i, j + 1, idx + 1);     

        vis[i][j] = false;
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/79.md" >}}

---

{{< youtube pfiQ_PS1g8E >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

