
+++
authors = ["grid47"]
title = "Leetcode 481: Magical String"
date = "2024-09-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 481: Magical String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/magical-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/481.webp" 
    alt="A sequence where the magical string gradually forms, with each step softly glowing as the pattern emerges."
    caption="Solution to LeetCode 481: Magical String Problem"
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
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while(s.size() < n)
        s += string(s[i++] - '0', s.back() ^ 3);
        return count(s.begin(), s.begin() + n, '1');
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/481.md" >}}
---
{{< youtube -iFDu2kaCpY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #486: Predict the Winner](https://grid47.xyz/posts/leetcode-486-predict-the-winner-solution/) |
| --- |
