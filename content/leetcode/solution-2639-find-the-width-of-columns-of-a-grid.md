
+++
authors = ["grid47"]
title = "Leetcode 2639: Find the Width of Columns of a Grid"
date = "2024-02-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2639: Find the Width of Columns of a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "RSRjK563HVY"
youtube_upload_date="2023-04-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RSRjK563HVY/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed m x n integer matrix `grid`. The width of a column is determined by the length of its longest integer. For example, the length of an integer is defined as the number of digits in its absolute value, with an additional digit for negative numbers. For each column, return its width, which is the maximum length of any integer in that column.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a matrix `grid`, where each element is an integer. The matrix has `m` rows and `n` columns.
- **Example:** `grid = [[-9, 18, 7], [23, 34, -9], [12, 50, 6]]`
- **Constraints:**
	- 1 <= m, n <= 100
	- -10^9 <= grid[r][c] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer array `ans` of size `n` where each `ans[i]` represents the width of the i-th column in the grid.
- **Example:** `Output: [3, 2, 2]`
- **Constraints:**
	- The output array will have exactly `n` elements, each representing the width of a column.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the width of each column in the matrix by finding the maximum length of the integers in each column.

- Step 1: Define a helper function to calculate the length of an integer. This function should account for negative integers.
- Step 2: Iterate over each column in the matrix.
- Step 3: For each column, compute the maximum length of the integers in that column using the helper function.
- Step 4: Store the results in an array `ans` and return it.
{{< dots >}}
### Problem Assumptions ✅
- The matrix `grid` is non-empty and contains integers within the specified range.
- The matrix can contain both negative and positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[-9, 18, 7], [23, 34, -9], [12, 50, 6]]`  \
  **Explanation:** In the first column, -9 has length 2, 23 has length 2, and 12 has length 2. The maximum width of the column is 2. In the second column, the lengths are 2, 2, and 2. The width is 2. In the third column, the lengths are 1, 2, and 1, so the width is 2.

- **Input:** `grid = [[1],[22],[333]]`  \
  **Explanation:** In this case, the first column contains 1, 22, and 333. The maximum length in the first column is 3 (for 333). Thus, the width of the column is 3.

{{< dots >}}
## Approach 🚀
We will use a helper function to calculate the length of each integer, then iterate through each column of the matrix to find the maximum length for that column.

### Initial Thoughts 💭
- We need to consider negative numbers, which require an additional digit in their length.
- For each column, we need to compare the lengths of all the numbers and find the maximum length.
- Using a helper function to calculate the length of each number simplifies the task. Once we know the length of each number, finding the maximum in each column is straightforward.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty, the output should also be an empty array.
- The algorithm should handle the largest grid size (100x100) efficiently.
- When the grid contains negative values, the helper function must account for the extra digit in the length calculation.
- Ensure the solution works within the time limits for the largest inputs.
{{< dots >}}
## Code 💻
```cpp
int get(int num) {
    if(num == 0) return 1;
    int len = num < 0? 1: 0;
    num = abs(num);
    while(num > 0) {
        len++;
        num/=10;
    }
    return len;
}

vector<int> findColumnWidth(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        int len = 0;
        for(int j = 0; j < m; j++) {
            len = max(len, get(grid[j][i]));
        }
        ans[i] = len;
    }
    return ans;
}
```

This code defines two functions. The first function, 'get', computes the number of digits in an integer, considering negative values. The second function, 'findColumnWidth', takes a 2D grid and computes the maximum width (in terms of digits) for each column by applying the 'get' function.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int get(int num) {
	```
	The function 'get' is defined to calculate the number of digits in a given integer 'num'.

2. **Conditional Check**
	```cpp
	    if(num == 0) return 1;
	```
	This line handles the edge case where the number is zero, returning 1 as it has one digit.

3. **Initialization**
	```cpp
	    int len = num < 0? 1: 0;
	```
	The variable 'len' is initialized to 1 if the number is negative (for the sign digit), otherwise to 0.

4. **Abs Function**
	```cpp
	    num = abs(num);
	```
	The absolute value of 'num' is computed to avoid negative signs affecting digit calculation.

5. **Loop**
	```cpp
	    while(num > 0) {
	```
	A loop is started to count the digits of the number while it is greater than 0.

6. **Digit Count**
	```cpp
	        len++;
	```
	Each time the loop iterates, the 'len' variable is incremented, counting each digit.

7. **Dividing the Number**
	```cpp
	        num/=10;
	```
	The number is divided by 10 to remove the last digit in each iteration of the loop.

8. **Return Statement**
	```cpp
	    return len;
	```
	The function returns the total count of digits in the number.

9. **Function Definition**
	```cpp
	vector<int> findColumnWidth(vector<vector<int>>& grid) {
	```
	The function 'findColumnWidth' is defined to calculate the maximum width (in terms of digits) of each column in a 2D grid.

10. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	The dimensions of the grid are obtained: 'm' is the number of rows, and 'n' is the number of columns.

11. **Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	A vector 'ans' is initialized to store the maximum width for each column, all starting at 0.

12. **Loop Over Columns**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop starts to iterate over each column in the grid.

13. **Variable Initialization**
	```cpp
	        int len = 0;
	```
	A local variable 'len' is initialized to track the maximum width for the current column.

14. **Loop Over Rows**
	```cpp
	        for(int j = 0; j < m; j++) {
	```
	A nested loop starts to iterate over each row for the current column.

15. **Max Function**
	```cpp
	            len = max(len, get(grid[j][i]));
	```
	The maximum digit length for the current column is calculated by comparing the current value of 'len' with the result of the 'get' function for the current cell.

16. **Storing Result**
	```cpp
	        ans[i] = len;
	```
	The maximum width found for the current column is stored in the 'ans' vector.

17. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the 'ans' vector, which contains the maximum width for each column.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we process each element of the grid once and compute its length in constant time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the result array, where `n` is the number of columns in the grid.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/)

---
{{< youtube RSRjK563HVY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
