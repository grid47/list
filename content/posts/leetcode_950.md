
+++
authors = ["Crafted by Me"]
title = "Leetcode 950: Reveal Cards In Increasing Order"
date = "2022-03-28"
description = "In-depth solution and explanation for Leetcode 950: Reveal Cards In Increasing Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reveal-cards-in-increasing-order/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        queue<int> q;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++)
            q.push(i);
        
        for(int i = 0; i < n; i++) {
            res[q.front()] = deck[i];
            q.pop();
            if(!q.empty()) {
                q.push(q.front());
                q.pop();                
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/950.md" >}}
---
{{< youtube i2QrUdwWlak >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #951: Flip Equivalent Binary Trees](https://grid47.xyz/posts/leetcode_951) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

