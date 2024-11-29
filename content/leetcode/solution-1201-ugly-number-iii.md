
+++
authors = ["grid47"]
title = "Leetcode 1201: Ugly Number III"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1201: Ugly Number III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Combinatorics","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
An ugly number is a positive integer that is divisible by at least one of the integers a, b, or c. Your task is to return the nth ugly number in the sequence formed by the integers divisible by a, b, or c.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given four integers n, a, b, and c. You need to return the nth ugly number, where an ugly number is divisible by a, b, or c.
- **Example:** `Input: n = 3, a = 2, b = 3, c = 5`
- **Constraints:**
	- 1 <= n, a, b, c <= 10^9
	- 1 <= a * b * c <= 10^18
	- It is guaranteed that the result will be in range [1, 2 * 10^9].

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the nth ugly number from the sequence.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the nth ugly number in the sequence formed by numbers divisible by a, b, or c.

- Perform a binary search to find the nth ugly number.
- At each step, calculate the number of ugly numbers less than or equal to the mid-point of the search range.
- Adjust the range based on the count of ugly numbers found and repeat until the correct ugly number is found.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that the integers a, b, and c are not equal to zero.
- The given values are large but within the range allowed by the solution approach.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3, a = 2, b = 3, c = 5`  \
  **Explanation:** The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10, 12... The 3rd ugly number is 4.

- **Input:** `Input: n = 4, a = 2, b = 3, c = 4`  \
  **Explanation:** The ugly numbers are 2, 3, 4, 6, 8, 9, 10... The 4th ugly number is 6.

- **Input:** `Input: n = 5, a = 2, b = 11, c = 13`  \
  **Explanation:** The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th ugly number is 10.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, a binary search approach is used to find the nth ugly number. The idea is to calculate how many ugly numbers are there less than or equal to a given number using the formula for counting divisibility by a, b, and c.

### Initial Thoughts 💭
- The problem is constrained by large values, so a brute-force approach of checking all numbers is inefficient.
- A binary search allows for efficient narrowing of the range of possible ugly numbers.
- Binary search is optimal for this kind of problem, where the answer lies within a specific range.
{{< dots >}}
### Edge Cases 🌐
- Ensure all inputs are positive integers.
- Ensure the solution handles large values of n, a, b, and c efficiently.
- Consider edge cases where a, b, or c might be large prime numbers or powers of each other.
- The constraints allow us to use a binary search approach because the range of possible ugly numbers is manageable.
{{< dots >}}
## Code 💻
```cpp
int nthUglyNumber(int k, int A, int B, int C) {
    int lo = 1, hi = 2* (int)1e9;
    long a = long(A), b = long(B), c = long(C);
    long ab = a * b / __gcd(a, b);
    long bc = b * c / __gcd(b, c);
    long ac = a * c / __gcd(a, c);
    long abc = a * bc / __gcd(a, bc);
    while (lo < hi ) {
        int mid = lo + (hi - lo)/2;
        int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
        
        if (cnt < k) {
            lo = mid + 1;
        } else hi = mid;
    }
    return lo;
}
```

This function calculates the k-th ugly number that is divisible by any of A, B, or C. It uses binary search to efficiently compute the result by considering least common multiples and avoiding overcounting.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	int nthUglyNumber(int k, int A, int B, int C) {
	```
	Defines the function that calculates the k-th ugly number based on inputs A, B, and C.

2. **Variable Initialization**
	```cpp
	    int lo = 1, hi = 2* (int)1e9;
	```
	Initializes the search range for the binary search algorithm.

3. **Variable Initialization**
	```cpp
	    long a = long(A), b = long(B), c = long(C);
	```
	Converts the inputs A, B, and C to long type for arithmetic operations.

4. **Mathematical Calculation**
	```cpp
	    long ab = a * b / __gcd(a, b);
	```
	Computes the least common multiple (LCM) of A and B using their GCD.

5. **Mathematical Calculation**
	```cpp
	    long bc = b * c / __gcd(b, c);
	```
	Computes the LCM of B and C using their GCD.

6. **Mathematical Calculation**
	```cpp
	    long ac = a * c / __gcd(a, c);
	```
	Computes the LCM of A and C using their GCD.

7. **Mathematical Calculation**
	```cpp
	    long abc = a * bc / __gcd(a, bc);
	```
	Computes the LCM of A, B, and C using the LCM of B and C.

8. **Loop**
	```cpp
	    while (lo < hi ) {
	```
	Begins the binary search loop to narrow down the k-th ugly number.

9. **Binary Search**
	```cpp
	        int mid = lo + (hi - lo)/2;
	```
	Calculates the midpoint of the current range in binary search.

10. **Counting**
	```cpp
	        int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
	```
	Counts how many numbers up to mid are divisible by A, B, or C, adjusting for overlaps.

11. **Conditional Check**
	```cpp
	        if (cnt < k) {
	```
	If the count of valid numbers is less than k, adjust the lower bound.

12. **Adjust Bound**
	```cpp
	            lo = mid + 1;
	```
	Moves the lower bound up when the count is less than k.

13. **Adjust Bound**
	```cpp
	        } else hi = mid;
	```
	Moves the upper bound down when the count meets or exceeds k.

14. **Return**
	```cpp
	    return lo;
	```
	Returns the k-th ugly number after narrowing down the search range.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(2 * 10^9))
- **Average Case:** O(log(2 * 10^9))
- **Worst Case:** O(log(2 * 10^9))

The binary search narrows the range logarithmically, ensuring a fast solution even for large inputs.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution only requires a few variables, making it space-efficient.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/ugly-number-iii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
