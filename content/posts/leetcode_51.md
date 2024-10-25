
+++
authors = ["Yasir"]
title = "Leetcode 51: N-Queens"
date = "2024-09-06"
description = "Solution to Leetcode 51"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/n-queens/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int n;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string str(n, '.');
        vector<string> tmp(n, str);
        this->n = n;
        bt(0, ans, tmp);
        return ans;
    }
    
    void bt(int i, vector<vector<string>> &ans, vector<string> &tmp) {
        if(i == n) {
            ans.push_back(tmp);
            return;
        }
        
        for(int j = 0; j < n; j++) {
            if(canPlace(tmp, i, j)) {
                tmp[i][j] = 'Q';
                
                bt(i + 1, ans, tmp);
                
                tmp[i][j] = '.';
            }
        }
    }
    
    bool canPlace(vector<string> &tmp, int i, int j) {
        for(int k = 0; k < i; k++) {
            if(tmp[k][j] == 'Q')
                return false;
        }
        
        int x = i - 1, y = j - 1;
        while(x >= 0 && y >= 0) {
            if(tmp[x][y] == 'Q')
                return false;
            x--, y--;
        }
        x = i - 1, y = j + 1;
        while(x >= 0 && y < n) {
            if(tmp[x][y] == 'Q')
                return false;
            x--, y++;
        }        
        return true;
    }
};
{{< /highlight >}}

