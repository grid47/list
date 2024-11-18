
+++
authors = ["grid47"]
title = "Leetcode 2443: Sum of Number and Its Reverse"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2443: Sum of Number and Its Reverse in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-number-and-its-reverse/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rev(int num) {
        int tmp = 0;
        while(num) {
            tmp = tmp * 10 + num % 10;
            num /= 10;
        }
        return tmp;
    }
    
    bool sumOfNumberAndReverse(int num) {
        
        for(int i = 0; i <= num; i++) {
            if((i + rev(i) )== num) {
                return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2443.md" >}}
---
{{< youtube ESqVFCHtAGg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2446: Determine if Two Events Have Conflict](https://grid47.xyz/leetcode/solution-2446-determine-if-two-events-have-conflict/) |
| --- |
