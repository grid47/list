
+++
authors = ["grid47"]
title = "Leetcode 1432: Max Difference You Can Get From Changing an Integer"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1432: Max Difference You Can Get From Changing an Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int change(int num, int x, int y) {
        int tmp = 0, ten = 1;
        int digit;
        while(num) {
            digit = num % 10;
            if(digit == x) digit = y;
            tmp = ten * digit + tmp;
            num /= 10;
            ten *= 10;
        }
        return digit == 0? -1: tmp;
    }
    
    int maxDiff(int num) {
        int mn = num, mx = num;
        for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++) {
            if(i == j) continue;
            int ret = change(num, i, j);
            if(ret <= 0) continue;
            mn = min(mn, ret);
            mx = max(mx, ret);
        }
        cout << mx << " " << mn;
        return mx - mn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1432.md" >}}
---
{{< youtube sOnpt2zHWfQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1433: Check If a String Can Break Another String](https://grid47.xyz/posts/leetcode-1433-check-if-a-string-can-break-another-string-solution/) |
| --- |
