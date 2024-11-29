
+++
authors = ["grid47"]
title = "Leetcode 790: Domino and Tromino Tiling"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 790: Domino and Tromino Tiling in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/790.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/790.webp" 
    alt="A grid being tiled with dominos and trominos, with the valid tiles glowing softly as they’re placed."
    caption="Solution to LeetCode 790: Domino and Tromino Tiling Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a 2 x n grid and two types of tiles: a 2 x 1 domino and a tromino (which can be rotated). You must cover the grid entirely with these tiles. The task is to find the number of possible ways to tile the 2 x n board, modulo 10^9 + 7. Each tile must cover exactly two adjacent squares, and every square must be covered by a tile.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer n, representing the length of the grid.
- **Example:** `n = 4`
- **Constraints:**
	- 1 <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of ways to tile the 2 x n grid, modulo 10^9 + 7.
- **Example:** `Output: 11`
- **Constraints:**
	- The output should be returned as a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the number of ways to tile a 2 x n grid with dominos and trominos, use dynamic programming to compute the number of ways for each grid size up to n.

- Initialize a dynamic programming array where dp[i] stores the number of ways to tile a 2 x i grid.
- Base cases: dp[1] = 1, dp[2] = 2, dp[3] = 5.
- For each i from 4 to n, calculate dp[i] as (2 * dp[i-1] + dp[i-3]) % mod.
- Return dp[n].
{{< dots >}}
### Problem Assumptions ✅
- The input n is always valid, and there are no constraints on the arrangement of the tiles other than that they must fill the grid completely.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3`  \
  **Explanation:** The number of ways to tile a 2 x 3 grid is 5. The five different ways are achieved by combining 2 x 1 dominoes and 2 x 2 trominos in different configurations.

- **Input:** `Input: n = 1`  \
  **Explanation:** There is only one way to tile a 2 x 1 grid, using one 2 x 1 domino. Hence, the output is 1.

{{< dots >}}
## Approach 🚀
We can approach this problem using dynamic programming by building the solution iteratively from smaller subproblems.

### Initial Thoughts 💭
- The problem can be solved efficiently using dynamic programming, where the solution to a problem depends on solutions to smaller subproblems.
- The key observation is that the number of ways to tile a 2 x n grid can be computed using the number of ways to tile smaller grids, leveraging previously computed results.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the input is guaranteed to be a positive integer.
- For large inputs up to n = 1000, the solution should efficiently compute the number of ways using dynamic programming.
- For n = 1 and n = 2, the number of ways to tile the grid is very small (1 and 2 respectively).
- Ensure that all calculations are done modulo 10^9 + 7 to avoid overflow.
{{< dots >}}
## Code 💻
```cpp
int numTilings(int n) {
    int mod = 1e9 + 7;
    vector<long long> v(10001, 0);
    v[1] = 1;
    v[2] = 2;
    v[3] = 5;
    if(n <= 3) return v[n];
    for(int i = 4; i <= n; i++) {
        v[i]  = (2 * v[i-1] + v[i-3]);
        v[i] %= mod;
    }
    return v[n];
}
```

This function calculates the number of ways to tile a 2xN grid using 1x2 dominoes and 2x1 dominoes. The result is computed using dynamic programming and is taken modulo 1e9 + 7.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numTilings(int n) {
	```
	The function 'numTilings' is defined with a parameter 'n', representing the length of the grid.

2. **Modulo Definition**
	```cpp
	    int mod = 1e9 + 7;
	```
	This line defines the modulus 'mod' as 1e9 + 7 to prevent integer overflow and ensure the result is within manageable limits.

3. **Array Initialization**
	```cpp
	    vector<long long> v(10001, 0);
	```
	A vector 'v' of size 10001 is initialized with all values set to 0. This vector will store the number of ways to tile grids of different lengths.

4. **Base Cases**
	```cpp
	    v[1] = 1;
	```
	The base case: there is one way to tile a 2x1 grid (using a single vertical domino).

5. **Base Cases**
	```cpp
	    v[2] = 2;
	```
	The base case: there are two ways to tile a 2x2 grid (using two vertical dominoes or two horizontal dominoes).

6. **Base Cases**
	```cpp
	    v[3] = 5;
	```
	The base case: there are five ways to tile a 2x3 grid. This is derived from the problem constraints.

7. **Early Return for Small n**
	```cpp
	    if(n <= 3) return v[n];
	```
	If 'n' is less than or equal to 3, the function returns the precomputed result from the base cases.

8. **Dynamic Programming Loop**
	```cpp
	    for(int i = 4; i <= n; i++) {
	```
	A loop starts from 4 up to 'n' to calculate the number of ways to tile grids of size 2x4, 2x5, etc., using the recurrence relation.

9. **Recurrence Relation**
	```cpp
	        v[i]  = (2 * v[i-1] + v[i-3]);
	```
	The number of ways to tile a 2x' i' grid is calculated using the recurrence relation: v[i] = 2 * v[i-1] + v[i-3]. This accounts for different ways of filling the grid using smaller grids.

10. **Modulo Operation**
	```cpp
	        v[i] %= mod;
	```
	The result is taken modulo 1e9 + 7 to prevent overflow and ensure it fits within the constraints.

11. **Return Result**
	```cpp
	    return v[n];
	```
	Finally, the function returns the precomputed result for a grid of size 2xN.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the grid.
- **Average Case:** O(n), since we calculate dp[i] for each i from 1 to n.
- **Worst Case:** O(n), where n is the maximum value of 1000.

The time complexity is linear, as we only need to compute the result for each value of i from 1 to n once.

### Space Complexity 💾
- **Best Case:** O(1), if the solution is optimized to use constant space.
- **Worst Case:** O(n), where n is the size of the grid, since we store the number of ways to tile each grid size in the dynamic programming array.

The space complexity is linear, as we store the result for each grid size up to n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/domino-and-tromino-tiling/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
