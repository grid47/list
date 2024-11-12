
+++
authors = ["grid47"]
title = "Leetcode 1031: Maximum Sum of Two Non-Overlapping Subarrays"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1031: Maximum Sum of Two Non-Overlapping Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int maxTwoNoOverlap(vector<int>& A, int L, int M, int sz, int res = 0) {
        vector<int> left(sz+1), right(sz+1);

        for (int i = 0, j = sz - 1, s_r = 0, s_l = 0; i < sz; ++i, --j) {
            s_l += A[i], s_r += A[j];
            left[i + 1] = max(left[i], s_l);
            right[j] = max(right[j + 1], s_r);
            if (i + 1 >= L) s_l -= A[i + 1 - L];
            if (i + 1 >= M) s_r -= A[j + M - 1];
        }

        for (auto i = 0; i < A.size(); ++i) {
            res = max(res, left[i] + right[i]);
        }
  
        return res;

    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(maxTwoNoOverlap(nums, firstLen, secondLen, nums.size()),
                   maxTwoNoOverlap(nums, secondLen, firstLen, nums.size()));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1031.md" >}}
---
{{< youtube YAcHH5AVsZg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1033: Moving Stones Until Consecutive](https://grid47.xyz/posts/leetcode-1033-moving-stones-until-consecutive-solution/) |
| --- |
