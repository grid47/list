
+++
authors = ["grid47"]
title = "Leetcode 2457: Minimum Addition to Make Integer Beautiful"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2457: Minimum Addition to Make Integer Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NoGK4582ey8"
youtube_upload_date="2022-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/NoGK4582ey8/maxresdefault.webp"
comments = true
+++



---
Given a positive integer n and a target sum, the task is to find the smallest non-negative integer x such that the sum of the digits of n + x is less than or equal to the given target. The solution is guaranteed to always be possible for the given constraints.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers, n and target, where n is a positive integer and target is the maximum allowed sum of the digits of n + x.
- **Example:** `n = 25, target = 10`
- **Constraints:**
	- 1 <= n <= 10^12
	- 1 <= target <= 150

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum non-negative integer x such that the sum of the digits of n + x is less than or equal to target. The result should be a single integer.
- **Example:** `For n = 25 and target = 10, the output will be 5.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest integer x such that the sum of the digits of n + x is less than or equal to the target.

- 1. Calculate the sum of digits of n.
- 2. If the sum of digits of n is already less than or equal to target, return 0.
- 3. Otherwise, find the smallest x by incrementing n in such a way that the sum of the digits becomes less than or equal to target.
{{< dots >}}
### Problem Assumptions ✅
- It is always possible to find a non-negative x such that n + x becomes beautiful.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 25, target = 10`  \
  **Explanation:** Initially, the sum of the digits of n (25) is 2 + 5 = 7, which is less than target. After adding 5 to n, we get 30, and the sum of digits becomes 3 + 0 = 3, which is still less than target.

- **Input:** `n = 467, target = 6`  \
  **Explanation:** The sum of digits of n (467) is 4 + 6 + 7 = 17, which is greater than target. After adding 33, n becomes 500, and the sum of digits is 5 + 0 + 0 = 5, which satisfies the target.

{{< dots >}}
## Approach 🚀
We will increment the integer n in such a way that the sum of its digits becomes less than or equal to the target. The approach works by checking the sum of digits of n and gradually adjusting it by incrementing the number until the sum meets the target condition.

### Initial Thoughts 💭
- We need to find a way to manipulate the digits of n to make their sum less than or equal to the target.
- We can use a loop to increment n and calculate the sum of digits until the condition is met.
{{< dots >}}
### Edge Cases 🌐
- The problem ensures that n is always a positive integer, so there are no empty inputs.
- Ensure the solution can handle n up to 10^12 efficiently.
- If the sum of digits of n is already less than or equal to target, x will be 0.
- The solution must handle large inputs and large numbers efficiently.
{{< dots >}}
## Code 💻
```cpp

int sum(long long n) {
    int res = 0;
    while(n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

long long makeIntegerBeautiful(long long n, int target) {
    long long n0 = n, base = 1;
    while(sum(n) > target) {
        n = n / 10 + 1;
        base *= 10;
    }
    return n * base - n0;
}
```

This solution modifies a number to make its digit sum less than or equal to a target by increasing its value and scaling it up.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sum(long long n) {
	```
	Defines a helper function to calculate the sum of the digits of a number.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes the variable `res` to store the cumulative digit sum.

3. **Loop Through Digits**
	```cpp
	    while(n > 0) {
	```
	Loops through each digit of the number while `n` is greater than 0.

4. **Digit Calculation**
	```cpp
	        res += n % 10;
	```
	Adds the last digit of `n` to the result `res`.

5. **Digit Removal**
	```cpp
	        n /= 10;
	```
	Removes the last digit of `n` by performing integer division by 10.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returns the cumulative sum of the digits.

7. **Function Definition**
	```cpp
	long long makeIntegerBeautiful(long long n, int target) {
	```
	Defines the main function to modify the number `n` such that its digit sum is less than or equal to the target.

8. **Variable Initialization**
	```cpp
	    long long n0 = n, base = 1;
	```
	Stores the original value of `n` in `n0` and initializes a scaling factor `base` to 1.

9. **Condition Loop**
	```cpp
	    while(sum(n) > target) {
	```
	Loops while the digit sum of `n` is greater than the target.

10. **Value Update**
	```cpp
	        n = n / 10 + 1;
	```
	Reduces `n` by removing the last digit, increments it, and prepares it for scaling.

11. **Scaling**
	```cpp
	        base *= 10;
	```
	Increases the scaling factor by a factor of 10 with each iteration.

12. **Return Statement**
	```cpp
	    return n * base - n0;
	```
	Returns the scaled and modified value of `n` minus the original value `n0`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity depends on the number of digits in n, which is O(log n), and we perform operations on these digits.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only store a few variables during the calculation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/)

---
{{< youtube NoGK4582ey8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
