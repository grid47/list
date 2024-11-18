
+++
authors = ["grid47"]
title = "Leetcode 1631: Path With Minimum Effort"
date = "2024-05-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1631: Path With Minimum Effort in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Depth-First Search","Breadth-First Search","Union Find","Heap (Priority Queue)","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XQlxCCx2vI4"
youtube_upload_date="2023-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/XQlxCCx2vI4/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1631.md" >}}
---
{{< youtube XQlxCCx2vI4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1637: Widest Vertical Area Between Two Points Containing No Points](https://grid47.xyz/leetcode/solution-1637-widest-vertical-area-between-two-points-containing-no-points/) |
| --- |
