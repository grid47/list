
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 403: Frog Jump"
date = "2023-09-24"
description = "Solution to Leetcode 403"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/frog-jump/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int, set<int>> mp;
        mp[0].insert(1);
        for(int i = 0; i < n; i++) {
            int st = stones[i];
            for(int step : mp[st]) {
                int tgt = st + step;
                if(tgt == stones[stones.size() - 1]) return true;
                mp[tgt].insert(step + 1);
                mp[tgt].insert(step);
                if(step - 1 > 0) mp[tgt].insert(step - 1);
            }
        }
        return false;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/403.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

