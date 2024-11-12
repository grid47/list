
+++
authors = ["grid47"]
title = "Leetcode 2928: Distribute Candies Among Children I"
date = "2024-01-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2928: Distribute Candies Among Children I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Combinatorics","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distribute-candies-among-children-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for(int i = 0; i <= limit; ++i){
            for(int j = 0; j <= limit; ++j){
                for(int k = 0; k <= limit; ++k){
                    if(i + j + k == n) { res++; }
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2928.md" >}}
---
{{< youtube hVNcZKh8r40 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2932: Maximum Strong Pair XOR I](https://grid47.xyz/posts/leetcode-2932-maximum-strong-pair-xor-i-solution/) |
| --- |
