
+++
authors = ["Yasir"]
title = "Leetcode 870: Advantage Shuffle"
date = "2022-06-12"
description = "Solution to Leetcode 870"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/advantage-shuffle/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(begin(nums1), end(nums1));
        for ( auto i = 0; i < nums2.size(); i++) {
            auto p = *s.rbegin() <= nums2[i] ? s.begin() : s.upper_bound(nums2[i]);
            nums1[i] = *p;
            s.erase(p);
        }
        return nums1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

