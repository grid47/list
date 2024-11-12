
+++
authors = ["grid47"]
title = "Leetcode 2962: Count Subarrays Where Max Element Appears at Least K Times"
date = "2024-01-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2962: Count Subarrays Where Max Element Appears at Least K Times in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2962.md" >}}
---
{{< youtube CZ-z1ViskzE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2965: Find Missing and Repeated Values](https://grid47.xyz/posts/leetcode-2965-find-missing-and-repeated-values-solution/) |
| --- |
