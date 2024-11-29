
+++
authors = ["grid47"]
title = "Leetcode 1886: Determine Whether Matrix Can Be Obtained By Rotation"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1886: Determine Whether Matrix Can Be Obtained By Rotation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vf_nUx64R0E"
youtube_upload_date="2021-06-06"
youtube_thumbnail="https://i.ytimg.com/vi/vf_nUx64R0E/maxresdefault.jpg"
comments = true
+++



---
You are given two n x n binary matrices mat and target. Your task is to determine if it is possible to rotate the matrix mat in 90-degree increments so that it matches the target matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two 2D matrices, mat and target, where each matrix is of size n x n. The elements of the matrices are binary (either 0 or 1).
- **Example:** `For example, given mat = [[0,1],[1,0]] and target = [[1,0],[0,1]]`
- **Constraints:**
	- The number of rows and columns in mat and target is between 1 and 10, inclusive.
	- Each element in mat and target is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to rotate mat in 90-degree increments such that it becomes equal to target; otherwise, return false.
- **Example:** `For mat = [[0,1],[1,0]] and target = [[1,0],[0,1]], the output will be true.`
- **Constraints:**
	- The output is a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if mat can be rotated in 90-degree increments to match the target matrix.

- Start with the matrix mat.
- For each 90-degree rotation, compare mat with target.
- If any of the rotations match target, return true. If none match, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input matrices are always square matrices (n x n).
- The elements of the matrices are binary (0 or 1).
{{< dots >}}
## Examples 🧩
- **Input:** `mat = [[0,1],[1,0]] and target = [[1,0],[0,1]]`  \
  **Explanation:** By rotating mat 90 degrees clockwise, it matches the target matrix. Thus, the output is true.

- **Input:** `mat = [[0,1],[1,1]] and target = [[1,0],[0,1]]`  \
  **Explanation:** No matter how many times mat is rotated, it will never match the target matrix. Thus, the output is false.

- **Input:** `mat = [[0,0,0],[0,1,0],[1,1,1]] and target = [[1,1,1],[0,1,0],[0,0,0]]`  \
  **Explanation:** By rotating mat twice (180 degrees), it matches the target matrix. Thus, the output is true.

{{< dots >}}
## Approach 🚀
We will rotate mat 0, 90, 180, and 270 degrees and compare it with the target matrix at each rotation.

### Initial Thoughts 💭
- Each 90-degree rotation can be achieved by first transposing the matrix and then reversing the rows.
- Since the matrix size n is small (maximum 10), rotating the matrix four times and checking each is computationally feasible.
{{< dots >}}
### Edge Cases 🌐
- Empty matrices are not allowed since n >= 1.
- Since n is at most 10, the algorithm will run efficiently even with the maximum size.
- Matrices where all elements are 0 or 1 may present patterns that are easily detectable.
- The matrices are always square and their sizes are small, so performance should not be an issue.
{{< dots >}}
## Code 💻
```cpp
bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    
    for(int i = 0; i < 4; i++) {
        if(match(mat, target)) return true;
        rotate(mat);
    }
    return false;
}

void rotate(vector<vector<int>>& mtx) {
    int n= mtx.size();
    int i = 0, j = n - 1;
    while(i <= j)
        swap(mtx[i++], mtx[j--]);
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
        swap(mtx[i][j], mtx[j][i]);
}

bool match(vector<vector<int>>& mtx1, vector<vector<int>>& mtx2) {
    int n = mtx1.size();
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        if(mtx1[i][j] != mtx2[i][j])
            return false;
    return true;
}
```

This is the code that implements the solution for rotating a matrix and checking if it matches the target matrix after multiple 90-degree rotations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
	```
	Defines a function to check if one matrix can be obtained by rotating another matrix 0 to 3 times.

2. **Loop**
	```cpp
	    for(int i = 0; i < 4; i++) {
	```
	A loop that iterates 4 times, once for each possible 90-degree rotation.

3. **Condition Check**
	```cpp
	        if(match(mat, target)) return true;
	```
	Checks if the current matrix `mat` matches the target matrix. If they match, the function returns true.

4. **Function Call**
	```cpp
	        rotate(mat);
	```
	Rotates the matrix 90 degrees.

5. **Return**
	```cpp
	    return false;
	```
	Returns false if no rotation results in a match.

6. **Function Definition**
	```cpp
	void rotate(vector<vector<int>>& mtx) {
	```
	Defines the function to rotate the matrix 90 degrees.

7. **Variable Declaration**
	```cpp
	    int n= mtx.size();
	```
	Declares `n` as the size of the matrix.

8. **Variable Initialization**
	```cpp
	    int i = 0, j = n - 1;
	```
	Initializes the indices `i` and `j` to represent the leftmost and rightmost columns of the matrix.

9. **Loop**
	```cpp
	    while(i <= j)
	```
	A loop to traverse and swap the matrix elements across the horizontal middle.

10. **Swap**
	```cpp
	        swap(mtx[i++], mtx[j--]);
	```
	Swaps elements at positions `i` and `j` and moves the indices inward.

11. **Nested Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Outer loop to iterate through each row of the matrix.

12. **Inner Loop**
	```cpp
	    for(int j = i + 1; j < n; j++)
	```
	Inner loop to iterate over the upper triangle of the matrix.

13. **Swap**
	```cpp
	        swap(mtx[i][j], mtx[j][i]);
	```
	Swaps elements at positions `mtx[i][j]` and `mtx[j][i]` to rotate the matrix.

14. **Function Definition**
	```cpp
	bool match(vector<vector<int>>& mtx1, vector<vector<int>>& mtx2) {
	```
	Defines a function to check if two matrices are equal.

15. **Variable Declaration**
	```cpp
	    int n = mtx1.size();
	```
	Declares `n` as the size of the matrix.

16. **Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Outer loop to iterate through each row.

17. **Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Inner loop to iterate through each column.

18. **Condition Check**
	```cpp
	        if(mtx1[i][j] != mtx2[i][j])
	```
	Checks if the elements at position `mtx1[i][j]` and `mtx2[i][j]` are different.

19. **Return**
	```cpp
	            return false;
	```
	Returns false if any element does not match.

20. **Return**
	```cpp
	    return true;
	```
	Returns true if all elements match.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

We rotate the matrix up to four times, and each rotation involves O(n^2) comparisons with the target.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

We need space to store the matrix and its rotations, which takes O(n^2) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/)

---
{{< youtube vf_nUx64R0E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
