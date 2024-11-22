
+++
authors = ["grid47"]
title = "Leetcode 3122: Minimum Number of Operations to Satisfy Conditions"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3122: Minimum Number of Operations to Satisfy Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LLDe54TfbMs"
youtube_upload_date="2024-04-21"
youtube_thumbnail="https://i.ytimg.com/vi/LLDe54TfbMs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int m, n;
    vector<vector<int>> frq, mem;
    
    int dp(int i, int prv) {
        if(i == frq.size()) return 0;
        if(mem[i][prv + 1] != -1) return mem[i][prv + 1];

        int ans = INT_MAX;
        for(int j = 0; j <= 9; j++) {
            if(j == prv) continue;
            ans = min(ans, m - frq[i][j] + dp(i + 1, j));
        }

        return mem[i][prv + 1] = ans;
    }
    
    int minimumOperations(vector<vector<int>>& grid) {
        
        m = grid.size(), n = grid[0].size();
        
        frq.resize(n, vector<int>(10, 0));
        mem.resize(n, vector<int>(11, -1));
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            frq[i][grid[j][i]]++;
        }
        
        return dp(0, -1);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the minimum number of operations required to change the numbers in a grid such that no two adjacent numbers (vertically or horizontally) are the same. In each operation, we can change any number in the grid to any digit from 0 to 9. Our goal is to determine the least number of operations needed to achieve this condition.

Given a grid, the solution needs to compute how to transform it with the fewest changes such that no adjacent cells contain the same number.

### Approach

The approach used in the code is a **dynamic programming (DP)** approach, where the problem is broken down into smaller subproblems. We start by considering each column of the grid and the number of changes required for making the grid valid as we traverse row by row.

The key idea behind the approach is:
1. **Dynamic Programming to Minimize Changes**: We aim to minimize the number of changes required to transform the grid into a valid one, where adjacent cells do not contain the same digit.
2. **Frequency Count for Each Column**: We maintain a frequency count of digits in each column of the grid. This helps us to compute the number of changes needed for each potential digit choice.
3. **Memoization**: To avoid redundant calculations, we use a memoization table (`mem`) to store intermediate results. This table is used to record the minimum number of operations for a given state in the dynamic programming recursion.
4. **Column-wise Optimization**: The algorithm optimizes the choice of digits for each column in a way that minimizes the total number of operations, ensuring that no two adjacent cells are the same digit.

### Code Breakdown

#### Step 1: Initialize Variables
```cpp
int m, n;
vector<vector<int>> frq, mem;
```
- `m`: The number of rows in the grid.
- `n`: The number of columns in the grid.
- `frq`: A 2D vector that stores the frequency of each digit (0-9) for each column.
- `mem`: A 2D memoization table that stores the minimum number of operations needed to make the grid valid, starting from a given row and previous column's digit.

#### Step 2: Frequency Counting
```cpp
for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
        frq[i][grid[j][i]]++;
    }
```
- We iterate over each cell in the grid and populate the `frq` array. This array keeps track of how many times each digit (0-9) appears in each column. This helps us determine the number of changes needed when choosing a particular digit for each column.

#### Step 3: The Recursive `dp` Function
```cpp
int dp(int i, int prv) {
    if(i == frq.size()) return 0;
    if(mem[i][prv + 1] != -1) return mem[i][prv + 1];

    int ans = INT_MAX;
    for(int j = 0; j <= 9; j++) {
        if(j == prv) continue;
        ans = min(ans, m - frq[i][j] + dp(i + 1, j));
    }

    return mem[i][prv + 1] = ans;
}
```
- **Base Case**: If we have processed all columns (`i == frq.size()`), no more changes are needed, so return 0.
- **Memoization**: Before performing any calculations, we check if the result for the current state (`i`, `prv`) has already been computed (i.e., if `mem[i][prv + 1] != -1`). If it has, we return the stored result to avoid redundant computation.
- **Recursive Case**: For each column, we consider each possible digit (`j` from 0 to 9) and check if it is different from the previous digit (`prv`). If it is different, we calculate the number of changes required for that digit (`m - frq[i][j]`), which is the number of cells in the current column that need to be changed. We then recursively compute the minimum number of changes for the remaining columns, storing the result in `mem[i][prv + 1]`.
- **Result**: We return the minimum number of changes required for the entire grid, starting from the first column with no previous digit (`-1`).

#### Step 4: `minimumOperations` Function
```cpp
int minimumOperations(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    
    frq.resize(n, vector<int>(10, 0));
    mem.resize(n, vector<int>(11, -1));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            frq[i][grid[j][i]]++;
        }
    
    return dp(0, -1);
}
```
- **Grid Size Initialization**: The dimensions of the grid (`m` and `n`) are initialized.
- **Frequency and Memoization Initialization**: The `frq` array is resized to store the frequency of digits in each column, and the `mem` array is resized to store the memoized results for each state.
- **Populate Frequency Array**: We loop through the grid to populate the `frq` array.
- **Start DP Calculation**: We invoke the `dp` function, starting with the first column (`i = 0`) and no previous digit (`prv = -1`).

#### Step 5: Final Output
The result of the `dp` function is returned, which gives the minimum number of operations needed to make the grid valid.

### Complexity

#### Time Complexity:
- **O(m * n * 10)**: 
  - We are iterating through each column of the grid (`n` columns) and each possible digit (0-9). For each state, we calculate the minimum changes by checking each of the 10 possible digits for the current column.
  - The memoization table has dimensions `n x 11`, so at most we perform `O(n * 11)` operations for memoization, and for each state, we check 10 digits.

#### Space Complexity:
- **O(n * 10)**: 
  - The space complexity is driven by the `frq` and `mem` arrays, each of size `n x 10` for storing the frequency of digits and the memoized results for each state.
  - The space complexity is proportional to the size of the grid and the number of possible digits (0-9).

### Conclusion

The solution uses a dynamic programming approach to efficiently compute the minimum number of operations required to transform the grid such that no adjacent cells have the same digit. By leveraging memoization and tracking the frequency of digits in each column, the algorithm is able to minimize redundant calculations and achieve an optimal solution.

This approach ensures that the problem is solved in a time complexity that scales well with the grid size, and it efficiently handles the constraint of transforming the grid with the fewest operations. The use of dynamic programming is crucial in breaking down the problem into manageable subproblems, making it possible to compute the result in an optimal manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/description/)

---
{{< youtube LLDe54TfbMs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
