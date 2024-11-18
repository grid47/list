
+++
authors = ["grid47"]
title = "Leetcode 2169: Count Operations to Obtain Zero"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2169: Count Operations to Obtain Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "yPqe3KshvVo"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/count-operations-to-obtain-zero/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 > 0 && num2 > 0) {
            if(num1 > num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2169.md" >}}
---
{{< youtube yPqe3KshvVo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2170: Minimum Operations to Make the Array Alternating](https://grid47.xyz/leetcode/solution-2170-minimum-operations-to-make-the-array-alternating/) |
| --- |
