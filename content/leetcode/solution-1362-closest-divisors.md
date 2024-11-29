
+++
authors = ["grid47"]
title = "Leetcode 1362: Closest Divisors"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1362: Closest Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wx3731P3At4"
youtube_upload_date="2022-08-04"
youtube_thumbnail="https://i.ytimg.com/vi/wx3731P3At4/maxresdefault.jpg"
comments = true
+++



---
Given an integer `num`, find the closest two integers whose product is equal to either `num + 1` or `num + 2` and whose absolute difference is the smallest. You need to return these two integers in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `num` which represents the given number.
- **Example:** `num = 8`
- **Constraints:**
	- 1 <= num <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of two integers that have the smallest absolute difference, whose product is equal to `num + 1` or `num + 2`.
- **Example:** `[3, 3]`
- **Constraints:**
	- The output will always contain exactly two integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the two closest divisors of `num + 1` or `num + 2` whose absolute difference is the smallest.

- For each possible divisor from `sqrt(num + 2)` down to 1, check if it divides `num + 1` or `num + 2`.
- Once a divisor is found, return the pair of divisors with the smallest difference.
{{< dots >}}
### Problem Assumptions ✅
- The input `num` is always a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `num = 8`  \
  **Explanation:** For `num + 1 = 9`, the closest divisors are `3` and `3`, and for `num + 2 = 10`, the closest divisors are `2` and `5`. The pair `[3, 3]` is returned as it has the smallest absolute difference.

- **Input:** `num = 25`  \
  **Explanation:** For `num + 1 = 26`, the closest divisors are `2` and `13`, and for `num + 2 = 27`, the closest divisors are `3` and `9`. The pair `[5, 6]` is returned because it forms the closest divisors.

{{< dots >}}
## Approach 🚀
The approach involves iterating from the square root of `num + 2` down to 1, checking divisibility, and selecting the closest divisors with the smallest absolute difference.

### Initial Thoughts 💭
- The problem requires finding divisors of `num + 1` and `num + 2`.
- We can use the square root method to optimize the search for divisors.
- The main challenge is to ensure that the divisors have the smallest possible difference.
{{< dots >}}
### Edge Cases 🌐
- This problem does not involve empty inputs, as the input is always a positive integer.
- Ensure that the solution handles very large values of `num` up to 10^9 efficiently.
- Handle cases where `num + 1` or `num + 2` has only one divisor pair.
- Ensure that the solution works within the given constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> closestDivisors(int num) {
    
    for(int a = sqrt(num + 2); a > 0; a--) {
        if((num + 1) % a == 0) return vector<int>{a, (num + 1) / a};
        if((num + 2) % a == 0) return vector<int>{a, (num + 2) / a};            
    }
    return vector<int>{};
}
```

This function finds the closest divisors of a number 'num' by checking the divisors of 'num+1' and 'num+2' starting from the largest possible divisor and returns the pair of divisors. If no divisors are found, it returns an empty vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> closestDivisors(int num) {
	```
	The function 'closestDivisors' takes an integer 'num' and returns a vector containing two divisors of 'num+1' or 'num+2' whose product is closest to 'num'.

2. **For Loop Initialization**
	```cpp
	    for(int a = sqrt(num + 2); a > 0; a--) {
	```
	A for loop is initialized with 'a' starting from the square root of 'num + 2'. It iterates downwards, checking possible divisors of 'num+1' and 'num+2'.

3. **Divisor Check for num+1**
	```cpp
	        if((num + 1) % a == 0) return vector<int>{a, (num + 1) / a};
	```
	Checks if 'a' is a divisor of 'num+1'. If true, it returns a vector with 'a' and 'num+1' divided by 'a' as the divisors.

4. **Divisor Check for num+2**
	```cpp
	        if((num + 2) % a == 0) return vector<int>{a, (num + 2) / a};            
	```
	Checks if 'a' is a divisor of 'num+2'. If true, it returns a vector with 'a' and 'num+2' divided by 'a' as the divisors.

5. **Return Empty Vector**
	```cpp
	    return vector<int>{};
	```
	If no divisors are found for 'num+1' or 'num+2', the function returns an empty vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(sqrt(num))
- **Average Case:** O(sqrt(num))
- **Worst Case:** O(sqrt(num))

The time complexity is dominated by the need to check divisors up to the square root of `num + 2`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since only a few variables are used in the solution.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/closest-divisors/description/)

---
{{< youtube wx3731P3At4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
