
+++
authors = ["Yasir"]
title = "Leetcode 950: Reveal Cards In Increasing Order"
date = "2022-03-22"
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

**Code:**

{{< highlight html >}}
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

