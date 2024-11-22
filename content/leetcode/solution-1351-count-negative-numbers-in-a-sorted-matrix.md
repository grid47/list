
+++
authors = ["grid47"]
title = "Leetcode 1351: Count Negative Numbers in a Sorted Matrix"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1351: Count Negative Numbers in a Sorted Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, m = grid.size();
        for(int i = 0; i < m; i++) {
            auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
            if(*grid[i].rbegin() > -1) continue;
            res += it - grid[i].rbegin();
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The objective is to count the number of negative integers in a given 2D grid (matrix) where each row is sorted in non-increasing order. This means that each row's elements are sorted from highest to lowest, and there are negative numbers at the end of each row. The solution should efficiently traverse this grid and return the total count of negative integers.

### Approach
To solve the problem, we can leverage the sorted property of the rows. Since each row is sorted, we can efficiently find the count of negative numbers by using binary search techniques.

1. **Iterate Through Each Row**: We will traverse each row of the grid.
2. **Binary Search**: For each row, we will use `upper_bound` to find the first element that is less than or equal to -1. The position returned by `upper_bound` allows us to determine how many elements are negative in that row.
3. **Count the Negatives**: The difference between the position returned and the beginning of the row will give the count of negative numbers for that row.
4. **Aggregate the Count**: Sum the counts from all rows to get the total number of negative integers in the grid.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, m = grid.size();
```
- The `countNegatives` function begins by initializing a variable `res` to hold the total count of negative numbers and retrieves the number of rows in the grid using `m = grid.size()`.

```cpp
        for(int i = 0; i < m; i++) {
            auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
```
- A loop iterates through each row of the grid.
- The `upper_bound` function is called with `grid[i].rbegin()` and `grid[i].rend()` as iterators for the current row, searching for `-1`. This function returns an iterator pointing to the first element in the row that is greater than `-1`.

```cpp
            if(*grid[i].rbegin() > -1) continue;
```
- This conditional checks if the last element of the row (the smallest) is greater than `-1`. If it is, that means there are no negative numbers in the row, and we can skip further calculations for that row.

```cpp
            res += it - grid[i].rbegin();
        }
        return res;
    }
};
```
- If there are negative numbers, the difference `it - grid[i].rbegin()` gives the count of negative numbers in that row, which is then added to `res`.
- After processing all rows, the function returns the total count of negative integers.

### Complexity Analysis
- **Time Complexity**:
  - The overall time complexity of the function is \(O(m \log n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the grid. This complexity arises from performing a binary search (`upper_bound`) on each row.

- **Space Complexity**:
  - The space complexity is \(O(1)\) since we are using a constant amount of additional space for the counters and iterators.

### Conclusion
The `countNegatives` function in this `Solution` class efficiently counts the number of negative integers in a 2D grid with rows sorted in non-increasing order. By utilizing binary search, it optimizes the search for negative numbers in each row, significantly reducing the time complexity compared to a naive approach of iterating through every element in the grid.

This implementation is particularly useful in coding interviews and competitive programming scenarios where efficiency is crucial. The ability to recognize and utilize the properties of sorted data structures to enhance performance is a valuable skill for software developers. 

In practical applications, counting elements based on specific conditions is a common task, and mastering such techniques can lead to improved problem-solving strategies and more efficient algorithms. This method exemplifies how to leverage data organization to achieve optimal results, making it a valuable addition to a developer's toolkit.


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
