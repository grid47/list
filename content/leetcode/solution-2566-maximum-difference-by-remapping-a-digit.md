
+++
authors = ["grid47"]
title = "Leetcode 2566: Maximum Difference by Remapping a Digit"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2566: Maximum Difference by Remapping a Digit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mmTJskqxquI"
youtube_upload_date="2023-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/mmTJskqxquI/maxresdefault.jpg"
comments = true
+++



---
You are given an integer num, and you know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit. Your task is to return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num. If no change is made, the value of num remains the same.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer num, which can be as large as 10^8.
- **Example:** `For example, num = 13579.`
- **Constraints:**
	- 1 <= num <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the difference between the maximum and minimum possible values that Bob can obtain after remapping one digit.
- **Example:** `For example, the output for num = 13579 is 99850.`
- **Constraints:**
	- The number should be in its integer form and the difference between max and min should be returned.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the largest possible difference between the maximum and minimum values obtained after remapping a digit.

- 1. For each digit in num, calculate the value after remapping it to every other possible digit (0 to 9).
- 2. Track the minimum and maximum values obtained.
- 3. Return the difference between the maximum and minimum values.
{{< dots >}}
### Problem Assumptions ✅
- The input num will always be an integer within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `For num = 13579, the largest difference comes from remapping the digit 1 to 9 for maximum value and 9 to 0 for minimum value.`  \
  **Explanation:** This leads to the maximum value of 99579 and minimum value of 13570, resulting in a difference of 99850.

- **Input:** `For num = 81, no remapping gives a higher or lower value than 81, so the difference is 0.`  \
  **Explanation:** The result is 81 - 81 = 0.

{{< dots >}}
## Approach 🚀
To solve this problem, we will iterate through each digit and simulate all possible remapping operations.

### Initial Thoughts 💭
- We need to compute both the maximum and minimum numbers Bob can create by changing a single digit.
- By testing all digits for remapping and calculating the resulting number, we can identify the max-min difference.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the input is always a valid integer.
- When num is a large integer (up to 10^8), the solution needs to handle the digits efficiently.
- If num has all identical digits, remapping any digit to another won't change the number.
- The input num will always be a valid positive integer.
{{< dots >}}
## Code 💻
```cpp
int minMaxDifference(int num) {
    int min_v = num, max_v = num;
    for (int i = 0; i < 10; ++i) {
        int lo = 0, hi = 0, mul = 1;
        for (int n = num; n; n /= 10) {
            bool replace = n % 10 == i;
            lo += (replace ? 0 : n % 10) * mul;
            hi += (replace ? 9 : n % 10) * mul;
            mul *= 10;
        }
        min_v = min(min_v, lo);
        max_v = max(max_v, hi);
    }
    return max_v - min_v;
}
```

This is the full implementation of the function that calculates the maximum difference between the largest and smallest numbers that can be formed by replacing one digit of the given number with a number from 0 to 9.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minMaxDifference(int num) {
	```
	Defines the function `minMaxDifference` which takes an integer `num` as input.

2. **Variable Initialization**
	```cpp
	    int min_v = num, max_v = num;
	```
	Initializes two variables `min_v` and `max_v` to the value of `num`, which will track the minimum and maximum values during the calculations.

3. **Looping**
	```cpp
	    for (int i = 0; i < 10; ++i) {
	```
	A loop that iterates over each digit (0 to 9) to simulate replacing digits of `num` with each possible value.

4. **Variable Initialization**
	```cpp
	        int lo = 0, hi = 0, mul = 1;
	```
	Initializes variables `lo` and `hi` to track the lowest and highest possible numbers, respectively, and `mul` to control the place value during digit manipulation.

5. **Looping and Modulo Operation**
	```cpp
	        for (int n = num; n; n /= 10) {
	```
	A nested loop that processes each digit of `num` from right to left, dividing by 10 after each iteration to isolate each digit.

6. **Conditional Statement**
	```cpp
	            bool replace = n % 10 == i;
	```
	Checks if the current digit (`n % 10`) matches the digit `i` being considered for replacement in the outer loop.

7. **Mathematical Operations**
	```cpp
	            lo += (replace ? 0 : n % 10) * mul;
	```
	Calculates the lower number by replacing the matching digit with 0, and keeps the other digits unchanged by adding them to `lo`.

8. **Mathematical Operations**
	```cpp
	            hi += (replace ? 9 : n % 10) * mul;
	```
	Calculates the higher number by replacing the matching digit with 9, and keeps the other digits unchanged by adding them to `hi`.

9. **Mathematical Operations**
	```cpp
	            mul *= 10;
	```
	Multiplies `mul` by 10 to move to the next higher place value for the next digit.

10. **Mathematical Operations**
	```cpp
	        min_v = min(min_v, lo);
	```
	Updates `min_v` to store the smallest possible value between the current `min_v` and the new `lo` value.

11. **Mathematical Operations**
	```cpp
	        max_v = max(max_v, hi);
	```
	Updates `max_v` to store the largest possible value between the current `max_v` and the new `hi` value.

12. **Return Statement**
	```cpp
	    return max_v - min_v;
	```
	Returns the difference between the maximum and minimum values calculated during the loops.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(d), where d is the number of digits in num.
- **Average Case:** O(d * 10), where d is the number of digits in num.
- **Worst Case:** O(d * 10), where d is the number of digits in num.

For each digit, we try remapping it to all other digits, so the time complexity is linear with respect to the number of digits.

### Space Complexity 💾
- **Best Case:** O(d), where d is the number of digits in num.
- **Worst Case:** O(d), where d is the number of digits in num.

We need space to store the digits of num during the remapping process.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/)

---
{{< youtube mmTJskqxquI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
