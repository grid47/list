
+++
authors = ["grid47"]
title = "Leetcode 1914: Cyclically Rotating a Grid"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1914: Cyclically Rotating a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3dCs1ZHDNjM"
youtube_upload_date="2021-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/3dCs1ZHDNjM/maxresdefault.jpg"
comments = true
+++



---
You are given an m x n integer matrix grid, where both m and n are even integers, and an integer k. The matrix consists of several concentric layers, and each layer can be thought of as a circular band of numbers. A cyclic rotation of a layer is done by shifting all its elements counter-clockwise by one position. You are asked to return the matrix after applying k cyclic rotations to each of its layers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an m x n matrix grid and an integer k representing the number of rotations to be performed on each layer of the matrix.
- **Example:** `grid = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], k = 2`
- **Constraints:**
	- 2 <= m, n <= 50
	- m and n are even integers
	- 1 <= grid[i][j] <= 5000
	- 1 <= k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the matrix after applying k cyclic rotations to its layers.
- **Example:** `[[3, 4, 8, 12], [2, 11, 10, 16], [1, 7, 6, 15], [5, 9, 13, 14]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To perform k cyclic rotations on each layer of the matrix.

- Divide the matrix into concentric layers.
- For each layer, apply k cyclic rotations, adjusting for the layer's length.
- After applying the rotations, update the matrix with the new values.
{{< dots >}}
### Problem Assumptions ✅
- The matrix will always have even dimensions for both m and n, ensuring that every matrix has complete layers.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], k = 2`  \
  **Explanation:** The grid is divided into concentric layers. After 2 counter-clockwise rotations, the elements shift as shown in the output.

{{< dots >}}
## Approach 🚀
We need to cyclically rotate the elements in each layer by k positions. This requires extracting each layer, performing the rotation, and then placing the rotated layer back into the matrix.

### Initial Thoughts 💭
- We need to break the grid into its concentric layers and perform the rotation on each layer independently.
- The rotation can be optimized by reducing the number of unnecessary rotations using modulo arithmetic on the length of the layer.
{{< dots >}}
### Edge Cases 🌐
- The matrix will never be empty based on problem constraints.
- Ensure that the solution handles large values for k efficiently by using modulo arithmetic.
- If k is larger than the length of the layer, use modulo to reduce the number of rotations.
- The number of rows and columns are always even and between 2 and 50.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    // cout << m << " " << n;
    // k = k % (m * n);
    for(int i = 0; i < min(m, n) / 2; i++) {            


        int l = i + 0, r = n - 1 - i;
        int t = i + 0, b = m - 1 - i;

        int total = 2 * (r - l) + 2 * (b - t);
        int rot = k % total;
        if(l < r && t < b) {

            for(int j = 0; j < rot; j++) {

                int tmp = grid[t][l];
                for(int p = l; p < r; p++)
                    grid[t][p] = grid[t][p + 1];

                for(int p = t; p < b; p++)
                    grid[p][r] = grid[p + 1][r];

                for(int p = r; p > l; p--)
                    grid[b][p] = grid[b][p-1];

                for(int p = b; p > t; p--)
                    grid[p][l] = grid[p-1][l];

                grid[t + 1][l] = tmp;
            }

        }
    }
    return grid;
}
```

This function rotates a grid of integers by a given number of positions, k, in a clockwise direction.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
	```
	Defines the function 'rotateGrid' that takes a 2D vector (grid) and an integer (k) as input.

2. **Variable Declaration**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Declares two variables 'm' and 'n' to store the dimensions (rows and columns) of the grid.

3. **Loop**
	```cpp
	    for(int i = 0; i < min(m, n) / 2; i++) {
	```
	Starts a loop that iterates over the layers of the grid, from outermost to innermost.

4. **Variable Initialization**
	```cpp
	        int l = i + 0, r = n - 1 - i;
	```
	Initializes 'l' (left index) and 'r' (right index) for the current layer.

5. **Variable Initialization**
	```cpp
	        int t = i + 0, b = m - 1 - i;
	```
	Initializes 't' (top index) and 'b' (bottom index) for the current layer.

6. **Computation**
	```cpp
	        int total = 2 * (r - l) + 2 * (b - t);
	```
	Calculates the total number of elements in the current layer of the grid.

7. **Computation**
	```cpp
	        int rot = k % total;
	```
	Calculates the effective number of rotations needed for the current layer.

8. **Condition Check**
	```cpp
	        if(l < r && t < b) {
	```
	Checks if the current layer is a valid rectangle (ensuring there are more than one row and column).

9. **Loop**
	```cpp
	            for(int j = 0; j < rot; j++) {
	```
	Loops to rotate the elements in the current layer 'rot' times.

10. **Variable Assignment**
	```cpp
	                int tmp = grid[t][l];
	```
	Saves the value of the top-left element of the layer into 'tmp'.

11. **Inner Loop**
	```cpp
	                for(int p = l; p < r; p++)
	```
	Loops through the top row of the current layer, shifting elements to the right.

12. **Element Shifting**
	```cpp
	                    grid[t][p] = grid[t][p + 1];
	```
	Shifts the element at 'p' to the right by one position.

13. **Inner Loop**
	```cpp
	                for(int p = t; p < b; p++)
	```
	Loops through the right column of the current layer, shifting elements downward.

14. **Element Shifting**
	```cpp
	                    grid[p][r] = grid[p + 1][r];
	```
	Shifts the element at 'p' downward by one position.

15. **Inner Loop**
	```cpp
	                for(int p = r; p > l; p--)
	```
	Loops through the bottom row of the current layer, shifting elements to the left.

16. **Element Shifting**
	```cpp
	                    grid[b][p] = grid[b][p-1];
	```
	Shifts the element at 'p' to the left by one position.

17. **Inner Loop**
	```cpp
	                for(int p = b; p > t; p--)
	```
	Loops through the left column of the current layer, shifting elements upward.

18. **Element Shifting**
	```cpp
	                    grid[p][l] = grid[p-1][l];
	```
	Shifts the element at 'p' upward by one position.

19. **Element Assignment**
	```cpp
	                grid[t + 1][l] = tmp;
	```
	Assigns the saved value 'tmp' to the position that was vacated during the shift.

20. **Return**
	```cpp
	    return grid;
	```
	Returns the rotated grid after all layers have been processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

We iterate through each element in each layer once to apply rotations.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

We store the elements of the layer in a temporary list, so the space complexity is proportional to the size of the matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/cyclically-rotating-a-grid/description/)

---
{{< youtube 3dCs1ZHDNjM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
