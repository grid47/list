
+++
authors = ["Crafted by Me"]
title = "Leetcode 2092: Find All People With Secret"
date = "2019-02-10"
description = "In-depth solution and explanation for Leetcode 2092: Find All People With Secret in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-people-with-secret/description/)

---

**Code:**

{{< highlight cpp >}}
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        id[find(b)] = find(a);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    void reset(int a) { id[a] = a; }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& A, int firstPerson) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[2] < b[2]; });
        UnionFind uf(n);
        uf.connect(0, firstPerson);
        vector<int> ppl;
        for (int i = 0, M = A.size(); i < M; ) {
            ppl.clear();
            int time = A[i][2];
            for (; i < M && A[i][2] == time; ++i) {
                uf.connect(A[i][0], A[i][1]);
                ppl.push_back(A[i][0]);
                ppl.push_back(A[i][1]);
            }
            for (int n : ppl) {
                if (!uf.connected(0, n)) uf.reset(n);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (uf.connected(0, i)) ans.push_back(i);
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube v8-OkMKBqyA >}}

"| 2093: Minimum Cost to Reach City With Discounts |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

