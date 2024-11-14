
+++
authors = ["grid47"]
title = "Leetcode 754: Reach a Number"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 754: Reach a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reach-a-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/754.webp" 
    alt="A number line where the steps to reach a target number are traced, with each step glowing softly."
    caption="Solution to LeetCode 754: Reach a Number Problem"
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
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
        long long sum = n * (n + 1) / 2;
        if (sum == target) return n;
        long long res = sum - target;
        if((res &1) == 0)   return n;
        else                return n + ((n&1)? 2: 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/754.md" >}}
---
{{< youtube K8yXBn4cCQs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #756: Pyramid Transition Matrix](https://grid47.xyz/posts/leetcode-756-pyramid-transition-matrix-solution/) |
| --- |
