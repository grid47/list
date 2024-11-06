
+++
authors = ["Crafted by Me"]
title = "Leetcode 692: Top K Frequent Words"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 692: Top K Frequent Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Trie","Sorting","Heap (Priority Queue)","Bucket Sort","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/top-k-frequent-words/description/)

---

**Code:**

{{< highlight cpp >}}
using tup_t = tuple<int, string>;
class cmp {
public:
    bool operator() (const tup_t &p1, const tup_t &p2) {
        if(get<0>(p1) == get<0>(p2)) return get<1>(p1) > get<1>(p2);
        else return get<0>(p1) < get<0>(p2);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string str: words)
            mp[str]++;

        priority_queue<tup_t, vector<tup_t>, cmp> pq;
        for(auto it: mp) {
            auto tp = make_tuple(it.second, it.first);
            pq.push(tp);
        }
        vector<string> ans;
        while(k-- > 0) {
            auto e = pq.top();
            ans.push_back(get<1>(e));
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/692.md" >}}
---
{{< youtube jEm_HfkIk9s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #693: Binary Number with Alternating Bits](https://grid47.xyz/posts/leetcode_693) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
