
+++
authors = ["grid47"]
title = "Leetcode 2500: Delete Greatest Value in Each Row"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2500: Delete Greatest Value in Each Row in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "xWRu1KHVAIo"
youtube_upload_date="2022-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xWRu1KHVAIo/maxresdefault.webp"
comments = true
+++



---
You are given a matrix grid with positive integers. In each operation, remove the greatest value from each row, and if multiple elements have the same greatest value, remove any one of them. After removing the greatest value from all rows, add the maximum of these values to the answer. The number of columns decreases by one after each operation. Perform these operations until the grid is empty, and return the sum of the maximum values from all operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D grid where each row contains positive integers. The grid has m rows and n columns, and the values in the grid are sorted within each row in ascending order.
- **Example:** `Input: grid = [[1, 3, 4], [2, 5, 6]]`
- **Constraints:**
	- 1 <= m, n <= 50
	- 1 <= grid[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the maximum values removed from the grid in each operation.
- **Example:** `Output: 13`
- **Constraints:**
	- The sum is calculated by adding the maximum value removed in each operation.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the sum of the maximum values from the elements removed from each row during each operation, by reducing the grid by one column at a time.

- 1. For each row in the grid, sort the values to easily access the greatest value.
- 2. In each operation, remove the greatest element from each row and find the maximum among them.
- 3. Keep track of the sum of these maximum values until the grid becomes empty.
{{< dots >}}
### Problem Assumptions ✅
- All rows are not empty and contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[1, 3, 4], [2, 5, 6]]`  \
  **Explanation:** In the first operation, we remove 4 from the first row and 6 from the second row, adding 6 to the result. In the second operation, we remove 3 from the first row and 5 from the second row, adding 5 to the result. In the final operation, we remove 1 and 2, adding 2 to the result. The total sum is 6 + 5 + 2 = 13.

- **Input:** `Input: grid = [[10]]`  \
  **Explanation:** In this case, there is only one element, 10, and it is removed in the first operation. The total sum is 10.

{{< dots >}}
## Approach 🚀
The solution involves sorting each row to easily access the maximum element and then performing the operation of removing the largest elements until the grid is empty. The result is the sum of the maximum values removed in each operation.

### Initial Thoughts 💭
- Sorting each row will allow easy access to the maximum element.
- By sorting the rows, we can directly pick the maximum element and track the maximum values in each operation.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one row and one column, so this case is not applicable.
- Ensure the solution can handle grids of the largest size, with m and n up to 50.
- Handle cases where the grid has only one row or one column.
- The solution should efficiently handle cases with maximum values for m and n.
{{< dots >}}
## Code 💻
```cpp
  int deleteGreatestValue(vector<vector<int>>& g) {
  int res = 0, si = g.size(), sj = g[0].size();
  for (auto &r : g)
      sort(begin(r), end(r));
  for (int j = 0; j < sj; ++j) {
      int max_row = 0;
      for (int i = 0; i < si; ++i) 
          max_row = max(max_row, g[i][j]);
      res += max_row;
  }
  return res;
  }
```

The function `deleteGreatestValue` calculates the sum of the greatest values in each column of a 2D matrix after sorting each row in ascending order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  int deleteGreatestValue(vector<vector<int>>& g) {
	```
	Defines the function `deleteGreatestValue` that takes a 2D vector `g` (a matrix) and returns an integer representing the sum of the greatest values in each column.

2. **Variable Initialization**
	```cpp
	  int res = 0, si = g.size(), sj = g[0].size();
	```
	Initializes the variable `res` to store the result, and calculates the number of rows (`si`) and columns (`sj`) in the 2D vector `g`.

3. **Looping**
	```cpp
	  for (auto &r : g)
	```
	Loops through each row of the 2D vector `g`.

4. **Sorting**
	```cpp
	      sort(begin(r), end(r));
	```
	Sorts each row of the 2D vector `g` in ascending order.

5. **Looping**
	```cpp
	  for (int j = 0; j < sj; ++j) {
	```
	Starts a loop to iterate through each column (`j`) of the sorted 2D vector.

6. **Variable Initialization**
	```cpp
	      int max_row = 0;
	```
	Initializes a variable `max_row` to store the maximum value in the current column during the iteration.

7. **Looping**
	```cpp
	      for (int i = 0; i < si; ++i) 
	```
	Starts a loop to iterate through each row (`i`) in the current column (`j`).

8. **Mathematical Operations**
	```cpp
	          max_row = max(max_row, g[i][j]);
	```
	Calculates the maximum value between the current `max_row` and the current element `g[i][j]` in the column.

9. **Result Calculation**
	```cpp
	      res += max_row;
	```
	Adds the maximum value found in the current column (`max_row`) to the result `res`.

10. **Return Statement**
	```cpp
	  return res;
	```
	Returns the final result `res`, which is the sum of the greatest values from each column.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n log n)
- **Average Case:** O(m * n log n)
- **Worst Case:** O(m * n log n)

The time complexity is dominated by the sorting step for each row, which takes O(n log n) per row, resulting in a total complexity of O(m * n log n).

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) since we need to store the grid, and the sorting operation requires additional space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-greatest-value-in-each-row/description/)

---
{{< youtube xWRu1KHVAIo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
