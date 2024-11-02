
+++
authors = ["Crafted by Me"]
title = "Leetcode 1282: Group the People Given the Group Size They Belong To"
date = "2020-04-29"
description = "Solution to Leetcode 1282"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gz) {
        vector<vector<int>> res, gzs(gz.size() + 1);
        for(auto i = 0; i < gz.size(); i++) {
            gzs[gz[i]].push_back(i);
            if(gzs[gz[i]].size() == gz[i]) {
                res.push_back({});
                swap(res.back(), gzs[gz[i]]);
            }
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube RrnhHjJmzj8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

