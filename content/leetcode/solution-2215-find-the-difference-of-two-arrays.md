
+++
authors = ["grid47"]
title = "Leetcode 2215: Find the Difference of Two Arrays"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2215: Find the Difference of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "oypp_RzI69w"
youtube_upload_date="2023-05-03"
youtube_thumbnail="https://i.ytimg.com/vi/oypp_RzI69w/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> s1, s2;
        for(int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
        for(int x: s1) {
            if(!s2.count(x))
                ans[0].push_back(x);
        }
        for(int x: s2) {
            if(!s1.count(x))
                ans[1].push_back(x);
        }        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2215.md" >}}
---
{{< youtube oypp_RzI69w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2216: Minimum Deletions to Make Array Beautiful](https://grid47.xyz/leetcode/solution-2216-minimum-deletions-to-make-array-beautiful/) |
| --- |