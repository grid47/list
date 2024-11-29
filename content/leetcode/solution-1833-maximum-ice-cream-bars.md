
+++
authors = ["grid47"]
title = "Leetcode 1833: Maximum Ice Cream Bars"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1833: Maximum Ice Cream Bars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "40qxrlPwBMM"
youtube_upload_date="2021-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/40qxrlPwBMM/maxresdefault.webp"
comments = true
+++



---
A boy wants to buy as many ice cream bars as possible, given their prices and the number of coins he has. Determine the maximum number of ice cream bars he can purchase without exceeding his budget.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `costs` of length `n`, where `costs[i]` is the price of the `i-th` ice cream bar, and an integer `coins` representing the total coins the boy has.
- **Example:** `costs = [2, 1, 3, 4, 2], coins = 6`
- **Constraints:**
	- 1 <= costs.length <= 10^5
	- 1 <= costs[i] <= 10^5
	- 1 <= coins <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of ice cream bars the boy can buy without exceeding his available coins.
- **Example:** `3`
- **Constraints:**
	- The output will be a non-negative integer indicating the maximum number of ice cream bars that can be bought.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the maximum number of ice cream bars the boy can afford given his budget.

- Sort the `costs` array in non-decreasing order.
- Iterate through the sorted `costs` array and keep track of the total cost and the number of bars purchased.
- Stop when the total cost exceeds the available `coins`.
{{< dots >}}
### Problem Assumptions ✅
- The input array `costs` will contain only valid integer values.
- The `coins` value is guaranteed to be within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `costs = [2, 1, 3, 4, 2], coins = 6`  \
  **Explanation:** By sorting the costs to [1, 2, 2, 3, 4], the boy can afford 3 ice cream bars for a total of 1 + 2 + 2 = 5 coins, leaving him with enough coins to buy 3 bars.

- **Input:** `costs = [5, 3, 8, 2], coins = 4`  \
  **Explanation:** The boy can only afford the ice cream bar with the price of 2 coins. He can buy just one ice cream bar.

- **Input:** `costs = [1, 1, 2, 3, 1], coins = 7`  \
  **Explanation:** The boy can afford all 5 bars for a total price of 8 coins, so he can buy 5 ice cream bars.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use a greedy approach by sorting the array and then iterating through it to select as many bars as the boy can afford.

### Initial Thoughts 💭
- Sorting the costs array will allow us to buy the cheapest ice cream bars first, maximizing the number of bars the boy can afford.
- We can implement this solution efficiently with a time complexity of O(n log n) due to the sorting step.
{{< dots >}}
### Edge Cases 🌐
- The array `costs` will always contain at least one element.
- For large inputs, sorting the `costs` array will take O(n log n) time, which should be efficient enough within the problem's constraints.
- If the boy cannot afford any ice cream bars, the result will be 0.
- Ensure that the sorting and iteration steps are optimized for large inputs.
{{< dots >}}
## Code 💻
```cpp
int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int sum = 0;
    for(int i = 0; i < costs.size(); i++) {
        sum += costs[i];
        if(sum == coins)
            return i +1;
        if(sum > coins)
            return i;
    }
    return costs.size();
}
```

The function `maxIceCream` returns the maximum number of ice creams that can be bought with a given amount of coins. It first sorts the ice cream costs and iterates through them, accumulating the sum of costs and checking if it exceeds or exactly matches the available coins.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxIceCream(vector<int>& costs, int coins) {
	```
	Defines the function `maxIceCream`, which takes a vector of ice cream costs (`costs`) and the total number of coins (`coins`) as input, and returns the maximum number of ice creams that can be bought.

2. **Sorting**
	```cpp
	    sort(costs.begin(), costs.end());
	```
	Sorts the `costs` vector in ascending order to prioritize buying cheaper ice creams first.

3. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes a variable `sum` to keep track of the total cost of ice creams bought so far.

4. **Loop Through Costs**
	```cpp
	    for(int i = 0; i < costs.size(); i++) {
	```
	Starts a loop to iterate through the sorted `costs` vector, with each iteration representing the purchase of one ice cream.

5. **Sum Calculation**
	```cpp
	        sum += costs[i];
	```
	Adds the cost of the current ice cream (`costs[i]`) to the running total (`sum`).

6. **Exact Match Check**
	```cpp
	        if(sum == coins)
	```
	Checks if the accumulated `sum` exactly matches the available `coins`.

7. **Return Exact Match**
	```cpp
	            return i + 1;
	```
	If the total cost matches the available coins, returns the current index plus one, representing the number of ice creams bought.

8. **Exceed Coins Check**
	```cpp
	        if(sum > coins)
	```
	Checks if the accumulated `sum` exceeds the available `coins`.

9. **Return Exceed Case**
	```cpp
	            return i;
	```
	If the total cost exceeds the available coins, returns the current index, which represents the maximum number of ice creams that can be bought.

10. **Return Total Ice Creams**
	```cpp
	    return costs.size();
	```
	If all ice creams can be bought without exceeding the available coins, returns the total number of ice creams.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-ice-cream-bars/description/)

---
{{< youtube 40qxrlPwBMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
