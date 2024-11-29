
+++
authors = ["grid47"]
title = "Leetcode 2643: Row With Maximum Ones"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2643: Row With Maximum Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yieYsDt7yVM"
youtube_upload_date="2023-04-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yieYsDt7yVM/maxresdefault.webp"
comments = true
+++



---
Given a binary matrix of size m x n, your task is to find the row that contains the highest number of 1's. If there are multiple rows with the same count of 1's, return the row with the smallest index. The output should contain the index of the row and the count of 1's in that row.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary matrix 'mat' with m rows and n columns. Each element in the matrix is either 0 or 1.
- **Example:** `mat = [[0, 1, 1], [1, 0, 1], [1, 1, 1]]`
- **Constraints:**
	- 1 <= m, n <= 100
	- mat[i][j] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing two integers: the index of the row with the maximum count of 1's and the number of 1's in that row.
- **Example:** `Output: [2, 3]`
- **Constraints:**
	- The output array should contain the row index and the count of 1's in the selected row.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the row with the maximum number of 1's and return its index along with the count of 1's in that row.

- Step 1: Initialize a variable to track the maximum count of 1's and the corresponding row index.
- Step 2: Traverse each row of the matrix and count the number of 1's in the row.
- Step 3: If the count of 1's in the current row exceeds the previous maximum, update the row index and the maximum count.
- Step 4: After processing all rows, return the row index and the count of 1's in the row with the maximum count.
{{< dots >}}
### Problem Assumptions ✅
- The matrix contains only 0's and 1's.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mat = [[0, 1, 1], [1, 0, 1], [1, 1, 1]]`  \
  **Explanation:** The first row has 2 ones, the second row has 2 ones, and the third row has 3 ones. The row with the maximum count of 1's is the third row (index 2), so the output is [2, 3].

{{< dots >}}
## Approach 🚀
We will iterate through each row of the binary matrix and count the number of 1's. As we process each row, we track the maximum count of 1's and its corresponding row index. The result is returned once all rows have been evaluated.

### Initial Thoughts 💭
- Since the problem is about counting 1's in each row, a straightforward approach of iterating through the matrix should suffice.
- We need to ensure that the solution is efficient enough to handle matrices of size 100 x 100.
{{< dots >}}
### Edge Cases 🌐
- If the matrix has no rows or columns, handle it appropriately.
- For larger matrices, ensure that the solution works efficiently within the given constraints.
- If all rows contain no 1's, return the first row with 0 ones.
- The algorithm should run in linear time, O(m * n), where m is the number of rows and n is the number of columns.
{{< dots >}}
## Code 💻
```cpp
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int mx = 0, idx = 0;
    for(int i = 0; i < m; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(mat[i][j]) cnt++;
        if(cnt > mx) {
            idx = i;
            mx = cnt;
        }
    }
    return vector<int>{idx, mx};
}
```

This is the complete function implementation to find the row with the maximum number of 1's in a binary matrix. It returns the index of the row and the count of 1's.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
	```
	The function is declared with a vector of vectors `mat` as the input, representing a binary matrix, and it returns a vector of integers containing the index of the row with the maximum 1's and the count of 1's.

2. **Variable Initialization**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	Here, the number of rows `m` and columns `n` of the matrix are obtained by using the `size()` function.

3. **Variable Initialization**
	```cpp
	    int mx = 0, idx = 0;
	```
	Two variables are initialized: `mx` (to store the maximum count of 1's found) and `idx` (to store the index of the row with the maximum 1's).

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	A loop is started to iterate through each row of the matrix.

5. **Variable Initialization**
	```cpp
	        int cnt = 0;
	```
	A variable `cnt` is initialized to count the number of 1's in the current row.

6. **Inner Loop**
	```cpp
	        for(int j = 0; j < n; j++)
	```
	An inner loop starts to iterate through each column of the current row.

7. **Condition**
	```cpp
	            if(mat[i][j]) cnt++;
	```
	If the current element of the matrix is 1, increment the counter `cnt`.

8. **Comparison**
	```cpp
	        if(cnt > mx) {
	```
	If the count of 1's in the current row is greater than the previous maximum (`mx`), proceed to update the values.

9. **Variable Update**
	```cpp
	            idx = i;
	```
	Update `idx` to the current row index `i` as it now has the highest count of 1's.

10. **Variable Update**
	```cpp
	            mx = cnt;
	```
	Update the maximum count of 1's found so far with the current row's count `cnt`.

11. **Return Statement**
	```cpp
	    return vector<int>{idx, mx};
	```
	Return a vector containing the index of the row with the maximum 1's and the count of 1's.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we are iterating through all elements in the matrix.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are only using a few variables to track the result, and no additional data structures are required.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/row-with-maximum-ones/description/)

---
{{< youtube yieYsDt7yVM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
