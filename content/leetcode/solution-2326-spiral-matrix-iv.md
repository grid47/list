
+++
authors = ["grid47"]
title = "Leetcode 2326: Spiral Matrix IV"
date = "2024-03-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2326: Spiral Matrix IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "sOV1nRhmsMQ"
youtube_upload_date="2024-09-09"
youtube_thumbnail="https://i.ytimg.com/vi/sOV1nRhmsMQ/maxresdefault.jpg"
comments = true
+++



---
You are given two integers, m and n, which represent the dimensions of a matrix. You are also given the head of a linked list of integers. Your task is to generate an m x n matrix by filling it in a spiral order (clockwise) using the integers from the linked list. If any spaces remain, fill them with -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, m and n, and the head of a linked list containing integers.
- **Example:** `m = 3, n = 5, head = [1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37]`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 1 <= m * n <= 10^5
	- The linked list contains between 1 and m * n integers.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an m x n matrix where the values from the linked list are placed in a spiral order, and any remaining empty spaces are filled with -1.
- **Example:** `For m = 3, n = 5, and head = [1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37], the output is [[1, 4, 7, 10, 13], [16, 19, 22, 25, 28], [31, 34, 37, -1, -1]].`
- **Constraints:**
	- The generated matrix must have exactly m rows and n columns.

{{< dots >}}
### Core Logic 🔍
**Goal:** To fill the matrix in a spiral order using the integers from the linked list and handle any remaining empty spaces.

- 1. Initialize an m x n matrix filled with -1.
- 2. Use the linked list to place values in the matrix in spiral order (clockwise).
- 3. When the linked list is exhausted, stop placing values. Any remaining empty cells should be filled with -1.
- 4. Return the filled matrix.
{{< dots >}}
### Problem Assumptions ✅
- The linked list contains between 1 and m * n integers.
- The matrix size is valid for the given m and n values.
{{< dots >}}
## Examples 🧩
- **Input:** `m = 3, n = 5, head = [1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37]`  \
  **Explanation:** The linked list values are filled into the matrix in a spiral order. The remaining cells are filled with -1.

- **Input:** `m = 2, n = 3, head = [0, 1, 2, 3]`  \
  **Explanation:** The linked list values are placed in the matrix in a spiral order, with any remaining cells filled with -1.

{{< dots >}}
## Approach 🚀
The task is to fill the matrix in a spiral order using the integers from the linked list. We can use a directional approach to achieve the spiral filling.

### Initial Thoughts 💭
- We need to traverse the matrix in a spiral fashion and fill it with values from the linked list.
- Each time we hit the boundary of the matrix or an already filled cell, we change direction.
- A straightforward approach would be to simulate the movement through the matrix while filling it with values from the linked list.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one node in the linked list, so empty linked lists do not need to be handled.
- The solution must efficiently handle matrices with sizes up to 10^5 cells and corresponding linked lists.
- Ensure that the matrix is filled in the spiral order and any remaining spaces are correctly filled with -1.
- The linked list must contain a number of elements between 1 and m * n.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> res(m, vector<int>(n, -1));
    int i = 0, j = 0, cur_dir = 0, d[5] = {0, 1, 0, -1, 0};
    for(;head != nullptr; head = head->next) {
        res[i][j] = head->val;
        int ni = i + d[cur_dir], nj = j + d[cur_dir + 1];
        if(min(ni, nj) < 0 || ni >= m || nj >= n || res[ni][nj] != -1)
            cur_dir = (cur_dir + 1) % 4;
        i += d[cur_dir];
        j += d[cur_dir + 1];
    }
    return res;
}
```

This function takes two integers `m` and `n` representing the dimensions of a matrix and a linked list `head`. It fills the matrix in a spiral order using the values from the linked list and returns the filled matrix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
	```
	Declares the `spiralMatrix` function that takes the matrix dimensions `m` and `n` and a linked list `head` as inputs. It returns a 2D matrix filled in a spiral order.

2. **Matrix Initialization**
	```cpp
	    vector<vector<int>> res(m, vector<int>(n, -1));
	```
	Initializes a 2D vector `res` of size `m` by `n`, with all elements set to -1. This matrix will hold the final result of the spiral traversal.

3. **Variable Initialization**
	```cpp
	    int i = 0, j = 0, cur_dir = 0, d[5] = {0, 1, 0, -1, 0};
	```
	Initializes variables `i` and `j` to 0 to start at the top-left corner of the matrix. `cur_dir` tracks the current direction (0 = right, 1 = down, 2 = left, 3 = up). The array `d` represents the change in row and column for each direction.

4. **Linked List Traversal**
	```cpp
	    for(;head != nullptr; head = head->next) {
	```
	Iterates through each node in the linked list `head` until the list is exhausted.

5. **Matrix Assignment**
	```cpp
	        res[i][j] = head->val;
	```
	Assigns the value of the current node `head->val` to the current position in the matrix `res[i][j]`.

6. **Next Position Calculation**
	```cpp
	        int ni = i + d[cur_dir], nj = j + d[cur_dir + 1];
	```
	Calculates the next row (`ni`) and column (`nj`) based on the current direction (`cur_dir`).

7. **Boundary Check**
	```cpp
	        if(min(ni, nj) < 0 || ni >= m || nj >= n || res[ni][nj] != -1)
	```
	Checks if the next position (`ni`, `nj`) is out of bounds or already filled. If true, it indicates the need to change direction.

8. **Direction Change**
	```cpp
	            cur_dir = (cur_dir + 1) % 4;
	```
	Changes the direction (right -> down -> left -> up) by updating `cur_dir`. This ensures the traversal follows a spiral pattern.

9. **Position Update**
	```cpp
	        i += d[cur_dir];
	```
	Updates the row index `i` to the next position based on the current direction.

10. **Position Update**
	```cpp
	        j += d[cur_dir + 1];
	```
	Updates the column index `j` to the next position based on the current direction.

11. **Return Statement**
	```cpp
	    return res;
	```
	Returns the matrix `res` after it has been filled in a spiral order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n), as each cell in the matrix is filled once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n), as we need to store the resulting matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/spiral-matrix-iv/description/)

---
{{< youtube sOV1nRhmsMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
