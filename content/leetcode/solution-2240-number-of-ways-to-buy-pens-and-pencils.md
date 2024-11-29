
+++
authors = ["grid47"]
title = "Leetcode 2240: Number of Ways to Buy Pens and Pencils"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2240: Number of Ways to Buy Pens and Pencils in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WzmIQmBNa0A"
youtube_upload_date="2022-04-16"
youtube_thumbnail="https://i.ytimg.com/vi/WzmIQmBNa0A/maxresdefault.jpg"
comments = true
+++



---
You have a certain amount of money and want to buy pens and pencils. Given their costs, determine the number of distinct ways you can buy some combination of pens and pencils, including buying none.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer total representing your total budget, and two integers cost1 and cost2 representing the cost of a pen and a pencil respectively.
- **Example:** `Input: total = 15, cost1 = 6, cost2 = 4`
- **Constraints:**
	- 1 <= total, cost1, cost2 <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct ways to buy pens and pencils while not exceeding the total budget.
- **Example:** `Output: 7`
- **Constraints:**
	- The output must be a single integer representing the number of valid combinations.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the number of distinct ways to purchase pens and pencils such that the total cost is less than or equal to the budget.

- 1. Iterate over the number of pens that can be purchased, ranging from 0 to total/cost1.
- 2. For each number of pens, calculate the remaining budget after buying the pens.
- 3. Determine the maximum number of pencils that can be purchased within the remaining budget.
- 4. Accumulate the total number of valid combinations.
{{< dots >}}
### Problem Assumptions ✅
- At least one valid combination is possible, even if it means buying nothing.
- The costs of pens and pencils are not necessarily multiples of each other.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: total = 15, cost1 = 6, cost2 = 4`  \
  **Explanation:** You can buy 0 pens and 0-3 pencils (4 ways), 1 pen and 0-1 pencils (2 ways), or 2 pens and 0 pencils (1 way). Total: 4 + 2 + 1 = 7.

- **Input:** `Input: total = 7, cost1 = 3, cost2 = 4`  \
  **Explanation:** You can buy 0 pens and 0-1 pencils (2 ways) or 1 pen and 0 pencils (1 way). Total: 2 + 1 = 3.

{{< dots >}}
## Approach 🚀
Use a simple loop to iterate through possible purchases of pens and calculate the corresponding combinations for pencils.

### Initial Thoughts 💭
- The problem can be broken into two nested loops: the outer loop iterates over the possible numbers of pens, and the inner logic calculates the maximum number of pencils for the remaining budget.
- Each iteration of the loop corresponds to a possible number of pens.
- Using a single loop is possible because we only calculate the maximum number of pencils for a given budget.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the inputs are always positive integers.
- total = 10^6, cost1 = 1, cost2 = 2
- cost1 or cost2 is greater than total, e.g., total = 5, cost1 = 10, cost2 = 3.
- Ensure calculations do not overflow for large inputs within the given constraints.
{{< dots >}}
## Code 💻
```cpp
long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long cnt = 0;
    int sum = total;
    while(sum >= 0 || sum/cost2 > 0) {
        cnt+= (sum/cost2 + 1);
        sum -= cost1;
    }
    return cnt;
}
```

This function calculates how many pens and pencils can be bought given the total amount of money, the cost of a pen, and the cost of a pencil. The process is repeated while there are enough funds to buy at least one pencil.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long waysToBuyPensPencils(int total, int cost1, int cost2) {
	```
	This is the function definition for 'waysToBuyPensPencils', which takes three parameters: total money, cost of a pen, and cost of a pencil. It returns a long long value representing the total number of items that can be bought.

2. **Variable Initialization**
	```cpp
	    long long cnt = 0;
	```
	This initializes the variable 'cnt' to store the total number of pens and pencils that can be bought.

3. **Setting Initial Sum**
	```cpp
	    int sum = total;
	```
	This sets the 'sum' variable to the total amount of money available for purchase.

4. **Loop for Buying Items**
	```cpp
	    while(sum >= 0 || sum/cost2 > 0) {
	```
	This while loop continues as long as there is enough money to buy at least one pencil (based on the cost of a pencil).

5. **Counting Possible Purchases**
	```cpp
	        cnt+= (sum/cost2 + 1);
	```
	This line calculates the maximum number of pencils that can be bought with the current 'sum' and adds it to the 'cnt' variable.

6. **Reducing Total Money**
	```cpp
	        sum -= cost1;
	```
	This subtracts the cost of one pen from 'sum', reducing the available money after each purchase.

7. **Returning Result**
	```cpp
	    return cnt;
	```
	This returns the total count of pens and pencils that can be bought with the available money.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(total/cost1)
- **Average Case:** O(total/cost1)
- **Worst Case:** O(total/cost1)

The time complexity is proportional to the number of iterations for possible pen purchases.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

Only a few variables are used for tracking state, making space usage constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/)

---
{{< youtube WzmIQmBNa0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
