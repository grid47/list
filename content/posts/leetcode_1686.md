
+++
authors = ["Crafted by Me"]
title = "Leetcode 1686: Stone Game VI"
date = "2020-03-22"
description = "In-depth solution and explanation for Leetcode 1686: Stone Game VI in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


| Next : [LeetCode #1687: Delivering Boxes from Storage to Ports](grid47.xyz/leetcode_1687) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

