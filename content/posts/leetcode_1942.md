
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1942: The Number of the Smallest Unoccupied Chair"
date = "2019-07-07"
description = "Solution to Leetcode 1942"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int t) {
        int tt = a[t][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reserve;
        priority_queue<int, vector<int>, greater<int>> avail;
        sort(a.begin(), a.end());
        for(auto &t : a) {
            
            while(!reserve.empty() && reserve.top().first <= t[0]) {
                
                avail.push(reserve.top().second);
                reserve.pop();
                
            }
            
            if(t[0] == tt) break;
            if (!avail.empty()) {
                
                reserve.push({t[1], avail.top()});
                             
               avail.pop();
                
            } else {
                
                reserve.push({t[1], reserve.size()});
                
            }
            
        }
        
        return avail.empty()? reserve.size() : avail.top();
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

