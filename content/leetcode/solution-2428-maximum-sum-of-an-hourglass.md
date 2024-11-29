
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
comments = true
+++



---
You are given a matrix of integers. An hourglass is defined as a pattern of elements in the matrix where the middle element is surrounded by 3 elements above it and 3 elements below it, forming the shape of an hourglass. Your task is to find the maximum sum of all hourglasses that can be formed within the matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an m x n matrix of integers.
- **Example:** `grid = [[4, 1, 2, 3], [5, 2, 1, 4], [9, 7, 1, 6], [2, 5, 8, 3]]`
- **Constraints:**
	- 3 <= m, n <= 150
	- 0 <= grid[i][j] <= 106

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of the elements of an hourglass in the matrix.
- **Example:** `Output: 30`
- **Constraints:**
	- The matrix will always have at least one hourglass.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the maximum sum of an hourglass in the given matrix.

- 1. Iterate over all possible positions in the matrix where an hourglass can be formed.
- 2. For each valid position, calculate the sum of the hourglass and track the maximum sum.
- 3. Return the maximum sum found.
{{< dots >}}
### Problem Assumptions ✅
- The matrix will always have dimensions where an hourglass can be formed (at least 3x3).
- All elements in the matrix are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[6, 2, 1, 3], [4, 2, 1, 5], [9, 2, 8, 7], [4, 1, 2, 9]]`  \
  **Explanation:** The hourglass with the maximum sum is formed by the cells 6, 2, 1, 2, 9, 2, 8. The sum is 30.

{{< dots >}}
## Approach 🚀
The goal is to find all possible hourglasses in the matrix and calculate the sum of each, keeping track of the maximum sum encountered.

### Initial Thoughts 💭
- An hourglass requires a 3x3 area of the matrix to form.
- The problem can be solved by iterating through the matrix and calculating the sum of each hourglass formed by a center element.
{{< dots >}}
### Edge Cases 🌐
- Not applicable since m, n >= 3.
- Ensure the solution handles large matrices (up to 150x150) efficiently.
- If all elements are the same, the maximum hourglass sum will be the sum of a typical hourglass.
- The matrix will always have dimensions sufficient to form at least one hourglass.
{{< dots >}}
## Code 💻
```cpp
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
```

This function calculates the maximum sum of a 3x3 subgrid in a given grid, including the center element and its surrounding neighbors.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxSum(vector<vector<int>>& grid) {
	```
	This line defines the function 'maxSum' which takes a 2D vector grid as input and returns the maximum sum of a 3x3 subgrid.

2. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Here, 'm' and 'n' are initialized to represent the number of rows and columns of the grid.

3. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable 'ans' is initialized to 0 to store the maximum sum found during the iteration.

4. **Outer Loop Setup**
	```cpp
	    for(int i = 1; i < m - 1; i++)
	```
	This is the outer loop, starting at index 1 and ending at m-2, to avoid out-of-bounds access while checking neighboring cells.

5. **Inner Loop Setup**
	```cpp
	    for(int j = 1; j < n - 1; j++) {
	```
	This is the inner loop, starting at index 1 and ending at n-2, ensuring we do not go out of bounds while checking the grid elements.

6. **Sum Calculation**
	```cpp
	        int sum = grid[i][j] + grid[i - 1][j] + grid[i + 1][j] +
	```
	Here, the sum of the center element (grid[i][j]) and its vertical neighbors (top and bottom) is calculated.

7. **Sum Calculation Continued**
	```cpp
	            grid[i - 1][j - 1] + grid[i - 1][j + 1] +
	```
	The sum is extended to include the diagonal neighbors (top-left and top-right).

8. **Sum Calculation Continued**
	```cpp
	            grid[i + 1][j - 1] + grid[i + 1][j + 1];
	```
	The sum is completed by adding the diagonal neighbors (bottom-left and bottom-right).

9. **Max Sum Update**
	```cpp
	        ans = max(ans, sum);
	```
	Here, the maximum of the current 'ans' and the newly calculated 'sum' is stored back in 'ans'.

10. **Return Statement**
	```cpp
	    return ans;
	```
	After all iterations, the function returns the maximum sum found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) as we need to iterate through the matrix and calculate the sum of hourglasses at each valid position.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only store a few variables for the maximum sum and do not use extra space proportional to the matrix size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/)

---
{{< youtube u4dYdiBXAjI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
