
+++
authors = ["Crafted by Me"]
title = "Leetcode 2391: Minimum Amount of Time to Collect Garbage"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2391: Minimum Amount of Time to Collect Garbage in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {}, res = 0;        
        for(int i = 0; i < garbage.size(); i++) {
            res += garbage[i].size();
            for(char c : garbage[i])
                last[c] = i;
        }

        for(int j = 1; j < travel.size(); j++)
            travel[j] += travel[j - 1];
        
        for(int c : "PGM")
        if(last[c])
        res += travel[last[c] - 1];
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2392: Build a Matrix With Conditions](https://grid47.xyz/posts/leetcode_2392) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

