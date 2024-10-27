
+++
authors = ["Yasir"]
title = "Leetcode 2150: Find All Lonely Numbers in the Array"
date = "2018-12-09"
description = "Solution to Leetcode 2150"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums) mp[num]++;

        vector<int> res;
        for(auto [x, cnt]: mp) {
            if(cnt == 1 && !mp.count(x - 1) && !mp.count(x +1))
                res.push_back(x);
        }

        return res;
    }
};
{{< /highlight >}}

