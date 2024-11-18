
+++
authors = ["grid47"]
title = "Leetcode 1680: Concatenation of Consecutive Binary Numbers"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1680: Concatenation of Consecutive Binary Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int concatenatedBinary(int n) {
        
        int mod = (int) 1e9 + 7;
        
        long ans = 0;
        int len = 0;
        for(int i = 1; i <= n; i++) {
            if(__builtin_popcount(i) == 1) len++;
            
            ans = ((ans << len) % mod + i % mod) % mod;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1680.md" >}}
---
{{< youtube 1ZtYzuWUFwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1684: Count the Number of Consistent Strings](https://grid47.xyz/leetcode/solution-1684-count-the-number-of-consistent-strings/) |
| --- |
