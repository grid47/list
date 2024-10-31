
+++
authors = ["Crafted by Me"]
title = "Leetcode 1686: Stone Game VI"
date = "2020-03-21"
description = "Solution to Leetcode 1686"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-vi/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int ap = 0, bp = 0;

        int n = alice.size();
        
        /*
            Take out stones with max points (alice[i] + bob[i])
            It either increase our winning chance
            or reduces the opponents winning chance
        */
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
        
        for(int i = 0; i < n; i++) {
            pq.push({alice[i] + bob[i], i});
        }
        
        bool isA = true;
        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            if(isA) {
                ap += alice[tmp.second];
            } else {
                bp += bob[tmp.second];
            }
            isA = !isA;
        }
        // cout << ap << " " << bp;
        return ap > bp ? 1 : ap < bp ? -1: 0;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

