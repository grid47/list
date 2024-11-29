
+++
authors = ["grid47"]
title = "Leetcode 2400: Number of Ways to Reach a Position After Exactly k Steps"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2400: Number of Ways to Reach a Position After Exactly k Steps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gFsI5OR-GfQ"
youtube_upload_date="2022-09-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gFsI5OR-GfQ/maxresdefault.webp"
comments = true
+++



---
You are standing at a starting position `startPos` on an infinite number line, and you need to reach a destination `endPos` in exactly `k` steps. In each step, you can move either one position to the left or one position to the right. Your task is to find the number of different ways to reach `endPos` from `startPos` in exactly `k` steps. Since the number of ways can be very large, return the result modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the integers `startPos`, `endPos`, and `k`. These represent the starting position, the destination, and the number of steps respectively.
- **Example:** `startPos = 3, endPos = 5, k = 4`
- **Constraints:**
	- 1 <= startPos, endPos, k <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of ways to reach `endPos` from `startPos` in exactly `k` steps, modulo 10^9 + 7.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the number of valid ways to move from `startPos` to `endPos` in exactly `k` steps, adhering to the movement rules (left or right in each step).

- 1. Calculate the absolute difference `d` between `startPos` and `endPos`.
- 2. Use dynamic programming or recursion with memoization to count the number of ways to reach the target by moving either left or right.
- 3. Return the count modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input values are valid and within the specified range.
- The number of ways can be very large, so modulo operation must be used.
{{< dots >}}
## Examples 🧩
- **Input:** `startPos = 1, endPos = 2, k = 3`  \
  **Explanation:** We can reach position 2 from 1 in exactly 3 steps in three distinct ways: 1 -> 2 -> 3 -> 2, 1 -> 2 -> 1 -> 2, and 1 -> 0 -> 1 -> 2. Therefore, the output is 3.

- **Input:** `startPos = 2, endPos = 5, k = 10`  \
  **Explanation:** It is impossible to reach position 5 from position 2 in exactly 10 steps. Hence, the output is 0.

{{< dots >}}
## Approach 🚀
The approach involves using a dynamic programming technique or recursion with memoization to count the number of valid ways to move from `startPos` to `endPos` in `k` steps.

### Initial Thoughts 💭
- The problem can be reduced to finding paths with exactly `k` steps on a number line, which can be modeled as a dynamic programming problem.
- We need to calculate the number of paths efficiently, considering both left and right moves at each step.
{{< dots >}}
### Edge Cases 🌐
- This problem does not have an empty input case since the input size is guaranteed to be within the range 1 to 1000.
- For large values of `k`, the recursive approach should be optimized using dynamic programming or memoization to avoid recalculating results for the same subproblems.
- If `startPos` and `endPos` are the same, we must ensure that we move in such a way that we still perform exactly `k` steps.
- Dynamic programming or memoization should be used to efficiently handle inputs close to the upper limit.
{{< dots >}}
## Code 💻
```cpp
int numberOfWays(int start, int end, int k) {
    return dfs(k, abs(start - end));
}

int dfs(int k, int d) {
    if (d >= k) return d == k;
    if(dp[k][d] == 0)
        dp[k][d] = (1 + dfs(k-1, d + 1) + dfs(k -1, abs(d -1))) % mod;
    
    return dp[k][d] -1;
    
}
```

This code implements a recursive approach to finding the number of ways to reach a destination by using dynamic programming and depth-first search (DFS). The `numberOfWays` function calculates the number of possible ways given `start`, `end`, and `k`, using the helper function `dfs`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfWays(int start, int end, int k) {
	```
	Defines the function `numberOfWays` which takes three parameters: `start`, `end`, and `k`. The function will return the number of ways to reach from `start` to `end` with `k` steps.

2. **Recursive Call**
	```cpp
	    return dfs(k, abs(start - end));
	```
	This line calls the helper function `dfs`, passing `k` and the absolute difference between `start` and `end` as arguments.

3. **Helper Function Definition**
	```cpp
	int dfs(int k, int d) {
	```
	Defines the helper function `dfs`, which takes two parameters: `k` (number of steps remaining) and `d` (the current distance to cover). It will return the number of ways to complete the journey recursively.

4. **Base Case Check**
	```cpp
	    if (d >= k) return d == k;
	```
	Checks if the distance `d` is greater than or equal to `k`. If it is, it checks if `d` is exactly equal to `k` and returns 1 if true (base case), otherwise returns 0.

5. **Memoization Check**
	```cpp
	    if(dp[k][d] == 0)
	```
	Checks if the value of `dp[k][d]` has been previously computed. If it hasn't been computed (i.e., it is 0), the code proceeds to calculate it.

6. **Recursion and Memoization**
	```cpp
	        dp[k][d] = (1 + dfs(k-1, d + 1) + dfs(k -1, abs(d -1))) % mod;
	```
	Calculates the number of ways recursively by making two recursive calls to `dfs`: one where the distance increases by 1 (`d + 1`) and another where the distance decreases by 1 (`abs(d - 1)`). The result is stored in `dp[k][d]` and taken modulo `mod`.

7. **Return Value**
	```cpp
	    return dp[k][d] -1;
	```
	Returns the computed result from the `dp` array, decrementing it by 1 (to account for the last unnecessary computation step).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k), where k is the number of steps. This is when the number of recursive calls is minimized due to memoization.
- **Average Case:** O(k * d), where d is the distance between `startPos` and `endPos`. This depends on the recursive branching.
- **Worst Case:** O(k * d), where d is the maximum possible distance. Memoization ensures that redundant calculations are avoided.

The time complexity is determined by the number of recursive calls and the distance between `startPos` and `endPos`.

### Space Complexity 💾
- **Best Case:** O(1), if no memoization is used and the problem is solved directly.
- **Worst Case:** O(k * d), where d is the distance between `startPos` and `endPos`. This is the space used by the memoization table.

The space complexity is primarily determined by the size of the memoization table.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/)

---
{{< youtube gFsI5OR-GfQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
