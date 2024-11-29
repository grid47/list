
+++
authors = ["grid47"]
title = "Leetcode 1351: Count Negative Numbers in a Sorted Matrix"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1351: Count Negative Numbers in a Sorted Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an m x n matrix grid, sorted in non-increasing order both row-wise and column-wise. Your task is to determine how many negative numbers are present in the grid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a matrix grid where each row and each column is sorted in non-increasing order.
- **Example:** `For example, [[7,5,3,-1], [6,4,2,-1], [3,1,-2,-3], [-1,-2,-3,-4]].`
- **Constraints:**
	- 1 <= m, n <= 100
	- -100 <= grid[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the count of negative numbers in the grid.
- **Example:** `For example, in the matrix [[7,5,3,-1], [6,4,2,-1], [3,1,-2,-3], [-1,-2,-3,-4]], the output would be 8.`
- **Constraints:**
	- The result should be an integer representing the number of negative numbers.

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the number of negative numbers in the grid by efficiently checking each row and column.

- 1. Iterate through each row of the matrix.
- 2. For each row, use binary search or a direct check to count how many negative numbers are present.
- 3. Sum the results for each row to get the total count of negative numbers.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is always sorted in non-increasing order both row-wise and column-wise.
- All values in the grid are integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: grid = [[7, 5, 3, -1], [6, 4, 2, -1], [3, 1, -2, -3], [-1, -2, -3, -4]]`  \
  **Explanation:** In this matrix, there are 8 negative numbers, which are counted and returned as the result.

- **Input:** `Example 2: grid = [[1, 0], [0, 0]]`  \
  **Explanation:** This matrix has no negative numbers, so the result is 0.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we can leverage the sorted nature of the matrix. By using binary search or row-wise iteration, we can quickly count the number of negative numbers.

### Initial Thoughts 💭
- The matrix is sorted both row-wise and column-wise, which provides an opportunity for optimization.
- We can use binary search to quickly locate the first negative number in each row.
- Iterating over the rows and applying binary search to count negative numbers in each row would reduce the time complexity.
{{< dots >}}
### Edge Cases 🌐
- Empty grid: No numbers, so the result should be 0.
- Grid with the maximum size (100x100): The algorithm should handle this efficiently.
- Grids with no negative numbers: Ensure the result is 0.
- Ensure that the solution handles both small and large grids within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int countNegatives(vector<vector<int>>& grid) {
    int res = 0, m = grid.size();
    for(int i = 0; i < m; i++) {
        auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
        if(*grid[i].rbegin() > -1) continue;
        res += it - grid[i].rbegin();
    }
    return res;
}
```

This function calculates the count of negative numbers in a sorted 2D grid by iterating through each row and using reverse iterators with the `upper_bound` function to identify negative values efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countNegatives(vector<vector<int>>& grid) {
	```
	Declares a function that takes a 2D vector grid as input and returns the count of negative numbers.

2. **Variable Initialization**
	```cpp
	    int res = 0, m = grid.size();
	```
	Initializes a result variable to store the count of negative numbers and retrieves the number of rows in the grid.

3. **Loop Iteration**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Iterates through each row of the grid using a for loop.

4. **Upper Bound Search**
	```cpp
	        auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
	```
	Uses the `upper_bound` function on the reversed row to locate the first element greater than -1.

5. **Condition Check**
	```cpp
	        if(*grid[i].rbegin() > -1) continue;
	```
	Skips processing the row if the last element is greater than -1, as it indicates no negatives are present.

6. **Negative Count Update**
	```cpp
	        res += it - grid[i].rbegin();
	```
	Adds the count of negative numbers in the current row to the result by calculating the difference between iterators.

7. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total count of negative numbers found in the grid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m log n) where m is the number of rows and n is the number of columns.
- **Average Case:** O(m log n) for each row search.
- **Worst Case:** O(m log n) due to the binary search for each row.

The binary search reduces the time complexity of checking each row from O(n) to O(log n), making it more efficient for larger grids.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1) as we are only using a constant amount of extra space.

The space complexity is constant, as we only need a few variables to keep track of the count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
