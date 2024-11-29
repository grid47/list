
+++
authors = ["grid47"]
title = "Leetcode 50: Pow(x, n)"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 50: Pow(x, n) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/50.webp"
youtube = "g9YQyYi4IQQ"
youtube_upload_date="2021-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/g9YQyYi4IQQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/50.webp" 
    alt="A soft, glowing beam expanding and contracting in gentle rhythmic pulses."
    caption="Solution to LeetCode 50: Pow(x, n) Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a number `x` and an integer `n`. Your task is to compute `x` raised to the power `n` (i.e., `x^n`). Handle cases where the exponent is negative by returning the reciprocal of the result.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a number `x` (float) and an integer `n` (int).
- **Example:** `["x = 3.00000, n = 4"]`
- **Constraints:**
	- -100.0 < x < 100.0
	- -231 <= n <= 231-1
	- n is an integer.
	- Either x is not zero or n > 0.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a float value, which is `x` raised to the power `n`.
- **Example:** `["81.00000"]`
- **Constraints:**
	- The result must be computed within the constraints of the problem.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate `x^n` efficiently, especially for large `n` values.

- 1. Check if the exponent `n` is zero. If so, return 1.
- 2. If `n` is negative, compute the power of the reciprocal of `x` raised to the positive exponent.
- 3. Use fast exponentiation (divide-and-conquer) for optimal computation, where the power is halved for each recursive step.
{{< dots >}}
### Problem Assumptions ✅
- The function should handle both positive and negative exponents correctly.
- The input constraints guarantee that no invalid values (such as x = 0 when n <= 0) will be provided.
{{< dots >}}
## Examples 🧩
- **Input:** `["x = 3.00000, n = 4"]`  \
  **Explanation:** In this example, `3^4` is calculated, resulting in `81.00000`.

- **Input:** `["x = 2.50000, n = -2"]`  \
  **Explanation:** Here, `2.5^-2` is computed as the reciprocal of `2.5^2`, resulting in `0.16000`.

{{< dots >}}
## Approach 🚀
The approach uses a divide-and-conquer strategy to calculate the power efficiently. If the exponent is negative, we compute the reciprocal of the power of the positive exponent.

### Initial Thoughts 💭
- Exponentiation can be computed efficiently using recursion or iteration with halving the exponent.
- Handling negative exponents requires computing the reciprocal of the result.
{{< dots >}}
### Edge Cases 🌐
- No empty input values as per the constraints.
- For large inputs, the algorithm needs to handle large exponentiation efficiently without overflow.
- Handling zero as an exponent (e.g., `x^0` should always return 1).
- Handle negative exponents by computing the reciprocal of the result.
{{< dots >}}
## Code 💻
```cpp
double myPow(double x, int n) {
    if(n== 0) return 1;
    if(n < 0) return 1/x * myPow(1/x, -(n + 1));
    
    return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n/ 2);
}
```

This code implements the `myPow` function to calculate the power of a number `x` raised to the power of `n`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	double myPow(double x, int n) {
	```
	This line declares a function named `myPow` that takes a double `x` and an integer `n` as input and returns the result of `x` raised to the power of `n`.

2. **Base Case: Zero Power**
	```cpp
	    if(n== 0) return 1;
	```
	This line checks if the exponent `n` is 0. If so, the function returns 1, as any number raised to the power of 0 is 1.

3. **Base Case: Negative Power**
	```cpp
	    if(n < 0) return 1/x * myPow(1/x, -(n + 1));
	```
	This line handles the case where the exponent `n` is negative. It calculates the reciprocal of `x` and recursively calls the function with the absolute value of `n` incremented by 1.

4. **Recursive Calculation**
	```cpp
	    return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n/ 2);
	```
	This line implements the core recursive calculation. It leverages the fact that `x^n` can be calculated efficiently using the following properties:
1. **Even Power:** If `n` is even, `x^n = (x^2)^(n/2)`.
2. **Odd Power:** If `n` is odd, `x^n = x * (x^2)^((n-1)/2)`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is logarithmic due to the halving of the exponent in each recursive step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(log n)

The space complexity is logarithmic due to the recursive calls. In the best case (no recursion), it is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/powx-n/description/)

---
{{< youtube g9YQyYi4IQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
