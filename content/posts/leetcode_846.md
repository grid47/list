
+++
authors = ["Crafted by Me"]
title = "Leetcode 846: Hand of Straights"
date = "2022-07-10"
description = "Solution to Leetcode 846"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/hand-of-straights/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(int x: hand) mp[x]++;
        
        for(auto it: mp) {
            if(mp[it.first] > 0)
            for(int i = 1; i < groupSize; i++){
                mp[it.first + i] -= mp[it.first];
                if(mp[it.first + i] < 0)
                    return false;
            }
            mp[it.first] = 0;
        }
        return true;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/846.md" >}}
- by gpt
        
---
{{< youtube amnrMCVd2YI >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

