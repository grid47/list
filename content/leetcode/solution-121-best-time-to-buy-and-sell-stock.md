
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
---

### 📈 **Max Profit from Stock Trading** – Let’s Maximize Your Gains!

The **Max Profit** problem asks you to find the maximum profit you can make from buying and selling a stock, given an array of stock prices where each element represents the stock's price on a particular day. Your objective is to buy at one point and sell later for the highest possible profit. If no profit can be made, return `0`.

#### **Example Walkthrough**:

- **Input**: `prices = [7, 1, 5, 3, 6, 4]`
- **Output**: `5`
  - **Explanation**: Buy on day 2 (price = 1), sell on day 5 (price = 6), resulting in a profit of `6 - 1 = 5`.

- **Input**: `prices = [7, 6, 4, 3, 1]`
- **Output**: `0`
  - **Explanation**: No transaction can be made as prices are always decreasing.

### 💡 **Approach to Solve the Problem**

To solve this efficiently, we need to track the minimum stock price observed so far and calculate the maximum profit by selling at each day’s price. Here’s how we can approach it:

1. **Track the Minimum Price** (`l`): Start by setting the minimum price to the first price in the array.
2. **Calculate the Potential Profit**: For each price, subtract the minimum price from the current price to determine the potential profit.
3. **Track the Maximum Profit** (`g`): Update the maximum profit whenever we find a higher profit than the previous maximum.

This approach ensures we only need to traverse the array once.

### 🖥️ **Code Breakdown (Step-by-Step)**

#### **Function Signature**
```cpp
int maxProfit(vector<int>& prices)
```
This function takes a vector of integers, `prices`, which represent stock prices over several days, and returns an integer representing the maximum profit from a single buy and sell transaction.

#### **Initialize Variables**
```cpp
int l = prices[0], g = 0;
```
- `l`: Stores the minimum price observed so far.
- `g`: Stores the maximum profit encountered so far, initialized to `0`.

#### **Iterate Over Prices**
```cpp
for(int x: prices) {
    l = min(l, x); // Update the minimum price
    g = max(g, x - l); // Update the maximum profit
}
```
- **Updating `l`**: For each price `x`, update `l` to be the minimum of the current price and `l`.
- **Updating `g`**: Calculate the potential profit (`x - l`) and update `g` if the current profit is greater than the previous maximum.

#### **Return the Maximum Profit**
```cpp
return g;
```
After iterating through all prices, return `g`, which holds the maximum profit.

### 🎬 **Example Walkthrough**

Let’s walk through an example to see the algorithm in action.

#### **Input**: `prices = [7, 1, 5, 3, 6, 4]`

1. **Initialization**:
   - `l = 7`, `g = 0`.

2. **Iterate Over Prices**:

   - **Price 7**: 
     - `l = min(7, 7) = 7`
     - `g = max(0, 7 - 7) = 0`

   - **Price 1**: 
     - `l = min(7, 1) = 1`
     - `g = max(0, 1 - 1) = 0`

   - **Price 5**: 
     - `l = min(1, 5) = 1`
     - `g = max(0, 5 - 1) = 4`

   - **Price 3**: 
     - `l = min(1, 3) = 1`
     - `g = max(4, 3 - 1) = 4`

   - **Price 6**: 
     - `l = min(1, 6) = 1`
     - `g = max(4, 6 - 1) = 5`

   - **Price 4**: 
     - `l = min(1, 4) = 1`
     - `g = max(5, 4 - 1) = 5`

3. **Final Output**: 
   - The maximum profit is `5`.

### ⏱️ **Time and Space Complexity**

- **Time Complexity**: `O(n)`
  - We iterate through the array once, performing constant-time operations for each price.

- **Space Complexity**: `O(1)`
  - We only use a few integer variables (`l` and `g`), so the space complexity remains constant.

### 🏆 **Conclusion**

This solution efficiently solves the problem of finding the maximum profit from a single buy and sell transaction. By iterating through the prices once and tracking the minimum price and maximum profit encountered, we achieve an optimal solution with time complexity `O(n)` and space complexity `O(1)`. This makes the algorithm both **time-efficient** and **space-efficient**, perfect for handling large inputs.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

---
{{< youtube kJZrMGpyWpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
