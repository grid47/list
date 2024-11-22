
+++
authors = ["grid47"]
title = "Leetcode 2428: Maximum Sum of an Hourglass"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2428: Maximum Sum of an Hourglass in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "u4dYdiBXAjI"
youtube_upload_date="2022-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/u4dYdiBXAjI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i = 1; i < m - 1; i++)
        for(int j = 1; j < n - 1; j++) {
            
            int sum = grid[i][j] + grid[i - 1][j] + grid[i + 1][j] +
                grid[i - 1][j - 1] + grid[i - 1][j + 1] +
                grid[i + 1][j - 1] + grid[i + 1][j + 1];
            
            ans = max(ans, sum);
            
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the maximum sum of an hourglass shape within a 2D grid. An hourglass shape in the grid consists of seven elements: the center element, the two elements directly above and below it, and the two diagonal elements surrounding it. The task is to calculate the sum of these seven elements for all possible hourglasses in the grid and return the maximum sum encountered.

### Approach

We can break the problem into two main components: 

1. **Understanding the Hourglass Shape**:
   - In a given 2D grid, an hourglass shape is formed by selecting one center element and then picking its adjacent elements (both vertically and diagonally). 
   - For a grid element `grid[i][j]`, the hourglass elements are:
     - The center: `grid[i][j]`
     - The top: `grid[i-1][j-1]`, `grid[i-1][j]`, `grid[i-1][j+1]`
     - The bottom: `grid[i+1][j-1]`, `grid[i+1][j]`, `grid[i+1][j+1]`
   
   The sum of these seven elements is what we need to compute for each possible hourglass.

2. **Traversing the Grid**:
   - We need to traverse the grid and compute the sum for each possible hourglass. An hourglass can only start at positions where the center is not at the boundary of the grid. Hence, the valid indices for the center element are `i` ranging from `1` to `m-2` and `j` ranging from `1` to `n-2`, where `m` is the number of rows and `n` is the number of columns of the grid.
   - For each valid center, we compute the sum of the seven elements and track the maximum sum encountered.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int m = grid.size(), n = grid[0].size();
int ans = 0;
```

- We first get the number of rows `m` and columns `n` of the grid using `grid.size()` and `grid[0].size()`, respectively.
- We initialize a variable `ans` to store the maximum hourglass sum. Initially, we set `ans` to 0.

#### Step 2: Loop Over the Valid Centers

```cpp
for(int i = 1; i < m - 1; i++) 
    for(int j = 1; j < n - 1; j++) {
```

- We use two nested loops to iterate over all potential valid centers for the hourglasses. The outer loop iterates over `i` from `1` to `m-2` (to avoid the first and last rows), and the inner loop iterates over `j` from `1` to `n-2` (to avoid the first and last columns). 
- This ensures that we are only considering the valid centers for the hourglasses and not at the grid boundaries.

#### Step 3: Calculate the Hourglass Sum

```cpp
int sum = grid[i][j] + grid[i - 1][j] + grid[i + 1][j] +
          grid[i - 1][j - 1] + grid[i - 1][j + 1] +
          grid[i + 1][j - 1] + grid[i + 1][j + 1];
```

- For each valid center element `grid[i][j]`, we compute the sum of the seven elements that form the hourglass:
  - The center: `grid[i][j]`
  - The top: `grid[i - 1][j - 1]`, `grid[i - 1][j]`, `grid[i - 1][j + 1]`
  - The bottom: `grid[i + 1][j - 1]`, `grid[i + 1][j]`, `grid[i + 1][j + 1]`

#### Step 4: Update Maximum Sum

```cpp
ans = max(ans, sum);
```

- After computing the sum of the hourglass at the current center, we update `ans` to store the maximum of the current `ans` and the calculated `sum`.

#### Step 5: Return the Result

```cpp
return ans;
```

- After traversing the entire grid and calculating the sum for all possible hourglasses, we return `ans`, which holds the maximum hourglass sum.

### Complexity Analysis

#### Time Complexity:

- **Outer Loops**: The two nested loops iterate over all valid centers in the grid. The valid centers range from `1` to `m-2` for rows and `1` to `n-2` for columns. Thus, the number of valid centers is approximately `(m - 2) * (n - 2)`. 
- **Computing the Hourglass Sum**: For each valid center, we compute the sum of the seven elements in constant time (`O(1)`), since accessing the elements in the grid takes constant time.

Thus, the overall time complexity is:
\[
O((m - 2) \times (n - 2)) = O(m \times n)
\]
In the worst case, where we consider all elements of the grid, the time complexity is proportional to the size of the grid.

#### Space Complexity:

- The solution uses only a few variables (`m`, `n`, `ans`, and `sum`) and does not require additional data structures that grow with the input size. Therefore, the space complexity is constant:
\[
O(1)
\]

### Example Walkthrough

Let's walk through a simple example to see how the algorithm works.

#### Example 1: `grid = [[1, 1, 1], [1, 9, 1], [1, 1, 1]]`

1. **Initialization**:
   - The grid has dimensions `3 x 3`, so `m = 3` and `n = 3`.
   - We initialize `ans = 0`.

2. **First (and only) Hourglass**:
   - The only valid center is `grid[1][1]`, with value `9`.
   - The sum of the hourglass centered at `(1, 1)` is:
     ```
     9 + 1 + 1 + 1 + 1 + 1 + 1 = 15
     ```
   - We update `ans` to `15`.

3. **Result**:
   - The maximum hourglass sum is `15`.

#### Example 2: `grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]`

1. **Initialization**:
   - The grid has dimensions `3 x 3`, so `m = 3` and `n = 3`.
   - We initialize `ans = 0`.

2. **First (and only) Hourglass**:
   - The only valid center is `grid[1][1]`, with value `5`.
   - The sum of the hourglass centered at `(1, 1)` is:
     ```
     5 + 2 + 8 + 4 + 6 + 7 + 9 = 41
     ```
   - We update `ans` to `41`.

3. **Result**:
   - The maximum hourglass sum is `41`.

### Conclusion

This solution efficiently calculates the maximum sum of an hourglass in a 2D grid by iterating over valid centers and summing the elements of the hourglass shape for each valid center. The time complexity is proportional to the size of the grid, and the space complexity is constant. This approach is optimal for the given problem constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/)

---
{{< youtube u4dYdiBXAjI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
