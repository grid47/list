
+++
authors = ["grid47"]
title = "Leetcode 2806: Account Balance After Rounded Purchase"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2806: Account Balance After Rounded Purchase in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "I3XEMabQJxE"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/I3XEMabQJxE/maxresdefault.webp"
comments = true
+++



---
You have a bank account with a balance of 100 dollars. You are given a purchase amount and need to round it to the nearest multiple of 10. Then, deduct the rounded amount from your account balance and return the remaining balance.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer 'purchaseAmount' representing the price of an item you wish to buy.
- **Example:** `Input: purchaseAmount = 18`
- **Constraints:**
	- 0 <= purchaseAmount <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the bank account balance after the rounded amount has been deducted.
- **Example:** `Output: 80`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the nearest multiple of 10 for the given purchase amount and update the bank balance.

- 1. Round the 'purchaseAmount' to the nearest multiple of 10.
- 2. Subtract the rounded amount from the initial balance of 100 dollars.
- 3. Return the updated balance.
{{< dots >}}
### Problem Assumptions ✅
- The purchase amount is always a non-negative integer and will be rounded to the nearest multiple of 10.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: purchaseAmount = 18`  \
  **Explanation:** The nearest multiple of 10 to 18 is 20. So the account balance becomes 100 - 20 = 80.

- **Input:** `Input: purchaseAmount = 8`  \
  **Explanation:** The nearest multiple of 10 to 8 is 10. So the account balance becomes 100 - 10 = 90.

{{< dots >}}
## Approach 🚀
The problem can be solved by determining the nearest multiple of 10 and then subtracting it from the initial balance.

### Initial Thoughts 💭
- The rounding rules for the purchase amount must be carefully followed to ensure the correct amount is deducted.
- We need to handle both small values (e.g., 1) and large values (e.g., 100) correctly, ensuring rounding happens in all cases.
{{< dots >}}
### Edge Cases 🌐
- The input will always be a valid integer within the given range, so empty inputs are not a concern.
- The largest possible input (purchaseAmount = 100) will be handled by rounding it to 100.
- When the purchaseAmount is 5, 15, 25, etc., it will be rounded up to the next multiple of 10.
- The input will always be within the specified range and will not exceed the maximum value of 100.
{{< dots >}}
## Code 💻
```cpp
int accountBalanceAfterPurchase(int val) {
    
    if(val % 10 == 5) val += 5;
    else if(val % 10 > 5) {
        val = val / 10;
        val = (val + 1) * 10;
    } else {
        val = (val / 10) * 10;
    }
    return 100 - val;
}
```

This code calculates the remaining balance after a purchase, adjusting the price based on the last digit of the value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **function**
	```cpp
	int accountBalanceAfterPurchase(int val) {
	```
	Start of the function definition to calculate the account balance after a purchase based on a given value.

2. **if_condition**
	```cpp
	    if(val % 10 == 5) val += 5;
	```
	Check if the last digit of the value is 5, and if so, increment the value by 5.

3. **else_if_condition**
	```cpp
	    else if(val % 10 > 5) {
	```
	If the last digit of the value is greater than 5, then adjust the value by dividing by 10 and rounding up.

4. **operation**
	```cpp
	        val = val / 10;
	```
	Divide the value by 10 to remove the last digit.

5. **operation**
	```cpp
	        val = (val + 1) * 10;
	```
	Increase the value by 1 and multiply by 10 to round it to the next multiple of 10.

6. **else_condition**
	```cpp
	    } else {
	```
	If the last digit is less than 5, proceed with rounding down.

7. **operation**
	```cpp
	        val = (val / 10) * 10;
	```
	Divide the value by 10 to remove the last digit and multiply by 10 to round it down.

8. **return_statement**
	```cpp
	    return 100 - val;
	```
	Return the final value after subtracting from 100 to calculate the account balance after the purchase.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is O(1) because the operations involved (rounding and subtraction) are constant time operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because only a constant amount of space is used for calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/account-balance-after-rounded-purchase/description/)

---
{{< youtube I3XEMabQJxE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
