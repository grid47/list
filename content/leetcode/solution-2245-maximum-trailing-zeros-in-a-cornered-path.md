
+++
authors = ["grid47"]
title = "Leetcode 2245: Maximum Trailing Zeros in a Cornered Path"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2245: Maximum Trailing Zeros in a Cornered Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QMRHGd9ftz8"
youtube_upload_date="2022-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/QMRHGd9ftz8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
array<int, 2> operator+(const array<int, 2> &r1, const array<int, 2> &r2) { return { r1[0] + r2[0], r1[1] + r2[1] }; }

array<int, 2> operator-(const array<int, 2> &r1, const array<int, 2> &r2) { return { r1[0] - r2[0], r1[1] - r2[1] }; }

int pairs (const array<int, 2> &p) { return min(p[0], p[1]); }

class Solution {
public:
    int fact(int i, int j) {
        return i % j ? 0 : 1 + fact(i/j, j);
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        
        vector<vector<array<int, 2>>> h(m, vector<array<int, 2>>(n + 1)), v(m+1, vector<array<int, 2>>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int t = grid[i][j];
                array<int, 2> node = { fact(t, 2), fact(t, 5) };
                h[i][j + 1] = h[i][j] + node;
                v[i + 1][j] = v[i][j] + node;
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                array<int, 2> h1 = h[i][j], 
                h2 = h[i][n] - h[i][j+1],
                v1 = v[i+1][j],
                v2 = v[m][j] - v[i][j];
                res = max({res, pairs(v1+h1), pairs(v1+h2), pairs(v2+h1), pairs(v2+h2)});
                
            }
            }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem is to find the maximum number of trailing zeros in any possible subgrid of a given 2D grid of integers. A trailing zero in a number results from factors of 10, which is the product of the prime factors 2 and 5. For each number in the grid, we need to count how many times it can be divided by 2 and 5. The task is to determine which subgrid produces the maximum number of trailing zeros when considering the factors of 2 and 5 across all possible subgrids.

### Approach
To solve this problem, we will use the following steps:

1. **Factorization**:
   Every number can be broken down into prime factors, primarily focusing on the factors 2 and 5 because trailing zeros are produced by multiples of 10, and 10 = 2 * 5. For each number in the grid, we calculate how many times it can be divided by 2 (`fact(i, 2)`) and by 5 (`fact(i, 5)`).

2. **Prefix Sum Arrays**:
   To efficiently calculate the number of trailing zeros in any subgrid, we use prefix sum arrays. We maintain two 2D arrays (`h` for horizontal sums and `v` for vertical sums) to store cumulative counts of the factors 2 and 5 up to each point in the grid.

3. **Maximize Trailing Zeros**:
   The idea is to calculate the number of trailing zeros in all possible subgrids by considering different combinations of horizontal and vertical segments from the `h` and `v` arrays. We then track the maximum number of trailing zeros across all these subgrids.

4. **Efficient Calculation**:
   By using the prefix sum arrays, we can quickly compute the number of trailing zeros for any subgrid without recalculating sums from scratch each time. The goal is to compute these sums in `O(1)` time for each query after preprocessing.

### Code Breakdown (Step by Step)

1. **Operator Overloading for Addition and Subtraction of Factor Pairs**:
   We overload the `+` and `-` operators for arrays of size 2, which store the counts of factors 2 and 5 for a number. This allows us to easily combine the factor counts from different parts of the grid:
   ```cpp
   array<int, 2> operator+(const array<int, 2> &r1, const array<int, 2> &r2) { 
       return { r1[0] + r2[0], r1[1] + r2[1] }; 
   }

   array<int, 2> operator-(const array<int, 2> &r1, const array<int, 2> &r2) { 
       return { r1[0] - r2[0], r1[1] - r2[1] }; 
   }
   ```

2. **Counting Factors (2 and 5) for a Number**:
   The `fact` function is designed to count how many times a number can be divided by a given factor (`2` or `5`). It uses recursive division to calculate the number of times the number can be divided by the factor until it's no longer divisible:
   ```cpp
   int fact(int i, int j) {
       return i % j ? 0 : 1 + fact(i / j, j);
   }
   ```

3. **Grid Initialization**:
   The grid `grid` is a 2D matrix where each element is an integer. We initialize two 2D arrays `h` (horizontal sums) and `v` (vertical sums), where each element stores an array of two integers: the count of factors of 2 and the count of factors of 5 for the corresponding position in the grid.

   We compute these values while iterating over the grid, and at each position `(i, j)`, we update `h[i][j + 1]` and `v[i + 1][j]` by adding the factor counts of the current number to the cumulative sums in the horizontal and vertical directions.

4. **Prefix Sum Calculation**:
   This step uses the prefix sums to calculate the total factors of 2 and 5 for each subgrid efficiently. The arrays `h` and `v` hold the cumulative sums for factors of 2 and 5, allowing us to quickly compute the factors for any subgrid:
   ```cpp
   for(int i = 0; i < m; i++) {
       for(int j = 0; j < n; j++) {
           int t = grid[i][j];
           array<int, 2> node = { fact(t, 2), fact(t, 5) };
           h[i][j + 1] = h[i][j] + node;
           v[i + 1][j] = v[i][j] + node;
       }
   }
   ```

5. **Finding the Maximum Number of Trailing Zeros**:
   For each position `(i, j)`, we calculate the possible number of trailing zeros by considering the factors of 2 and 5 from four subgrids:
   - Subgrid 1: Uses the factors from the top-left portion of the grid.
   - Subgrid 2: Uses the factors from the top-right portion of the grid.
   - Subgrid 3: Uses the factors from the bottom-left portion of the grid.
   - Subgrid 4: Uses the factors from the bottom-right portion of the grid.

   We compute the number of trailing zeros for each of these four subgrids and update the result with the maximum number of trailing zeros:
   ```cpp
   for(int i = 0; i < m; i++) {
       for(int j = 0; j < n; j++) {
           array<int, 2> h1 = h[i][j], 
               h2 = h[i][n] - h[i][j+1],
               v1 = v[i+1][j],
               v2 = v[m][j] - v[i][j];
           res = max({res, pairs(v1 + h1), pairs(v1 + h2), pairs(v2 + h1), pairs(v2 + h2)});
       }
   }
   ```

6. **Return the Result**:
   The final result, `res`, stores the maximum number of trailing zeros for any subgrid. We return this value as the output of the function:
   ```cpp
   return res;
   ```

### Complexity

#### Time Complexity:
- The time complexity for computing the factor counts for each element in the grid is `O(m * n)` where `m` is the number of rows and `n` is the number of columns in the grid.
- The `fact` function computes the factors for each element, which takes `O(log i)` time where `i` is the value of the element. Since the grid elements can be large, we assume that the factorization is handled efficiently.
- The total complexity for the grid processing and calculation of trailing zeros for all subgrids is `O(m * n)`.

#### Space Complexity:
- We use two 2D arrays, `h` and `v`, each of size `m * n`. Therefore, the space complexity is `O(m * n)`.

### Conclusion
The approach efficiently computes the maximum number of trailing zeros in any subgrid of a given 2D grid of integers by leveraging prefix sum arrays to compute the factors of 2 and 5. The solution is optimized for both time and space complexity, handling large grids and large numbers efficiently. By using prefix sums and operator overloading for array operations, the solution provides a clean and efficient way to tackle the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/description/)

---
{{< youtube QMRHGd9ftz8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
