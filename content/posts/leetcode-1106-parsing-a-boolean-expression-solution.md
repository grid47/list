
+++
authors = ["grid47"]
title = "Leetcode 1106: Parsing A Boolean Expression"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1106: Parsing A Boolean Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Recursion"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/parsing-a-boolean-expression/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool parseBoolExpr(string e) {
  if (e.size() == 1) return e == "t" ? true : false;
  if (e[0] == '!') return !parseBoolExpr(e.substr(2, e.size() - 3));
  bool isAnd = e[0] == '&' ? true : false, res = isAnd;
  for (auto i = 2, j = 2, cnt = 0; res == isAnd && i < e.size(); ++i) {
    if (e[i] == '(') ++cnt;
    if (e[i] == ')') --cnt;      
    if (i == e.size() - 1 || (e[i] == ',' && cnt == 0)) {
      if (isAnd) res &= parseBoolExpr(e.substr(j, i - j));
      else res |= parseBoolExpr(e.substr(j, i - j));
      j = i + 1;
    }
  }
  return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1106.md" >}}
---
{{< youtube q2L6yHIIbs8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1109: Corporate Flight Bookings](https://grid47.xyz/posts/leetcode-1109-corporate-flight-bookings-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
