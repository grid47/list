
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 901: Online Stock Span"
date = "2022-05-12"
description = "Solution to Leetcode 901"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

