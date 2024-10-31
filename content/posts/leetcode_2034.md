
+++
authors = ["Crafted by Me"]
title = "Leetcode 2034: Stock Price Fluctuation "
date = "2019-04-08"
description = "Solution to Leetcode 2034"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stock-price-fluctuation/description/)

---

**Code:**

{{< highlight cpp >}}
class StockPrice {
    set<pair<int, int>> strm, ord;
    map<int, int> mp;
    
public:
    StockPrice() {
        
    }
    
    void update(int ts, int pc) {
        if(mp.count(ts)) {
            strm.erase(pair<int, int>(ts, mp[ts]));

            ord.erase(pair<int, int>(mp[ts], ts));
        }
        mp[ts] = pc;
        strm.insert(pair<int, int>(ts, pc));
        ord.insert(pair<int,int>(pc, ts));
    }
    
    int current() {
       cout<< strm.size() <<endl;
        return rbegin(strm)->second;
    }
    
    int maximum() {
        return rbegin(ord)->first;
    }
    
    int minimum() {
        return begin(ord)->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

