
+++
authors = ["grid47"]
title = "Leetcode 2017: Grid Game"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2017: Grid Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "N4wDSOw65hI"
youtube_upload_date="2021-09-26"
youtube_thumbnail="https://i.ytimg.com/vi/N4wDSOw65hI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottom = 0;
        int n = grid[0].size();
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            top -= grid[0][i];
            ans = min(ans, max(top, bottom));
            bottom+= grid[1][i];
      }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we need to find the minimum possible score for the second player in a two-row grid game. Each player can choose a column, and the goal is to minimize the score for the second player, who collects points from the bottom row after the first player has selected their column. The first player selects a column, and the score for the second player is the sum of points in the bottom row minus any points from the column that the first player chooses.

Given a grid of dimensions 2 x n, where each cell contains a non-negative integer representing points, the task is to calculate the minimum score for the second player after the first player has made their selection.

### Approach

To solve this problem, we can follow these steps:

1. **Initial Calculations**: Compute the total points in the top row. We will also maintain a running total of points collected by the second player in the bottom row.

2. **Iterate through the Columns**: For each column, simulate the first player picking that column and compute the resultant score for the second player:
   - Deduct the points from the selected column in the top row from the total points.
   - Add the points from the current column in the bottom row to a running total.
   - Calculate the maximum score for the second player after this selection.

3. **Track the Minimum Score**: Keep track of the minimum score observed after considering all possible selections by the first player.

4. **Return the Result**: Finally, return the minimum score found.

### Code Breakdown (Step by Step)

Let's analyze the implementation:

```cpp
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
```
- We define a class named `Solution` with a public method `gridGame` that takes a 2D vector of integers as its parameter, representing the grid.

```cpp
        long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
```
- We calculate the total points in the top row using the `accumulate` function from the STL, initializing it with `0LL` to ensure we are working with long long integers.

```cpp
        long long bottom = 0;
        int n = grid[0].size();
```
- We initialize `bottom` to zero, which will be used to accumulate the points from the bottom row. We also retrieve the number of columns `n` in the grid.

```cpp
        long long ans = LLONG_MAX;
```
- We set `ans` to the maximum possible long long value, as we are looking for the minimum score.

```cpp
        for(int i = 0; i < n; i++) {
```
- We start a loop that will iterate over each column in the grid.

```cpp
            top -= grid[0][i];
```
- For each column, we deduct the points in the top row from `top`, simulating the first player picking that column.

```cpp
            ans = min(ans, max(top, bottom));
```
- We compute the maximum score between the updated `top` and the accumulated `bottom` points, then update `ans` to hold the minimum score observed.

```cpp
            bottom += grid[1][i];
```
- We add the points from the bottom row in the current column to `bottom` for the next iteration.

```cpp
        }
        return ans;
    }
};
```
- The loop concludes, and we return the minimum score `ans`.

### Complexity

The time complexity of this algorithm is O(n), where n is the number of columns in the grid, as we are iterating through the columns just once. The space complexity is O(1) since we are using a constant amount of extra space for our variables.

### Conclusion

In summary, the `gridGame` method efficiently calculates the minimum score for the second player in the grid game by leveraging a single pass through the columns. This approach is optimal and avoids the need for nested iterations, making it suitable for larger inputs.

By keeping track of the total points in the top row and maintaining a running total for the bottom row, we can quickly evaluate the potential outcomes for each column selection made by the first player. This demonstrates the power of cumulative calculations and optimal score tracking in algorithm design.

This solution not only provides an effective means to solve the problem but also illustrates key concepts in dynamic programming and greedy algorithms. The implementation is straightforward and easy to follow, serving as a great learning tool for those looking to deepen their understanding of such algorithms.

In real-world applications, similar approaches can be employed in various scenarios where resource allocation and optimization are key factors. Understanding how to manipulate and evaluate potential outcomes based on choices made in sequential structures is a valuable skill for any programmer or data analyst.

[`Link to LeetCode Lab`](https://leetcode.com/problems/grid-game/description/)

---
{{< youtube N4wDSOw65hI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
