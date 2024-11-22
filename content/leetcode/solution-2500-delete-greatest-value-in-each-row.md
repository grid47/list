
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to delete the greatest value from each column in a given 2D grid and return the sum of the deleted values. The process of deleting the greatest value involves sorting the rows of the grid in non-decreasing order and then iterating over each column to pick the largest remaining element. This needs to be done efficiently, and the result should be the sum of the greatest values deleted from each column.

### Approach

The key idea here is to:
1. **Sort the rows of the grid**: Sorting each row ensures that for every column, the maximum value is the last element in each row.
2. **Iterate through each column**: For each column, pick the largest element from the sorted rows (which will be the last element after sorting each row).
3. **Sum the largest values**: The sum of the maximum values from each column will be the final result.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int res = 0, si = g.size(), sj = g[0].size();
```

The first step initializes two variables:
- `res`: This will store the sum of the maximum values that are "deleted" from each column.
- `si`: This stores the number of rows in the grid `g` (i.e., the number of elements in the outer vector).
- `sj`: This stores the number of columns in the grid `g` (i.e., the number of elements in the inner vectors).

#### Step 2: Sort Each Row

```cpp
for (auto &r : g)
    sort(begin(r), end(r));
```

The next step sorts each row of the grid in non-decreasing order. The `sort` function is applied to each row `r` of the grid `g`, ensuring that for any column, the largest value will be the last element of the row after sorting.

- **Why sort each row?** Sorting each row ensures that when we pick the value from each row at any column index, it will always be the largest remaining value in that row.
  
For example, if a row initially contains the elements `[3, 1, 2]`, sorting it will make it `[1, 2, 3]`. The largest element in that row will then be at the end (`3`), which is what we need to "delete."

#### Step 3: Iterate Over Columns and Find Maximum Value

```cpp
for (int j = 0; j < sj; ++j) {
    int max_row = 0;
    for (int i = 0; i < si; ++i) 
        max_row = max(max_row, g[i][j]);
    res += max_row;
}
```

After sorting each row, the algorithm iterates over each column `j` and finds the maximum value for that column across all rows:

- **Outer loop**: The outer loop runs through each column `j` (from `0` to `sj - 1`).
- **Inner loop**: The inner loop iterates through all rows `i` (from `0` to `si - 1`) and compares the value in column `j` of the current row `g[i][j]` with the current maximum value `max_row`.
- **Finding max for column**: For each column, the algorithm computes the maximum value from all rows and stores it in `max_row`.

Once the maximum value for a column is determined, it is added to `res` to track the sum of the greatest values deleted from each column.

#### Step 4: Return the Result

```cpp
return res;
```

Once all columns have been processed and the maximum values have been accumulated in `res`, the function returns the total sum of these values. This sum is the desired result.

### Complexity Analysis

#### Time Complexity:

- **Sorting each row**: Sorting each row takes \(O(n \log n)\), where \(n\) is the number of columns in the row. The sorting operation is applied to every row, so for `m` rows, the total time complexity for sorting is \(O(m \cdot n \log n)\).
- **Finding the maximum for each column**: For each column, we check every row to find the maximum value. This operation takes \(O(m)\) time per column, and since there are `n` columns, the total time complexity for this step is \(O(m \cdot n)\).

Thus, the overall time complexity is dominated by the sorting step, which is \(O(m \cdot n \log n)\), where `m` is the number of rows and `n` is the number of columns.

#### Space Complexity:

- **Space for the grid**: The grid `g` itself requires \(O(m \cdot n)\) space, where `m` is the number of rows and `n` is the number of columns.
- **Auxiliary space for sorting**: The sorting operation itself requires extra space, but this depends on the sorting algorithm used. If we use the standard C++ `sort` function, which uses a form of quicksort, the extra space used for sorting each row is \(O(\log n)\) per row. Since sorting is done in place, the space complexity for sorting is \(O(m \cdot \log n)\).

Therefore, the overall space complexity is \(O(m \cdot n)\) due to the storage required for the grid.

### Conclusion

In conclusion, the solution efficiently computes the sum of the greatest values deleted from each column of a 2D grid. By sorting each row and then iterating over the columns to find the largest value, the algorithm ensures that the task is completed in an optimal manner. The time complexity of \(O(m \cdot n \log n)\) makes the solution suitable for moderate-sized grids, and the space complexity of \(O(m \cdot n)\) is acceptable given that we only store the grid itself.

- **Time Complexity**: \(O(m \cdot n \log n)\), where `m` is the number of rows and `n` is the number of columns in the grid.
- **Space Complexity**: \(O(m \cdot n)\), due to the storage required for the grid.

This solution is both time-efficient and space-efficient for the problem at hand.

[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-greatest-value-in-each-row/description/)

---
{{< youtube xWRu1KHVAIo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
