
+++
authors = ["grid47"]
title = "Leetcode 1818: Minimum Absolute Sum Difference"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1818: Minimum Absolute Sum Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PlenJ9Ny45s"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PlenJ9Ny45s/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-sum-difference/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        set<int> sel(begin(nums1), end(nums1));

        long gain = 0, res = 0;
        for(int i = 0; i < n; i++) {
            long og = abs(nums1[i] - nums2[i]);
            res += og;
            if (gain < og) {
                auto num = sel.lower_bound(nums2[i]);
                if (num !=   end(sel)) gain = max(gain, og - abs(*num       - nums2[i]));
                if (num != begin(sel)) gain = max(gain, og - abs(*prev(num) - nums2[i]));
            }
        }

        return (res - gain) % 1000000007;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1818.md" >}}
---
{{< youtube PlenJ9Ny45s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1822: Sign of the Product of an Array](https://grid47.xyz/leetcode/solution-1822-sign-of-the-product-of-an-array/) |
| --- |