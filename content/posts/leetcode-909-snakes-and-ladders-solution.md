
+++
authors = ["grid47"]
title = "Leetcode 909: Snakes and Ladders"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 909: Snakes and Ladders in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/snakes-and-ladders/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void getCoordinate(int n, int s, int &row, int &col) {
        row = n-1-(s-1)/n;
        col = (s-1)%n;
        if((n%2 ==1 && row%2==1) || (n%2==0 && row%2==0))
            col= n-1-col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> seen(n*n+1, false);
        seen[1] = true;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int row, col, s = p.first, dist = p.second;
            if(s == n*n) 
                return dist;
            for(int i = 1; s+i<= n *n && i<=6;i++) {
                getCoordinate(n, s+i, row, col);
                int sfinal = board[row][col] == -1? s+i:board[row][col];
                if(seen[sfinal] == false) {
                    seen[sfinal] = true;
                    q.push({sfinal, dist + 1});
                }
            }
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/909.md" >}}
---
{{< youtube 6lH4nO3JfLk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #910: Smallest Range II](https://grid47.xyz/posts/leetcode-910-smallest-range-ii-solution/) |
| --- |
