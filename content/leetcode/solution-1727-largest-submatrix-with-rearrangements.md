
+++
authors = ["grid47"]
title = "Leetcode 1727: Largest Submatrix With Rearrangements"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1727: Largest Submatrix With Rearrangements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NYyIVuSCfOA"
youtube_upload_date="2023-11-26"
youtube_thumbnail="https://i.ytimg.com/vi/NYyIVuSCfOA/maxresdefault.jpg"
comments = true
+++



---
You are given a binary matrix with dimensions `m x n` consisting of 0's and 1's. You can rearrange the columns of the matrix in any order. The task is to find the area of the largest submatrix within the matrix where every element is 1 after optimally reordering the columns.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a matrix of size `m x n` where each element is either 0 or 1.
- **Example:** `Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]`
- **Constraints:**
	- m == matrix.length
	- n == matrix[i].length
	- 1 <= m * n <= 10^5
	- matrix[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the area of the largest submatrix consisting entirely of 1's after rearranging the columns optimally.
- **Example:** `Output: 4`
- **Constraints:**
	- The output should be a single integer representing the area of the largest submatrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the largest submatrix of 1's after rearranging the columns of the binary matrix optimally.

- 1. For each column, compute how many consecutive 1's are there for each row. Store this information in a new matrix.
- 2. For each row, sort the column values in descending order to group larger submatrices of 1's together.
- 3. For each row, compute the maximum area of submatrix of 1's by multiplying the number of consecutive 1's by the number of columns.
- 4. Return the maximum area found.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the matrix are either 0 or 1.
- Reordering the columns means you can rearrange the entire matrix as you wish.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]`  \
  **Explanation:** By rearranging the columns optimally, we can form a 2x2 submatrix of 1's. Therefore, the output is 4.

- **Input:** `Input: matrix = [[1,0,1,0,1]]`  \
  **Explanation:** After rearranging the columns, we can form a submatrix with three 1's in a row, resulting in an area of 3.

{{< dots >}}
## Approach 🚀
The problem can be solved by counting consecutive 1's in each column and sorting them to form the largest submatrices of 1's. We can then calculate the maximum area of submatrices by considering different rows and column orders.

### Initial Thoughts 💭
- We need to calculate the number of consecutive 1's in each column, then rearrange the columns to maximize the area of 1's submatrix.
- Sorting the column values by descending order helps to group larger 1's together, making it easier to compute the largest submatrix.
{{< dots >}}
### Edge Cases 🌐
- Empty matrices are not a valid input, as the matrix must contain at least one element.
- Ensure that the solution can handle large matrices efficiently.
- The matrix may contain a row or column of all 0's, which should be handled appropriately.
- The solution must be able to handle up to 100,000 elements in the matrix.
{{< dots >}}
## Code 💻
```cpp
int largestSubmatrix(vector<vector<int>>& mtx) {
    int n = mtx[0].size(), m = mtx.size();
    vector<vector<int>> one(m, vector<int>(n, 0));
    int res = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if (mtx[j][i] == 1) { cnt++; } 
            else { cnt = 0; }
            one[j][i] = cnt;
        }
    }
    
    for(int i = 0; i < m; i++)
    sort(one[i].rbegin(), one[i].rend());

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            
            res = max(res, one[i][j] * (j + 1));
            
        }
    }
    return res;
}
```

This function finds the area of the largest submatrix in a binary matrix `mtx`, where each cell has a value of either 0 or 1. The algorithm computes the largest rectangle formed by consecutive 1s in each column, and for each row, it sorts the heights in decreasing order to maximize the area.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int largestSubmatrix(vector<vector<int>>& mtx) {
	```
	The function `largestSubmatrix` is defined, taking a 2D vector `mtx` as input, which represents a binary matrix. The goal is to calculate the largest area of a submatrix consisting only of 1s.

2. **Matrix Dimensions**
	```cpp
	    int n = mtx[0].size(), m = mtx.size();
	```
	The dimensions of the matrix are extracted: `n` is the number of columns, and `m` is the number of rows.

3. **Matrix Initialization**
	```cpp
	    vector<vector<int>> one(m, vector<int>(n, 0));
	```
	A 2D vector `one` is initialized with the same dimensions as `mtx`, where each element is set to 0. This will store the heights of 1s in each column for each row.

4. **Result Initialization**
	```cpp
	    int res = 0;
	```
	The variable `res` is initialized to 0. This will keep track of the maximum area found.

5. **Outer Loop - Columns**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The outer loop starts to iterate over each column `i` in the matrix `mtx`.

6. **Count Initialization**
	```cpp
	        int cnt = 0;
	```
	The variable `cnt` is initialized to 0. It will be used to count the consecutive 1s in each column.

7. **Inner Loop - Rows**
	```cpp
	        for(int j = 0; j < m; j++) {
	```
	The inner loop starts to iterate over each row `j` in the matrix `mtx`.

8. **Count Update**
	```cpp
	            if (mtx[j][i] == 1) { cnt++; } 
	```
	If the current element `mtx[j][i]` is 1, `cnt` is incremented to keep track of consecutive 1s.

9. **Count Reset**
	```cpp
	            else { cnt = 0; }
	```
	If the current element is 0, `cnt` is reset to 0 as the consecutive 1s are broken.

10. **Store Heights**
	```cpp
	            one[j][i] = cnt;
	```
	The height of consecutive 1s for row `j` and column `i` is stored in the `one` matrix at position `one[j][i]`.

11. **Inner Loop End**
	```cpp
	        }
	```
	End of the inner loop for iterating through rows.

12. **Sort Heights**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	A loop iterates through each row `i` of the matrix `one`.

13. **Sort Row**
	```cpp
	    sort(one[i].rbegin(), one[i].rend());
	```
	Each row of `one` is sorted in reverse order to maximize the area of the submatrix formed by the heights.

14. **Second Loop Start**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	The second loop starts again to iterate through the rows of the matrix `one`.

15. **Third Loop Start**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	The third loop starts to iterate through the columns of the matrix `one`.

16. **Area Calculation**
	```cpp
	            res = max(res, one[i][j] * (j + 1));
	```
	For each position `one[i][j]`, the area of the rectangle is calculated by multiplying the height `one[i][j]` by its width `(j + 1)`. The maximum area found is stored in `res`.

17. **Return Result**
	```cpp
	    return res;
	```
	The result `res`, which contains the maximum area of the largest submatrix, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n log n), since sorting the columns for each row takes log n time.
- **Average Case:** O(m * n log n), as sorting will take O(log n) for each row.
- **Worst Case:** O(m * n log n), the worst case where all rows need to be processed and sorted.

The time complexity is dominated by the sorting step for each row.

### Space Complexity 💾
- **Best Case:** O(m * n), due to the space required for the new matrix and the input matrix.
- **Worst Case:** O(m * n), as we need additional space for storing the consecutive 1's matrix.

The space complexity is linear in terms of the number of elements in the matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/)

---
{{< youtube NYyIVuSCfOA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
