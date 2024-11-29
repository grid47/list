
+++
authors = ["grid47"]
title = "Leetcode 2906: Construct Product Matrix"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2906: Construct Product Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "CXuoLKjEWIs"
youtube_upload_date="2023-10-15"
youtube_thumbnail="https://i.ytimg.com/vi/CXuoLKjEWIs/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D integer matrix grid of size n * m. Your task is to calculate a new 2D matrix p of the same size, where each element p[i][j] is the product of all elements in grid except for grid[i][j]. The result for each element should be taken modulo 12345.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D matrix grid with dimensions n * m, where each element grid[i][j] is an integer.
- **Example:** `grid = [[2, 3], [4, 5]]`
- **Constraints:**
	- 1 <= n == grid.length <= 10^5
	- 1 <= m == grid[i].length <= 10^5
	- 2 <= n * m <= 10^5
	- 1 <= grid[i][j] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D matrix where each element p[i][j] is the product of all other elements in grid[i][j], modulo 12345.
- **Example:** `For input grid = [[2, 3], [4, 5]], the output is [[20, 15], [12, 10]].`
- **Constraints:**
	- The output matrix must have the same dimensions as the input grid.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the product for each element in the matrix, excluding the element itself, and take the result modulo 12345.

- Initialize two matrices xx and yy. Iterate over the grid to fill xx with products of elements from top-left to bottom-right, and yy with products from bottom-right to top-left.
- For each element p[i][j], calculate its value by multiplying the corresponding values from xx and yy, modulo 12345.
{{< dots >}}
### Problem Assumptions ✅
- Matrix dimensions are reasonable, meaning n * m <= 10^5.
- Elements in the matrix are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[12345], [2], [1]]`  \
  **Explanation:** For each element, calculate the product of all elements except for the current one, taking care to compute modulo 12345.

{{< dots >}}
## Approach 🚀
The approach involves calculating two matrices, one storing products from the top-left to bottom-right and the other from bottom-right to top-left. The final product matrix is derived by multiplying corresponding values from these two matrices.

### Initial Thoughts 💭
- The challenge is to handle large input sizes efficiently.
- By calculating the products from different directions, we can avoid recalculating the product for each element multiple times.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where n or m is 0, though it is not required by the constraints.
- Optimize for large grid sizes (n * m up to 10^5).
- Take care with elements that are equal to 12345, since they can affect modulo operations.
- Ensure the solution handles the constraints efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>>ans(n,vector<int>(m));
    vector<vector<int>>xx(n,vector<int>(m));
    vector<vector<int>>yy(n,vector<int>(m));
    
    
    
    int mod = 12345;
    long long p = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            xx[i][j] = p;
            p *= grid[i][j];
            p %= mod;
        }
    }
    p = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            yy[i][j] = p;
            p *= grid[i][j];
            p %= mod;
        }
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            long long mul = xx[i][j] * yy[i][j];
            
            ans[i][j] = mul%mod;
        }
    }
    return ans;

}
```

This function constructs a product matrix from the given `grid`, where each element of the matrix represents the product of the elements from the top-left to the current element and the bottom-right to the current element. The results are taken modulo `12345`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
	```
	Defines the function `constructProductMatrix` which takes a 2D vector `grid` and returns a 2D vector where each element is the product of grid values from the top-left to the current cell and from the bottom-right to the current cell.

2. **Size Initialization**
	```cpp
	    int n = grid.size();
	```
	Initializes `n` with the number of rows in the `grid`.

3. **Size Initialization**
	```cpp
	    int m = grid[0].size();
	```
	Initializes `m` with the number of columns in the first row of `grid`.

4. **Matrix Initialization**
	```cpp
	    vector<vector<int>>ans(n,vector<int>(m));
	```
	Initializes a 2D vector `ans` to store the final result of the product matrix, with the same dimensions as the input `grid`.

5. **Matrix Initialization**
	```cpp
	    vector<vector<int>>xx(n,vector<int>(m));
	```
	Initializes a 2D vector `xx` to store products of elements from the top-left of the grid to each element.

6. **Matrix Initialization**
	```cpp
	    vector<vector<int>>yy(n,vector<int>(m));
	```
	Initializes a 2D vector `yy` to store products of elements from the bottom-right of the grid to each element.

7. **Modulo Initialization**
	```cpp
	    int mod = 12345;
	```
	Sets a constant modulo value `mod` used to compute the remainder of the product for each element in the matrix.

8. **Variable Initialization**
	```cpp
	    long long p = 1;
	```
	Initializes a variable `p` to store the running product while iterating through the grid.

9. **Forward Iteration**
	```cpp
	    for(int i=0; i<n; i++){
	```
	Begins a loop to iterate through the rows of the grid.

10. **Forward Iteration Inner Loop**
	```cpp
	        for(int j=0; j<m; j++){
	```
	Begins an inner loop to iterate through the columns of the grid.

11. **Storing Products in xx**
	```cpp
	            xx[i][j] = p;
	```
	Stores the current running product `p` in the `xx` matrix at position `(i, j)`.

12. **Product Calculation**
	```cpp
	            p *= grid[i][j];
	```
	Multiplies the running product `p` by the current element `grid[i][j]`.

13. **Modulo Operation**
	```cpp
	            p %= mod;
	```
	Applies the modulo operation to `p` to ensure the product remains within a manageable range.

14. **Resetting p**
	```cpp
	    p = 1;
	```
	Resets the variable `p` to `1` before starting the backward iteration.

15. **Backward Iteration**
	```cpp
	    for(int i=n-1; i>=0; i--){
	```
	Begins a loop to iterate through the rows of the grid in reverse order.

16. **Backward Iteration Inner Loop**
	```cpp
	        for(int j=m-1; j>=0; j--){
	```
	Begins an inner loop to iterate through the columns in reverse order.

17. **Storing Products in yy**
	```cpp
	            yy[i][j] = p;
	```
	Stores the current running product `p` in the `yy` matrix at position `(i, j)`.

18. **Product Calculation**
	```cpp
	            p *= grid[i][j];
	```
	Multiplies the running product `p` by the current element `grid[i][j]`.

19. **Modulo Operation**
	```cpp
	            p %= mod;
	```
	Applies the modulo operation to `p` to ensure the product remains within a manageable range.

20. **Final Computation**
	```cpp
	    for(int i=0; i<n; i++){
	```
	Begins a loop to iterate through all the rows for the final computation of the product matrix.

21. **Final Computation Inner Loop**
	```cpp
	        for(int j=0; j<m; j++){
	```
	Begins an inner loop to iterate through the columns for the final computation.

22. **Product Calculation**
	```cpp
	            long long mul = xx[i][j] * yy[i][j];
	```
	Calculates the product of the values from `xx[i][j]` and `yy[i][j]`.

23. **Storing Final Result**
	```cpp
	            ans[i][j] = mul%mod;
	```
	Stores the final product in `ans[i][j]` after applying the modulo operation.

24. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final product matrix `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

Since we iterate over the matrix several times, the time complexity is linear in terms of the number of elements.

### Space Complexity 💾
- **Best Case:** O(n * m)
- **Worst Case:** O(n * m)

The space complexity is linear in terms of the size of the grid, as we use two additional matrices of the same size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-product-matrix/description/)

---
{{< youtube CXuoLKjEWIs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
