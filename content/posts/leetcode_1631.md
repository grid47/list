
+++
authors = ["Crafted by Me"]
title = "Leetcode 1631: Path With Minimum Effort"
date = "2020-05-15"
description = "Solution to Leetcode 1631"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-with-minimum-effort/description/)

---



**Code:**

{{< highlight cpp >}}
class cmp {
public:
    bool operator() (array<int, 3> &a, array<int, 3> &b) {
        return a[2] > b[2];
    }
};

class Solution {
    
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int dir[] = {0, 1, 0, -1, 0};
        int m = h.size(), n = h[0].size();
        vector<vector<int>> sz(m, vector<int>(n, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, cmp> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            array<int, 3> r = pq.top();
            pq.pop();
            int i = r[0], j = r[1], d = r[2];
            //cout << i << ' ' << j << ' ' << d << endl;
            if(d > sz[i][j]) continue;
            if((i == (m - 1)) && (j == (n - 1))) return d;
            for(int k = 0; k < 4; k++) {
                int ni = i + dir[k], nj = j + dir[k + 1];
                if(min(ni, nj) < 0 || ni >= m || nj >= n) continue;

                int nxt = sz[ni][nj];
                int nd  = max(abs(h[i][j] - h[ni][nj]), d);
                if (nxt > nd) {
                    sz[ni][nj] = nd;
                    pq.push({ni, nj, nd});
                }
            }
        }
        return 0;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

