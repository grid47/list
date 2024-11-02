
+++
authors = ["Crafted by Me"]
title = "Leetcode 56: Merge Intervals"
date = "2023-09-07"
description = "Solution to Leetcode 56"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-intervals/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        sort(iv.begin(), iv.end());
        vector<vector<int>> ans;
        vector<int> tmp = iv[0];
        for(int i = 0; i < iv.size(); i++) {
            if(iv[i][0] <= tmp[1]) {
                tmp[1] = max(tmp[1], iv[i][1]);
            } else {
                ans.push_back(tmp);
                tmp = iv[i];
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/56.md" >}}
---
{{< youtube HCbKvBOlMVI >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

