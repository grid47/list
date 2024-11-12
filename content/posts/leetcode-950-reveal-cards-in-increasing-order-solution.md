
+++
authors = ["grid47"]
title = "Leetcode 950: Reveal Cards In Increasing Order"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 950: Reveal Cards In Increasing Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Sorting","Simulation"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #951: Flip Equivalent Binary Trees](https://grid47.xyz/posts/leetcode-951-flip-equivalent-binary-trees-solution/) |
| --- |
