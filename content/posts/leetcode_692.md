
+++
authors = ["Crafted by Me"]
title = "Leetcode 692: Top K Frequent Words"
date = "2022-12-10"
description = "Solution to Leetcode 692"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/top-k-frequent-words/description/)

---

{{< youtube jEm_HfkIk9s >}}

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

