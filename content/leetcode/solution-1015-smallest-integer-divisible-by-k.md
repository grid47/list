
+++
authors = ["grid47"]
title = "Leetcode 1015: Smallest Integer Divisible by K"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1015: Smallest Integer Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kaEYJUNhQ3k"
youtube_upload_date="2020-11-25"
youtube_thumbnail="https://i.ytimg.com/vi/kaEYJUNhQ3k/maxresdefault.jpg"
comments = true
+++



---
Given a positive integer k, find the length of the smallest positive integer n such that n is divisible by k, and n consists only of the digit 1. If no such number exists, return -1. Note that n might not fit into a 64-bit signed integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer k, where k is a positive integer.
- **Example:** `k = 7`
- **Constraints:**
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the length of the smallest integer n that is divisible by k and only contains the digit 1, or -1 if no such integer exists.
- **Example:** `Output: 6`
- **Constraints:**
	- The result must be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the length of the smallest integer n that is divisible by k and consists only of the digit 1.

- Iterate through possible lengths of numbers formed only by the digit 1.
- For each length, compute the number formed by that many 1s, and check if it's divisible by k.
- Return the length of the first such number, or -1 if no such number exists.
{{< dots >}}
### Problem Assumptions ✅
- There is always a valid input integer k, and it will be between 1 and 100,000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: k = 1`  \
  **Explanation:** The smallest number divisible by 1 is simply 1, which has length 1.

- **Input:** `Input: k = 2`  \
  **Explanation:** There is no number formed by 1s that is divisible by 2, so the output is -1.

- **Input:** `Input: k = 3`  \
  **Explanation:** The smallest number divisible by 3 is 111, which has length 3.

{{< dots >}}
## Approach 🚀
The approach is to iteratively compute the remainder when numbers formed by the digit 1 are divided by k, and check when this remainder becomes zero. The first such number will give us the length of the desired number.

### Initial Thoughts 💭
- We can form numbers using the digit 1 repeatedly, and compute their remainder with respect to k.
- If the remainder becomes zero, we've found the smallest such number.
- Rather than directly constructing the large number, we can calculate the remainder iteratively by considering the number as a series of digits (all 1s).
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to be a positive integer k, so no need to handle empty inputs.
- For large values of k, the solution should handle remainders efficiently without constructing large numbers.
- When k is 1, the smallest number is 1 itself, which has length 1.
- Ensure that the solution works efficiently for large k values up to 100,000.
{{< dots >}}
## Code 💻
```cpp
int smallestRepunitDivByK(int k) {
    for(int r = 0, N = 1; N <= k; N++)
    if((r = (r * 10 + 1)%k )== 0) return N;
    return -1;
}
```

This function finds the smallest integer `N` such that the number formed by repeating '1' exactly `N` times is divisible by `k`. It uses modular arithmetic to check divisibility by `k` as it iterates through increasing values of `N`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int smallestRepunitDivByK(int k) {
	```
	Declares the function `smallestRepunitDivByK`, which takes an integer `k` and returns the smallest integer `N` such that the number formed by repeating '1' `N` times is divisible by `k`.

2. **Loop Initialization**
	```cpp
	    for(int r = 0, N = 1; N <= k; N++)
	```
	Initializes a loop with two variables: `r`, which will store the remainder when dividing the current number by `k`, and `N`, which represents the number of '1's in the current candidate number. The loop continues until `N` exceeds `k`.

3. **Modular Arithmetic**
	```cpp
	    if((r = (r * 10 + 1)%k )== 0) return N;
	```
	For each iteration, the number formed by repeating '1' is calculated modulo `k` using the formula `(r * 10 + 1) % k`. If the remainder `r` is zero, it means the number formed by repeating '1' `N` times is divisible by `k`, and the function returns `N`.

4. **Return -1**
	```cpp
	    return -1;
	```
	If no such `N` is found after looping through all possible values up to `k`, the function returns `-1`, indicating no solution exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k)
- **Average Case:** O(k)
- **Worst Case:** O(k)

The solution iterates through the remainders for at most k iterations, leading to a time complexity of O(k).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only maintain a few variables to track the remainder and length of the number.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-integer-divisible-by-k/description/)

---
{{< youtube kaEYJUNhQ3k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
