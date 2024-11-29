
+++
authors = ["grid47"]
title = "Leetcode 2352: Equal Row and Column Pairs"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2352: Equal Row and Column Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TmLXO3ZS6Lw"
youtube_upload_date="2022-07-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/TmLXO3ZS6Lw/maxresdefault.webp"
comments = true
+++



---
Given a square matrix of integers, find the number of pairs of row and column indices where the row and column are equal in terms of their elements and their order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an n x n matrix of integers, where n is the number of rows and columns.
- **Example:** `Input: grid = [[5, 3, 2], [3, 7, 6], [2, 7, 7]]`
- **Constraints:**
	- 1 <= n <= 200
	- 1 <= grid[i][j] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of pairs of rows and columns that are equal.
- **Example:** `Output: 1`
- **Constraints:**
	- The grid contains only integers and is square.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to iterate over rows and columns and check if they match.

- For each row, create a column vector corresponding to each column in the grid.
- Compare the row and column vectors. If they are equal, increment the counter.
{{< dots >}}
### Problem Assumptions ✅
- The grid is non-empty and contains integers only.
- The grid contains at least one pair of equal row-column matches.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[5, 3, 2], [3, 7, 6], [2, 7, 7]]`  \
  **Explanation:** The only equal pair is the third row and the second column, both [2, 7, 7].

{{< dots >}}
## Approach 🚀
To solve the problem, we need to compare rows and columns one by one and count the matching pairs.

### Initial Thoughts 💭
- This is a straightforward comparison problem where we need to check each row against each column.
- We can use a simple approach where we iterate over the grid and check if each row matches each column.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one matching pair.
- The solution should handle grids up to the size of 200 x 200 efficiently.
- If the grid has repeated rows or columns, they should be counted as separate matching pairs.
- The solution should work within the given constraints efficiently.
{{< dots >}}
## Code 💻
```cpp
int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans = 0;
    for (int c = 0; c < n; c++) {
        vector<int> col;
        col.reserve(n);
        for(int i = 0; i < n; i++)
        col.push_back(grid[i][c]);
        ans += count(begin(grid), end(grid), col);
    }
    return ans;
}
```

This function `equalPairs` takes a 2D grid and counts how many rows are identical to any of the columns. It compares each column with all rows using the `count` function to track matching pairs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int equalPairs(vector<vector<int>>& grid) {
	```
	The function `equalPairs` is declared, which accepts a 2D grid and returns an integer representing the count of identical row-column pairs.

2. **Grid Size Calculation**
	```cpp
	    int n = grid.size();
	```
	The variable `n` is initialized to the size of the grid (number of rows or columns, assuming the grid is square).

3. **Answer Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to 0, which will hold the count of identical row-column pairs.

4. **Column Loop Start**
	```cpp
	    for (int c = 0; c < n; c++) {
	```
	A loop is started to iterate over each column `c` in the grid.

5. **Column Vector Declaration**
	```cpp
	        vector<int> col;
	```
	A temporary vector `col` is declared to hold the current column's values as a separate array.

6. **Reserve Space for Column**
	```cpp
	        col.reserve(n);
	```
	The `reserve` function is called on the vector `col` to allocate memory for `n` elements, optimizing the vector's performance.

7. **Row Loop Start**
	```cpp
	        for(int i = 0; i < n; i++)
	```
	A loop is started to iterate over each row `i` in the grid to extract the column values.

8. **Push Column Values**
	```cpp
	        col.push_back(grid[i][c]);
	```
	The value from row `i` and column `c` is pushed into the vector `col`.

9. **Count Matching Rows**
	```cpp
	        ans += count(begin(grid), end(grid), col);
	```
	The `count` function is used to count how many rows in the grid match the current column `col`. The result is added to `ans`.

10. **Return Result**
	```cpp
	    return ans;
	```
	The function returns the total count of row-column pairs that match.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) as we compare each row to each column.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) as we store a column for each comparison, and the size of each column is n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/equal-row-and-column-pairs/description/)

---
{{< youtube TmLXO3ZS6Lw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
