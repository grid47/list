
+++
authors = ["Crafted by Me"]
title = "Leetcode 403: Frog Jump"
date = "2023-09-26"
description = "In-depth solution and explanation for Leetcode 403: Frog Jump in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/frog-jump/description/)

---

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
---


| Next : [LeetCode #404: Sum of Left Leaves](grid47.xyz/leetcode_404) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

