
+++
authors = ["Yasir"]
title = "Leetcode 1054: Distant Barcodes"
date = "2021-12-10"
description = "Solution to Leetcode 1054"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

