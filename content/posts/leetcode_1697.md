
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1697: Checking Existence of Edge Length Limited Paths"
date = "2020-03-07"
description = "Solution to Leetcode 1697"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> id;
    UF(int n) : id(n) {
        iota(id.begin(), id.end(), 0);
    }
    bool join(int x, int y) {
        int p = find(x), q = find(y);
        if(p != q) {
            id[p] = q;
            return true;
        }
        return false;
    }
    bool conn(int x, int y) {
        return find(x) == find(y);
    }
    int find(int x) {
        return id[x] == x? x: (id[x] = find(id[x]));
    }
};

class Solution {
public:
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& q) {
        vector<bool> ans(q.size(), 0);
        for(int i = 0; i < q.size(); i++) q[i].push_back(i); 
        sort(edge.begin(), edge.end(), [&](auto &a, auto &b) {return a[2] < b[2];});
        sort(q.begin(), q.end(), [&](auto &a, auto &b) {return a[2] < b[2];});        
        UF uf(n);
        int i = 0;
        for(int j = 0; j < q.size(); j++) {
            int limit = q[j][2], idx = q[j][3];
            for(; i < edge.size() && edge[i][2] < limit; i++) uf.join(edge[i][0], edge[i][1]);
            ans[idx] = uf.conn(q[j][0], q[j][1]);
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

