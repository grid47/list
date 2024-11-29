
+++
authors = ["grid47"]
title = "Leetcode 1672: Richest Customer Wealth"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1672: Richest Customer Wealth in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Aap1zzi70Pg"
youtube_upload_date="2020-11-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Aap1zzi70Pg/maxresdefault.webp"
comments = true
+++



---
You are given a 2D list `accounts`, where each row represents a customer and each element within a row is the amount of money they have in a particular bank. Your task is to return the wealth of the richest customer. A customer's wealth is the sum of all their bank accounts' balances. The richest customer is the one with the maximum wealth.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D list `accounts`, where each element represents a customer's balance across multiple banks.
- **Example:** `accounts = [[2, 3, 4], [1, 5, 2]]`
- **Constraints:**
	- 1 <= m, n <= 50
	- 1 <= accounts[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the wealth of the richest customer.
- **Example:** `Output: 9`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the wealth of each customer and return the maximum.

- Iterate through each row in the `accounts` list.
- For each customer, calculate the total wealth by summing the elements of their corresponding row.
- Track the maximum wealth during the iteration.
- Return the maximum wealth after processing all customers.
{{< dots >}}
### Problem Assumptions ✅
- There is no need to handle negative balances.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[3, 1], [6, 7], [4, 3]]`  \
  **Explanation:** The wealth of each customer is calculated by summing their balances. The richest customer is the one with the maximum wealth.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through the list of accounts and calculating the sum of each customer's wealth. The final result will be the maximum wealth found during the iteration.

### Initial Thoughts 💭
- We need to calculate the wealth of each customer.
- The solution involves summing the elements of each row and finding the maximum.
- A simple approach of iterating over the 2D list and finding the maximum wealth will work within the given constraints.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one customer.
- The problem can handle up to 50 customers and 50 accounts for each.
- Balances will always be positive integers between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
int maximumWealth(vector<vector<int>>& accounts) {
    int richest = 0;
    for (auto &customer : accounts)
        richest = max (richest, accumulate(customer.begin(), customer.end(), 0));
    
    return richest;
}
```

This function calculates the maximum wealth from a list of customer account balances, where each customer’s wealth is the sum of their individual account balances. It uses a for-loop to iterate over all customers and computes the maximum wealth.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maximumWealth(vector<vector<int>>& accounts) {
	```
	This line defines the function `maximumWealth` that takes a 2D vector `accounts`, where each inner vector represents a customer's account balances, and returns an integer representing the maximum wealth.

2. **Variable Initialization**
	```cpp
	    int richest = 0;
	```
	Here, the variable `richest` is initialized to 0. This variable will hold the maximum wealth encountered as the program iterates over the `accounts` vector.

3. **Looping through Accounts**
	```cpp
	    for (auto &customer : accounts)
	```
	This for-loop iterates through each customer's account (represented as `customer`) in the `accounts` vector.

4. **Accumulation of Wealth**
	```cpp
	        richest = max (richest, accumulate(customer.begin(), customer.end(), 0));
	```
	This line calculates the sum of the balances in each customer's account using `accumulate()`. It then updates the `richest` variable if the current customer's wealth is greater than the previous maximum wealth.

5. **Return Statement**
	```cpp
	    return richest;
	```
	Once all customers have been processed, this line returns the maximum wealth found, stored in `richest`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

We iterate over each customer and their accounts, so the time complexity is proportional to the size of the input.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only use a constant amount of extra space to track the maximum wealth.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/richest-customer-wealth/description/)

---
{{< youtube Aap1zzi70Pg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
