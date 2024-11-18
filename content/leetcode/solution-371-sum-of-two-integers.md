
+++
authors = ["grid47"]
title = "Leetcode 371: Sum of Two Integers"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 371: Sum of Two Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-two-integers/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/371.webp" 
    alt="A set of two glowing numbers adding up to a sum, with each number and their sum softly illuminated."
    caption="Solution to LeetCode 371: Sum of Two Integers Problem"
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
    int getSum(int a, int b) {
        return b == 0? a: getSum(a^b, (a&b)<<1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/371.md" >}}
---
{{< youtube gVUrDV4tZfY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #372: Super Pow](https://grid47.xyz/leetcode/solution-372-super-pow/) |
| --- |
