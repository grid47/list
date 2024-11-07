
+++
authors = ["Crafted by Me"]
title = "Leetcode 2102: Sequentially Ordinal Rank Tracker"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2102: Sequentially Ordinal Rank Tracker in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Heap (Priority Queue)","Data Stream","Ordered Set"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/)

---

**Code:**

{{< highlight cpp >}}
class CmpMn {
    public:
    bool operator()(pair<int, string> &a, pair<int, string> &b) {
        bool ans = false;
        if(a.first != b.first) ans = a.first < b.first;
        else ans = a.second > b.second;
        return !ans;
    }
};

class CmpMx {
    public:
    bool operator()(pair<int, string> &a, pair<int, string> &b) {
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

class SORTracker {
public:

    int i = 1;
    priority_queue<pair<int, string>, vector<pair<int, string>>, CmpMx> mx;
    priority_queue<pair<int, string>, vector<pair<int, string>>, CmpMn> mn;

    SORTracker() {
    }

    void add(string name, int score) {
        mx.push({score, name});
        mn.push(mx.top());
        mx.pop();
        if (mn.size() > i) {
            mx.push(mn.top());
            mn.pop();
        }
    }

    string get() {
        // cout<< mn.top().first << " ";
        while(mn.size() < i) {
            mn.push(mx.top());
            mx.pop();
        }
        i++;
        return mn.top().second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2102.md" >}}
---
{{< youtube 2Axb1zd8eOc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2104: Sum of Subarray Ranges](https://grid47.xyz/posts/leetcode_2104) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
