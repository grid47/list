
+++
authors = ["grid47"]
title = "Leetcode 2540: Minimum Common Value"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2540: Minimum Common Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "pbKnQYJuSY0"
youtube_upload_date="2023-01-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pbKnQYJuSY0/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-common-value/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2540.md" >}}
---
{{< youtube pbKnQYJuSY0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2541: Minimum Operations to Make Array Equal II](https://grid47.xyz/leetcode/solution-2541-minimum-operations-to-make-array-equal-ii/) |
| --- |
