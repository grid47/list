
+++
authors = ["grid47"]
title = "Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0l2IwK_OHac"
youtube_upload_date="2023-10-29"
youtube_thumbnail="https://i.ytimg.com/vi/0l2IwK_OHac/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
        for(int num: nums1) cnt1 += num == 0, sum1 += num;
        for(int num: nums2) cnt2 += num == 0, sum2 += num;

        if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
            cnt2 == 0 && cnt1 + sum1 > sum2)
                return -1;

        return max(sum1 + cnt1, sum2 + cnt2);

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2918.md" >}}
---
{{< youtube 0l2IwK_OHac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2919: Minimum Increment Operations to Make Array Beautiful](https://grid47.xyz/leetcode/solution-2919-minimum-increment-operations-to-make-array-beautiful/) |
| --- |
