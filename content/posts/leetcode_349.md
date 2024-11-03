
+++
authors = ["Crafted by Me"]
title = "Leetcode 349: Intersection of Two Arrays"
date = "2023-11-19"
description = "In-depth solution and explanation for Leetcode 349: Intersection of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/349.md" >}}
---
{{< youtube XxStWmfXJRs >}}
| Next : [LeetCode #350: Intersection of Two Arrays II](https://grid47.xyz/posts/leetcode_350) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

