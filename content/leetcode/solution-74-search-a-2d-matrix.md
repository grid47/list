
+++
authors = ["grid47"]
title = "Leetcode 74: Search a 2D Matrix"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 74: Search a 2D Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/74.webp"
youtube = "x-dYOtIudzc"
youtube_upload_date="2024-02-28"
youtube_thumbnail="https://i.ytimg.com/vi/x-dYOtIudzc/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/74.webp" 
    alt="A soft, glowing grid with a pinpoint highlighting the search area."
    caption="Solution to LeetCode 74: Search a 2D Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtx, int target) {
        int m = mtx.size(), n = mtx[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = l + (r - l) /2;
            int rw = mid / n, c = mid % n, val = mtx[rw][c];
                 if(val == target) return true;
            else if(val  > target) r = mid - 1;
            else                   l = mid + 1;
        }
        return false;
    }
};
{{< /highlight >}}
---


### 🔍 **Search in a 2D Matrix (Sorted Rows and Columns)**

In this problem, you are asked to search for a target value in a **2D matrix** where each row and each column is sorted in ascending order. The goal is to determine whether the target value exists in the matrix using an efficient approach without having to check every element.

Given the following constraints:
1. **Rows are sorted in ascending order**.
2. **Columns are sorted in ascending order**.

### 🚀 **Approach**

The structure of the matrix — where both rows and columns are sorted — allows us to search for the target efficiently, using **binary search**, rather than checking every single element (which would be inefficient).

The idea is to **flatten the 2D matrix into a 1D array**, and then perform **binary search** on this 1D representation. By doing this, we take advantage of the sorted order of both the rows and columns, significantly improving the search time.

#### Key Insights:
1. **Sorted Rows and Columns**: The matrix is sorted such that each row and each column increases in value.
2. **Binary Search**: Flattening the matrix into a 1D array allows us to apply binary search, which is optimal for sorted sequences.
3. **Index Mapping**: The index in the 1D array corresponds to a position in the 2D matrix, so we can efficiently search across both dimensions.

### 📝 **Code Breakdown**

#### Step 1: Define Matrix Dimensions
```cpp
int m = mtx.size(), n = mtx[0].size();
```
- We first get the number of rows `m` and the number of columns `n` from the matrix. This will help us calculate the correct index mapping in the flattened 1D array.

#### Step 2: Initialize Binary Search Range
```cpp
int l = 0, r = m * n - 1;
```
- We initialize two pointers `l` (left) and `r` (right) representing the search range in the 1D array.
- The total number of elements in the matrix is `m * n`, so `l = 0` and `r = m * n - 1`.

#### Step 3: Perform Binary Search
```cpp
while(l <= r) {
    int mid = l + (r - l) / 2;
    int rw = mid / n, c = mid % n, val = mtx[rw][c];
    if(val == target) return true;
    else if(val > target) r = mid - 1;
    else l = mid + 1;
}
```
- **Binary Search Loop**:
    - While `l` is less than or equal to `r`, we calculate the middle index `mid`.
    - `mid / n` gives the row index `rw` in the matrix, and `mid % n` gives the column index `c`.
    - We then check the value at this position (`mtx[rw][c]`) against the target value.
    - If `val == target`, we return `true` as the target is found.
    - If `val > target`, we search in the left half by adjusting `r` to `mid - 1`.
    - If `val < target`, we search in the right half by adjusting `l` to `mid + 1`.

#### Step 4: Return False if Target is Not Found
```cpp
return false;
```
- If the binary search completes without finding the target, return `false` to indicate that the target is not present in the matrix.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(log(m * n))**:
    - We perform **binary search** on the 1D flattened array with `m * n` elements.
    - The time complexity of binary search on a sequence of size `m * n` is `O(log(m * n))`.

#### Space Complexity:
- **O(1)**:
    - The algorithm uses a constant amount of space to store the binary search pointers (`l`, `r`) and the index calculations.
    - No additional space is used, making the space complexity **O(1)**.

### 🎯 **Conclusion**

This solution efficiently searches for the target element in a 2D matrix by applying **binary search** on a flattened 1D array representation of the matrix. The sorted order of the matrix rows and columns allows us to utilize the binary search to reduce the time complexity to **O(log(m * n))**, which is optimal for large matrices. With **O(1)** space complexity, the solution avoids using extra memory, making it ideal for memory-constrained environments.

This approach highlights the power of leveraging sorting properties in data structures like matrices to improve search efficiency. By transforming the matrix into a sequence suitable for binary search, we achieve faster results and can handle larger datasets effectively.

---

### 🌟 **Key Takeaways**
- **Binary search** is highly efficient for sorted arrays and matrices.
- Flattening a 2D matrix into a 1D array allows you to apply binary search without extra space usage.
- Always consider how the structure of your data (like sorted rows and columns) can help optimize your search or sorting algorithms.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/search-a-2d-matrix/description/)

---
{{< youtube x-dYOtIudzc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
