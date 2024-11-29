
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
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/121.webp"
youtube = "kJZrMGpyWpk"
youtube_upload_date="2024-06-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kJZrMGpyWpk/maxresdefault.webp"
comments = true
+++


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
You are given an array of prices where prices[i] represents the price of a stock on the i-th day. You want to maximize your profit by buying the stock on one day and selling it on a future day. Return the maximum profit you can achieve from this transaction. If no profit can be made, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array prices where prices[i] is the price of the stock on the i-th day.
- **Example:** `Input: prices = [10, 3, 15, 8, 12, 5]`
- **Constraints:**
	- 1 <= prices.length <= 10^5
	- 0 <= prices[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a single integer representing the maximum profit you can achieve from buying and selling the stock.
- **Example:** `Output: 9`
- **Constraints:**
	- The profit should be the difference between the selling price and the buying price, where the selling day is after the buying day.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the profit by choosing the best day to buy and the best day to sell in the future.

- Start by initializing the lowest price (l) as the price of the first day.
- Iterate through the prices and update the lowest price (l) as the minimum price encountered so far.
- For each price, calculate the potential profit by subtracting the lowest price (l) from the current price.
- Keep track of the maximum profit (g) encountered during the iteration.
- Return the maximum profit after processing all prices.
{{< dots >}}
### Problem Assumptions ✅
- The input array prices contains valid values with at least one price.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: prices = [10, 3, 15, 8, 12, 5]`  \
  **Explanation:** The maximum profit can be achieved by buying the stock on day 2 (price = 3) and selling it on day 3 (price = 15). The profit is 15 - 3 = 12.

- **Input:** `Input: prices = [7, 6, 4, 3, 1]`  \
  **Explanation:** In this case, no profit can be made as prices keep decreasing, so the maximum profit is 0.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating through the prices while tracking the minimum price seen so far and calculating the potential profit for each day. The maximum profit is then updated accordingly.

### Initial Thoughts 💭
- The approach involves iterating over the array once to keep track of the minimum price and maximum profit.
- The key observation is that the best profit comes from buying at the lowest price before a higher price in the future.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs allowed, as prices array has at least one element.
- The algorithm should efficiently handle inputs up to 100,000 prices.
- If all prices are the same or decreasing, the maximum profit will be 0.
- The array length will always be between 1 and 100,000, inclusive.
{{< dots >}}
## Code 💻
```cpp
int maxProfit(vector<int>& prices) {
    int l = prices[0], g = 0;
    for(int x: prices) {
        l = min(l, x);
        g = max(g, x - l);
    }
    return g;
}
```

This function calculates the maximum profit from a single buy-and-sell stock transaction using a greedy approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxProfit(vector<int>& prices) {
	```
	Declare a function to compute the maximum profit from stock prices given as input.

2. **Variable Initialization**
	```cpp
	    int l = prices[0], g = 0;
	```
	Initialize `l` to the first price (representing the lowest price seen so far) and `g` to 0 (representing the maximum profit).

3. **Loop Iteration**
	```cpp
	    for(int x: prices) {
	```
	Iterate over all stock prices to compute the lowest price and maximum profit dynamically.

4. **Minimum Update**
	```cpp
	        l = min(l, x);
	```
	Update `l` to the minimum of the current price and the previously seen lowest price.

5. **Profit Update**
	```cpp
	        g = max(g, x - l);
	```
	Update `g` to the maximum profit seen so far by subtracting the lowest price from the current price.

6. **Return Statement**
	```cpp
	    return g;
	```
	Return the maximum profit calculated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each element of the prices array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of space to store the variables for the minimum price and maximum profit.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

---
{{< youtube kJZrMGpyWpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
