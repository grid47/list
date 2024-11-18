
+++
authors = ["grid47"]
title = "Leetcode 714: Best Time to Buy and Sell Stock with Transaction Fee"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 714: Best Time to Buy and Sell Stock with Transaction Fee in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/714.webp"
youtube = "HLr_OnShK4s"
youtube_upload_date="2021-02-21"
youtube_thumbnail="https://i.ytimg.com/vi/HLr_OnShK4s/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/714.webp" 
    alt="A stock price chart where the best time to buy and sell is highlighted, with the optimal prices softly glowing."
    caption="Solution to LeetCode 714: Best Time to Buy and Sell Stock with Transaction Fee Problem"
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
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0;
        int days = prices.size();
        vector<int> buy(days, 0), sell(days, 0);
        buy[0]= -prices[0]-fee;
        for(int i = 1; i < days; i++) {
            buy[i] = max(buy[i -1], sell[i -1]-prices[i]-fee);
            sell[i] = max(sell[i -1], buy[i - 1]+prices[i]);
        }
        return sell[days - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/714.md" >}}
---
{{< youtube HLr_OnShK4s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #718: Maximum Length of Repeated Subarray](https://grid47.xyz/leetcode/solution-718-maximum-length-of-repeated-subarray/) |
| --- |
