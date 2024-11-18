
+++
authors = ["grid47"]
title = "Leetcode 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZNAJbQTv3yk"
youtube_upload_date="2020-09-06"
youtube_thumbnail="https://i.ytimg.com/vi/ZNAJbQTv3yk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        long res = 0;

        for(int v: nums1)
            res += twoProd((long)v * v, nums2);
        for(int v: nums2)
            res += twoProd((long)v * v, nums1);

        return res;
    }
    
    
    long twoProd(long i, vector<int> &nums) {
        map<long, long> mp;
        
        int cnt = 0;
        for(int n : nums) {
            if(i % n == 0)
                cnt += mp[i / n];
            mp[n]++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1577.md" >}}
---
{{< youtube ZNAJbQTv3yk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1578: Minimum Time to Make Rope Colorful](https://grid47.xyz/leetcode/solution-1578-minimum-time-to-make-rope-colorful/) |
| --- |
