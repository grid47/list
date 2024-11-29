
+++
authors = ["grid47"]
title = "Leetcode 1648: Sell Diminishing-Valued Colored Balls"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1648: Sell Diminishing-Valued Colored Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "oj7Rxz1r70g"
youtube_upload_date="2021-02-13"
youtube_thumbnail="https://i.ytimg.com/vi/oj7Rxz1r70g/maxresdefault.jpg"
comments = true
+++



---
You are given an inventory of different colored balls. The customer wants to buy a specific number of balls, and each ball has a value based on how many of that color are still available. Calculate the maximum total value you can obtain after fulfilling the customer's order. The result should be returned modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers representing the inventory of different colored balls and an integer representing the total number of orders the customer wants.
- **Example:** `inventory = [4, 7], orders = 5`
- **Constraints:**
	- 1 <= inventory.length <= 10^5
	- 1 <= inventory[i] <= 10^9
	- 1 <= orders <= min(sum(inventory[i]), 10^9)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum total value that can be attained after selling the orders of colored balls. The result should be modulo 10^9 + 7.
- **Example:** `Output: 25`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the value obtained by selling the balls in the most valuable order, starting with the most abundant colors.

- Sort the inventory in descending order to maximize the value for each ball sold.
- Sell the balls from the most abundant colors first, decreasing the value of each ball with each sale.
- Calculate the total value after fulfilling the number of orders, ensuring no more balls are sold than are available.
- Return the total value modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain valid values for inventory and orders, with no need to handle negative values or invalid input.
{{< dots >}}
## Examples 🧩
- **Input:** `inventory = [4, 7], orders = 5`  \
  **Explanation:** First, sell the highest valued ball (from the largest inventory) to maximize the value. Then, sell balls from the next inventory, continuing the process until all orders are fulfilled.

{{< dots >}}
## Approach 🚀
The approach involves sorting the inventory, then selling balls in the most valuable order while keeping track of the total value and reducing the value of the balls with each sale.

### Initial Thoughts 💭
- To maximize the total value, sell balls starting from the color with the most balls in stock.
- We need to consider both the value of the balls and the decreasing stock while fulfilling the order.
{{< dots >}}
### Edge Cases 🌐
- Ensure there is always at least one color of balls in the inventory and at least one order.
- The solution must efficiently handle large values for inventory sizes and ball counts.
- When the orders are fewer than the number of balls available, we need to ensure we only sell the required number of balls.
- Ensure the solution works efficiently within the given input size limits.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7;
int maxProfit(vector<int>& inv, int orders) {
    
    
    long n = inv.size(), res = 0;
    
    sort(inv.rbegin(), inv.rend());
    
    for(int i = 0, col = 1; i < n && orders > 0; i++, col++) {
        long cur = inv[i], prv = i + 1 < n? inv[i + 1]: 0;
        long depth = min((long)orders/col, (long)cur - prv);
        orders -= depth * col;
        
    res = (res + ((cur * (cur + 1) - (cur - depth) * (cur - depth + 1)) / 2 * col)) % mod;
              
        if(cur - prv > depth) {
            res = (res + orders * (cur - depth)) % mod;
            break;
        }
    }
    
    /*
        There is a value k, for which all the balls above this value are sold.
        
    */
    return res;
}
```

This function calculates the maximum profit from selling inventory items by using a greedy algorithm and modulo arithmetic for large sums. The inventory is processed in descending order to maximize profit at each step.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	Defines a constant to handle large numbers with modulo arithmetic.

2. **Function Definition**
	```cpp
	int maxProfit(vector<int>& inv, int orders) {
	```
	Begins the function definition for calculating the maximum profit from inventory sales.

3. **Sorting**
	```cpp
	    sort(inv.rbegin(), inv.rend());
	```
	Sorts the inventory in descending order to prioritize higher profits.

4. **Loop**
	```cpp
	    for(int i = 0, col = 1; i < n && orders > 0; i++, col++) {
	```
	Iterates through inventory items, calculating profit and reducing orders.

5. **Calculation**
	```cpp
	        long cur = inv[i], prv = i + 1 < n? inv[i + 1]: 0;
	```
	Determines the current inventory level and the next level for comparison.

6. **Calculation**
	```cpp
	        long depth = min((long)orders/col, (long)cur - prv);
	```
	Calculates the depth of items to sell at the current level.

7. **Update**
	```cpp
	        orders -= depth * col;
	```
	Decreases the remaining order count by the number of items sold.

8. **Calculation**
	```cpp
	    res = (res + ((cur * (cur + 1) - (cur - depth) * (cur - depth + 1)) / 2 * col)) % mod;
	```
	Updates the result with the profit from selling the current level's items.

9. **Condition**
	```cpp
	        if(cur - prv > depth) {
	```
	Checks if additional items remain at the current level after depth sales.

10. **Update**
	```cpp
	            res = (res + orders * (cur - depth)) % mod;
	```
	Handles remaining orders by selling items at the current level.

11. **Break**
	```cpp
	            break;
	```
	Exits the loop once all orders are fulfilled.

12. **Return**
	```cpp
	    return res;
	```
	Returns the total profit calculated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the inventory takes O(n log n) time, where n is the number of distinct colors in the inventory.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the inventory and the sorted list of inventories.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/description/)

---
{{< youtube oj7Rxz1r70g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
