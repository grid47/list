
+++
authors = ["grid47"]
title = "Leetcode 349: Intersection of Two Arrays"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 349: Intersection of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/intersection-of-two-arrays/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/349.webp" 
    alt="Two arrays intersecting with glowing elements where they overlap, gently highlighting the intersection points."
    caption="Solution to LeetCode 349: Intersection of Two Arrays Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #355: Design Twitter](https://grid47.xyz/posts/leetcode-355-design-twitter-solution/) |
| --- |
