
+++
authors = ["grid47"]
title = "Leetcode 1390: Four Divisors"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1390: Four Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/four-divisors/description/)

---
**Code:**

{{< highlight cpp >}}


class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        
        int sum = 0;
        
        for(auto n: nums) {
            int d = 0;
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    if(d == 0) {
                        d = i;
                    } else {
                        d = 0;
                        break;
                    }
                }
            }
            if(d > 0 && d != n/d) {
                sum += 1 + n + d + n/d;
            }            
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1390.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1391: Check if There is a Valid Path in a Grid](https://grid47.xyz/leetcode/solution-1391-check-if-there-is-a-valid-path-in-a-grid/) |
| --- |
