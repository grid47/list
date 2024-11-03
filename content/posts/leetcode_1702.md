
+++
authors = ["Crafted by Me"]
title = "Leetcode 1702: Maximum Binary String After Change"
date = "2020-03-06"
description = "In-depth solution and explanation for Leetcode 1702: Maximum Binary String After Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-binary-string-after-change/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumBinaryString(string binary) {
        int ones = 0, zeros = 0, n = binary.size();
        for (auto &c: binary) {
            if(c == '0')
            zeros++;
            else if (zeros == 0)
            ones++;
            c = '1';
        }
        if(ones < n)
        binary[zeros + ones -1] = '0';
        return binary;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1702.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1703: Minimum Adjacent Swaps for K Consecutive Ones](https://grid47.xyz/posts/leetcode_1703) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

