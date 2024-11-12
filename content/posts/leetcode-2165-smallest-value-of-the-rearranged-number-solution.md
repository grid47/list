
+++
authors = ["grid47"]
title = "Leetcode 2165: Smallest Value of the Rearranged Number"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2165: Smallest Value of the Rearranged Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long smallestNumber(long long num) {
        auto s = to_string(abs(num));
        sort(s.begin(), s.end(), [&](char a, char b){
            return num > 0? a < b: b < a;
        });
        if(num > 0)
        swap(s[0], s[s.find_first_not_of('0')]);
        return stoll(s) * (num < 0? -1: 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2165.md" >}}
---
{{< youtube fe3yn96MAoI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2166: Design Bitset](https://grid47.xyz/posts/leetcode-2166-design-bitset-solution/) |
| --- |
