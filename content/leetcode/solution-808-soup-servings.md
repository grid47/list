
+++
authors = ["grid47"]
title = "Leetcode 808: Soup Servings"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 808: Soup Servings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/808.webp"
+++



[`Problem Link`](https://leetcode.com/problems/soup-servings/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/808.webp" 
    alt="Bowls of soup where servings are poured, glowing softly as each serving is calculated."
    caption="Solution to LeetCode 808: Soup Servings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
        vector<vector<double>> mem;
public:
    double soupServings(int n) {
        mem.resize(200, vector<double>(200, 0));
        return n > 4800? 1:f((n +24)/25, (n+24)/25);
    }

    double f(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;
        if(mem[a][b] > 0) return mem[a][b];
 mem[a][b] = 0.25 * (f(a-4, b) + f(a-3, b-1) + f(a - 2, b -2) + f(a-1, b-3));
        return mem[a][b];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/808.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #809: Expressive Words](https://grid47.xyz/leetcode/solution-809-expressive-words/) |
| --- |
