
+++
authors = ["grid47"]
title = "Leetcode 1605: Find Valid Matrix Given Row and Column Sums"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1605: Find Valid Matrix Given Row and Column Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ks6fGnXkHPg"
youtube_upload_date="2024-07-20"
youtube_thumbnail="https://i.ytimg.com/vi/Ks6fGnXkHPg/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays representing the sum of elements in each row and each column of a 2D matrix. The rowSum[i] represents the sum of the elements in the i-th row, and colSum[j] represents the sum of the elements in the j-th column. Your task is to find a matrix of non-negative integers that satisfies these row and column sum requirements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with two arrays, rowSum and colSum, where rowSum[i] is the sum of the i-th row of a matrix and colSum[j] is the sum of the j-th column. The dimensions of the matrix are rowSum.length x colSum.length.
- **Example:** `rowSum = [5, 7], colSum = [7, 5]`
- **Constraints:**
	- 1 <= rowSum.length, colSum.length <= 500
	- 0 <= rowSum[i], colSum[i] <= 10^8
	- sum(rowSum) == sum(colSum)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D matrix where the sum of the elements in each row equals the corresponding value in rowSum, and the sum of the elements in each column equals the corresponding value in colSum.
- **Example:** `For rowSum = [5, 7], colSum = [7, 5], one possible output could be [[0,5], [7, 0]]`
- **Constraints:**
	- The matrix must be filled with non-negative integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** To construct a matrix that satisfies both row and column sum constraints.

- Start by initializing a 2D matrix of size rowSum.length x colSum.length, filled with zeros.
- Iterate over each element in the matrix, choosing the minimum of the remaining row sum and column sum at that position.
- Reduce the corresponding row sum and column sum by the value chosen for the matrix element.
- Repeat this process until all row and column sums are satisfied.
{{< dots >}}
### Problem Assumptions ✅
- The sum of elements in rowSum will always equal the sum of elements in colSum.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: rowSum = [3,8], colSum = [4,7]`  \
  **Explanation:** In this case, the matrix should be such that the sum of the first row is 3 and the second row is 8. Similarly, the sum of the first column is 4 and the second column is 7. One possible solution is [[3, 0], [1, 7]].

- **Input:** `Input: rowSum = [5,7,10], colSum = [8,6,8]`  \
  **Explanation:** For this case, the matrix should be constructed such that each row sum is satisfied and each column sum is also satisfied. One possible solution is [[0,5,0], [6,1,0], [2,0,8]].

{{< dots >}}
## Approach 🚀
This approach leverages a greedy method where we fill the matrix by choosing the minimum value between the remaining row sum and column sum at each position. This ensures that we can satisfy the constraints while maintaining non-negative integer values in the matrix.

### Initial Thoughts 💭
- The total sum of rowSum must equal the total sum of colSum, ensuring that a solution is always possible.
- The solution requires filling each cell with the minimum value between the corresponding row and column sums, which guarantees that both constraints are met.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the input arrays are non-empty as per the problem constraints.
- The solution should handle large inputs efficiently, given the constraints on rowSum and colSum.
- Consider cases where rowSum or colSum elements are zero, ensuring the matrix remains valid.
- Ensure that the sum of rowSum equals the sum of colSum to guarantee that a valid matrix exists.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for(int i = 0; i < m ;i++)
    for(int j = 0; j < n; j++) {
        ans[i][j] = min(rowSum[i], colSum[j]);
        rowSum[i]-= ans[i][j];
        colSum[j]-= ans[i][j];
    }
    return ans;
}
```

This code defines a function `restoreMatrix` that takes two vectors, `rowSum` and `colSum`, and returns a matrix where each element is filled such that the row and column sums are maintained. The values are filled by taking the minimum of the available row and column sums.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
	```
	This is the function definition of `restoreMatrix`, which takes two vectors, `rowSum` and `colSum`, and returns a 2D vector (matrix) of integers.

2. **Variable Initialization**
	```cpp
	    int m = rowSum.size(), n = colSum.size();
	```
	Initialize variables `m` and `n` to store the sizes of the `rowSum` and `colSum` vectors, respectively. These values will be used to determine the number of rows and columns of the resulting matrix.

3. **Matrix Initialization**
	```cpp
	    vector<vector<int>> ans(m, vector<int>(n, 0));
	```
	Create a 2D vector `ans` initialized with zeros. This matrix will eventually hold the values where the row and column sums are satisfied.

4. **Loop**
	```cpp
	    for(int i = 0; i < m ;i++)
	```
	Start a loop over the rows of the matrix. The loop runs from `i = 0` to `i = m-1`.

5. **Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Start a nested loop over the columns of the matrix. The loop runs from `j = 0` to `j = n-1`.

6. **Matrix Assignment**
	```cpp
	        ans[i][j] = min(rowSum[i], colSum[j]);
	```
	At each position `ans[i][j]`, assign the minimum of the remaining values in `rowSum[i]` and `colSum[j]`. This ensures that the values placed in the matrix maintain the row and column sum constraints.

7. **Update**
	```cpp
	        rowSum[i]-= ans[i][j];
	```
	After assigning a value to `ans[i][j]`, decrement the corresponding row sum (`rowSum[i]`) by the assigned value.

8. **Update**
	```cpp
	        colSum[j]-= ans[i][j];
	```
	Similarly, decrement the corresponding column sum (`colSum[j]`) by the assigned value in `ans[i][j]`.

9. **Return**
	```cpp
	    return ans;
	```
	After the matrix is filled with appropriate values, return the resulting matrix `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The best, average, and worst case all involve iterating over the entire matrix, resulting in O(m * n) time complexity.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

We need to store the matrix, so the space complexity is O(m * n), where m and n are the dimensions of the matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/)

---
{{< youtube Ks6fGnXkHPg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
