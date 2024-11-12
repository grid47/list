
+++
authors = ["grid47"]
title = "Leetcode 2034: Stock Price Fluctuation "
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2034: Stock Price Fluctuation  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Data Stream","Ordered Set"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2034.md" >}}
---
{{< youtube iJqGjXpqdYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2037: Minimum Number of Moves to Seat Everyone](https://grid47.xyz/posts/leetcode-2037-minimum-number-of-moves-to-seat-everyone-solution/) |
| --- |
