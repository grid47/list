
+++
authors = ["Yasir"]
title = "Leetcode 2962: Count Subarrays Where Max Element Appears at Least K Times"
date = "2016-09-18"
description = "Solution to Leetcode 2962"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        int a = *max_element(A.begin(), A.end()), n = A.size(), cur = 0, i = 0;
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            cur += A[j] == a;
            while (cur >= k)
                cur -= A[i++] == a;
            res += i;
        }
        return res;
    }
};
{{< /highlight >}}

