
+++
authors = ["grid47"]
title = "Leetcode 29: Divide Two Integers"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 29: Divide Two Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/29.webp"
youtube = "LzcSE7-m6vY"
youtube_upload_date="2024-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/LzcSE7-m6vY/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/29.webp" 
    alt="Two smooth, glowing beams dividing and separating in perfect balance."
    caption="Solution to LeetCode 29: Divide Two Integers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two integers `dividend` and `divisor`, divide `dividend` by `divisor` without using multiplication, division, or modulus operators. Truncate the result towards zero and return the quotient.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers `dividend` and `divisor`.
- **Example:** `For example, `dividend = 15`, `divisor = 4`.`
- **Constraints:**
	- -2^31 <= dividend, divisor <= 2^31 - 1
	- divisor != 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the quotient after dividing `dividend` by `divisor`. The result should be truncated toward zero.
- **Example:** `For `dividend = 15`, `divisor = 4`, the output is `3`.`
- **Constraints:**
	- The result should be within the 32-bit signed integer range: [-2^31, 2^31 - 1].

{{< dots >}}
### Core Logic 🔍
**Goal:** Divide the `dividend` by `divisor` without using multiplication, division, or modulus operators, and truncate the result toward zero.

- Handle edge case where the dividend is INT_MIN and divisor is -1 to prevent overflow.
- Use bit manipulation (shifting) to simulate the division process and determine the quotient.
- Calculate the sign of the result based on the signs of the `dividend` and `divisor`.
- Iterate, doubling the divisor (using left shift) to subtract from the dividend in large chunks to optimize the division process.
{{< dots >}}
### Problem Assumptions ✅
- Both the `dividend` and `divisor` are valid 32-bit integers.
- The result must be truncated toward zero.
{{< dots >}}
## Examples 🧩
- **Input:** `For `dividend = 15`, `divisor = 4``  \
  **Explanation:** The division of `15` by `4` results in `3.75`. Truncated toward zero, the result is `3`.

- **Input:** `For `dividend = 10`, `divisor = -3``  \
  **Explanation:** The division of `10` by `-3` results in `-3.33333...`. Truncated toward zero, the result is `-3`.

{{< dots >}}
## Approach 🚀
The approach is to simulate the division operation using bit shifts. This avoids using multiplication, division, or modulus operators and allows us to compute the quotient efficiently.

### Initial Thoughts 💭
- The division can be optimized using bit shifts, which effectively doubles the divisor in each iteration, enabling fast subtraction from the dividend.
- We can use bitwise operations to speed up the division process and avoid expensive division or multiplication operations.
{{< dots >}}
### Edge Cases 🌐
- This problem will not encounter empty inputs as the `dividend` and `divisor` are always provided.
- Ensure that the solution handles large values of `dividend` and `divisor` efficiently.
- Handle the case where the `dividend` is `INT_MIN` and the `divisor` is `-1`, as it could lead to overflow.
- Ensure that the result is always within the 32-bit signed integer range.
{{< dots >}}
## Code 💻
```cpp
int divide(int dividend, int divisor) {
    
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    long dvd = labs(dividend), dvs = labs(divisor);
    int sgn = (dividend > 0) ^ (divisor > 0) ? -1: 1;
    long ans = 0;

    while( dvd >= dvs ) {
        long tmp = dvs, m = 1;
        while(tmp << 1 <= dvd) {
            tmp <<= 1;
            m <<= 1;
        }
        dvd -= tmp;
        ans += m;
    }

    return sgn * ans;
}
```

This code implements integer division without using multiplication or division operators, handling edge cases and overflow.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int divide(int dividend, int divisor) {
	```
	This line declares a function named 'divide' that takes two integer arguments: 'dividend' and 'divisor', and returns an integer representing the result of integer division.

2. **Edge Case Handling**
	```cpp
	    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
	```
	This line handles a special edge case: when the dividend is the minimum integer value and the divisor is -1. In this case, the result would overflow, so the function returns the maximum integer value.

3. **Variable Initialization**
	```cpp
	    long dvd = labs(dividend), dvs = labs(divisor);
	```
	This line converts both the dividend and divisor to long integers to avoid integer overflow during calculations. The `labs` function is used to get the absolute values of the operands.

4. **Variable Initialization**
	```cpp
	    int sgn = (dividend > 0) ^ (divisor > 0) ? -1: 1;
	```
	This line calculates the sign of the result. The `^` operator is used for XOR operation to determine the sign based on the signs of the dividend and divisor.

5. **Variable Initialization**
	```cpp
	    long ans = 0;
	```
	This line initializes a variable 'ans' to store the calculated quotient.

6. **Loop Iteration**
	```cpp
	    while( dvd >= dvs ) {
	```
	This line starts a loop that continues as long as the dividend is greater than or equal to the divisor.

7. **Variable Initialization**
	```cpp
	        long tmp = dvs, m = 1;
	```
	This line initializes two temporary variables: 'tmp' to store the current divisor and 'm' to track the multiplier.

8. **Loop Iteration**
	```cpp
	        while(tmp << 1 <= dvd) {
	```
	This inner loop repeatedly doubles the 'tmp' and 'm' values as long as doubling 'tmp' does not exceed the dividend.

9. **Bitwise Operations**
	```cpp
	            tmp <<= 1;
	```
	This line left-shifts 'tmp' by 1, effectively doubling its value.

10. **Bitwise Operations**
	```cpp
	            m <<= 1;
	```
	This line left-shifts 'm' by 1, doubling its value as well.

11. **Mathematical Operations**
	```cpp
	        dvd -= tmp;
	```
	This line subtracts the doubled 'tmp' value from the dividend.

12. **Result Update**
	```cpp
	        ans += m;
	```
	This line adds the doubled 'm' value to the 'ans', effectively adding the number of times the doubled divisor can be subtracted from the dividend.

13. **Return**
	```cpp
	    return sgn * ans;
	```
	After the loop, the 'ans' variable holds the quotient. The function returns the quotient multiplied by the sign determined earlier.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) since the divisor is doubled in each iteration, reducing the dividend quickly.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of space for variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-two-integers/description/)

---
{{< youtube LzcSE7-m6vY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
