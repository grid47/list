
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement:
In this problem, we are tasked with finding the probability that a knight, starting from a given position on an `n x n` chessboard, remains on the board after making exactly `k` moves. The knight follows the typical movement rules, which means it can move in an "L" shape: two squares in one direction and one square in a perpendicular direction.

The objective is to compute the probability that after `k` moves, the knight stays within the bounds of the board. The problem can be solved using a **dynamic programming (DP)** approach with **memoization** to efficiently calculate the probability of staying on the board after each move.

### Approach:
To solve this problem, we use a recursive approach with **memoization** to avoid redundant calculations. The recursion explores all possible moves the knight can make, and at each step, it calculates the probability of staying on the board.

- **Recursive DFS**: We use Depth-First Search (DFS) to explore all possible knight moves recursively.
- **Memoization**: The results of previously computed states are cached to avoid redundant calculations, making the solution efficient.
- **Knight’s Movement**: From each position, the knight can move to eight possible new positions. For each of these positions, we recursively calculate the probability that the knight stays on the board after the remaining moves.

### Code Breakdown (Step by Step):

#### 1. **Class Definition**:
```cpp
class Solution {
public:
    int n;
    vector<vector<vector<double>>> memo;
    double knightProbability(int n, int k, int row, int col) {
        this->n = n;
        memo.resize(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
        return dfs(k, row, col);
    }
```
The class `Solution` defines a method to calculate the probability. It first initializes the grid size `n` and the 3D vector `memo` that will store the results of subproblems.

- **Parameters**:
  - `n`: The size of the chessboard (an `n x n` grid).
  - `k`: The number of moves the knight will make.
  - `row` and `col`: The starting position of the knight on the chessboard.
  
The `memo` vector is a 3D matrix where:
- The first dimension represents the number of moves left (`k`).
- The second and third dimensions represent the rows and columns of the board, respectively.

#### 2. **DFS Function**:
```cpp
    double dfs(int k, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= n) return 0;  // If out of bounds, return probability 0.
        if (k == 0) return 1;  // If no moves left, return probability 1 (we are on the board).
        if (memo[k][i][j] != 0) return memo[k][i][j];  // Return cached result if available.

        double res = 0;
```
- The `dfs` function is the recursive function that explores the knight's movements.
- **Base Cases**:
  - If the knight is out of bounds (`i < 0 || j < 0 || i >= n || j >= n`), it returns `0` because the knight has left the board.
  - If there are no moves left (`k == 0`), it returns `1`, meaning the knight is still on the board.
  - If the result has already been computed for the current state (`memo[k][i][j] != 0`), the cached value is returned to save computation time.

#### 3. **Knight’s Movement and Recursive Calls**:
```cpp
        // Recursive calls for all 8 possible knight moves.
        res += 0.125 * dfs(k - 1, i + 1, j - 2);  // Move 1
        res += 0.125 * dfs(k - 1, i + 1, j + 2);  // Move 2
        res += 0.125 * dfs(k - 1, i + 2, j + 1);  // Move 3
        res += 0.125 * dfs(k - 1, i + 2, j - 1);  // Move 4
        res += 0.125 * dfs(k - 1, i - 1, j + 2);  // Move 5
        res += 0.125 * dfs(k - 1, i - 1, j - 2);  // Move 6
        res += 0.125 * dfs(k - 1, i - 2, j + 1);  // Move 7
        res += 0.125 * dfs(k - 1, i - 2, j - 1);  // Move 8
```
- The knight has 8 possible moves from any position, and the probability of each move is `1/8` (since the knight is equally likely to move to any of the 8 positions).
- The `dfs(k - 1, i + dx, j + dy)` represents a recursive call for each possible move, where `dx` and `dy` are the changes in the row and column for each of the knight's moves.

#### 4. **Memoization**:
```cpp
        return memo[k][i][j] = res;  // Store the result in memoization table and return it.
    }
};
```
- After calculating the probability for all 8 possible moves, the result is stored in the `memo` table for the current state (`k` moves left, position `(i, j)`).
- The function then returns the computed probability.

#### 5. **Main Function (`knightProbability`)**:
The main function is the entry point for calculating the knight's probability. It initializes the `memo` table and starts the recursive process by calling `dfs(k, row, col)`.

### Complexity:

#### Time Complexity:
The time complexity of this approach is **O(k * n * n)**, where:
- `k` is the number of moves the knight has to make.
- `n * n` represents the size of the chessboard (since we may need to compute the result for every position on the board).

For each of the `k` moves, we explore 8 possible positions (8 recursive calls), and each of these recursive calls may potentially visit each cell on the board. Memoization ensures that each state is calculated only once, saving time in redundant calls.

#### Space Complexity:
The space complexity is **O(k * n * n)** due to the 3D `memo` table. The depth of the recursion can be at most `k`, and at each recursive step, the board state `(i, j)` is stored for each move count `k`. Therefore, the overall space used is proportional to `k * n * n`.

### Conclusion:
This solution efficiently calculates the probability that a knight stays on the board after `k` moves using a dynamic programming approach with memoization. By leveraging the recursive DFS traversal of all possible moves and storing intermediate results, the algorithm avoids redundant computations, making it efficient even for large values of `n` and `k`. The use of memoization ensures that the time complexity is kept manageable, while the space complexity is proportional to the number of states that need to be stored.

[`Link to LeetCode Lab`](https://leetcode.com/problems/knight-probability-in-chessboard/description/)

---
{{< youtube hNovJsUbNjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
