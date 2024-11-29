
+++
authors = ["grid47"]
title = "Leetcode 2706: Buy Two Chocolates"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2706: Buy Two Chocolates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "BTzNimiQdW4"
youtube_upload_date="2023-12-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BTzNimiQdW4/maxresdefault.webp"
comments = true
+++



---
You are given an integer array representing the prices of chocolates in a store and a total amount of money you have. Your task is to buy exactly two chocolates in a way that ensures you still have some leftover money, and you want to minimize the sum of the prices of the two chocolates. If you cannot buy two chocolates without going into debt, return the original amount of money you had.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with a list of chocolate prices and an integer representing your total amount of money.
- **Example:** `Input: prices = [2, 3, 5], money = 6`
- **Constraints:**
	- 2 <= prices.length <= 50
	- 1 <= prices[i] <= 100
	- 1 <= money <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the amount of money you will have left after buying two chocolates, or the original amount of money if it is not possible to buy two chocolates.
- **Example:** `Output: 0`
- **Constraints:**
	- The leftover money should be non-negative.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the least sum of prices for two chocolates that fit within the available budget.

- Step 1: Identify the two cheapest chocolates in the list of prices.
- Step 2: Check if the sum of the prices of these two chocolates is less than or equal to the available money.
- Step 3: If so, return the leftover money after purchasing the two chocolates.
- Step 4: If not, return the original amount of money.
{{< dots >}}
### Problem Assumptions ✅
- You can buy exactly two chocolates from the store.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: prices = [1, 2, 3], money = 4`  \
  **Explanation:** In this case, you can buy chocolates priced at 1 and 3, leaving you with 4 - (1 + 3) = 0 units of money.

- **Input:** `Input: prices = [5, 8, 7], money = 10`  \
  **Explanation:** In this case, even though you have 10 units of money, the two cheapest chocolates cost 5 and 7, summing to 12, which exceeds the money you have. Therefore, you can't buy two chocolates, and the result is 10.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we need to identify the two cheapest chocolates and compare their sum to the available money. If the sum is affordable, subtract it from the available money; otherwise, return the original money.

### Initial Thoughts 💭
- The problem is about selecting the two lowest prices and checking if they fit within the budget.
- Sorting the prices array to easily access the two smallest prices can be a quick solution.
{{< dots >}}
### Edge Cases 🌐
- There are always at least two prices, so no need to handle empty inputs.
- The solution should handle the upper limit of 50 chocolate prices efficiently.
- If the two cheapest chocolates' prices exceed the available money, return the original money.
- The solution should work efficiently within the constraints of prices and money.
{{< dots >}}
## Code 💻
```cpp
int buyChoco(vector<int>& p, int m) {
    int l1 = 200, l2 = 200;
    for(int i = 0; i < p.size(); i++) {
        if(p[i] < l1) {
            l2 = l1;
            l1 = p[i];
        } else if(p[i] < l2) {
            l2 = p[i];
        }
    }
    
    if(l1 + l2 <= m) return m - l1 - l2;
    return m;
}
```

The function `buyChoco` takes a list of prices `p` and an integer `m`, representing the money available. It returns the maximum money left after purchasing two chocolates with the lowest prices, if possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int buyChoco(vector<int>& p, int m) {
	```
	This line declares the function `buyChoco`, which takes a reference to a vector `p` (prices of chocolates) and an integer `m` (the money available). The function returns an integer representing the remaining money after purchasing the two cheapest chocolates.

2. **Variable Initialization**
	```cpp
	    int l1 = 200, l2 = 200;
	```
	Two variables `l1` and `l2` are initialized to 200. These represent the two lowest prices found in the list `p`.

3. **For Loop**
	```cpp
	    for(int i = 0; i < p.size(); i++) {
	```
	A for loop is started to iterate through all the prices in the vector `p`.

4. **If Condition - First Lowest Price**
	```cpp
	        if(p[i] < l1) {
	```
	This condition checks if the current price `p[i]` is smaller than the current lowest price `l1`.

5. **Update Variables**
	```cpp
	            l2 = l1;
	```
	If the current price is the smallest, the second lowest price `l2` is updated to the previous lowest price `l1`.

6. **Update Variables**
	```cpp
	            l1 = p[i];
	```
	The lowest price `l1` is updated to the current price `p[i]`.

7. **Else If Condition - Second Lowest Price**
	```cpp
	        } else if(p[i] < l2) {
	```
	This condition checks if the current price is smaller than `l2` but greater than or equal to `l1`.

8. **Update Second Lowest Price**
	```cpp
	            l2 = p[i];
	```
	If the current price is between `l1` and `l2`, the second lowest price `l2` is updated to the current price `p[i]`.

9. **If Condition - Purchase Feasibility**
	```cpp
	    if(l1 + l2 <= m) return m - l1 - l2;
	```
	This condition checks if the sum of the two lowest prices is less than or equal to the available money `m`. If so, it returns the remaining money after purchasing the two chocolates.

10. **Return Statement - No Purchase**
	```cpp
	    return m;
	```
	If the two lowest prices are more than the available money, the function returns the original amount of money `m` (no purchase is made).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step, where n is the number of chocolate prices.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the prices array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/buy-two-chocolates/description/)

---
{{< youtube BTzNimiQdW4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
