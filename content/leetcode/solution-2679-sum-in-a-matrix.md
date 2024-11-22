
+++
authors = ["grid47"]
title = "Leetcode 2679: Sum in a Matrix"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2679: Sum in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "oL_BwmPMkng"
youtube_upload_date="2023-05-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/oL_BwmPMkng/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        int res = 0;
        
        int m = nums.size(), n = nums[0].size();
        
        for(int i = 0; i < m; i++)
        sort(nums[i].rbegin(), nums[i].rend());
        
        for(int i = 0; i < n; i++) {
            int mx = nums[0][i];
            for(int j = 0; j < m; j++) {
                mx = max(mx, nums[j][i]);
            }
            res += mx;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves calculating the sum of the maximum elements from each column in a matrix after sorting each row in descending order. Given a matrix, you need to sort each row in descending order and then find the maximum value in each column. The goal is to return the sum of these maximum values.

### Approach

The approach to solving this problem involves two main steps:

1. **Sorting the rows**: Each row in the matrix is sorted in descending order.
2. **Finding the maximum of each column**: After sorting, for each column, we select the maximum element and accumulate it in the result.

The matrix is given as a 2D vector of integers, and we need to apply the sorting and the column-wise maximum selection to compute the sum.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Result and Matrix Dimensions

```cpp
int res = 0;
int m = nums.size(), n = nums[0].size();
```

- **Line 1**: We initialize `res` to 0, which will hold the final result (sum of the maximum values from each column).
- **Line 2**: `m` is assigned the number of rows in the matrix (`nums.size()`), and `n` is assigned the number of columns (`nums[0].size()`).

#### Step 2: Sort Each Row in Descending Order

```cpp
for(int i = 0; i < m; i++)
    sort(nums[i].rbegin(), nums[i].rend());
```

- **Line 3-4**: We loop through each row of the matrix (`i` from 0 to `m-1`), and for each row, we sort it in descending order. The `sort` function with `rbegin()` and `rend()` sorts the row in reverse order (descending).
    - `nums[i].rbegin()` is an iterator pointing to the last element of the row (rightmost element).
    - `nums[i].rend()` is an iterator pointing just before the first element of the row.
    - Sorting in descending order ensures that the largest element of each row is at the beginning of the row.

#### Step 3: Find the Maximum in Each Column

```cpp
for(int i = 0; i < n; i++) {
    int mx = nums[0][i];
    for(int j = 0; j < m; j++) {
        mx = max(mx, nums[j][i]);
    }
    res += mx;
}
```

- **Line 5-6**: We iterate over each column (`i` from 0 to `n-1`), and for each column, we initialize `mx` to the first element of the column (`nums[0][i]`).
- **Line 7-9**: We then iterate over each row (`j` from 0 to `m-1`) to find the maximum element in the current column. We update `mx` to be the maximum of its current value and the value at `nums[j][i]`, which is the element in the `j`-th row and `i`-th column.
    - By the end of this loop, `mx` will contain the maximum value in column `i`.
- **Line 10**: We add the value of `mx` (the maximum value in the current column) to the result `res`.

#### Step 4: Return the Result

```cpp
return res;
```

- **Line 11**: After iterating through all the columns, the sum of the maximum values from each column is stored in `res`, which we then return.

### Complexity

#### Time Complexity:

1. Sorting each row takes **O(n log n)**, where `n` is the number of columns in a row. Since there are `m` rows, the sorting step for all rows takes **O(m * n log n)**.
2. Finding the maximum in each column involves iterating through each row, which takes **O(m)** for each column. Since there are `n` columns, this step takes **O(m * n)**.

Thus, the total time complexity is:

- **O(m * n log n)** for sorting the rows.
- **O(m * n)** for finding the maximum in each column.

Overall, the time complexity of the solution is dominated by the sorting step, so the total time complexity is:

- **O(m * n log n)**

#### Space Complexity:

- **O(1)** additional space. The sorting operation is done in-place on the matrix, and we only use a constant amount of extra space for the result and iterators.
- Thus, the space complexity is **O(1)**, as no extra data structures are used beyond the input matrix and the result variable.

### Conclusion

The solution provided efficiently solves the problem of summing the maximum values from each column in a matrix after sorting each row in descending order. It leverages sorting to arrange the elements in each row and uses a simple loop to find the maximum element in each column. The algorithm is optimized to work in **O(m * n log n)** time, making it efficient for large matrices with `m` rows and `n` columns. The space complexity is **O(1)**, as the matrix is modified in place without the need for additional data structures. This solution is optimal for most practical use cases where performance and memory usage are critical factors.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-in-a-matrix/description/)

---
{{< youtube oL_BwmPMkng >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
