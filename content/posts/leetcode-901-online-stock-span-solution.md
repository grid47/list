
+++
authors = ["grid47"]
title = "Leetcode 901: Online Stock Span"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 901: Online Stock Span in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design","Monotonic Stack","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/online-stock-span/description/)

---
**Code:**

{{< highlight cpp >}}
class StockSpanner {
    stack<pair<int, int>> cp;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int res = 1;
        
        while(!cp.empty() && cp.top().first <= price) {
            res += cp.top().second;
            cp.pop();
        }
        
        cp.push(make_pair(price, res));
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/901.md" >}}
---
{{< youtube slYh0ZNEqSw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #904: Fruit Into Baskets](https://grid47.xyz/posts/leetcode-904-fruit-into-baskets-solution/) |
| --- |
