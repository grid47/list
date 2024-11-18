
+++
authors = ["grid47"]
title = "Leetcode 343: Integer Break"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 343: Integer Break in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "61kuCyvWWhI"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/343.webp"
+++



[`Problem Link`](https://leetcode.com/problems/integer-break/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/343.webp" 
    alt="A glowing number breaking down into smaller integer components, with the optimal break point softly illuminated."
    caption="Solution to LeetCode 343: Integer Break Problem"
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
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int product = 1;
        while(n > 4) {
            product *= 3;
            n -= 3;
        }
        product *= n;
        return product;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/343.md" >}}
---
{{< youtube 61kuCyvWWhI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #344: Reverse String](https://grid47.xyz/leetcode/solution-344-reverse-string/) |
| --- |
