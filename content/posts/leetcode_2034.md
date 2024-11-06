
+++
authors = ["Crafted by Me"]
title = "Leetcode 2034: Stock Price Fluctuation "
date = "2024-11-01"
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


---
{{< youtube iJqGjXpqdYo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2035: Partition Array Into Two Arrays to Minimize Sum Difference](https://grid47.xyz/posts/leetcode_2035) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
