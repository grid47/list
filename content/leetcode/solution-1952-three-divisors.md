
+++
authors = ["grid47"]
title = "Leetcode 1952: Three Divisors"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1952: Three Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Rl-JOgrVru0"
youtube_upload_date="2021-08-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Rl-JOgrVru0/maxresdefault.webp"
comments = true
+++



---
Given an integer n, return true if n has exactly three distinct positive divisors. Otherwise, return false. A divisor of n is a positive integer that divides n without leaving a remainder.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n. Your task is to determine if n has exactly three positive divisors.
- **Example:** `n = 9`
- **Constraints:**
	- 1 <= n <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if n has exactly three divisors, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value indicating whether n has exactly three divisors.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the given integer n has exactly three distinct divisors.

- Step 1: Find all divisors of n by iterating through integers from 1 to sqrt(n).
- Step 2: Count the number of divisors.
- Step 3: If the count of divisors is exactly 3, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input integer n will always be a valid integer within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 9`  \
  **Explanation:** The divisors of 9 are 1, 3, and 9, so it has exactly 3 divisors. Therefore, the output is true.

- **Input:** `Input: n = 10`  \
  **Explanation:** The divisors of 10 are 1, 2, 5, and 10, so it has 4 divisors. Therefore, the output is false.

{{< dots >}}
## Approach 🚀
The approach is to check the divisors of the given number n and verify if there are exactly three distinct divisors.

### Initial Thoughts 💭
- The number of divisors of n depends on its prime factorization. For n to have exactly three divisors, n must be a square of a prime number.
- If n is a perfect square and its square root is prime, then n will have exactly three divisors: 1, the prime number, and n itself.
{{< dots >}}
### Edge Cases 🌐
- n cannot be 0, as the problem constraints specify that 1 <= n.
- When n is large (up to 10^4), the approach should efficiently handle checking if n is a perfect square and if its square root is prime.
- For prime numbers, n will never have exactly three divisors, so the output should be false.
- Ensure that n is checked within the valid range of 1 to 10^4.
{{< dots >}}
## Code 💻
```cpp
bool isThree(int n) {
int d = 2;
for (int i = 2; i < n && d <= 3; i += 1)
    d += n % i == 0;
return d == 3;
}
```

This function checks if a number 'n' has exactly three divisors.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isThree(int n) {
	```
	The function is defined with a boolean return type, indicating it will return true if 'n' has exactly three divisors, and false otherwise.

2. **Variable Initialization**
	```cpp
	int d = 2;
	```
	The variable 'd' is initialized to 2, as we start by assuming that 'n' has at least two divisors: 1 and 'n' itself.

3. **Loop for Divisor Check**
	```cpp
	for (int i = 2; i < n && d <= 3; i += 1)
	```
	A loop starts from 2 and iterates until 'n' or until 'd' exceeds 3. The loop checks if there are additional divisors of 'n'.

4. **Divisor Check**
	```cpp
	    d += n % i == 0;
	```
	For each iteration, the condition 'n % i == 0' checks if 'i' is a divisor of 'n'. If it is, 'd' is incremented by 1.

5. **Return Statement**
	```cpp
	return d == 3;
	```
	The function returns true if 'd' equals 3, meaning 'n' has exactly three divisors. Otherwise, it returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(sqrt(n))
- **Worst Case:** O(sqrt(n))

The time complexity is O(sqrt(n)) due to checking if n is a perfect square and verifying the primality of sqrt(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as only a constant amount of space is required for storing intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/three-divisors/description/)

---
{{< youtube Rl-JOgrVru0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
