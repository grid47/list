
+++
authors = ["grid47"]
title = "Leetcode 397: Integer Replacement"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 397: Integer Replacement in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Greedy","Bit Manipulation","Memoization"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/integer-replacement/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/397.webp" 
    alt="A glowing number transforming step by step into its minimal representation through division or subtraction."
    caption="Solution to LeetCode 397: Integer Replacement Problem"
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
    int integerReplacement(int n) {
        if(n == INT_MAX) return 32;
        int cnt = 0;
        while(n > 1) {
            if(n % 2 == 0) n /= 2;
            else {
                if((n + 1) %4 == 0 && (n - 1) != 2) n++;
                else n--;
            }
            cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/397.md" >}}
---
{{< youtube 5ksn2Myjlig >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #398: Random Pick Index](https://grid47.xyz/posts/leetcode-398-random-pick-index-solution/) |
| --- |
