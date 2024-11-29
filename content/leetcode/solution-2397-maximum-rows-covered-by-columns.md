
+++
authors = ["grid47"]
title = "Leetcode 2397: Maximum Rows Covered by Columns"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2397: Maximum Rows Covered by Columns in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Matrix","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "scBL7uQiPMg"
youtube_upload_date="2022-09-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/scBL7uQiPMg/maxresdefault.webp"
comments = true
+++



---
You are given a binary matrix `matrix` of size m x n and an integer `numSelect`. Your goal is to select exactly `numSelect` distinct columns from the matrix such that you cover as many rows as possible. A row is considered covered if all the 1's in that row are included in the selected columns. If a row has no 1's, it is also considered covered.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an m x n binary matrix `matrix` and an integer `numSelect` representing the number of columns to select.
- **Example:** `matrix = [[0, 0, 0], [1, 0, 1], [0, 1, 1], [0, 0, 1]], numSelect = 2`
- **Constraints:**
	- 1 <= m, n <= 12
	- 1 <= numSelect <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of rows that can be covered by selecting `numSelect` columns.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to select `numSelect` columns such that the maximum number of rows are covered. A row is covered if all its 1's appear in the selected columns.

- 1. Iterate through all possible selections of `numSelect` columns.
- 2. For each selection, check if the columns cover the rows based on the presence of 1's in the selected columns.
- 3. Count the number of rows that are covered.
- 4. Keep track of the maximum number of rows covered across all column selections.
{{< dots >}}
### Problem Assumptions ✅
- Matrix entries are either 0 or 1.
- numSelect is at most n, the number of columns in the matrix.
{{< dots >}}
## Examples 🧩
- **Input:** `matrix = [[1, 0], [0, 0], [1, 1]], numSelect = 1`  \
  **Explanation:** Selecting column 1 will cover both rows with 1's. Therefore, the answer is 3, as all rows are covered.

- **Input:** `matrix = [[0, 0, 0], [1, 0, 1], [0, 1, 1], [0, 0, 1]], numSelect = 2`  \
  **Explanation:** Selecting columns 0 and 2 will cover 3 rows because: Row 1 is covered as both columns 0 and 2 are selected, Row 0 is covered as it has no 1's, Row 3 is covered as column 2 is selected. The maximum rows covered is 3.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to try selecting different combinations of `numSelect` columns and check how many rows can be covered. We can iterate over all possible column selections, check coverage for each row, and return the maximum count.

### Initial Thoughts 💭
- The problem is combinatorial in nature, and since the matrix size is small, we can afford to check all column combinations.
- Efficient iteration over column selections can help us determine the maximum number of rows covered.
{{< dots >}}
### Edge Cases 🌐
- Handle matrices where all elements are 0, as all rows will be covered.
- Even though m, n <= 12, the solution should handle the largest matrix sizes efficiently.
- If `numSelect` equals `n`, all columns must be selected, so all rows with 1's will be covered.
- The solution needs to handle combinations of columns efficiently.
{{< dots >}}
## Code 💻
```cpp
int maximumRows(vector<vector<int>>& mtx, int sel) {
    int m = mtx.size(), n = mtx[0].size();
    
    int ans = 0;
    for(int msk = 0; msk < (1 << n); msk++) {
        if(__builtin_popcount(msk) != sel) continue;
        int res = 0;
        for(int i = 0; i < m; i++) {
            bool take = true;
            for(int j = 0; j < n; j++)
                if(mtx[i][j] && (((msk >> j) & 1) == 0)) {
                    take = false;
                    break;
                }
            if(take) res++;
        }
        ans = max(ans, res);
    }
    
    
    return ans;
}

```

The function `maximumRows` calculates the maximum number of rows from a matrix `mtx` that can be selected, with a given number of selected columns `sel`, where each selected row must satisfy specific conditions based on the selected columns.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maximumRows(vector<vector<int>>& mtx, int sel) {
	```
	The function `maximumRows` is declared, which takes a reference to a 2D vector `mtx` and an integer `sel` as input. It is designed to find the maximum number of rows that can be selected with specific conditions.

2. **Matrix Size Calculation**
	```cpp
	    int m = mtx.size(), n = mtx[0].size();
	```
	The number of rows `m` and the number of columns `n` of the matrix `mtx` are calculated.

3. **Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to 0, which will hold the final result—the maximum number of rows that can be selected.

4. **Bit Masking Loop**
	```cpp
	    for(int msk = 0; msk < (1 << n); msk++) {
	```
	A loop iterates over all possible bitmasks for selecting columns from the matrix, where `msk` is a bitmask representing a selection of columns.

5. **Bitmask Column Selection**
	```cpp
	        if(__builtin_popcount(msk) != sel) continue;
	```
	The condition checks if the number of selected columns in the current bitmask (`__builtin_popcount(msk)`) is equal to `sel`. If not, it continues to the next bitmask.

6. **Result Initialization**
	```cpp
	        int res = 0;
	```
	The variable `res` is initialized to 0. This will count how many rows can be selected for the current bitmask.

7. **Row Loop**
	```cpp
	        for(int i = 0; i < m; i++) {
	```
	A loop iterates through each row of the matrix `mtx`.

8. **Row Selection Check**
	```cpp
	            bool take = true;
	```
	A boolean variable `take` is initialized to `true`, which will track whether the current row can be selected based on the current bitmask.

9. **Column Loop**
	```cpp
	            for(int j = 0; j < n; j++)
	```
	A nested loop iterates through each column of the current row.

10. **Column Validation**
	```cpp
	                if(mtx[i][j] && (((msk >> j) & 1) == 0)) {
	```
	This condition checks if a cell in the matrix `mtx[i][j]` is non-zero (indicating that it is part of the selection) and if the corresponding column is not selected in the bitmask.

11. **Row Dismissal**
	```cpp
	                    take = false;
	```
	If the condition above is true, the row `i` is dismissed by setting `take` to `false`, meaning this row cannot be selected with the current bitmask.

12. **Exit Column Loop**
	```cpp
	                    break;
	```
	If a column is not selected in the bitmask while it should be, the inner loop breaks, and the row is dismissed.

13. **Row Count Update**
	```cpp
	            if(take) res++;
	```
	If the row can be selected (`take` is `true`), the `res` counter is incremented.

14. **Result Update**
	```cpp
	        ans = max(ans, res);
	```
	The result `ans` is updated to hold the maximum value between its current value and the value of `res` for the current bitmask.

15. **Return Result**
	```cpp
	    return ans;
	```
	The function returns the value of `ans`, which is the maximum number of rows that can be selected based on the given conditions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns.
- **Average Case:** O(m * n * C(n, numSelect))
- **Worst Case:** O(m * n * C(n, numSelect))

The worst-case time complexity is dependent on the number of column combinations, which is O(C(n, numSelect)), where C is the combination function.

### Space Complexity 💾
- **Best Case:** O(1), if using constant space for calculations.
- **Worst Case:** O(n), where n is the number of columns, to store combinations of columns.

Space complexity is mainly dependent on the space used for storing combinations and the matrix itself.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-rows-covered-by-columns/description/)

---
{{< youtube scBL7uQiPMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
