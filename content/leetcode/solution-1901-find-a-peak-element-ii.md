
+++
authors = ["grid47"]
title = "Leetcode 1901: Find a Peak Element II"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1901: Find a Peak Element II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
In a given 2D grid, a peak element is an element that is greater than all of its adjacent elements (left, right, top, and bottom). You are given an m x n matrix `mat` where no two adjacent elements are equal. Your task is to find and return the coordinates of any peak element. The grid is surrounded by a perimeter filled with -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A matrix of integers, mat, representing the grid.
- **Example:** `mat = [[10, 20, 15], [21, 30, 14], [7, 16, 32]]`
- **Constraints:**
	- m == mat.length
	- n == mat[i].length
	- 1 <= m, n <= 500
	- 1 <= mat[i][j] <= 10^5
	- No two adjacent cells are equal.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the coordinates of any peak element in the grid.
- **Example:** `[1, 1]`
- **Constraints:**
	- Coordinates of any peak element in the grid.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the coordinates of any peak element.

- Perform binary search on columns.
- For each column, find the row with the largest element.
- Check if the element is greater than its left and right neighbors.
- Adjust the search space based on comparisons with neighbors.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is non-empty and valid.
- There will always be at least one peak element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mat = [[10, 20, 15], [21, 30, 14], [7, 16, 32]]`  \
  **Explanation:** The element at [1, 1] (30) is a peak because it is greater than its neighbors (20, 15, 21, 14).

{{< dots >}}
## Approach 🚀
We can use binary search to find a peak element in O(m log(n)) or O(n log(m)) time.

### Initial Thoughts 💭
- The problem can be approached using a divide-and-conquer technique, such as binary search.
- By reducing the search space at each step, we can efficiently find a peak element.
{{< dots >}}
### Edge Cases 🌐
- An empty matrix is not allowed based on constraints.
- Handle matrices with dimensions close to 500 x 500.
- Ensure proper handling when elements are at the edges of the matrix.
- The matrix is guaranteed to have no two adjacent equal cells.
{{< dots >}}
## Code 💻
```cpp
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    
    int l = 0, r = n - 1;
    
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        
        int row = 0;
        for(int i = 0; i < m; i++)
            row = mat[i][mid] >= mat[row][mid]? i: row;
        
        int isRightLarger = mid + 1 <= r ? mat[row][mid + 1] > mat[row][mid]: false;
        int isLeftLarger = mid - 1 >= l  ? mat[row][mid - 1] > mat[row][mid]: false;            
        
        if(!isRightLarger && !isLeftLarger)
            return vector<int>{row, mid};
        
        if(isRightLarger) l = mid + 1;
        else             r = mid - 1;
        
    }
    return vector<int>{-1, -1};
}
```

This is the complete function to find a peak element in a 2D grid using a binary search approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findPeakGrid(vector<vector<int>>& mat) {
	```
	The function 'findPeakGrid' is defined to take a 2D matrix as input and return a vector of integers representing the peak's coordinates.

2. **Variable Initialization**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	Here, we initialize 'm' to the number of rows and 'n' to the number of columns in the matrix.

3. **Binary Search Setup**
	```cpp
	    int l = 0, r = n - 1;
	```
	We initialize two variables 'l' and 'r' to represent the left and right boundaries for the binary search on columns.

4. **While Loop**
	```cpp
	    while(l <= r) {
	```
	This while loop will continue to iterate as long as there is a valid range between 'l' and 'r'.

5. **Mid Calculation**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Here, we calculate the middle column index 'mid' to split the matrix and search for the peak.

6. **Row Search**
	```cpp
	        int row = 0;
	```
	We initialize a variable 'row' to track the row that contains the maximum value at the current 'mid' column.

7. **Iterating Rows**
	```cpp
	        for(int i = 0; i < m; i++)
	```
	This for loop iterates over each row of the matrix to find the row where the element in the 'mid' column is the largest.

8. **Row Selection**
	```cpp
	            row = mat[i][mid] >= mat[row][mid]? i: row;
	```
	If the current element in the 'mid' column is greater than the previous maximum, update the 'row' variable.

9. **Right Comparison**
	```cpp
	        int isRightLarger = mid + 1 <= r ? mat[row][mid + 1] > mat[row][mid]: false;
	```
	We check if the element to the right of 'mid' in the same row is larger. If it is, we will move the binary search range to the right.

10. **Left Comparison**
	```cpp
	        int isLeftLarger = mid - 1 >= l  ? mat[row][mid - 1] > mat[row][mid]: false;
	```
	We check if the element to the left of 'mid' in the same row is larger. If it is, we will move the binary search range to the left.

11. **Peak Check**
	```cpp
	        if(!isRightLarger && !isLeftLarger)
	```
	If neither the left nor the right elements are larger, we have found the peak element, so we return the coordinates.

12. **Returning Peak**
	```cpp
	            return vector<int>{row, mid};
	```
	Return the coordinates of the peak element as a vector.

13. **Adjusting Search Range**
	```cpp
	        if(isRightLarger) l = mid + 1;
	```
	If the right neighbor is larger, update the left boundary 'l' to search the right half of the matrix.

14. **Adjusting Search Range**
	```cpp
	        else             r = mid - 1;
	```
	If the left neighbor is larger, update the right boundary 'r' to search the left half of the matrix.

15. **Return Invalid Result**
	```cpp
	    return vector<int>{-1, -1};
	```
	If no peak is found, return an invalid result indicating failure to find a peak.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m log(n))
- **Average Case:** O(m log(n))
- **Worst Case:** O(m log(n))

Binary search is applied on columns, ensuring logarithmic time complexity in one dimension.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we do not use any additional space for storing intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-a-peak-element-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
