
+++
authors = ["Yasir"]
title = "Leetcode 56: Merge Intervals"
date = "2024-09-01"
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

{{< highlight html >}}
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

