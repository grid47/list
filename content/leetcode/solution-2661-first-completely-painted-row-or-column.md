
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
comments = true
+++



---
You are given a list of integers `arr` and a 2D matrix `mat`. The list `arr` contains all the integers from the range [1, m * n] and represents the order in which you paint the cells of `mat`. Each integer in `arr` corresponds to a cell in `mat` that is being painted. The goal is to find the smallest index `i` at which either a row or a column becomes completely painted.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two elements: an array `arr` and a 2D integer matrix `mat`.
- **Example:** `Input: arr = [3, 1, 2, 4], mat = [[4, 1], [3, 2]]`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 1 <= m * n <= 10^5
	- 1 <= arr[i], mat[r][c] <= m * n
	- All integers in `arr` are unique.
	- All integers in `mat` are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the smallest index `i` at which either a row or a column is completely painted.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be a non-negative integer representing the smallest index `i`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to track when a row or column is completely painted by checking each number in `arr` and marking the corresponding cell in `mat`.

- Step 1: Create mappings for each value in `mat` to its corresponding row and column index.
- Step 2: Initialize counters for each row and column to keep track of how many cells are painted.
- Step 3: Iterate through the array `arr` and for each number, increment the counters for the corresponding row and column.
- Step 4: Check if any row or column is completely painted. If so, return the index `i`.
{{< dots >}}
### Problem Assumptions ✅
- Each element in `arr` corresponds to a unique position in `mat`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [3, 1, 2, 4], mat = [[4, 1], [3, 2]]`  \
  **Explanation:** The cells are painted in the order: arr[0] = 3, arr[1] = 1, arr[2] = 2, arr[3] = 4. After arr[2], both the first row and second column are completely painted, so the smallest index is 2.

- **Input:** `Input: arr = [8, 5, 1, 7, 3, 4, 2, 6], mat = [[1, 5, 7], [2, 8, 6], [3, 4, 9]]`  \
  **Explanation:** The cells are painted in the order: arr[0] = 8, arr[1] = 5, arr[2] = 1, arr[3] = 7. After arr[3], the second column is completely painted, so the smallest index is 3.

{{< dots >}}
## Approach 🚀
We will track the painting process of each row and column using counters. By mapping each element of `arr` to its position in `mat`, we can update the counters efficiently and check when a row or column becomes fully painted.

### Initial Thoughts 💭
- We need to efficiently track the number of painted cells in each row and column.
- Once a row or column reaches its full count, we can immediately return the index.
- A dictionary can be used to store the row and column indexes for each element in `mat`.
{{< dots >}}
### Edge Cases 🌐
- There should always be at least one row and one column in `mat`.
- The solution should handle large matrices and arrays efficiently.
- The solution should handle matrices with a single row or column.
- Ensure that the solution works within the given constraints.
{{< dots >}}
## Code 💻
```cpp
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
```

This function returns the index of the first element in 'arr' such that all occurrences of the corresponding element in the 2D matrix 'mat' are marked, based on row and column counts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
	```
	The function starts by taking a vector 'arr' and a 2D matrix 'mat' as input. The goal is to find the first index in 'arr' such that all occurrences of that number in 'mat' are fully marked.

2. **Variable Initialization**
	```cpp
	    unordered_map<int, long> r, c, mtx;
	```
	We initialize three unordered maps: 'r' for tracking row occurrences, 'c' for column occurrences, and 'mtx' to store the row and column index of each element in 'mat'.

3. **Matrix Size Calculation**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	We retrieve the dimensions of the matrix 'mat', where 'm' is the number of rows and 'n' is the number of columns.

4. **Matrix Mapping**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	We start iterating over the rows of the matrix.

5. **Matrix Mapping**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	We iterate over each element in the row, accessing both the row index 'i' and column index 'j'.

6. **Matrix Element Mapping**
	```cpp
	        mtx[mat[i][j]] = (long) i * 100000 + j;
	```
	We store the row and column indices of each element in the 'mtx' map, using a combination of the row index and column index for a unique identifier.

7. **Matrix Mapping End**
	```cpp
	    }
	```
	End of the loop for mapping the matrix elements to their respective row and column indices.

8. **Main Loop**
	```cpp
	    for(int i = 0; i < arr.size(); i++) {
	```
	We iterate over each element in the array 'arr' to check if it satisfies the condition of completing all occurrences in 'mat'.

9. **Element Mapping Retrieval**
	```cpp
	        long k = mtx[arr[i]];
	```
	For the current element in 'arr', we retrieve its row-column indices from 'mtx'.

10. **Row Index Extraction**
	```cpp
	        long x = k / 100000;
	```
	We extract the row index 'x' from the combined index 'k' (using division by 100000).

11. **Column Index Extraction**
	```cpp
	        long y = k % 100000;
	```
	We extract the column index 'y' from the combined index 'k' (using the remainder operation).

12. **Row Occurrence Update**
	```cpp
	        r[x]++;
	```
	We increment the count for the row index 'x' to track how many occurrences of the element have been marked in that row.

13. **Check Row Completion**
	```cpp
	        if(r[x] == n) return i;
	```
	If all occurrences in the row 'x' are marked (i.e., the row count equals the number of columns 'n'), we return the current index 'i' from 'arr'.

14. **Column Occurrence Update**
	```cpp
	        c[y]++;
	```
	We increment the count for the column index 'y' to track how many occurrences of the element have been marked in that column.

15. **Check Column Completion**
	```cpp
	        if(c[y] == m) return i;
	```
	If all occurrences in the column 'y' are marked (i.e., the column count equals the number of rows 'm'), we return the current index 'i' from 'arr'.

16. **Return Not Found**
	```cpp
	    return -1;
	```
	If no such index in 'arr' satisfies the condition, return -1 to indicate failure.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate through each element in `arr` once, where n is the total number of elements.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the storage of row and column counts and the dictionary `mtx`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/first-completely-painted-row-or-column/description/)

---
{{< youtube -XgxrCAuu68 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
