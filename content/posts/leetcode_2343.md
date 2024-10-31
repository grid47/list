
+++
authors = ["Crafted by Me"]
title = "Leetcode 2343: Query Kth Smallest Trimmed Number"
date = "2018-06-03"
description = "Solution to Leetcode 2343"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> res;
        for(auto &v : q) {
            
            vector<pair<string, int>> fk;
            for(int i = 0; i < nums.size(); i++) {
                fk.push_back({nums[i].substr(nums[i].size() - v[1]), i});
            }
            sort(fk.begin(), fk.end());
            res.push_back(fk[v[0] - 1].second);
            
        }
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

