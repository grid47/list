
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1656: Design an Ordered Stream"
date = "2020-04-19"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

