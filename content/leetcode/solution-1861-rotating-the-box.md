
+++
authors = ["grid47"]
title = "Leetcode 1861: Rotating the Box"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1861: Rotating the Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2LRnTMOiqSI"
youtube_upload_date="2021-05-17"
youtube_thumbnail="https://i.ytimg.com/vi/2LRnTMOiqSI/maxresdefault.jpg"
comments = true
+++



---
You are given an m x n matrix of characters `box`, where each cell is a stone (`#`), a stationary obstacle (`*`), or an empty space (`.`). After rotating the box 90 degrees clockwise, gravity will cause stones to fall down until they land on an obstacle, another stone, or the bottom. Return the updated matrix after the stones have fallen.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an m x n matrix of characters where each cell can either be a stone (`#`), a stationary obstacle (`*`), or an empty space (`.`).
- **Example:** `box = [[# , ., *], [#, *, #]]`
- **Constraints:**
	- 1 <= m, n <= 500
	- Each box[i][j] is either '#', '*', or '.'

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the updated matrix representing the box after the stones have fallen due to gravity, while obstacles remain stationary.
- **Example:** `Output = [[#, .], [#, #], [*, *], [., .]]`
- **Constraints:**
	- The output is an m x n matrix of characters, representing the new arrangement after the stones have fallen.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the rotation and gravity effect to correctly place the stones.

- Step 1: Reverse the rows of the matrix to simulate a 90-degree clockwise rotation.
- Step 2: Iterate over each column, from bottom to top, and move the stones downwards, stopping at obstacles or other stones.
- Step 3: Rebuild the matrix by placing stones at the bottom, obstacles where they are, and empty spaces above the stones.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is guaranteed to contain at least one row and one column.
- The stones are already placed in a valid position, meaning they will rest on an obstacle, another stone, or the bottom of the box.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[., ., #]]`  \
  **Explanation:** After rotating the box 90 degrees and applying gravity, the stone falls to the bottom.

- **Input:** `Input: [[., *, ., #], [., #, *, #]]`  \
  **Explanation:** The stones fall to the bottom after rotation, and the obstacles remain in place, causing the stones to settle above them.

{{< dots >}}
## Approach 🚀
The solution involves simulating the 90-degree rotation of the matrix and applying gravity to the stones. We will reverse the rows of the matrix and then process each column to move stones down while respecting obstacles and other stones.

### Initial Thoughts 💭
- This is a simulation problem where we need to handle gravity and rotation.
- Reversing the matrix rows will simulate the rotation. Then, we need to handle gravity by checking each column from bottom to top.
{{< dots >}}
### Edge Cases 🌐
- The matrix cannot be empty, as it is guaranteed to have at least one stone or obstacle.
- The algorithm should be efficient enough to handle matrices with the maximum size of 500x500.
- Consider cases where there are no stones in a column or when all stones are already at the bottom.
- The matrix is guaranteed to have at least one row and one column.
{{< dots >}}
## Code 💻
```cpp
vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    
    reverse(box.begin(), box.end());
    
    int m = box.size(), n = box[0].size();
    vector<vector<char>> tmp(n, vector<char>(m));
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        tmp[j][i] = box[i][j];
    
    for(int i = 0; i < m; i++) {
        int k = n - 1;
        for(int j = n - 1; j >= 0; j--) {
            if(tmp[j][i] == '#') {
                tmp[j][i] = '.'; // o
                tmp[k][i] = '#'; // order is important
                k--;
            } else if(tmp[j][i] == '*') {
                k = j - 1;
            }else if(tmp[j][i] == '.') {
                
            }
        }
    }
    return tmp; 
}
```

The function `rotateTheBox` rotates a 2D box represented by a grid, performing a series of operations including flipping the box vertically, transposing it, and shifting the elements to simulate gravity for non-empty cells (represented by `#`). The function returns the rotated and updated grid.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
	```
	Define the function `rotateTheBox`, which takes a reference to a 2D vector `box` representing a grid.

2. **Reverse Grid**
	```cpp
	    reverse(box.begin(), box.end());
	```
	Reverse the rows of the grid to simulate a vertical flip of the box.

3. **Variable Initialization**
	```cpp
	    int m = box.size(), n = box[0].size();
	```
	Store the dimensions of the grid: `m` for the number of rows and `n` for the number of columns.

4. **Matrix Initialization**
	```cpp
	    vector<vector<char>> tmp(n, vector<char>(m));
	```
	Create a new grid `tmp` with dimensions transposed from the original grid (`n` rows and `m` columns).

5. **Outer Loop (Rows)**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Start an outer loop to iterate over the rows of the original grid.

6. **Inner Loop (Columns)**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Start an inner loop to iterate over the columns of the original grid.

7. **Transposition**
	```cpp
	        tmp[j][i] = box[i][j];
	```
	Transpose the grid, storing the element at `box[i][j]` into the transposed grid `tmp[j][i]`.

8. **Loop through Transposed Grid**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Start a loop to process each column of the transposed grid.

9. **Initialize k**
	```cpp
	        int k = n - 1;
	```
	Initialize `k` to point to the last row in the current column of the transposed grid.

10. **Inner Loop (Process Elements)**
	```cpp
	        for(int j = n - 1; j >= 0; j--) {
	```
	Start an inner loop to process each element of the column, from bottom to top.

11. **If Condition (Non-empty Cell)**
	```cpp
	            if(tmp[j][i] == '#') {
	```
	Check if the current cell contains a non-empty element (`#`).

12. **Move Cell Down (Empty)**
	```cpp
	                tmp[j][i] = '.'; // o
	```
	Set the current cell to empty (`.`) to simulate the removal of the non-empty element.

13. **Move Cell Down (Non-empty)**
	```cpp
	                tmp[k][i] = '#'; // order is important
	```
	Place the non-empty element (`#`) into the first available position (at `k`) in the column.

14. **Update k**
	```cpp
	                k--;
	```
	Decrease `k` to move to the next available position for the next non-empty element.

15. **Else If Condition (Obstacle)**
	```cpp
	            } else if(tmp[j][i] == '*') {
	```
	Check if the current cell contains an obstacle (`*`).

16. **Update k (Obstacle)**
	```cpp
	                k = j - 1;
	```
	If the current cell is an obstacle, update `k` to the row before the obstacle.

17. **Else If Condition (Empty Cell)**
	```cpp
	            }else if(tmp[j][i] == '.') {
	```
	Check if the current cell is empty (`.`).

18. **Return Result**
	```cpp
	    return tmp; 
	```
	Return the rotated grid `tmp` after performing all the necessary operations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix. We process each element once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the new matrix used to store the updated box state.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rotating-the-box/description/)

---
{{< youtube 2LRnTMOiqSI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
