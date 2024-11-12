
+++
authors = ["grid47"]
title = "Leetcode 1283: Find the Smallest Divisor Given a Threshold"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1283: Find the Smallest Divisor Given a Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6, m , sum;
        while(left < right) {
            m = (left + right) / 2;
            sum = 0;
            for(int i: nums) sum += (i + m - 1)/m;
            if(sum > threshold) 
            left = m + 1;
            else right = m;
        }
        return left;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1283.md" >}}
---
{{< youtube KGlnb3yT8iY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1286: Iterator for Combination](https://grid47.xyz/posts/leetcode-1286-iterator-for-combination-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
