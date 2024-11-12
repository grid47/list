
+++
authors = ["grid47"]
title = "Leetcode 50: Pow(x, n)"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 50: Pow(x, n) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powx-n/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/50.webp" 
    alt="A soft, glowing beam expanding and contracting in gentle rhythmic pulses."
    caption="Solution to LeetCode 50: Pow(x, n) Problem"
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
    double myPow(double x, int n) {
        if(n== 0) return 1;
        if(n < 0) return 1/x * myPow(1/x, -(n + 1));
        
        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n/ 2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/50.md" >}}
---
{{< youtube g9YQyYi4IQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #53: Maximum Subarray](https://grid47.xyz/posts/leetcode-53-maximum-subarray-solution/) |
| --- |
