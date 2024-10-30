
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 950: Reveal Cards In Increasing Order"
date = "2022-03-26"
description = "Solution to Leetcode 950"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reveal-cards-in-increasing-order/description/)

---
{{< youtube nan >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

