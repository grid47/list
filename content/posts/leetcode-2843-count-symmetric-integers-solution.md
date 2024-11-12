
+++
authors = ["grid47"]
title = "Leetcode 2843:   Count Symmetric Integers"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2843:   Count Symmetric Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-symmetric-integers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; ++i) {
            string s = to_string(i);
            int t = 0, n = s.size();
            for(int j = 0; j < n/2; ++j) { t += s[j] - s[n - j - 1]; }
            if(n%2 == 0 && t == 0) ans++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2843.md" >}}
---
{{< youtube KHRfRTVqpVc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2844: Minimum Operations to Make a Special Number](https://grid47.xyz/posts/leetcode-2844-minimum-operations-to-make-a-special-number-solution/) |
| --- |
