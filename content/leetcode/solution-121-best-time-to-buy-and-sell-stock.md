
+++
authors = ["grid47"]
title = "Leetcode 121: Best Time to Buy and Sell Stock"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 121: Best Time to Buy and Sell Stock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "kJZrMGpyWpk"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/121.webp"
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/121.webp" 
    alt="A soft, glowing chart of stock prices with a smooth line representing the best time to buy and sell."
    caption="Solution to LeetCode 121: Best Time to Buy and Sell Stock Problem"
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
    int maxProfit(vector<int>& prices) {
        int l = prices[0], g = 0;
        for(int x: prices) {
            l = min(l, x);
            g = max(g, x - l);
        }
        return g;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/121.md" >}}
---
{{< youtube kJZrMGpyWpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #125: Valid Palindrome](https://grid47.xyz/leetcode/solution-125-valid-palindrome/) |
| --- |
