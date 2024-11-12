
+++
authors = ["grid47"]
title = "Leetcode 201: Bitwise AND of Numbers Range"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 201: Bitwise AND of Numbers Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/201.jpeg" 
    alt="A series of overlapping circles, each representing a number, with a soft intersection of glowing bits in the middle."
    caption="Solution to LeetCode 201: Bitwise AND of Numbers Range Problem"
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
    int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    
    while(right != left)
    {
        right >>= 1 ;
        left  >>= 1;
        shift++;
    }
    
    return right << shift;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/201.md" >}}
---
{{< youtube vZkutwUrPgE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #202: Happy Number](https://grid47.xyz/posts/leetcode-202-happy-number-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
