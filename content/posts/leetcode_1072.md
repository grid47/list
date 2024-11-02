
+++
authors = ["Crafted by Me"]
title = "Leetcode 1072: Flip Columns For Maximum Number of Equal Rows"
date = "2020-11-25"
description = "Solution to Leetcode 1072"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mtx) {
        unordered_map<string, int> mp;
        for(auto x: mtx) {
            string s = "";
            int top = x[0];
            for(int i = 0; i < x.size(); i++) {
                if(x[i] == top) s += '1';
                else s += '0';
            }
            mp[s]++;
        }
        int res = 0;
        for(auto [k, v]: mp)
            res = max(res, v);
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

