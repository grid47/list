
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 846: Hand of Straights"
date = "2022-07-06"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

