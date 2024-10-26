
+++
authors = ["Yasir"]
title = "Leetcode 349: Intersection of Two Arrays"
date = "2023-11-13"
description = "Solution to Leetcode 349"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/intersection-of-two-arrays/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};
{{< /highlight >}}

