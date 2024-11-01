
+++
authors = ["Crafted by Me"]
title = "Leetcode 1656: Design an Ordered Stream"
date = "2020-04-21"
description = "Solution to Leetcode 1656"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-an-ordered-stream/description/)

---

**Code:**

{{< highlight cpp >}}
class OrderedStream {
public:
vector<string> s;
int ptr = 1;
OrderedStream(int n) : s(n + 1) {}
vector<string> insert(int id, string value) {
    s[id] = value;
    vector<string> res;
    while (ptr < s.size() && !s[ptr].empty())
        res.push_back(s[ptr++]);
    return res;
}
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

