
+++
authors = ["grid47"]
title = "Leetcode 54: Spiral Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 54: Spiral Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/54.webp"
youtube = "fcn8qkRcFVM"
youtube_upload_date="2024-06-14"
youtube_thumbnail="https://i.ytimg.com/vi/fcn8qkRcFVM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/54.webp" 
    alt="A glowing spiral matrix, gently unfurling and revealing numbers in soft concentric rings."
    caption="Solution to LeetCode 54: Spiral Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an m x n matrix, return all the elements of the matrix in spiral order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D matrix with m rows and n columns.
- **Example:** `["matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]"]`
- **Constraints:**
	- 1 <= m, n <= 10
	- -100 <= matrix[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of integers that represents the elements of the matrix in spiral order.
- **Example:** `["[1, 2, 3, 6, 9, 8, 7, 4, 5]"]`
- **Constraints:**
	- The output should be a list containing all the elements in spiral order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To traverse the matrix in a spiral order and collect the elements.

- 1. Initialize variables to track the boundaries of the matrix: top, bottom, left, and right.
- 2. Use a while loop to traverse in the spiral order until all boundaries are processed.
- 3. Traverse from left to right along the top row, then top to bottom along the right column.
- 4. Traverse from right to left along the bottom row, then bottom to top along the left column.
- 5. Continue adjusting the boundaries inward and repeat the traversal until all elements are collected.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is guaranteed to have at least one row and one column.
{{< dots >}}
## Examples 🧩
- **Input:** `["matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]"]`  \
  **Explanation:** The elements are traversed in a spiral order, starting from the top-left corner and moving right, down, left, and up, until all elements are visited.

- **Input:** `["matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]"]`  \
  **Explanation:** The elements are collected in a spiral order: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7].

{{< dots >}}
## Approach 🚀
The approach uses a systematic way to traverse the matrix in a spiral order by adjusting boundaries after processing each row and column.

### Initial Thoughts 💭
- We need to handle four directions: left to right, top to bottom, right to left, and bottom to top.
- As we traverse the matrix, the boundaries (top, bottom, left, right) will be reduced progressively.
- This problem can be solved in linear time by maintaining and updating boundaries during the traversal.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the matrix will have at least one row and one column.
- The solution must handle the maximum matrix size (10x10) efficiently.
- If the matrix contains negative values or zeros, the traversal should still proceed in the same spiral order.
- The solution must be efficient in terms of time and space complexity.
{{< dots >}}
## Code 💻
```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    vector<int> result;
    
    while (top <= bottom && left <= right) {
        // Traverse Right
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Traverse Down
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Traverse Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse Up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}
```

This code efficiently traverses a matrix in a spiral order and returns the elements in a vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
	```
	This line declares a function named `spiralOrder` that takes a 2D vector `matrix` as input and returns a vector containing the elements in spiral order.

2. **Variable Initialization**
	```cpp
	    int rows = matrix.size(), cols = matrix[0].size();
	```
	This line initializes variables `rows` and `cols` to store the number of rows and columns in the matrix, respectively.

3. **Boundary Initialization**
	```cpp
	    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
	```
	This line initializes variables to track the boundaries of the current spiral traversal: `top`, `bottom`, `left`, and `right`.

4. **Result Vector Initialization**
	```cpp
	    vector<int> result;
	```
	This line initializes an empty vector `result` to store the spiral order elements.

5. **Spiral Traversal Loop**
	```cpp
	    while (top <= bottom && left <= right) {
	```
	This loop continues as long as there are elements to be traversed in the spiral.

6. **Traverse Right**
	```cpp
	        for (int i = left; i <= right; i++) {
	            result.push_back(matrix[top][i]);
	        }
	```
	This loop traverses the top row from left to right, adding elements to the `result` vector.

7. **Update Top Boundary**
	```cpp
	        top++;
	```
	After traversing the top row, the `top` boundary is incremented to exclude the processed row.

8. **Traverse Down**
	```cpp
	        for (int i = top; i <= bottom; i++) {
	            result.push_back(matrix[i][right]);
	        }
	```
	This loop traverses the rightmost column from top to bottom, adding elements to the `result` vector.

9. **Update Right Boundary**
	```cpp
	        right--;
	```
	After traversing the right column, the `right` boundary is decremented to exclude the processed column.

10. **Traverse Left (Conditional)**
	```cpp
	        if (top <= bottom) {
	```
	This conditional check ensures that there's still a row to traverse from right to left.

11. **Traverse Left**
	```cpp
	            for (int i = right; i >= left; i--) {
	                result.push_back(matrix[bottom][i]);
	            }
	```
	This loop traverses the bottom row from right to left, adding elements to the `result` vector.

12. **Update Bottom Boundary**
	```cpp
	            bottom--;
	```
	After traversing the bottom row, the `bottom` boundary is decremented to exclude the processed row.

13. **Traverse Up (Conditional)**
	```cpp
	        if (left <= right) {
	```
	This conditional check ensures that there's still a column to traverse from bottom to top.

14. **Traverse Up**
	```cpp
	            for (int i = bottom; i >= top; i--) {
	                result.push_back(matrix[i][left]);
	            }
	```
	This loop traverses the leftmost column from bottom to top, adding elements to the `result` vector.

15. **Update Left Boundary**
	```cpp
	            left++;
	```
	After traversing the left column, the `left` boundary is incremented to exclude the processed column.

16. **Return Result**
	```cpp
	    return result;
	```
	The function returns the `result` vector containing the elements in spiral order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The algorithm processes every element of the matrix exactly once, so the time complexity is O(m * n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) for storing the result, but the in-place traversal itself requires O(1) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/spiral-matrix/description/)

---
{{< youtube fcn8qkRcFVM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
