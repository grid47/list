
+++
authors = ["grid47"]
title = "Leetcode 70: Climbing Stairs"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 70: Climbing Stairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/70.webp"
youtube = "I-R1XsECJu8"
youtube_upload_date="2024-06-01"
youtube_thumbnail="https://i.ytimg.com/vi/I-R1XsECJu8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/70.webp" 
    alt="A glowing staircase with each step symbolizing progress, slowly leading upwards."
    caption="Solution to LeetCode 70: Climbing Stairs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You need to climb a ladder with n steps to reach the top. Each time, you can either climb 1 step or 2 steps. Find the number of distinct ways to climb to the top.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A single integer n, representing the total number of steps in the ladder.
- **Example:** `Input: n = 4`
- **Constraints:**
	- 1 <= n <= 45

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the total number of distinct ways to climb the ladder.
- **Example:** `Output: 5`
- **Constraints:**
	- The output must be a valid integer that corresponds to the number of distinct ways.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the total number of ways to climb the ladder using a dynamic programming approach.

- Define an array dp, where dp[i] represents the number of ways to climb to the ith step.
- Initialize dp[0] = 1 (1 way to stay at the start) and dp[1] = 1 (1 way to climb the first step).
- Iteratively calculate dp[i] for 2 <= i <= n using the relation dp[i] = dp[i-1] + dp[i-2].
- Return dp[n] as the result.
{{< dots >}}
### Problem Assumptions ✅
- The input n is a valid integer.
- There are no additional environmental constraints affecting the problem.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4`  \
  **Explanation:** The number of distinct ways to climb 4 steps is 5, as shown in the example above.

- **Input:** `Input: n = 5`  \
  **Explanation:** The number of distinct ways to climb 5 steps is 8, as shown in the example above.

{{< dots >}}
## Approach 🚀
Use dynamic programming to calculate the number of ways to climb the ladder iteratively.

### Initial Thoughts 💭
- The problem can be broken down recursively: the number of ways to climb n steps depends on the number of ways to climb n-1 and n-2 steps.
- This is similar to the Fibonacci sequence.
- Use an iterative approach with an array to store intermediate results for efficiency.
{{< dots >}}
### Edge Cases 🌐
- Not applicable since the input n is guaranteed to be within the constraints.
- n = 45, the upper limit of the constraint.
- n = 1, the smallest number of steps.
- Ensure the implementation works for both small and large values of n within the range.
{{< dots >}}
## Code 💻
```cpp
int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }

    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }

    return second;
}
```

This code calculates the number of distinct ways to climb n stairs, where you can either take 1 or 2 steps at a time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int climbStairs(int n) {
	```
	This line declares a function named `climbStairs` that takes an integer `n` representing the number of stairs as input and returns the number of distinct ways to climb them.

2. **Base Cases**
	```cpp
	    if (n <= 2) {
	        return n;
	    }
	```
	This block handles the base cases: if `n` is 1 or 2, there's only one way to climb the stairs.

3. **Initialize Variables**
	```cpp
	    int first = 1, second = 2;
	```
	Initialize `first` and `second` to represent the number of ways to climb 1 and 2 stairs, respectively.

4. **Iterative Calculation**
	```cpp
	    for (int i = 3; i <= n; i++) {
	```
	This loop iterates from 3 to `n`, calculating the number of ways to climb `i` stairs.

5. **Calculate Ways to Climb i Stairs**
	```cpp
	        int third = first + second;
	```
	Calculate the number of ways to climb `i` stairs by adding the ways to climb `i-1` and `i-2` stairs.

6. **Update Variables**
	```cpp
	        first = second;
	        second = third;
	```
	Update `first` and `second` for the next iteration.

7. **Return Result**
	```cpp
	    return second;
	```
	After the loop, `second` will hold the number of ways to climb `n` stairs, so return it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each step from 2 to n is computed once.

### Space Complexity 💾
- **Best Case:** O(1) with optimization (using two variables instead of an array).
- **Worst Case:** O(n)

The space required depends on whether an array or two variables are used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/climbing-stairs/description/)

---
{{< youtube I-R1XsECJu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
