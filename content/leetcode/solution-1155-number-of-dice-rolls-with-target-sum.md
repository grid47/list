
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int dp[31][1001] = {};
    int numRollsToTarget(int d, int f, int target, int res = 0) {
        if (d == 0 || target <= 0) return d == target;
        if (dp[d][target]) return dp[d][target] - 1;
        for (auto i = 1; i <= f; ++i)
            res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
        dp[d][target] = res + 1;
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem requires calculating the number of ways to reach an exact target sum by rolling a specific number of dice. Each die has `f` faces, numbered from 1 to `f`. The function should return the result modulo \(10^9 + 7\) due to the large number of possible combinations.

The function signature is as follows:

```cpp
int numRollsToTarget(int d, int f, int target)
```

Where:
- `d` represents the number of dice.
- `f` represents the number of faces each die has.
- `target` is the sum we want to achieve by rolling the dice.

### Approach
This code uses dynamic programming (DP) and recursion to solve the problem. The primary idea is to break down the problem of finding the ways to achieve the target sum using `d` dice by recursively examining smaller subproblems with fewer dice and lower target values.

1. **Dynamic Programming Array (dp)**: `dp[d][target]` is a memoization table that stores previously computed results for a given number of dice (`d`) and a given target (`target`). This avoids recalculating the number of ways for the same `d` and `target` combination.

2. **Recursive Calls with Subproblems**: Each recursive call reduces the number of dice (`d`) and the target value by the face value rolled on the die, allowing us to explore all possible outcomes for each roll.

3. **Base Conditions**:
   - **Exact match with zero dice left**: If `d == 0` and `target == 0`, it means that we’ve successfully achieved the target, so we return 1 to count this as a valid way.
   - **Early exit for invalid conditions**: If we run out of dice or the target is non-positive when `d > 0`, it’s impossible to reach the target, so we return 0.

4. **Modulo Constraint**: The result is taken modulo \(10^9 + 7\) in each step to handle large values, as the number of combinations can grow rapidly.

### Code Breakdown (Step by Step)

Let’s walk through each section of the code in detail:

```cpp
class Solution {
public:
    int dp[31][1001] = {};
```
- **Line 1-3**: This is the class definition and declaration of the DP array `dp`. It’s initialized to zero and sized according to the constraints: up to 30 dice and a target of up to 1000.

```cpp
    int numRollsToTarget(int d, int f, int target, int res = 0) {
        if (d == 0 || target <= 0) return d == target;
```
- **Base Cases (Lines 5-6)**:
  - If `d == 0`, the function checks if `target` is also `0`. If both are zero, it means we’ve exactly met the target, so we return `1` (true case). If only one of them is zero, we return `0` (false case) since the target was not reached.

```cpp
        if (dp[d][target]) return dp[d][target] - 1;
```
- **Memoization Check (Line 7)**: If `dp[d][target]` is already computed, the function directly returns it, minus one (to account for initial array zeroing). This saves computational time by avoiding repeated calculations.

```cpp
        for (auto i = 1; i <= f; ++i)
            res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
```
- **Loop through Die Faces (Lines 8-9)**:
  - The loop iterates over all possible face values (`i` from `1` to `f`), attempting each as a potential outcome.
  - For each face value, it recursively calls `numRollsToTarget` with one less die (`d - 1`) and a reduced target (`target - i`). This breakdown allows the function to explore all potential ways to reach the target with `d` dice.

```cpp
        dp[d][target] = res + 1;
        return res;
    }
};
```
- **Memoization Update and Return (Lines 10-11)**:
  - After the loop, the result `res` (total count of ways) is stored in `dp[d][target]`, incremented by 1 to distinguish it from initial zeros in `dp`.
  - Finally, `res` is returned, representing the number of ways to reach the target sum with `d` dice.

### Complexity
1. **Time Complexity**: \(O(d \times \text{target} \times f)\), where `d` is the number of dice, `target` is the desired sum, and `f` is the number of faces per die. Each recursive call processes all `f` faces, making the algorithm efficient for reasonable values.
   
2. **Space Complexity**: \(O(d \times \text{target})\) due to the DP table. This array stores intermediate results, saving time by preventing redundant calculations.

### Conclusion
This `numRollsToTarget` function provides an efficient way to calculate the number of ways to achieve a target sum by rolling dice with a specified number of faces. By using dynamic programming and memoization, the solution avoids redundant calculations, making it suitable for large input sizes. This algorithm is versatile for solving dice probability problems, as it efficiently handles large targets and face values through recursion and modular arithmetic. The solution’s complexity is optimized to prevent excessive calculations and storage, ensuring high performance.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/)

---
{{< youtube y1PUOTOr-qU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
