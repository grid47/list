
+++
authors = ["grid47"]
title = "Leetcode 2520: Count the Digits That Divide a Number"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2520: Count the Digits That Divide a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "7SHHsS5kPJ8"
youtube_upload_date="2023-01-02"
youtube_thumbnail="https://i.ytimg.com/vi/7SHHsS5kPJ8/maxresdefault.jpg"
comments = true
+++



---
Given a positive integer `num`, determine how many of its digits divide `num` without leaving a remainder. In other words, for each digit in `num`, check if `num % digit == 0` and count how many digits satisfy this condition.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer `num`. You need to find how many of its digits divide the number `num` evenly.
- **Example:** `num = 123`
- **Constraints:**
	- 1 <= num <= 10^9
	- num does not contain the digit 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of digits in `num` that divide `num` without leaving a remainder.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be an integer representing the number of digits that divide the number.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many digits of `num` divide `num` evenly.

- Convert `num` to a string to access each digit.
- For each digit in the number, check if `num % digit == 0`.
- Count how many digits satisfy the condition.
{{< dots >}}
### Problem Assumptions ✅
- All digits in `num` are non-zero.
{{< dots >}}
## Examples 🧩
- **Input:** `num = 123`  \
  **Explanation:** For `123`, the digits `1` and `3` divide `123`, but `2` does not. So, the answer is 2.

- **Input:** `num = 256`  \
  **Explanation:** For `256`, the digits `2`, `5`, and `6` divide `256`. So, the answer is 3.

{{< dots >}}
## Approach 🚀
To solve the problem, we will convert the number into its digits, check each digit for divisibility, and count how many satisfy the condition.

### Initial Thoughts 💭
- The problem requires iterating through the digits of a number and checking divisibility.
- Converting the number to a string allows easy access to each digit, and the modulo operation can be used to check divisibility.
{{< dots >}}
### Edge Cases 🌐
- This problem does not require handling empty inputs as `num` is always a positive integer.
- The solution must be efficient enough to handle the largest possible value of `num` (up to 10^9).
- The number will not contain the digit zero, so no need to handle division by zero.
- Ensure that the solution runs within time limits for the largest values of `num`.
{{< dots >}}
## Code 💻
```cpp
int countDigits(int num) {
    int res = 0;
    for (int n = num; n > 0; n /= 10)
        res += num % (n % 10) == 0;
    return res;
}
```

This function `countDigits` calculates how many digits in a given number `num` divide the number evenly. It iterates over each digit of `num`, checking if `num` is divisible by the digit, and counts how many times this condition is true.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countDigits(int num) {
	```
	Define the function `countDigits` that takes an integer `num` as input and returns the count of digits that divide `num` evenly.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize a variable `res` to 0. This variable will hold the count of digits that divide `num` evenly.

3. **Loop**
	```cpp
	    for (int n = num; n > 0; n /= 10)
	```
	Start a `for` loop that iterates through each digit of `num`. The variable `n` starts as `num` and is divided by 10 in each iteration to move to the next digit.

4. **Condition Check**
	```cpp
	        res += num % (n % 10) == 0;
	```
	Check if the current digit `n % 10` divides `num` evenly (i.e., `num % digit == 0`). If true, increment the result `res`.

5. **Return Statement**
	```cpp
	    return res;
	```
	Return the final count of digits that divide `num` evenly, stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(d), where d is the number of digits in `num`.
- **Average Case:** O(d), where d is the number of digits in `num`.
- **Worst Case:** O(d), where d is the number of digits in `num`.

The time complexity is linear in terms of the number of digits in `num`, which is at most 9.

### Space Complexity 💾
- **Best Case:** O(d), where d is the number of digits in `num`.
- **Worst Case:** O(d), where d is the number of digits in `num`.

We need space proportional to the number of digits in `num` to store them temporarily.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/)

---
{{< youtube 7SHHsS5kPJ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
