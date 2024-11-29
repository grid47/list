
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
comments = true
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
You are given an m x n matrix where each row is sorted in non-decreasing order, and the first integer of each row is greater than the last integer of the previous row. Given a target integer, return true if the target exists in the matrix or false otherwise. The solution must have a time complexity of O(log(m * n)).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a matrix of size m x n with sorted rows and specific order between consecutive rows.
- **Example:** `matrix = [[2, 4, 6], [8, 10, 12], [14, 16, 18]], target = 10`
- **Constraints:**
	- 1 <= m, n <= 100
	- -104 <= matrix[i][j], target <= 104

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the target is present in the matrix; otherwise, return false.
- **Example:** `true`
- **Constraints:**
	- The function should return a boolean value indicating the presence of the target in the matrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently search for the target in the matrix using binary search.

- Flatten the matrix into a 1D array (conceptually).
- Use binary search to check if the target exists within the range of the flattened matrix.
{{< dots >}}
### Problem Assumptions ✅
- The matrix has at least one element.
- Matrix rows and columns are sorted in non-decreasing order, and no elements are repeated across rows.
{{< dots >}}
## Examples 🧩
- **Input:** `matrix = [[2, 4, 6], [8, 10, 12], [14, 16, 18]], target = 10`  \
  **Explanation:** The target 10 is present at the second row and second column, so the answer is true.

- **Input:** `matrix = [[1, 5, 9], [11, 13, 15], [17, 19, 21]], target = 8`  \
  **Explanation:** The target 8 is not present in the matrix, so the answer is false.

{{< dots >}}
## Approach 🚀
To achieve the required time complexity of O(log(m * n)), we can treat the matrix as a flattened array and apply binary search over it.

### Initial Thoughts 💭
- The matrix has sorted rows and columns.
- A simple binary search over the matrix could help find the target efficiently.
- By viewing the matrix as a 1D array, binary search can be applied directly to find the target with O(log(m * n)) complexity.
{{< dots >}}
### Edge Cases 🌐
- If the matrix is empty, return false immediately.
- Consider the performance of the binary search when the matrix size is at the upper limit (100 x 100).
- Ensure that the target value falls within the allowed range (-104 to 104).
- The function must run in O(log(m * n)) time.
{{< dots >}}
## Code 💻
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n, col = mid % n;
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}
```

This code efficiently searches for a target value in a 2D matrix using a modified binary search approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
	```
	Declares a function `searchMatrix` that takes a 2D matrix and a target value as input and returns a boolean indicating whether the target is found.

2. **Variable Initialization**
	```cpp
	    int m = matrix.size(), n = matrix[0].size();
	```
	Initializes variables `m` and `n` to store the number of rows and columns in the matrix.

3. **Variable Initialization**
	```cpp
	    int left = 0, right = m * n - 1;
	```
	Initializes two pointers `left` and `right` to represent the search range within the matrix, treated as a 1D array.

4. **Loop Iteration**
	```cpp
	    while (left <= right) {
	```
	Starts a `while` loop to perform binary search.

5. **Calculation**
	```cpp
	        int mid = left + (right - left) / 2;
	```
	Calculates the middle index `mid` using integer division to prevent overflow.

6. **Index Calculation**
	```cpp
	        int row = mid / n, col = mid % n;
	```
	Calculates the row and column indices corresponding to the `mid` index in the 1D representation.

7. **Condition**
	```cpp
	        if (matrix[row][col] == target) {
	```
	Checks if the element at the `mid` index is equal to the target value.

8. **Return**
	```cpp
	            return true;
	```
	If the target is found, returns `true`.

9. **Conditional**
	```cpp
	        } else if (matrix[row][col] < target) {
	```
	If the element at `mid` is less than the target, the target must be in the right half of the search space.

10. **Index Update**
	```cpp
	            left = mid + 1;
	```
	Adjusts the `left` pointer to the middle index plus 1.

11. **Conditional**
	```cpp
	        } else {
	```
	If the element at `mid` is greater than the target, the target must be in the left half of the search space.

12. **Index Update**
	```cpp
	            right = mid - 1;
	```
	Adjusts the `right` pointer to the middle index minus 1.

13. **Loop Iteration**
	```cpp
	    }
	```
	Continues the loop until the target is found or the search space is exhausted.

14. **Return**
	```cpp
	    return false;
	```
	If the target is not found after the loop, returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(m * n))
- **Average Case:** O(log(m * n))
- **Worst Case:** O(log(m * n))

The time complexity is O(log(m * n)) because we perform binary search over the matrix treated as a 1D array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the binary search is performed in place with no extra space required.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/search-a-2d-matrix/description/)

---
{{< youtube x-dYOtIudzc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
