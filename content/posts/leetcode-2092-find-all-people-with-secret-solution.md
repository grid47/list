
+++
authors = ["grid47"]
title = "Leetcode 2092: Find All People With Secret"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2092: Find All People With Secret in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2092.md" >}}
---
{{< youtube v8-OkMKBqyA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2095: Delete the Middle Node of a Linked List](https://grid47.xyz/posts/leetcode-2095-delete-the-middle-node-of-a-linked-list-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
