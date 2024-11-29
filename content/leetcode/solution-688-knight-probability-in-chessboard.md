
+++
authors = ["grid47"]
title = "Leetcode 688: Knight Probability in Chessboard"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 688: Knight Probability in Chessboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/688.webp"
youtube = "hNovJsUbNjo"
youtube_upload_date="2020-09-25"
youtube_thumbnail="https://i.ytimg.com/vi/hNovJsUbNjo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/688.webp" 
    alt="A chessboard where the knight’s possible moves are calculated, with the highest probability glowing softly."
    caption="Solution to LeetCode 688: Knight Probability in Chessboard Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an n x n chessboard and a knight that starts at a given position (row, column). The knight moves exactly k times and can randomly choose one of eight possible knight moves at each step. The task is to determine the probability that the knight remains on the board after completing all k moves.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of four integers: n (the size of the chessboard), k (the number of moves), row (the starting row), and column (the starting column).
- **Example:** `n = 4, k = 3, row = 1, column = 1`
- **Constraints:**
	- 1 <= n <= 25
	- 0 <= k <= 100
	- 0 <= row, column <= n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a floating point number representing the probability that the knight remains on the chessboard after k moves.
- **Example:** `0.1250`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the probability that after exactly k moves, the knight stays on the chessboard.

- Use a depth-first search (DFS) approach to explore all possible knight moves.
- Memoize results to optimize redundant calculations.
- At each step, check if the knight remains within the bounds of the chessboard.
{{< dots >}}
### Problem Assumptions ✅
- The knight will always move randomly and uniformly at each step.
- The chessboard is represented by a 2D grid with indices from 0 to n-1.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: n = 4, k = 3, row = 1, column = 1`  \
  **Explanation:** The knight has multiple possible moves, but only a subset of these will keep the knight on the board. After exploring all moves, the probability is 0.125.

{{< dots >}}
## Approach 🚀
We will implement a recursive DFS approach to explore all possible knight movements, using memoization to optimize and prevent recalculating the same state multiple times.

### Initial Thoughts 💭
- The knight has 8 possible moves from any given position.
- The moves can go off the chessboard, so we must handle this case.
- This problem can be solved using a depth-first search (DFS) with memoization to avoid redundant calculations.
{{< dots >}}
### Edge Cases 🌐
- If k = 0, the knight stays at the starting position, so the probability is 1.
- Ensure that the algorithm handles the maximum constraints efficiently.
- If the knight starts at the edge of the board, fewer moves will keep it on the board.
- The problem should handle up to 100 moves efficiently using memoization.
{{< dots >}}
## Code 💻
```cpp
int n;
vector<vector<vector<double>>> memo;
double knightProbability(int n, int k, int row, int col) {
    this->n = n;
    memo.resize(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
    return dfs(k, row, col);
}

double dfs(int k, int i, int j) {

    if(i < 0 || j < 0 || i >= n || j >= n) return 0;
    if(k == 0) return 1;
    if(memo[k][i][j] != 0 ) return memo[k][i][j];

    double res = 0;

    res += 0.125 * dfs(k - 1, i + 1, j - 2);
    res += 0.125 * dfs(k - 1, i + 1, j + 2);
    res += 0.125 * dfs(k - 1, i + 2, j + 1);
    res += 0.125 * dfs(k - 1, i + 2, j - 1);
    res += 0.125 * dfs(k - 1, i - 1, j + 2);
    res += 0.125 * dfs(k - 1, i - 1, j - 2);
    res += 0.125 * dfs(k - 1, i - 2, j + 1);
    res += 0.125 * dfs(k - 1, i - 2, j - 1);

    return memo[k][i][j] = res;
}
```

This code calculates the probability of a knight staying on a chessboard after k moves, starting from a given position. It uses dynamic programming with memoization to optimize repeated calculations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	This initializes the variable 'n', representing the size of the chessboard.

2. **Variable Initialization**
	```cpp
	vector<vector<vector<double>>> memo;
	```
	This initializes the 'memo' 3D vector, which is used to store previously computed probabilities for specific knight positions and moves.

3. **Method Definition**
	```cpp
	double knightProbability(int n, int k, int row, int col) {
	```
	This defines the function 'knightProbability' which calculates the probability of the knight's survival after 'k' moves from a given position (row, col).

4. **Variable Initialization**
	```cpp
	    this->n = n;
	```
	This sets the class variable 'n' to the size of the chessboard passed into the function.

5. **Memoization Setup**
	```cpp
	    memo.resize(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
	```
	This resizes the 'memo' vector to accommodate all 'k' possible moves, with dimensions based on the size of the chessboard.

6. **Recursive Call**
	```cpp
	    return dfs(k, row, col);
	```
	This calls the helper function 'dfs' (depth-first search) to recursively calculate the knight's survival probability, starting from the given position.

7. **Method Definition**
	```cpp
	double dfs(int k, int i, int j) {
	```
	This defines the recursive 'dfs' function, which computes the probability of the knight surviving after 'k' moves from position (i, j).

8. **Base Condition**
	```cpp
	    if(i < 0 || j < 0 || i >= n || j >= n) return 0;
	```
	This checks if the knight's position is out of bounds of the chessboard, in which case the probability is 0.

9. **Base Condition**
	```cpp
	    if(k == 0) return 1;
	```
	This checks if there are no remaining moves ('k == 0'), returning 1, as the knight is still on the board.

10. **Memoization**
	```cpp
	    if(memo[k][i][j] != 0 ) return memo[k][i][j];
	```
	This checks if the probability has already been calculated for this state (position and remaining moves). If so, it returns the memoized result.

11. **Variable Declaration**
	```cpp
	    double res = 0;
	```
	This initializes the variable 'res', which will accumulate the total probability for all possible moves.

12. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i + 1, j - 2);
	```
	This recursively calls 'dfs' for the knight's move to position (i + 1, j - 2), contributing 0.125 to the probability.

13. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i + 1, j + 2);
	```
	This recursively calls 'dfs' for the knight's move to position (i + 1, j + 2), contributing 0.125 to the probability.

14. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i + 2, j + 1);
	```
	This recursively calls 'dfs' for the knight's move to position (i + 2, j + 1), contributing 0.125 to the probability.

15. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i + 2, j - 1);
	```
	This recursively calls 'dfs' for the knight's move to position (i + 2, j - 1), contributing 0.125 to the probability.

16. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i - 1, j + 2);
	```
	This recursively calls 'dfs' for the knight's move to position (i - 1, j + 2), contributing 0.125 to the probability.

17. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i - 1, j - 2);
	```
	This recursively calls 'dfs' for the knight's move to position (i - 1, j - 2), contributing 0.125 to the probability.

18. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i - 2, j + 1);
	```
	This recursively calls 'dfs' for the knight's move to position (i - 2, j + 1), contributing 0.125 to the probability.

19. **Recursive Call**
	```cpp
	    res += 0.125 * dfs(k - 1, i - 2, j - 1);
	```
	This recursively calls 'dfs' for the knight's move to position (i - 2, j - 1), contributing 0.125 to the probability.

20. **Return Statement**
	```cpp
	    return memo[k][i][j] = res;
	```
	This stores the calculated probability in the 'memo' array and returns the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k * n^2)
- **Average Case:** O(k * n^2)
- **Worst Case:** O(k * n^2)

The time complexity is O(k * n^2) because we are recursively calculating for each position on the chessboard and each move.

### Space Complexity 💾
- **Best Case:** O(k * n^2)
- **Worst Case:** O(k * n^2)

The space complexity is O(k * n^2) due to memoization storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/knight-probability-in-chessboard/description/)

---
{{< youtube hNovJsUbNjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
