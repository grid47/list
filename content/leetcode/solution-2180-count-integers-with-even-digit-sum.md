
+++
authors = ["grid47"]
title = "Leetcode 2180: Count Integers With Even Digit Sum"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2180: Count Integers With Even Digit Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "McbkGprY2C4"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/McbkGprY2C4/maxresdefault.webp"
comments = true
+++



---
Given a positive integer `num`, return the number of positive integers less than or equal to `num` whose digit sum is even.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `num`.
- **Example:** `7`
- **Constraints:**
	- 1 <= num <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the number of positive integers less than or equal to `num` whose digit sum is even.
- **Example:** `3`
- **Constraints:**
	- The digit sum is calculated by summing all the digits of a number.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many numbers from 1 to `num` have an even digit sum.

- For each number from 1 to `num`, calculate the sum of its digits.
- If the sum of the digits is even, increment the count.
{{< dots >}}
### Problem Assumptions ✅
- The number `num` is positive and within the given range.
{{< dots >}}
## Examples 🧩
- **Input:** `7`  \
  **Explanation:** The integers less than or equal to 7 whose digit sum is even are 2, 4, and 6.

{{< dots >}}
## Approach 🚀
The approach involves checking the digit sum of each integer from 1 to `num` and counting how many have an even digit sum.

### Initial Thoughts 💭
- We can easily calculate the sum of digits by iterating over the digits of a number.
- Since we are iterating over the numbers up to `num`, the time complexity will be proportional to the size of `num`.
{{< dots >}}
### Edge Cases 🌐
- If `num` is 1, the result is 0 since there are no numbers with even digit sums less than 1.
- For large values of `num`, the solution should handle them efficiently within the given constraints.
- The edge case where `num` is the smallest value, 1, should be handled separately.
- Ensure the solution works efficiently for `num` values up to 1000.
{{< dots >}}
## Code 💻
```cpp
int countEven(int num) {
    int temp = num, sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2;
}
```

This function, `countEven`, calculates the sum of the digits of a given number `num` and checks if the sum is even. Based on this condition, it returns either `temp / 2` or `(temp - 1) / 2`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countEven(int num) {
	```
	Define the function `countEven` that takes an integer `num` and returns an integer result based on the sum of the digits.

2. **Variable Initialization**
	```cpp
	    int temp = num, sum = 0;
	```
	Initialize two variables: `temp` stores the original value of `num`, and `sum` accumulates the sum of the digits of `num`.

3. **Loop**
	```cpp
	    while (num > 0) {
	```
	Start a while loop that continues until `num` becomes 0.

4. **Sum Calculation**
	```cpp
	        sum += num % 10;
	```
	Add the last digit of `num` (obtained using `num % 10`) to `sum`.

5. **Update Number**
	```cpp
	        num /= 10;
	```
	Remove the last digit from `num` by dividing it by 10.

6. **Return Statement**
	```cpp
	    return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2;
	```
	Check if the sum of digits (`sum`) is even. If true, return `temp / 2`; otherwise, return `(temp - 1) / 2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the input size (`num`).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since the solution only requires a fixed amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-integers-with-even-digit-sum/description/)

---
{{< youtube McbkGprY2C4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
