
+++
authors = ["grid47"]
title = "Leetcode 258: Add Digits"
date = "2024-10-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 258: Add Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-digits/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/258.webp" 
    alt="A number gradually breaking down into smaller digits, with each step glowing brighter until a single digit is left."
    caption="Solution to LeetCode 258: Add Digits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        while(num > 9) {
            while(num > 0) {
                res += num % 10;
                num /= 10;
            }
            
            num = res;
            res = 0;
        }
        return num;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/258.md" >}}
---
{{< youtube gPZvXaniFDQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #268: Missing Number](https://grid47.xyz/leetcode/solution-268-missing-number/) |
| --- |
