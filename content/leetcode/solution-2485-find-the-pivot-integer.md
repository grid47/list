
+++
authors = ["grid47"]
title = "Leetcode 2485: Find the Pivot Integer"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2485: Find the Pivot Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xfw3A8uOdFw"
youtube_upload_date="2022-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xfw3A8uOdFw/maxresdefault.webp"
comments = true
+++



---
Given a positive integer n, you are tasked with finding an integer x such that the sum of all integers from 1 to x is equal to the sum of all integers from x to n, inclusive. If no such integer exists, return -1. It is guaranteed that there will be at most one solution for the given input.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A positive integer n representing the upper bound of the sequence.
- **Example:** `n = 8`
- **Constraints:**
	- 1 <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The pivot integer x such that the sum of numbers from 1 to x equals the sum of numbers from x to n, or -1 if no such x exists.
- **Example:** `Output: 6`
- **Constraints:**
	- The returned value will be an integer between 1 and n or -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the pivot integer x that satisfies the sum condition or return -1 if no such integer exists.

- 1. Calculate the total sum of all integers from 1 to n.
- 2. Check if there exists an integer x where the sum of integers from 1 to x equals the sum of integers from x to n.
- 3. If such x exists, return it; otherwise, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The solution assumes the sum formula for the first n integers is correct.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 8`  \
  **Explanation:** For n = 8, the total sum of numbers from 1 to 8 is 36. The sum from 1 to 6 is 21, and the sum from 6 to 8 is also 21. Hence, 6 is the pivot integer.

- **Input:** `n = 1`  \
  **Explanation:** For n = 1, the sum of numbers from 1 to 1 is 1. The sum from 1 to 1 is also 1, so 1 is the pivot integer.

- **Input:** `n = 4`  \
  **Explanation:** For n = 4, the total sum of numbers from 1 to 4 is 10. There is no integer x where the sum of numbers from 1 to x equals the sum from x to 4, so the output is -1.

{{< dots >}}
## Approach 🚀
To solve this problem, we can first compute the total sum of the integers from 1 to n. We then check for a pivot integer x such that the sum of integers from 1 to x equals the sum from x to n. We use the fact that the sum of the first n integers is given by the formula n * (n + 1) / 2.

### Initial Thoughts 💭
- We need to find an integer x where the sum of numbers from 1 to x is equal to the sum of numbers from x to n.
- This can be simplified using the formula for the sum of the first n integers. By calculating the total sum and checking if the square root of that sum is an integer, we can determine the pivot integer.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs are allowed as per the constraints.
- For large values of n (up to 1000), the solution must efficiently compute the sum and check for a valid pivot integer.
- If n is a small value like 1, the solution must correctly handle this edge case.
- Ensure that the solution works for all n between 1 and 1000.
{{< dots >}}
## Code 💻
```cpp
int pivotInteger(int n) {
    int sum = n * (n + 1) / 2, x = sqrt(sum);
    return x * x == sum ? x : -1;
}
```

This function computes the pivot integer of a number `n`, where the pivot integer `x` is such that the sum of integers from 1 to `x` equals the total sum of integers from 1 to `n`. If no such `x` exists, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int pivotInteger(int n) {
	```
	This line defines the function `pivotInteger`, which takes an integer `n` and returns the pivot integer `x` or -1 if no such pivot exists.

2. **Sum Calculation**
	```cpp
	    int sum = n * (n + 1) / 2, x = sqrt(sum);
	```
	Here, `sum` calculates the total sum of integers from 1 to `n`. `x` is the square root of this sum, representing the potential pivot integer.

3. **Conditional Check**
	```cpp
	    return x * x == sum ? x : -1;
	```
	This line checks if the square of `x` equals `sum`. If true, it returns `x` as the pivot integer; otherwise, it returns -1 to indicate no such pivot exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution computes the sum in constant time and checks if the square root of the sum is an integer, which takes constant time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we only store a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-pivot-integer/description/)

---
{{< youtube Xfw3A8uOdFw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
