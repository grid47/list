
+++
authors = ["grid47"]
title = "Leetcode 2661: First Completely Painted Row or Column"
date = "2024-02-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2661: First Completely Painted Row or Column in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-XgxrCAuu68"
youtube_upload_date="2023-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-XgxrCAuu68/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, long> r, c, mtx;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            mtx[mat[i][j]] = (long) i * 100000 + j;
        }
        for(int i = 0; i < arr.size(); i++) {
            long k = mtx[arr[i]];
            long x = k / 100000;
            long y = k % 100000;
            r[x]++;

            if(r[x] == n) return i;
            c[y]++;
            if(c[y] == m) return i;
            // cout << x << " "<< y << " " << r[x] << " " << c[y] << " " << m << " " << n << "\n";            
            // if(i == 2) break;
        }
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the first index in a given array `arr` such that all elements in the corresponding row or column of a matrix `mat` are present in the array `arr`. More specifically, the task is to determine the first element in `arr` that, when processed, causes one of the rows or one of the columns in `mat` to be completely covered with elements from `arr`. If no such index exists, return `-1`.

### Approach

The approach can be broken down into several key steps:
1. **Mapping the Matrix**: We start by creating a map that associates each value in the matrix `mat` with its corresponding position (row, column).
2. **Tracking the Row and Column Counts**: We use two hash maps `r` and `c` to keep track of how many times each row and column has been "covered" by the elements seen so far in `arr`.
3. **Simulating the Process**: We then iterate over the array `arr` and for each element:
   - Find the corresponding position in the matrix.
   - Update the counts for the row and column where that element is located.
   - If any row or column becomes fully covered, we immediately return the current index.
4. **Returning the Result**: If we finish processing all elements of `arr` without finding a fully covered row or column, we return `-1`.

This approach ensures that we process each element of `arr` only once, making the solution efficient.

### Code Breakdown (Step by Step)

```cpp
int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int, long> r, c, mtx;
    int m = mat.size(), n = mat[0].size();
```
- **Line 1-3**: We define the function `firstCompleteIndex` which takes the array `arr` and matrix `mat` as inputs.
- **Line 2**: Three unordered maps are initialized:
  - `r`: Tracks how many elements of each row are present in `arr`.
  - `c`: Tracks how many elements of each column are present in `arr`.
  - `mtx`: Maps each matrix element to its position in the matrix (using a long integer where the first part represents the row and the second part represents the column).
- **Line 3**: We extract the number of rows (`m`) and columns (`n`) from the matrix.

```cpp
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            mtx[mat[i][j]] = (long) i * 100000 + j;
        }
```
- **Line 4-6**: In this nested loop, we iterate over each element of the matrix `mat` and populate the map `mtx`. The key is the matrix element, and the value is a long integer that encodes both its row and column by multiplying the row index by 100000 and adding the column index.

```cpp
    for(int i = 0; i < arr.size(); i++) {
        long k = mtx[arr[i]];
        long x = k / 100000;
        long y = k % 100000;
        r[x]++;
```
- **Line 7-9**: We start processing the elements of `arr`. For each element:
  - `k = mtx[arr[i]]`: We retrieve the position of the current element in the matrix from the map `mtx`.
  - `x = k / 100000`: This extracts the row index of the matrix element.
  - `y = k % 100000`: This extracts the column index of the matrix element.
  - `r[x]++`: We increment the count of how many elements in row `x` have been seen so far.

```cpp
        if(r[x] == n) return i;
```
- **Line 10**: If the count of elements in row `x` has reached the total number of columns `n`, this means that the entire row has been covered, and we immediately return the current index `i` from `arr`.

```cpp
        c[y]++;
        if(c[y] == m) return i;
```
- **Line 11-12**: We perform the same check for columns:
  - `c[y]++`: We increment the count of how many elements in column `y` have been seen so far.
  - `if(c[y] == m) return i;`: If the count of elements in column `y` has reached the total number of rows `m`, the entire column has been covered, and we return the current index `i` from `arr`.

```cpp
    }
    return -1;
}
```
- **Line 13-14**: If no row or column becomes fully covered after processing all elements in `arr`, we return `-1` to indicate that no such index exists.

### Complexity

#### Time Complexity:
- Constructing the `mtx` map takes **O(m * n)** time, where `m` is the number of rows and `n` is the number of columns in the matrix.
- Processing the array `arr` takes **O(k)** time, where `k` is the size of the array. For each element, we perform constant-time operations (lookup in the map and updates to the row and column counts).
- Therefore, the overall time complexity is **O(m * n + k)**, where `m * n` is the time spent building the `mtx` map and `k` is the time spent processing `arr`.

#### Space Complexity:
- The space complexity is dominated by the space used for the map `mtx`, which stores at most `m * n` entries, each mapping a matrix element to its position. Therefore, the space complexity is **O(m * n)**.

### Conclusion

This solution efficiently tracks how many elements from each row and column of the matrix are covered by the elements of `arr`. By using hash maps to keep track of row and column counts, we can quickly determine whether any row or column becomes fully covered as we process the elements in `arr`. The solution has a time complexity of **O(m * n + k)** and space complexity of **O(m * n)**, making it efficient for large matrices and arrays. The use of long integers to encode matrix positions in a single map is an innovative way to handle matrix lookups and avoids the need for complex nested structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/first-completely-painted-row-or-column/description/)

---
{{< youtube -XgxrCAuu68 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
