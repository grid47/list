
+++
authors = ["Yasir"]
title = "Leetcode 2558: Take Gifts From the Richest Pile"
date = "2017-10-27"
description = "Solution to Leetcode 2558"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
  long long pickGifts(vector<int>& g, int k) {
    make_heap(g.begin(), g.end());
    while(k--) {
        pop_heap(begin(g), end(g));
        g.back() = sqrt(g.back());
        push_heap(begin(g), end(g));
    }
    return accumulate(begin(g), end(g), 0LL);
  }
};
{{< /highlight >}}

