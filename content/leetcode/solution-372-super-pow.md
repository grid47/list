
+++
authors = ["grid47"]
title = "Leetcode 372: Super Pow"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 372: Super Pow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Divide and Conquer"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/372.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/372.webp" 
    alt="A glowing number being raised to a power, with the power operations softly highlighted along the way."
    caption="Solution to LeetCode 372: Super Pow Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer `a` and an array `b`, where `b` represents a very large number, compute ( a^b % 1337 ). The array `b` stores the digits of `b` from most significant to least significant. You must handle extremely large values of `b` efficiently.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `a` and an array `b`, where `b[i]` is a digit of the large number `b`.
- **Example:** `Input: a = 3, b = [2]`
- **Constraints:**
	- 1 <= a <= 231 - 1
	- 1 <= b.length <= 2000
	- 0 <= b[i] <= 9
	- b does not contain leading zeros.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the value of ( a^b % 1337 ).
- **Example:** `Output: 9`
- **Constraints:**
	- The result should be computed modulo 1337.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute ( a^b % 1337 ) efficiently, even for extremely large values of `b`.

- 1. Reduce `a` modulo 1337 to prevent overflow.
- 2. Use recursion to handle the large exponent, breaking the problem into smaller parts.
- 3. Use the principle of modular arithmetic to compute the result using smaller powers.
{{< dots >}}
### Problem Assumptions ✅
- The integer `a` is a positive integer.
- The array `b` represents a valid large integer without leading zeros.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = 3, b = [2]
Output: 9`  \
  **Explanation:** The result is ( 3^2 % 1337 = 9 ), which is the expected output.

- **Input:** `Input: a = 5, b = [1, 2]
Output: 25`  \
  **Explanation:** The result is ( 5^{12} % 1337 = 25 ), which is computed using the recursive approach.

{{< dots >}}
## Approach 🚀
The approach uses recursion to break down the large exponent `b` and calculates the result using modular arithmetic.

### Initial Thoughts 💭
- Direct computation of large exponents is inefficient.
- Recursive solutions and modular arithmetic can break down the problem.
- By recursively calculating smaller powers, we can avoid overflow and handle the large size of `b`.
{{< dots >}}
### Edge Cases 🌐
- The array `b` will always have at least one digit.
- The array `b` can be up to 2000 digits long, so efficient handling of large numbers is necessary.
- If `a = 1`, the result is always 1, regardless of `b`.
- Ensure the solution handles the maximum and minimum values for `a` and handles large `b` values.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int base = 1337;
int powmod(int a, int k) {
    a %= base;
    int res = 1;
    for(int i = 0; i < k; i++)
    res = (res * a) % base;
    return res;
}
public:
int superPow(int a, vector<int>& b) {
    if(b.empty()) return 1;
    int last_digit = b.back();
    b.pop_back();
    return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
}
```

This solution defines a class `Solution` with a method `superPow`, which calculates the value of a raised to the power of a number represented by a list of digits `b` modulo 1337. The helper function `powmod` computes a^k % base using an iterative approach to efficiently calculate powers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int base = 1337;
	```
	The `base` variable is initialized to 1337. This is the modulus used in the calculation to keep the result within manageable limits.

2. **Method Declaration**
	```cpp
	int powmod(int a, int k) {
	```
	This line declares the helper method `powmod`, which calculates `a^k % base`. It takes two arguments: `a`, the base, and `k`, the exponent.

3. **Modulo Operation**
	```cpp
	    a %= base;
	```
	This line reduces `a` modulo `base`, ensuring that the base remains within the modulus before performing exponentiation.

4. **Variable Initialization**
	```cpp
	    int res = 1;
	```
	The variable `res` is initialized to 1, which will hold the result of the power calculation.

5. **Loop Iteration**
	```cpp
	    for(int i = 0; i < k; i++)
	```
	This loop runs `k` times, each time multiplying `res` by `a` and reducing it modulo `base`.

6. **Multiplication**
	```cpp
	    res = (res * a) % base;
	```
	In each iteration of the loop, `res` is updated to be the result of `res * a % base`, effectively calculating `a^k % base`.

7. **Return Statement**
	```cpp
	    return res;
	```
	The final result of the modular exponentiation is returned as the output of the `powmod` method.

8. **Method Declaration**
	```cpp
	int superPow(int a, vector<int>& b) {
	```
	The method `superPow` is declared. This method calculates `a` raised to the power represented by the list of digits `b`.

9. **Base Case**
	```cpp
	    if(b.empty()) return 1;
	```
	If the vector `b` is empty, the result is `1`, as any number raised to the power of zero is 1.

10. **Pop Last Digit**
	```cpp
	    int last_digit = b.back();
	```
	The last digit of the vector `b` is retrieved and stored in `last_digit`, representing the current power to apply.

11. **Pop Last Digit**
	```cpp
	    b.pop_back();
	```
	The last digit is removed from the vector `b` to reduce the problem size for the recursive call.

12. **Recursive Call**
	```cpp
	    return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
	```
	The method uses recursion to calculate the result. It calls `superPow` recursively to calculate the power of `a` raised to the value represented by `b`. It then combines the result with the power of `a` raised to `last_digit`, applying the modulus operation at each step.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(b.length)) where `b.length` is the number of digits in `b`.
- **Average Case:** O(log(b.length)) due to the recursive approach.
- **Worst Case:** O(log(b.length)) as the recursion depth is determined by the length of `b`.

The time complexity is logarithmic in relation to the length of `b`, as the problem is divided in each recursive step.

### Space Complexity 💾
- **Best Case:** O(1) if the recursion depth is minimal.
- **Worst Case:** O(log(b.length)) due to the recursion stack.

The space complexity is proportional to the recursion depth, which is logarithmic in relation to the number of digits in `b`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/super-pow/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
