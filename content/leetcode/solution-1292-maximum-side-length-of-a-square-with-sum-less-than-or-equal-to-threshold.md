
+++
authors = ["grid47"]
title = "Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2Y2a9VbqiC4"
youtube_upload_date="2020-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/2Y2a9VbqiC4/maxresdefault.jpg"
comments = true
+++



---
You are given a matrix of integers and a threshold. Your goal is to find the maximum side length of a square where the sum of the elements inside the square is less than or equal to the threshold.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a matrix mat of size m x n, and an integer threshold.
- **Example:** `Input: [[1,1,3,2,4,3,2], [1,1,3,2,4,3,2], [1,1,3,2,4,3,2]], threshold = 4`
- **Constraints:**
	- 1 <= m, n <= 300
	- 0 <= mat[i][j] <= 10^4
	- 0 <= threshold <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return the maximum side length of a square where the sum of the elements inside is less than or equal to the threshold, or 0 if no such square exists.
- **Example:** `Output: 2`
- **Constraints:**
	- The matrix has dimensions m x n.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the maximum side length of a square where the sum of elements inside is less than or equal to the threshold.

- Create a prefix sum matrix to efficiently calculate the sum of any submatrix.
- Iterate through all possible side lengths from largest to smallest.
- For each side length, check if there exists a square with that side length whose sum is less than or equal to the threshold.
- Return the largest side length where the condition holds true.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is non-empty.
- Threshold is non-negative.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[1,1,3,2,4,3,2], [1,1,3,2,4,3,2], [1,1,3,2,4,3,2]], threshold = 4`  \
  **Explanation:** The maximum side length of a square with a sum of elements less than or equal to 4 is 2, as seen by the top-left 2x2 square.

{{< dots >}}
## Approach 🚀
The solution involves using a prefix sum matrix to efficiently compute the sum of any submatrix and checking all possible square sizes.

### Initial Thoughts 💭
- Brute force approach would involve checking all possible squares which can be slow. A prefix sum matrix optimizes the sum calculation for submatrices.
- We can optimize by first constructing the prefix sum matrix, which will allow us to compute the sum of any submatrix in constant time.
{{< dots >}}
### Edge Cases 🌐
- The input matrix is never empty according to the constraints.
- The solution should be optimized to handle matrices as large as 300x300.
- If the threshold is 0, no square will have a positive sum unless the matrix contains all zeros.
- The solution should handle the largest possible matrix and the maximum element values efficiently.
{{< dots >}}
## Code 💻
```cpp
int maxSideLength(vector<vector<int>>& mat, int hit) {
    int m = mat.size(), n = mat[0].size();
    int res = 0, len = 1;
    vector<vector<int>> sum(m + 1, vector<int> (n + 1));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            if(i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= hit)
                res = len++;
        }
    }
    
    return res;
}
```

This function finds the maximum side length of a square with a sum less than or equal to a given threshold in a 2D matrix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxSideLength(vector<vector<int>>& mat, int hit) {
	```
	Defines a function to compute the largest side length of a square matrix with sum constraints.

2. **Variable Initialization**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	Initializes the dimensions of the matrix.

3. **Variable Initialization**
	```cpp
	    int res = 0, len = 1;
	```
	Initializes the result variable and the starting square side length.

4. **Matrix Initialization**
	```cpp
	    vector<vector<int>> sum(m + 1, vector<int> (n + 1));
	```
	Creates a prefix sum matrix with one extra row and column for easier computation.

5. **Outer Loop**
	```cpp
	    for(int i = 1; i <= m; i++) {
	```
	Iterates through each row of the matrix.

6. **Inner Loop**
	```cpp
	        for(int j = 1; j <= n; j++) {
	```
	Iterates through each column of the matrix.

7. **Prefix Sum Update**
	```cpp
	            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
	```
	Updates the prefix sum for the current cell in the matrix.

8. **Condition Check**
	```cpp
	            if(i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= hit)
	```
	Checks if the current square's sum is within the allowed threshold.

9. **Update Result**
	```cpp
	                res = len++;
	```
	Updates the result to the current square side length and increments the length.

10. **Return Result**
	```cpp
	    return res;
	```
	Returns the maximum side length of the square that satisfies the conditions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n) - The best case occurs when the prefix sum matrix is constructed in linear time.
- **Average Case:** O(m * n) - The average case remains O(m * n) as the algorithm involves iterating through the matrix.
- **Worst Case:** O(m * n) - The worst case involves checking all possible submatrices and square sizes.

The time complexity is dominated by the construction of the prefix sum matrix and the iteration through all possible square sizes.

### Space Complexity 💾
- **Best Case:** O(m * n) - The space complexity is the same in the best case as the matrix needs to be stored.
- **Worst Case:** O(m * n) - The space complexity comes from storing the prefix sum matrix.

The space complexity is O(m * n) due to the storage of the prefix sum matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/)

---
{{< youtube 2Y2a9VbqiC4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
