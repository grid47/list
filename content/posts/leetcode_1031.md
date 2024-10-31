
+++
authors = ["Crafted by Me"]
title = "Leetcode 1031: Maximum Sum of Two Non-Overlapping Subarrays"
date = "2022-01-05"
description = "Solution to Leetcode 1031"
tags = [
    
]
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


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

