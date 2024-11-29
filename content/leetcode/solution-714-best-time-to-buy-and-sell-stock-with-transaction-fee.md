
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
comments = true
+++


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
You are given an array `prices` where `prices[i]` represents the price of a stock on the `i`-th day, and an integer `fee` that represents a transaction fee for each transaction. The task is to calculate the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `prices` of integers representing the prices of the stock for each day and an integer `fee` representing the transaction fee.
- **Example:** `prices = [2, 6, 4, 7, 5, 9], fee = 3`
- **Constraints:**
	- 1 <= prices.length <= 5 * 10^4
	- 1 <= prices[i] < 5 * 10^4
	- 0 <= fee < 5 * 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum profit that can be achieved after completing as many transactions as possible, where each transaction is subject to a transaction fee.
- **Example:** `9`
- **Constraints:**
	- The result should be a non-negative integer representing the maximum profit.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the maximum profit by applying a dynamic programming approach.

- Use two arrays, `buy` and `sell`, where `buy[i]` stores the maximum profit at day `i` when buying the stock, and `sell[i]` stores the maximum profit at day `i` when selling the stock.
- Initialize `buy[0]` as `-prices[0] - fee` since you can buy the stock on the first day with the fee applied.
- Iterate through the `prices` array, and for each day, compute the maximum profit from either holding the stock or selling it (while considering the transaction fee).
- Finally, the value in `sell[n-1]` will hold the maximum profit at the end of the array.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least one price.
- The transaction fee is applied once for every transaction (buying and selling).
{{< dots >}}
## Examples 🧩
- **Input:** `prices = [2, 6, 4, 7, 5, 9], fee = 3`  \
  **Explanation:** The best strategy is to buy on day 1, sell on day 2, buy again on day 3, and sell on day 4. Then, buy on day 5 and sell on day 6. The total profit is 9.

- **Input:** `prices = [3, 2, 5, 1, 7], fee = 1`  \
  **Explanation:** The maximum profit can be obtained by buying at day 2 and selling at day 3, and then buying at day 4 and selling at day 5. The total profit is 6.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming with a space optimization technique.

### Initial Thoughts 💭
- We need to track the profit for both holding and selling stocks for each day.
- By maintaining two variables (buy and sell), we can optimize space while computing the maximum profit.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the result should be 0.
- Ensure the solution works efficiently for large inputs (up to 50,000 days).
- If the fee is 0, no fee is deducted from transactions.
- Handle cases where all prices are either constant or decrease across the days.
{{< dots >}}
## Code 💻
```cpp
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
```

The function calculates the maximum profit that can be obtained from buying and selling stocks with a transaction fee. It uses dynamic programming to track the profit states of 'buy' and 'sell' on each day.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxProfit(vector<int>& prices, int fee) {
	```
	Define the function 'maxProfit' which takes a vector of integers 'prices' representing stock prices and an integer 'fee' representing the transaction fee.

2. **Edge Case Handling**
	```cpp
	    if(prices.size() <= 1) return 0;
	```
	Handle the edge case where the number of prices is less than or equal to 1, meaning no profit can be made, thus return 0.

3. **Variable Initialization**
	```cpp
	    int days = prices.size();
	```
	Initialize 'days' to store the number of days (or prices), which is the size of the 'prices' vector.

4. **Array Initialization**
	```cpp
	    vector<int> buy(days, 0), sell(days, 0);
	```
	Initialize two vectors, 'buy' and 'sell', each of size 'days', to keep track of the maximum profit for buying and selling on each day.

5. **Initial State Setup**
	```cpp
	    buy[0]= -prices[0]-fee;
	```
	Set the initial 'buy' state on the first day, where the first element represents the cost of buying the stock with the transaction fee deducted.

6. **Loop**
	```cpp
	    for(int i = 1; i < days; i++) {
	```
	Start a loop from day 1 to the last day (index 1 to 'days-1') to calculate the maximum profit on each day.

7. **State Transition - Buy**
	```cpp
	        buy[i] = max(buy[i -1], sell[i -1]-prices[i]-fee);
	```
	Calculate the maximum profit for the 'buy' state by considering either the previous day's 'buy' state or the profit from selling the previous day's stock and buying on the current day (with the fee).

8. **State Transition - Sell**
	```cpp
	        sell[i] = max(sell[i -1], buy[i - 1]+prices[i]);
	```
	Calculate the maximum profit for the 'sell' state by considering either the previous day's 'sell' state or the profit from buying the previous day's stock and selling it on the current day.

9. **Return Statement**
	```cpp
	    return sell[days - 1];
	```
	Return the maximum profit at the last day, which is stored in the 'sell' array for the final day.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear since we process each price exactly once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to store the maximum profit.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

---
{{< youtube HLr_OnShK4s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
