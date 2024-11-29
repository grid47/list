
+++
authors = ["grid47"]
title = "Leetcode 2894: Divisible and Non-divisible Sums Difference"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2894: Divisible and Non-divisible Sums Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "CXjNaWOdJ34"
youtube_upload_date="2023-10-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/CXjNaWOdJ34/maxresdefault.webp"
comments = true
+++



---
You are given two positive integers, n and m. Calculate the difference between the sum of integers in the range [1, n] that are not divisible by m (num1) and the sum of integers in the range [1, n] that are divisible by m (num2). Return the result of num1 - num2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, n and m.
- **Example:** `n = 12, m = 4`
- **Constraints:**
	- 1 <= n, m <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the value of num1 - num2, where num1 is the sum of integers not divisible by m, and num2 is the sum of integers divisible by m.
- **Example:** `For input n = 12, m = 4, the output is 58.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the sum of integers that are divisible by m and those that are not, and return the difference between the two sums.

- Loop through all integers from 1 to n.
- Check if each number is divisible by m.
- If divisible, add it to num2; if not, add it to num1.
- Calculate the difference num1 - num2.
{{< dots >}}
### Problem Assumptions ✅
- Both n and m are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `For input n = 12, m = 4, the output is 58.`  \
  **Explanation:** The sum of numbers in the range [1, 12] that are not divisible by 4 is 54, while the sum of numbers divisible by 4 is 24. The result is 54 - 24 = 58.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the numbers from 1 to n, categorizing them as divisible by m or not, and summing them accordingly.

### Initial Thoughts 💭
- The task involves checking divisibility for each number from 1 to n.
- This can be solved by a simple loop through the range [1, n].
{{< dots >}}
### Edge Cases 🌐
- Both n and m are guaranteed to be positive, so there are no empty inputs.
- Ensure the algorithm handles cases with large values of n and m up to 1000.
- Consider when m is larger than n, where no numbers are divisible by m.
- The algorithm should be efficient enough to handle n up to 1000.
{{< dots >}}
## Code 💻
```cpp
int differenceOfSums(int n, int m) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % m == 0) {
            res -= i;
        } else {
            res += i;
        }
    }
    return res;
}
```

This function calculates the difference of sums by adding or subtracting integers from 1 to n based on their divisibility by m.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int differenceOfSums(int n, int m) {
	```
	Define the function that calculates the difference of sums. Takes two parameters: n (upper limit) and m (divisor).

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable to zero. This will store the accumulated sum (or difference).

3. **For Loop**
	```cpp
	    for (int i = 1; i <= n; ++i) {
	```
	Start a loop from 1 to n (inclusive) to iterate through all integers.

4. **Condition Check**
	```cpp
	        if (i % m == 0) {
	```
	Check if the current integer i is divisible by m (using modulus operation).

5. **Subtraction**
	```cpp
	            res -= i;
	```
	If i is divisible by m, subtract it from the result.

6. **Else Block**
	```cpp
	        } else {
	```
	If i is not divisible by m, add it to the result.

7. **Addition**
	```cpp
	            res += i;
	```
	Add the value of i to the result if it's not divisible by m.

8. **Return Statement**
	```cpp
	    return res;
	```
	Return the result, which is the difference of sums after processing all integers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we iterate through the range [1, n].

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of space for the sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/)

---
{{< youtube CXjNaWOdJ34 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
