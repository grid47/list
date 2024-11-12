
+++
authors = ["grid47"]
title = "Leetcode 1801: Number of Orders in the Backlog"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1801: Number of Orders in the Backlog in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-orders-in-the-backlog/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        int mod = (int) (1e9 + 7);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> buy;        
        
        for(auto it: orders) {
            
            if(it[2] == 0) { // For a buy order
                
                pair<int, int> top;
                while(!sell.empty() && sell.top().first <= it[0] && it[1]) {
                    top = sell.top();
                    sell.pop();
                    if(top.second > it[1]) {
                        top.second -= it[1];
                        it[1] = 0;
                        sell.push(top);
                    } else {
                        it[1] -= top.second;
                    }
                }
                if(it[1] > 0) buy.push({it[0], it[1]});
                
            } else if(it[2] == 1) {
                pair<int, int> top;
                while(!buy.empty() && buy.top().first >= it[0] && it[1]) {
                    top = buy.top();
                    buy.pop();
                    if(top.second > it[1]) {
                        top.second -= it[1];
                        it[1] = 0;
                        buy.push(top);
                    } else {
                        it[1] -= top.second;
                    }
                }
                if(it[1] > 0) sell.push({it[0], it[1]});              
            }
            
        }
        
        int cnt = 0;
        
        while(!sell.empty()) {
            auto top = sell.top();
            cnt = (cnt + top.second) % mod;
            sell.pop();
        }
        while(!buy.empty()) {
            auto top = buy.top();
            cnt = (cnt + top.second) % mod;
            buy.pop();
        }        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1801.md" >}}
---
{{< youtube hVVkBM-p1vg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1802: Maximum Value at a Given Index in a Bounded Array](https://grid47.xyz/posts/leetcode-1802-maximum-value-at-a-given-index-in-a-bounded-array-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
