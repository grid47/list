
+++
authors = ["Yasir"]
title = "Leetcode 1282: Group the People Given the Group Size They Belong To"
date = "2021-04-25"
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

{{< highlight html >}}
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

