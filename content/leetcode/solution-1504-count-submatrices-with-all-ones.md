
+++
authors = ["grid47"]
title = "Leetcode 1504: Count Submatrices With All Ones"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1504: Count Submatrices With All Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Matrix","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8miqwSN3EFo"
youtube_upload_date="2020-07-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8miqwSN3EFo/maxresdefault.webp"
comments = true
+++



---
You are given a binary matrix of size m x n where each element is either 0 or 1. Your task is to count how many submatrices consist entirely of 1s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a matrix of size m x n, where each element is either 0 or 1. The task is to count all submatrices that contain only 1s.
- **Example:** `mat = [[1,0,1],[1,1,0],[1,1,0]]`
- **Constraints:**
	- 1 <= m, n <= 150
	- Each mat[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the number of submatrices that consist entirely of 1s.
- **Example:** `10`
- **Constraints:**
	- The number of submatrices is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of submatrices consisting entirely of 1s by iterating through each potential rectangle.

- For each cell in the matrix, calculate the number of submatrices that can end at that cell.
- For each row, maintain the number of consecutive 1s up to that cell to efficiently calculate submatrices.
- Sum up the counts of all submatrices formed by each cell.
{{< dots >}}
### Problem Assumptions ✅
- The matrix may contain a mix of 1s and 0s, and its size can vary.
{{< dots >}}
## Examples 🧩
- **Input:** `mat = [[1,0,1],[1,1,0],[1,1,0]]`  \
  **Explanation:** The total number of submatrices made entirely of 1s is 10.

- **Input:** `mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]`  \
  **Explanation:** The total number of submatrices made entirely of 1s is 16.

{{< dots >}}
## Approach 🚀
The approach to solve this problem involves calculating, for each cell in the matrix, the number of possible rectangles ending at that cell. By doing so, we count all submatrices efficiently.

### Initial Thoughts 💭
- We need to calculate the total number of submatrices formed by 1s in the matrix.
- Iterating through each cell and considering all possible submatrices ending at each cell is key.
{{< dots >}}
### Edge Cases 🌐
- If the matrix is empty, return 0.
- Ensure that the solution handles the maximum matrix size efficiently.
- If the matrix contains only 0s, the answer should be 0.
- Ensure that the matrix dimensions respect the constraints.
{{< dots >}}
## Code 💻
```cpp
int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int cnt = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        cnt += helper(mat, i, j);        
    return cnt;
}

int helper(vector<vector<int>>& mat, int a, int b) {
    int m = mat.size(), n = mat[0].size();
    int cnt = 0, bnd = n;
    for(int i = a; i < m; i++)
    for(int j = b; j < bnd; j++) {
        if(mat[i][j]) cnt +=1;
        else bnd = j;
    }
    return cnt;
}
```

The code defines two functions: `numSubmat` which calculates the number of submatrices that contain only 1s in a given binary matrix, and `helper`, which calculates the count of valid submatrices starting from each position in the matrix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numSubmat(vector<vector<int>>& mat) {
	```
	Defines the main function that takes a binary matrix `mat` and calculates the number of submatrices containing only 1s.

2. **Variable Initialization**
	```cpp
	    int m = mat.size();
	```
	Initializes `m` to the number of rows in the matrix `mat`.

3. **Variable Initialization**
	```cpp
	    int n = mat[0].size();
	```
	Initializes `n` to the number of columns in the first row of the matrix `mat`.

4. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes the counter `cnt` to 0, which will store the total number of valid submatrices.

5. **Nested Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Iterates over each row in the matrix.

6. **Nested Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Iterates over each column in the matrix.

7. **Function Call**
	```cpp
	        cnt += helper(mat, i, j);        
	```
	Calls the helper function to calculate the number of valid submatrices starting from position `(i, j)` and adds the result to `cnt`.

8. **Return**
	```cpp
	    return cnt;
	```
	Returns the total count of submatrices that contain only 1s.

9. **Function Definition**
	```cpp
	int helper(vector<vector<int>>& mat, int a, int b) {
	```
	Defines the helper function that calculates the number of valid submatrices starting from position `(a, b)` in the matrix.

10. **Variable Initialization**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	Initializes `m` to the number of rows and `n` to the number of columns in the matrix `mat`.

11. **Variable Initialization**
	```cpp
	    int cnt = 0, bnd = n;
	```
	Initializes `cnt` to 0 for counting valid submatrices and `bnd` to `n`, the initial right boundary for each row.

12. **Nested Loop**
	```cpp
	    for(int i = a; i < m; i++)
	```
	Iterates over the rows starting from row `a`.

13. **Nested Loop**
	```cpp
	    for(int j = b; j < bnd; j++) {
	```
	Iterates over the columns starting from column `b` and up to the current boundary `bnd`.

14. **Conditional Statement**
	```cpp
	        if(mat[i][j]) cnt +=1;
	```
	If the current element is 1, increments the count `cnt` as it contributes to a valid submatrix.

15. **Conditional Statement**
	```cpp
	        else bnd = j;
	```
	If the current element is 0, updates the right boundary `bnd` to the current column `j` because no further valid submatrices can extend beyond this point in this row.

16. **Return**
	```cpp
	    return cnt;
	```
	Returns the count of valid submatrices found starting from position `(a, b)`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n), as we need to process each cell of the matrix.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) in the worst case when we store the submatrix counts for each cell.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-submatrices-with-all-ones/description/)

---
{{< youtube 8miqwSN3EFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
