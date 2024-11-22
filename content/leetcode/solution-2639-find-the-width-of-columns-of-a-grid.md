
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the width of each column in a given 2D grid (matrix). The width of a column is defined as the maximum length of the elements in that column when represented as strings. Negative numbers and positive numbers need to be handled correctly as they may have different lengths when converted to strings (e.g., the number `-45` is of length 3 and `45` is of length 2). We need to determine the width for each column in the grid.

### Approach

The approach to solving this problem involves iterating over each column of the grid and calculating the maximum length of the elements in each column when represented as strings. To achieve this, we follow these steps:

1. **Iterate through Columns**:
   - We start by iterating over each column of the grid (the grid has `n` columns). For each column, we calculate the width by examining each element in the column.
   
2. **Calculate Length of Each Element**:
   - For each element in the column, we convert it to its string representation and measure the number of characters in that string. The length of the string is the width of that particular element.
   - We handle negative numbers separately as they require an additional character for the minus sign.
   
3. **Track Maximum Length for Each Column**:
   - For each column, we track the maximum length across all the elements in that column, as the width of a column is determined by the largest element in that column when represented as a string.

4. **Return the Result**:
   - After calculating the maximum width for each column, we return the widths as a vector.

### Code Breakdown (Step by Step)

#### 1. `get(int num)` Function

The `get` function is responsible for calculating the number of characters (length) in the string representation of a given integer, including the handling of negative numbers.

- **Step 1.1**: If the number is `0`, the function returns `1` because the string representation of `0` has a length of `1`.
  
- **Step 1.2**: If the number is negative, we initialize `len` to `1`, accounting for the minus sign. Otherwise, `len` is initialized to `0`.

- **Step 1.3**: We then take the absolute value of the number to handle negative values and count how many digits the number has by continuously dividing the number by `10`. Each division reduces the number by a factor of `10`, and the loop continues until the number becomes `0`. For each iteration, the `len` is incremented.

- **Step 1.4**: Finally, the function returns the length (`len`) of the number when converted to a string.

```cpp
int get(int num) {
    if(num == 0) return 1;  // For 0, return length 1
    int len = num < 0 ? 1 : 0;  // If negative, add 1 for the minus sign
    num = abs(num);  // Work with absolute value
    while(num > 0) {  // Count the number of digits
        len++;
        num /= 10;  // Remove the last digit
    }
    return len;  // Return the length
}
```

#### 2. `findColumnWidth(vector<vector<int>>& grid)` Function

This function calculates the width of each column in the grid and returns a vector with the maximum width of each column.

- **Step 2.1**: We first get the dimensions of the grid, `m` (number of rows) and `n` (number of columns).
  
- **Step 2.2**: We initialize an array `ans` of size `n` (one element for each column) to store the maximum length for each column.

- **Step 2.3**: For each column (from `i = 0` to `n-1`), we initialize `len` to `0`. This variable tracks the maximum length of the elements in the current column.

- **Step 2.4**: We iterate over each row `j` of the grid and calculate the length of the element `grid[j][i]` using the `get` function. We update `len` to the maximum length found so far in that column.

- **Step 2.5**: After examining all the rows in the column, we store the maximum length for that column in the `ans` vector.

- **Step 2.6**: Finally, we return the `ans` vector containing the maximum width for each column.

```cpp
vector<int> findColumnWidth(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();  // Get the number of rows (m) and columns (n)
    vector<int> ans(n, 0);  // Initialize the result vector with 0s
    
    // Iterate over each column
    for(int i = 0; i < n; i++) {
        int len = 0;
        // Iterate over each row in the current column
        for(int j = 0; j < m; j++) {
            len = max(len, get(grid[j][i]));  // Get the maximum length in the current column
        }
        ans[i] = len;  // Store the maximum length for the column
    }
    
    return ans;  // Return the result vector
}
```

### Complexity

#### Time Complexity:
- **`get(int num)` function**: This function calculates the number of digits in a number. For a given number, the time complexity is \(O(\log(\text{num}))\) because each division by `10` reduces the number by a factor of `10`.
- **Main Loop**: We iterate over all columns and rows of the grid. For each element, we call the `get` function to compute its length. Hence, the time complexity of iterating over all elements in the grid is \(O(m \cdot n \cdot \log(\text{max\_element}))\), where `max_element` is the largest number in the grid.

Thus, the overall time complexity is:

\[
O(m \cdot n \cdot \log(\text{max\_element}))
\]

#### Space Complexity:
- **`ans` Vector**: We store the maximum width for each column, so the space complexity is \(O(n)\), where `n` is the number of columns.
- **Temporary Variables**: We use a few temporary variables like `len` and `m`/`n` but they do not depend on the size of the grid, so their space complexity is constant, i.e., \(O(1)\).

Thus, the overall space complexity is:

\[
O(n)
\]

### Conclusion

This solution efficiently computes the maximum width for each column in the grid by leveraging a helper function (`get`) to calculate the length of each element when represented as a string. It uses a simple double iteration through the grid: the outer loop iterates over the columns and the inner loop examines each element within the column. The time complexity is driven by the number of rows, columns, and the number of digits in the largest number in the grid. This approach ensures that the problem is solved in an efficient manner, suitable for moderately large grids.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/)

---
{{< youtube RSRjK563HVY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
