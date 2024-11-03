
+++
authors = ["Crafted by Me"]
title = "Leetcode 1801: Number of Orders in the Backlog"
date = "2019-11-28"
description = "In-depth solution and explanation for Leetcode 1801: Number of Orders in the Backlog in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


"| 1802: Maximum Value at a Given Index in a Bounded Array |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

