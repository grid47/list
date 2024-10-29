
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2260: Minimum Consecutive Cards to Pick Up"
date = "2018-08-23"
description = "Solution to Leetcode 2260"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int n = cards.size();
        int ans = n + 1;
        
        for(int i = 0; i < n; i++){
            if(mp.count(cards[i])) {
                ans = min(ans, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;            
        }
        
        return ans == n + 1? -1: ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

