
+++
authors = ["grid47"]
title = "Leetcode 2269: Find the K-Beauty of a Number"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2269: Find the K-Beauty of a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0, cur = 0, pow = 1;
        for (int n = num; n > 0; n /= 10) {
            cur += (n % 10) * pow;
            if (--k > 0)
                pow *= 10;
            else {
                res += cur && !(num % cur);
                cur /= 10;
            }
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2269.md" >}}
---
{{< youtube 23-y60kKUdY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2270: Number of Ways to Split Array](https://grid47.xyz/posts/leetcode-2270-number-of-ways-to-split-array-solution/) |
| --- |
