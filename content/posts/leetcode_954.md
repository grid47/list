
+++
authors = ["Crafted by Me"]
title = "Leetcode 954: Array of Doubled Pairs"
date = "2022-03-24"
description = "In-depth solution and explanation for Leetcode 954: Array of Doubled Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/array-of-doubled-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        unordered_map<int, int> c;
        for(int i : arr)
            c[i]++;
        
        vector<int> keys;
        for(auto it: c)
            keys.push_back(it.first);
        
        sort(keys.begin(), keys.end(), [&](int a, int b){
            return abs(a) < abs(b);
        });
        
        for(int x: keys) {
            if(c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/954.md" >}}
---
{{< youtube Q0WKzdpR74o >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

