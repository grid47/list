
+++
authors = ["grid47"]
title = "Leetcode 1920: Build Array from Permutation"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1920: Build Array from Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "LoUAGs8fqB0"
youtube_upload_date="2021-07-04"
youtube_thumbnail="https://i.ytimg.com/vi/LoUAGs8fqB0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/build-array-from-permutation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1920.md" >}}
---
{{< youtube LoUAGs8fqB0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1921: Eliminate Maximum Number of Monsters](https://grid47.xyz/leetcode/solution-1921-eliminate-maximum-number-of-monsters/) |
| --- |