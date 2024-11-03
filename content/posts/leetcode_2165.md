
+++
authors = ["Crafted by Me"]
title = "Leetcode 2165: Smallest Value of the Rearranged Number"
date = "2018-11-29"
description = "In-depth solution and explanation for Leetcode 2165: Smallest Value of the Rearranged Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


| Next : [LeetCode #2166: Design Bitset](grid47.xyz/leetcode_2166) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

