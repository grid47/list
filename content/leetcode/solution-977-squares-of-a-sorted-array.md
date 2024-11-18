
+++
authors = ["grid47"]
title = "Leetcode 977: Squares of a Sorted Array"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 977: Squares of a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "z0InhrjK3es"
youtube_upload_date="2024-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/z0InhrjK3es/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/squares-of-a-sorted-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1;
        int ll, rr;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ll = nums[l] * nums[l];
            rr = nums[r] * nums[r];
            if(ll < rr) ans[i] = rr, r--;
            else ans[i] = ll, l++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/977.md" >}}
---
{{< youtube z0InhrjK3es >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #978: Longest Turbulent Subarray](https://grid47.xyz/leetcode/solution-978-longest-turbulent-subarray/) |
| --- |
