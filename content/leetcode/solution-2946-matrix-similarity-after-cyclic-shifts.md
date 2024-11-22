
+++
authors = ["grid47"]
title = "Leetcode 2946: Matrix Similarity After Cyclic Shifts"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2946: Matrix Similarity After Cyclic Shifts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "7RGWUCc5IHw"
youtube_upload_date="2023-11-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7RGWUCc5IHw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for (const auto& l : mat) {
            int n = l.size();
            for (int i = 0; i < n; ++i) {
                if (l[i] != l[(i + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement:
The task is to determine if each row in a given matrix is similar to the others based on a circular shift operation. A row is considered similar to another if it can be transformed into the other by rotating it `k` positions to the right.

Given a matrix `mat` and an integer `k`, you need to check if all rows in the matrix can be made similar to each other by shifting each row by `k` positions.

### Approach:
The key observation in solving this problem is recognizing that the similarity condition relies on a circular shift of the elements in each row. When we shift a row to the right by `k` positions, the element at index `i` in the original row moves to index `(i + k) % n` in the shifted row, where `n` is the length of the row.

For each row, we will check whether it is similar to itself when shifted by `k` positions. Specifically, for each element in the row, we check if it matches the element at the corresponding shifted index. If this condition holds for all elements in all rows, we return `true`. Otherwise, we return `false`.

### Code Breakdown (Step by Step):

#### 1. **Loop Through Each Row**:
We start by iterating over each row in the matrix. The matrix `mat` consists of rows, and for each row, we check if it satisfies the similarity condition by shifting the elements by `k` positions.

```cpp
for (const auto& l : mat) {
    int n = l.size();  // Get the number of elements in the current row
```
The variable `l` represents the current row. `n` is the length of the row, which we will use to determine the shifted indices.

#### 2. **Check for Similarity by Shifting**:
For each row, we iterate over each element at index `i` and compare it with the element at the shifted position `(i + k) % n`. The `% n` ensures that the shifting operation wraps around circularly. If any element does not match its corresponding shifted element, the row is not similar, and we immediately return `false`.

```cpp
for (int i = 0; i < n; ++i) {
    if (l[i] != l[(i + k) % n]) {
        return false;  // If elements do not match, the row is not similar
    }
}
```

#### 3. **Return True if All Rows are Similar**:
After checking all elements in all rows, if no discrepancies were found, we return `true`, indicating that all rows are similar based on the circular shift.

```cpp
return true;  // All rows are similar by shifting by k positions
```

### Complexity:

#### Time Complexity:
- We iterate through each row and each element within the row.
- For each row, checking if the elements match their circularly shifted positions takes `O(n)` time, where `n` is the length of the row.
- The number of rows in the matrix is `m`. Therefore, the overall time complexity is:
\[
O(m \cdot n)
\]
where `m` is the number of rows, and `n` is the number of columns in each row.

#### Space Complexity:
- The space complexity is `O(1)` because we only use a few additional variables to perform the computation and do not require any additional data structures that scale with input size.

### Conclusion:
This solution efficiently checks whether all rows in the matrix are similar by performing circular shifts. The use of modulus (`%`) to handle the circular nature of the shift ensures correctness while keeping the code simple. Given the problem's constraints, the solution's time complexity of `O(m * n)` is optimal, where `m` is the number of rows and `n` is the number of columns.

#### Key Insights:
- **Circular Shift**: The core idea is recognizing that a circular shift can be handled with the modulus operation, which allows elements to wrap around.
- **Efficient Comparison**: By checking each row individually and stopping early if a mismatch is found, we avoid unnecessary computations.
- **Optimal Complexity**: The solution runs in linear time relative to the number of elements in the matrix, making it efficient for large inputs.

In summary, the algorithm efficiently checks for similarity between rows in the matrix by comparing elements with their circularly shifted counterparts, making it a good fit for this type of problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/)

---
{{< youtube 7RGWUCc5IHw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
