
+++
authors = ["grid47"]
title = "Leetcode 1584: Min Cost to Connect All Points"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1584: Min Cost to Connect All Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Union Find","Graph","Minimum Spanning Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/min-cost-to-connect-all-points/description/)

---
**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> ch;
    int cnt;
    UF(int n) {
        cnt = n;
        ch.resize(n, 0);
        for(int i = 0; i < n; i++)
            ch[i] = i;
    }
    bool uni(int a, int b) {
        int x = find(a);
        int y = find(b);
        if(x != y) {
            cnt--;
            ch[x] = y;
            return true;
        }
        return false;
    }
    
    int find(int x) {
        if(x == ch[x]) return x;
        return ch[x] = find(ch[x]);
    }
};

// class cmp {
//     public:
//     bool operator()(vector<int> a, vector<int> b) {
//         return a[0] > b[0];
//     }
// };

class Solution {
public:
    static bool cmp(array<int, 3> &a, array<int, 3> &b) {
        return a[0] < b[0];
    }
    int minCostConnectPoints(vector<vector<int>>& pts) {
        vector<array<int, 3>> q;
        // priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(int i = 0; i < pts.size(); i++) {
            for(int j = i + 1; j < pts.size(); j++)
                q.push_back({ abs(pts[i][0]-pts[j][0]) + abs(pts[i][1]-pts[j][1]), i, j});
        }
        sort(q.begin(), q.end(), cmp);
        UF* uf = new UF(pts.size());

        int cost = 0, n = pts.size();
        for(int i = 0; i < q.size(); i++) {
            // cout << uf->cnt << " " << q[0] << " " << q[1] << " " << q[2] << "\n";
            if(uf->uni(q[i][1], q[i][2])) {
    // cout << n << " "<< cost << " " << q[i][0] << " " << q[i][1] << " " << q[i][2] << "\n";
                cost += q[i][0];
                n--;
                if(n == 1) return cost;
            }

        }
        
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1584.md" >}}
---
{{< youtube 8VPIrqwQ8sQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1589: Maximum Sum Obtained of Any Permutation](https://grid47.xyz/posts/leetcode-1584-min-cost-to-connect-all-points-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
