
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
comments = true
+++



---
You are given an m x n matrix 'mat' and an integer 'k'. The rows of the matrix undergo cyclic shifts: even-indexed rows shift left, and odd-indexed rows shift right. After performing these k shifts, determine if the matrix is identical to its original form.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D matrix 'mat' and an integer 'k', where 'mat[i][j]' represents the element in the ith row and jth column.
- **Example:** `mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4`
- **Constraints:**
	- 1 <= mat.length <= 25
	- 1 <= mat[i].length <= 25
	- 1 <= mat[i][j] <= 25
	- 1 <= k <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the matrix is identical to its original after k shifts, otherwise return false.
- **Example:** `For mat = [[1,2,3],[4,5,6],[7,8,9]] and k = 4, the output is false.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine whether, after k cyclic shifts on the matrix, the matrix will match its original configuration.

- For each row in the matrix, determine whether performing cyclic shifts k times results in the same row.
- For even-indexed rows, perform a left cyclic shift; for odd-indexed rows, perform a right cyclic shift.
{{< dots >}}
### Problem Assumptions ✅
- Matrix rows can have different lengths but will be bounded by the constraints.
- Cyclic shifts are defined as moving elements in a row from one end to the other, wrapping around.
{{< dots >}}
## Examples 🧩
- **Input:** `mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4`  \
  **Explanation:** After performing 4 shifts, the matrix is no longer identical to the original one, so the result is false.

- **Input:** `mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2`  \
  **Explanation:** After performing 2 shifts, the matrix becomes identical to its original form, so the result is true.

{{< dots >}}
## Approach 🚀
To solve the problem, we perform k cyclic shifts on the matrix and compare the result with the original matrix.

### Initial Thoughts 💭
- Cyclic shifts can be easily simulated for each row by shifting elements accordingly.
- After applying the shifts, comparing the modified matrix with the original will give the desired result.
- We need to ensure that the shifting operation is applied to each row correctly, alternating between left and right shifts for even and odd rows, respectively.
{{< dots >}}
### Edge Cases 🌐
- The input matrix will always have at least one element, so there will be no empty matrices.
- Even though the matrix size can be large (up to 25x25), the complexity of the problem remains manageable due to the constraints.
- If all elements in the matrix are the same, any cyclic shifts will not alter the matrix.
- The constraints ensure that the size of the matrix is small enough to perform the cyclic shifts efficiently.
{{< dots >}}
## Code 💻
```cpp
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
```

This function checks if every row in a 2D matrix can be rotated by a specified number of positions 'k' to match itself. It iterates over each row, comparing elements based on the rotation condition. If any element doesn't match the rotated position, it returns 'false', indicating the matrix cannot be similar by the given rotation. If all rows satisfy the condition, it returns 'true'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool areSimilar(vector<vector<int>>& mat, int k) {
	```
	Defines the function 'areSimilar' which checks if a 2D matrix can be rotated by 'k' positions to match its original configuration in every row.

2. **Outer Loop**
	```cpp
	    for (const auto& l : mat) {
	```
	Starts iterating through each row 'l' of the matrix 'mat'. The variable 'l' represents a row in the matrix.

3. **Row Size**
	```cpp
	        int n = l.size();
	```
	Calculates the number of elements in the current row 'l' by storing the size of the row in the variable 'n'.

4. **Inner Loop**
	```cpp
	        for (int i = 0; i < n; ++i) {
	```
	Starts an inner loop to iterate over each element 'i' in the current row 'l'.

5. **Rotation Check**
	```cpp
	            if (l[i] != l[(i + k) % n]) {
	```
	Checks if the current element 'l[i]' matches the element at the rotated position '(i + k) % n'. The modulo ensures the index wraps around when it exceeds the size of the row.

6. **Return False**
	```cpp
	                return false;
	```
	If the elements do not match after the rotation, it returns 'false' immediately, indicating the rows are not similar after rotation.

7. **Return True**
	```cpp
	    return true;
	```
	If all rows pass the rotation check, it returns 'true', indicating that the matrix can be rotated to match itself for all rows.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k * m * n)
- **Average Case:** O(k * m * n)
- **Worst Case:** O(k * m * n)

The time complexity is O(k * m * n) because for each row, we perform a shift k times, and we need to compare each element in the matrix.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the storage needed for the matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/)

---
{{< youtube 7RGWUCc5IHw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
