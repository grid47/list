
+++
authors = ["Crafted by Me"]
title = "Leetcode 1054: Distant Barcodes"
date = "2021-12-14"
description = "In-depth solution and explanation for Leetcode 1054: Distant Barcodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distant-barcodes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
        unordered_map<int, int> mp;
        set<pair<int, int>> st;
        for(int num: b) mp[num]++;
        for(auto it: mp) st.insert({ it.second, it.first });
        for(auto it = st.rbegin(); it != st.rend(); it++) {
            for(auto cnt = 0; cnt < it->first; cnt++, pos += 2) {
                if(pos >= b.size()) pos  = 1;
                b[pos] = it->second;
            }
        }
        return b;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1054.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

