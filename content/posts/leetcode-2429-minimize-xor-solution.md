
+++
authors = ["grid47"]
title = "Leetcode 2429: Minimize XOR"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2429: Minimize XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-xor/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int res = 0;
        for(int i = 30; i >= 0; i--) {
            if(((num1 >> i) & 1) == 1) {
                if(n > 0) {
                    res |= (1 << i);
                    n--;
                    if(n == 0) return res;
                }
            }
        }
        int i = 0;
        while(n > 0) {
            if(((res >> i) & 1) == 0) {
                res |= (1 << i);
                n--;
            }
            i++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2429.md" >}}
---
{{< youtube mWUMfdloybo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2432: The Employee That Worked on the Longest Task](https://grid47.xyz/posts/leetcode-2432-the-employee-that-worked-on-the-longest-task-solution/) |
| --- |
