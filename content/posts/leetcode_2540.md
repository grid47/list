
+++
authors = ["Yasir"]
title = "Leetcode 2540: Minimum Common Value"
date = "2017-11-14"
description = "Solution to Leetcode 2540"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-common-value/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int x: nums1)
            mp[x] = true;
        for(int y: nums2)
            if(mp.count(y))
                return y;
        return -1;
    }
};
{{< /highlight >}}

