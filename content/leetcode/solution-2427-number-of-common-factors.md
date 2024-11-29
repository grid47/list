
+++
authors = ["grid47"]
title = "Leetcode 2427: Number of Common Factors"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2427: Number of Common Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QzFzbNvmRgs"
youtube_upload_date="2022-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QzFzbNvmRgs/maxresdefault.webp"
comments = true
+++



---
You are given two positive integers, a and b. Your task is to find the number of common divisors (factors) between a and b. A number x is considered a common divisor of a and b if it divides both a and b without leaving any remainder.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two positive integers, a and b.
- **Example:** `a = 18, b = 24`
- **Constraints:**
	- 1 <= a, b <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of common divisors (factors) of a and b.
- **Example:** `Output: 6`
- **Constraints:**
	- The result will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the number of common divisors efficiently.

- 1. Find the greatest common divisor (GCD) of a and b.
- 2. Count all the divisors of the GCD, since the divisors of the GCD are the common divisors of a and b.
{{< dots >}}
### Problem Assumptions ✅
- Both a and b are positive integers.
- We need to calculate only the common divisors between the two numbers.
{{< dots >}}
## Examples 🧩
- **Input:** `a = 18, b = 24`  \
  **Explanation:** The common divisors of 18 and 24 are 1, 2, 3, 6, 9, and 18. Therefore, the answer is 6.

{{< dots >}}
## Approach 🚀
We can solve the problem by first finding the greatest common divisor (GCD) of a and b. Then, we find all the divisors of the GCD, as they will also be the common divisors of both a and b.

### Initial Thoughts 💭
- The common divisors of two numbers are the divisors of their greatest common divisor (GCD).
- We can use the Euclidean algorithm to find the GCD of a and b and then count its divisors.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as both a and b are guaranteed to be positive integers.
- The solution should handle input values up to 1000 efficiently.
- If a and b are the same number, the GCD will be the number itself, and its divisors will be the number of divisors of that number.
- The solution must run efficiently for the entire input range.
{{< dots >}}
## Code 💻
```cpp
int commonFactors(int a, int b) {
int res = 1, hi = gcd(a, b);
for (int n = 2; n <= hi; ++n)
    res += a % n == 0 && b % n == 0;
return res;
}
```

This function calculates the number of common factors between two integers by iterating through potential divisors.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int commonFactors(int a, int b) {
	```
	This line defines the function 'commonFactors' that takes two integers as input parameters.

2. **Variable Initialization**
	```cpp
	int res = 1, hi = gcd(a, b);
	```
	Here, a variable 'res' is initialized to 1 and 'hi' is set to the greatest common divisor (gcd) of a and b.

3. **For Loop Setup**
	```cpp
	for (int n = 2; n <= hi; ++n)
	```
	This is the start of a loop that will iterate from 2 to the greatest common divisor (hi).

4. **Condition Check**
	```cpp
	    res += a % n == 0 && b % n == 0;
	```
	In this line, we check if both a and b are divisible by n. If so, 'res' is incremented.

5. **Return Statement**
	```cpp
	return res;
	```
	After the loop ends, the function returns the number of common factors found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(min(a, b))) for finding the GCD.
- **Average Case:** O(sqrt(gcd)) for counting the divisors.
- **Worst Case:** O(sqrt(gcd)) for counting the divisors.

The time complexity is dominated by finding the divisors of the GCD, which takes O(sqrt(gcd)) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-common-factors/description/)

---
{{< youtube QzFzbNvmRgs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
