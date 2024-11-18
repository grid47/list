
+++
authors = ["grid47"]
title = "Leetcode 1979: Find Greatest Common Divisor of Array"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1979: Find Greatest Common Divisor of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "sJ5pTyUWOZ0"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    public:
        int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }
        int findGCD(vector<int> &nums) {
            int min = 1001;
            int max = 0;
            // Find the min and max from array
            for (int e : nums) {
                if (e < min) min = e;
                if (e > max) max = e;
            }
            return gcd(min, max);
        }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1979.md" >}}
---
{{< youtube sJ5pTyUWOZ0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1980: Find Unique Binary String](https://grid47.xyz/leetcode/solution-1980-find-unique-binary-string/) |
| --- |
