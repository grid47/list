
+++
authors = ["grid47"]
title = "Leetcode 1155: Number of Dice Rolls With Target Sum"
date = "2024-07-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1155: Number of Dice Rolls With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "y1PUOTOr-qU"
youtube_upload_date="2021-02-21"
youtube_thumbnail="https://i.ytimg.com/vi/y1PUOTOr-qU/maxresdefault.jpg"
comments = true
+++



---
You have `n` dice, each with `k` faces numbered from 1 to `k`. You need to calculate the number of ways to roll the dice such that the sum of the dice equals a target value. Return the result modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three integers: `n`, `k`, and `target` representing the number of dice, the number of faces on each die, and the target sum, respectively.
- **Example:** `Input: [1, 6, 3]
Output: 1`
- **Constraints:**
	- 1 <= n, k <= 30
	- 1 <= target <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the number of ways to roll the dice such that their sum equals the target, modulo (10^9 + 7).
- **Example:** `Output: 1`
- **Constraints:**
	- Return the result modulo (10^9 + 7).

{{< dots >}}
### Core Logic 🔍
**Goal:** To solve this problem, we will use dynamic programming to count the number of ways to roll the dice such that their sum equals the target.

- Initialize a DP table where dp[i][j] represents the number of ways to get a sum of `j` using `i` dice.
- For each die, iterate through all possible face values from 1 to `k` and update the DP table for the target sum.
- Finally, return the value at dp[n][target] after taking modulo (10^9 + 7).
{{< dots >}}
### Problem Assumptions ✅
- The dice have faces numbered from 1 to k, with no other numbers on the faces.
- The dice rolls are independent, meaning the result of one die does not affect the others.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [2, 6, 7]
Output: 6`  \
  **Explanation:** You have two dice, each with 6 faces. The possible sums to reach 7 are 1+6, 2+5, 3+4, 4+3, 5+2, and 6+1. Hence, the output is 6.

{{< dots >}}
## Approach 🚀
We use dynamic programming (DP) to solve this problem by building up the solution from smaller subproblems. Each state in the DP table will represent the number of ways to achieve a certain sum using a given number of dice.

### Initial Thoughts 💭
- The problem is similar to the coin change problem, where we need to count the number of ways to form a target sum with limited values.
- A dynamic programming approach seems ideal for this problem because it involves calculating the number of ways to get a certain sum using a combination of dice.
{{< dots >}}
### Edge Cases 🌐
- Handle edge cases where n = 1, target = 1, or other minimal inputs.
- Ensure the solution handles the maximum constraints of n = 30 and target = 1000.
- Consider cases where the target is either very small or very large compared to n and k.
- The solution must be optimized to avoid brute force solutions due to the constraints.
{{< dots >}}
## Code 💻
```cpp
int dp[31][1001] = {};
int numRollsToTarget(int d, int f, int target, int res = 0) {
    if (d == 0 || target <= 0) return d == target;
    if (dp[d][target]) return dp[d][target] - 1;
    for (auto i = 1; i <= f; ++i)
        res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
    dp[d][target] = res + 1;
    return res;
}
```

This code defines a dynamic programming solution to the 'Number of Dice Rolls With Target Sum' problem. It uses a 2D DP array `dp` to store results of subproblems and computes the number of ways to roll dice such that their sum equals the target, using recursion with memoization.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int dp[31][1001] = {};
	```
	Declare a 2D array `dp` for storing the results of subproblems. The dimensions are chosen based on the maximum number of dice and target sum (31 dice and 1001 possible target sums).

2. **Method Definition**
	```cpp
	int numRollsToTarget(int d, int f, int target, int res = 0) {
	```
	Define the function `numRollsToTarget` which calculates the number of ways to roll `d` dice with `f` faces each to achieve a target sum.

3. **Base Case**
	```cpp
	    if (d == 0 || target <= 0) return d == target;
	```
	Base case: If there are no dice left or the target is non-positive, return whether the current number of dice is exactly equal to the target (this handles both the end of the recursion and edge cases).

4. **Memoization**
	```cpp
	    if (dp[d][target]) return dp[d][target] - 1;
	```
	Check if the result for this subproblem has already been computed. If it has, return the cached result (memoization) to avoid redundant calculations.

5. **Looping through Dice Faces**
	```cpp
	    for (auto i = 1; i <= f; ++i)
	```
	Loop through each possible face of the dice (from 1 to `f`) and recursively calculate the number of ways to reach the target by reducing the number of dice and the target sum.

6. **Recursive Calculation**
	```cpp
	        res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
	```
	For each face of the die, recursively call `numRollsToTarget` for `d-1` dice and `target-i`. The result is accumulated in `res`, and the modulo operation ensures that the result stays within the bounds of large numbers (mod 1,000,000,007).

7. **Memoize Result**
	```cpp
	    dp[d][target] = res + 1;
	```
	Memoize the result for this subproblem by storing the calculated value in the `dp` array at the current number of dice (`d`) and the target (`target`).

8. **Return Result**
	```cpp
	    return res;
	```
	Return the result of the current subproblem, which is the number of ways to roll `d` dice to reach the target sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * target * k) where n is the number of dice, target is the target sum, and k is the number of faces on each die.
- **Average Case:** O(n * target * k).
- **Worst Case:** O(n * target * k).

The solution requires iterating over all dice and all face values for each possible target sum.

### Space Complexity 💾
- **Best Case:** O(n * target) for storing the DP table.
- **Worst Case:** O(n * target) where n is the number of dice and target is the target sum.

The space complexity is determined by the DP table used to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/)

---
{{< youtube y1PUOTOr-qU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
