
+++
authors = ["grid47"]
title = "Leetcode 1492: The kth Factor of n"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1492: The kth Factor of n in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eD7-AQ2nUsI"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eD7-AQ2nUsI/maxresdefault.webp"
comments = true
+++



---
You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0. Consider a sorted list of all factors of n in ascending order. Return the kth factor from this list or return -1 if n has less than k factors.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers n and k. The integer n represents the number for which we need to find the factors, and k represents the position of the factor to return.
- **Example:** `n = 18, k = 4`
- **Constraints:**
	- 1 <= k <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the kth factor in the list of factors of n, or -1 if n has fewer than k factors.
- **Example:** `Output: 6`
- **Constraints:**
	- If n has less than k factors, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the kth factor of n by iterating through its divisors and returning the kth one.

- Iterate through integers from 1 to n.
- Check if each integer divides n without a remainder.
- Count the divisors and return the kth divisor if it exists.
- If fewer than k divisors are found, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input values of n and k will always be valid integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 18, k = 4`  \
  **Explanation:** The factors of 18 are [1, 2, 3, 6, 9, 18]. The 4th factor is 6.

- **Input:** `n = 9, k = 3`  \
  **Explanation:** The factors of 9 are [1, 3, 9]. The 3rd factor is 9.

- **Input:** `n = 10, k = 5`  \
  **Explanation:** The factors of 10 are [1, 2, 5, 10]. There are only 4 factors, so the result is -1.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, iterate through potential factors of n and check for divisibility. Return the kth factor if found.

### Initial Thoughts 💭
- The factors of n are the integers from 1 to n that divide n without leaving a remainder.
- We can check each integer in this range to see if it's a factor of n.
- We need to find the kth factor, so tracking the count of factors is essential to solving this problem.
{{< dots >}}
### Edge Cases 🌐
- There will always be valid input with n >= 1.
- For larger values of n (up to 1000), the solution must be efficient enough to handle the full range of factors.
- If k exceeds the number of factors of n, return -1.
- Ensure the solution handles all edge cases efficiently, especially when k is larger than the number of factors.
{{< dots >}}
## Code 💻
```cpp
int kthFactor(int n, int k) {
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) k--;
        if(k == 0) return i;
    }
    return -1;
}
```

The `kthFactor` function returns the k-th divisor of a given integer `n`. If the k-th divisor doesn't exist, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	int kthFactor(int n, int k) {
	```
	The function `kthFactor` is designed to find the k-th divisor of a given integer `n`.

2. **Loop**
	```cpp
	    for(int i = 1; i <= n; i++) {
	```
	A loop is used to iterate through all integers from 1 to `n` to check for divisibility.

3. **Divisibility Check**
	```cpp
	        if(n % i == 0) k--;
	```
	This condition checks if `i` is a divisor of `n`. If it is, it decrements the value of `k`.

4. **Return Divisor**
	```cpp
	        if(k == 0) return i;
	```
	If `k` reaches 0, it means the current number `i` is the k-th divisor of `n`, and it is returned.

5. **Return -1**
	```cpp
	    return -1;
	```
	If no k-th divisor is found, the function returns -1 to indicate that the k-th divisor does not exist.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The worst-case time complexity occurs when we check every integer from 1 to n for divisibility.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we are only using a few variables for tracking the factors.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-kth-factor-of-n/description/)

---
{{< youtube eD7-AQ2nUsI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
