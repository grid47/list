
+++
authors = ["Crafted by Me"]
title = "Leetcode 1970: Last Day Where You Can Still Cross"
date = "2018-06-11"
description = "Solution to Leetcode 1970"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-day-where-you-can-still-cross/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> parent;
    vector<int> rank;

    UF(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void join(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        UF* uf = new UF(row * col + 2);
        int top = row * col, bottom = row * col + 1;
        for(int i = 0; i < col; i++) {
            uf->join(top, i);
            uf->join(bottom, (row - 1) * col + i);            
        }
        vector<vector<int>> grid(row, vector<int>(col, -1));
        int len = cells.size() - 1;
        int dir[] = {0, 1, 0, -1, 0};
        while(uf->find(top) != uf->find(bottom) && len >= 0) {
            auto cell = cells[len--];
            int i = cell[0] - 1, j = cell[1] - 1;
            grid[i][j] = 0;
            for(int k = 0; k < 4; k++) {
                int x = i + dir[k], y = j + dir[k + 1];
                if (x < 0 || y < 0 || x == row || y == col || grid[x][y] != 0) continue;
                uf->join(i * col + j, x * col + y);
            }
        }
        return len + 1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

