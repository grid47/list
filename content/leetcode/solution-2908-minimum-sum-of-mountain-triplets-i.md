
+++
authors = ["grid47"]
title = "Leetcode 2908: Minimum Sum of Mountain Triplets I"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2908: Minimum Sum of Mountain Triplets I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "GegaVi1CeUM"
youtube_upload_date="2023-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/GegaVi1CeUM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] < nums[j] && nums[k] < nums[j]) ans = min(ans,nums[i]+nums[j]+nums[k]);
                }
            }
        }
        
        return (ans==INT_MAX ? -1:ans);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2908.md" >}}
---
{{< youtube GegaVi1CeUM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2909: Minimum Sum of Mountain Triplets II](https://grid47.xyz/leetcode/solution-2909-minimum-sum-of-mountain-triplets-ii/) |
| --- |
