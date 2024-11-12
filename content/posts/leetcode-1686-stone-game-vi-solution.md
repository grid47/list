
+++
authors = ["grid47"]
title = "Leetcode 1686: Stone Game VI"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1686: Stone Game VI in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Sorting","Heap (Priority Queue)","Game Theory"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1686.md" >}}
---
{{< youtube D5uS2MXRhfk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1688: Count of Matches in Tournament](https://grid47.xyz/posts/leetcode-1688-count-of-matches-in-tournament-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
