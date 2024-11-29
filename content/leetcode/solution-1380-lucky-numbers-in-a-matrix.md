
+++
authors = ["grid47"]
title = "Leetcode 1380: Lucky Numbers in a Matrix"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1380: Lucky Numbers in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ceuQgACqr78"
youtube_upload_date="2024-07-19"
youtube_thumbnail="https://i.ytimg.com/vi/ceuQgACqr78/maxresdefault.jpg"
comments = true
+++



---
You are given a matrix of distinct numbers with dimensions m x n. A lucky number in the matrix is an element that is the minimum value in its row and the maximum value in its column. Your task is to find and return all such lucky numbers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D matrix of distinct integers.
- **Example:** `matrix = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]`
- **Constraints:**
	- The matrix will have dimensions m x n where 1 <= m, n <= 50.
	- All elements in the matrix are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of all lucky numbers in the matrix.
- **Example:** `[70]`
- **Constraints:**
	- The output should include all lucky numbers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify and return all lucky numbers in the matrix, where each lucky number is the minimum in its row and maximum in its column.

- Find the minimum value in each row.
- Find the maximum value in each column.
- Identify the values that are both the minimum in their row and the maximum in their column.
{{< dots >}}
### Problem Assumptions ✅
- Each element in the matrix is distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `matrix = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]`  \
  **Explanation:** In this example, 70 is the only lucky number because it is the minimum in its row and the maximum in its column.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the matrix to find the minimum value in each row, followed by finding the maximum value in each column. Once the row minimums and column maximums are identified, we check for numbers that satisfy both conditions.

### Initial Thoughts 💭
- The matrix is guaranteed to have distinct numbers.
- To efficiently find the lucky numbers, we should first calculate the row minimums and column maximums.
{{< dots >}}
### Edge Cases 🌐
- The matrix will always have at least one element, so no need to handle empty matrices.
- Ensure the solution handles matrices with the maximum allowed size of 50 x 50.
- All elements in the matrix are distinct, so there will be no duplicate values to consider.
- The matrix elements are distinct and within the range [1, 10^5].
{{< dots >}}
## Code 💻
```cpp
vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> res;
    vector<int> row(matrix.size(), 0);
    vector<int> col(matrix[0].size(), 0);
    for(int i = 0; i < matrix.size(); i++)
    {
        int m = matrix[i][0];
        for(int j = 1; j < matrix[0].size(); j++) m = min(m, matrix[i][j]);
        row[i] = m;
    }
    for(int j = 0; j < matrix[0].size(); j++)
    {
        int m = matrix[0][j];
        for(int i = 1; i < matrix.size(); i++) m = max(m,matrix[i][j]);
        col[j] = m;
    }
    
    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
            if(row[i] == col[j]) res.push_back(row[i]);

    return res;
}
```

This function `luckyNumbers` finds all the 'lucky' numbers in a matrix. A number is 'lucky' if it is the minimum in its row and the maximum in its column.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
	```
	We define the function `luckyNumbers` that takes a 2D matrix and returns a vector containing the lucky numbers.

2. **Variable Declaration**
	```cpp
	    vector<int> res;
	```
	We declare a vector `res` to store the lucky numbers found in the matrix.

3. **Variable Initialization**
	```cpp
	    vector<int> row(matrix.size(), 0);
	```
	We initialize a vector `row` to store the minimum values of each row in the matrix.

4. **Variable Initialization**
	```cpp
	    vector<int> col(matrix[0].size(), 0);
	```
	We initialize a vector `col` to store the maximum values of each column in the matrix.

5. **Loop (Rows)**
	```cpp
	    for(int i = 0; i < matrix.size(); i++)
	```
	We start a loop to iterate over each row of the matrix.

6. **Variable Assignment**
	```cpp
	        int m = matrix[i][0];
	```
	We assign the first element of the row to the variable `m`, which will be used to find the minimum value in the row.

7. **Loop (Columns)**
	```cpp
	        for(int j = 1; j < matrix[0].size(); j++) m = min(m, matrix[i][j]);
	```
	We iterate through the remaining elements in the row to find the minimum value.

8. **Row Minimum Assignment**
	```cpp
	        row[i] = m;
	```
	We store the minimum value of the current row in the `row` vector.

9. **Loop (Columns)**
	```cpp
	    for(int j = 0; j < matrix[0].size(); j++)
	```
	We start a loop to iterate over each column of the matrix.

10. **Variable Assignment**
	```cpp
	        int m = matrix[0][j];
	```
	We assign the first element of the column to the variable `m`, which will be used to find the maximum value in the column.

11. **Loop (Rows)**
	```cpp
	        for(int i = 1; i < matrix.size(); i++) m = max(m,matrix[i][j]);
	```
	We iterate through the remaining elements in the column to find the maximum value.

12. **Column Maximum Assignment**
	```cpp
	        col[j] = m;
	```
	We store the maximum value of the current column in the `col` vector.

13. **Nested Loop (Matrix Elements)**
	```cpp
	    for(int i=0;i<matrix.size();i++)
	```
	We start a nested loop to iterate over all elements of the matrix again.

14. **Nested Loop (Matrix Elements)**
	```cpp
	        for(int j=0;j<matrix[0].size();j++)
	```
	We iterate through each column for the current row in the nested loop.

15. **Condition Check (Lucky Numbers)**
	```cpp
	            if(row[i] == col[j]) res.push_back(row[i]);
	```
	We check if the current row minimum is equal to the current column maximum. If they match, we add the value to the result vector `res`.

16. **Return Statement**
	```cpp
	    return res;
	```
	After finishing the loops, we return the vector `res`, which contains all the lucky numbers found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.

### Space Complexity 💾
- **Best Case:** O(m + n)
- **Worst Case:** O(m + n)

The space complexity is O(m + n), where m is the number of rows and n is the number of columns in the matrix due to the storage of row minimums and column maximums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/)

---
{{< youtube ceuQgACqr78 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
