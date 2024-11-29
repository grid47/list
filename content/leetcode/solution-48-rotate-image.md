
+++
authors = ["grid47"]
title = "Leetcode 48: Rotate Image"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 48: Rotate Image in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/48.webp"
youtube = "fMSJSS7eO1w"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fMSJSS7eO1w/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/48.webp" 
    alt="A serene, slow-moving image rotating in space, shifting with soft, calming colors."
    caption="Solution to LeetCode 48: Rotate Image Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an n x n 2D matrix representing an image, rotate the image by 90 degrees clockwise. The rotation should be done in-place, meaning you cannot allocate another 2D matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D matrix representing an image. The matrix is of size n x n, where n is between 1 and 20.
- **Example:** `[[1, 2, 3], [4, 5, 6], [7, 8, 9]]`
- **Constraints:**
	- 1 <= n <= 20
	- Each element of the matrix is an integer between -1000 and 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the matrix after rotating it by 90 degrees clockwise.
- **Example:** `[[7, 4, 1], [8, 5, 2], [9, 6, 3]]`
- **Constraints:**
	- The result should be the rotated matrix, achieved in-place.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rotate the matrix 90 degrees clockwise in-place without using extra space for another matrix.

- 1. Reverse the rows of the matrix.
- 2. Transpose the matrix by swapping the elements along the diagonal.
{{< dots >}}
### Problem Assumptions ✅
- The matrix will always be a square matrix with the same number of rows and columns.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 2, 3], [4, 5, 6], [7, 8, 9]]`  \
  **Explanation:** In this example, after reversing the rows and transposing, the final result is [[7, 4, 1], [8, 5, 2], [9, 6, 3]].

- **Input:** `[[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]`  \
  **Explanation:** In this example, after rotating the matrix 90 degrees clockwise, the final result is [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]].

{{< dots >}}
## Approach 🚀
The approach involves reversing the rows of the matrix and then transposing the matrix to achieve a 90-degree rotation.

### Initial Thoughts 💭
- Reversing the rows and transposing the matrix will effectively rotate it by 90 degrees clockwise.
- This approach is efficient as it modifies the matrix in place, without requiring additional space.
{{< dots >}}
### Edge Cases 🌐
- The matrix will never be empty since n >= 1.
- The maximum size for n is 20, so the matrix size is at most 20 x 20, which is manageable.
- Handle matrices with negative values or zeros, as these are valid elements in the matrix.
- The matrix will always be square, and its elements will be integers in the range [-1000, 1000].
{{< dots >}}
## Code 💻
```cpp
void rotate(vector<vector<int>>& mtx) {
    int i = 0, j = mtx.size() - 1;
    while(i <= j)
        swap(mtx[i++], mtx[j--]);
    
    for(int i = 0; i < mtx.size(); i++)
    for(int j = i+1; j< mtx.size(); j++)
        swap(mtx[i][j], mtx[j][i]);
}
```

This code rotates a square matrix by 90 degrees clockwise.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void rotate(vector<vector<int>>& mtx) {
	```
	This line declares a function named `rotate` that takes a 2D vector `mtx` representing the matrix as input and rotates it in-place.

2. **Index Initialization**
	```cpp
	    int i = 0, j = mtx.size() - 1;
	```
	This line initializes two index variables `i` and `j` to represent the start and end indices of the matrix.

3. **Matrix Transposition**
	```cpp
	    while(i <= j)
	```
	This line starts a `while` loop to iterate through the matrix diagonally, swapping elements to transpose the matrix.

4. **Matrix Transposition**
	```cpp
	        swap(mtx[i++], mtx[j--]);
	```
	Inside the loop, the elements at indices `i` and `j` are swapped. The `i` and `j` indices are then incremented and decremented, respectively, to move to the next diagonal pair.

5. **Matrix Reflection**
	```cpp
	    for(int i = 0; i < mtx.size(); i++)
	```
	This line starts a nested `for` loop to iterate through the upper triangular part of the matrix.

6. **Matrix Reflection**
	```cpp
	    for(int j = i+1; j< mtx.size(); j++)
	```
	The inner loop iterates through the elements to the right of the current row.

7. **Matrix Reflection**
	```cpp
	        swap(mtx[i][j], mtx[j][i]);
	```
	The elements at indices `(i, j)` and `(j, i)` are swapped to reflect the matrix along the main diagonal, completing the 90-degree rotation.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we need to iterate through all the elements of the matrix for the reverse and transpose operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the matrix is modified in-place without using extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rotate-image/description/)

---
{{< youtube fMSJSS7eO1w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
