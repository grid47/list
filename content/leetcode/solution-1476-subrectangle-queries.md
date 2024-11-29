
+++
authors = ["grid47"]
title = "Leetcode 1476: Subrectangle Queries"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1476: Subrectangle Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Design","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cMBkZMNVDdE"
youtube_upload_date="2020-06-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cMBkZMNVDdE/maxresdefault.webp"
comments = true
+++



---
You are tasked with implementing the SubrectangleQueries class which operates on a matrix representing a rectangle with integer values. The class should support two key operations: updateSubrectangle and getValue.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of method calls on the SubrectangleQueries object, where each call represents an operation to be performed.
- **Example:** `[[[1,2,3],[4,5,6],[7,8,9]]],[0,1],[1,1,2,2,10],[0,1],[1,2],[0,0,1,1,20],[1,0],[0,2]`
- **Constraints:**
	- 1 <= rows, cols <= 100
	- 0 <= row1 <= row2 < rows
	- 0 <= col1 <= col2 < cols
	- 1 <= newValue <= 10^9
	- 0 <= row < rows
	- 0 <= col < cols

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of the results of the method calls on the SubrectangleQueries object.
- **Example:** `[null,2,null,10,6,null,20,3]`
- **Constraints:**
	- There will be at most 500 operations considering both methods.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently update a subrectangle and retrieve values at specified coordinates.

- Store the initial matrix in the class.
- For the updateSubrectangle operation, iterate over the specified subrectangle and update all its values.
- For the getValue operation, simply retrieve the value from the matrix at the specified coordinates.
{{< dots >}}
### Problem Assumptions ✅
- The rectangle is initially provided in the form of a 2D array.
- All values within the specified subrectangle are updated to the newValue.
{{< dots >}}
## Examples 🧩
- **Input:** `[[[1,2,3],[4,5,6],[7,8,9]]],[0,1],[1,1,2,2,10],[0,1],[1,2],[0,0,1,1,20],[1,0],[0,2]`  \
  **Explanation:** The provided example demonstrates how updates are made to specific subrectangles and how values are retrieved after those updates.

{{< dots >}}
## Approach 🚀
The problem can be solved with a straightforward approach that updates values directly in the matrix for the subrectangle and retrieves values using array indexing for the getValue operation.

### Initial Thoughts 💭
- The subrectangle update operation involves looping over a submatrix and updating values.
- The getValue operation is efficient with direct access to the matrix.
- Directly modifying the subrectangle will result in a time complexity of O(k), where k is the number of cells in the subrectangle.
{{< dots >}}
### Edge Cases 🌐
- An empty rectangle is not a valid input.
- If the rectangle size is large, ensure the solution can handle large subrectangle updates efficiently.
- Handling the upper bound values for newValue and matrix elements should be done without overflow.
- Ensure that the row and column indices are within the valid bounds of the matrix.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> rec;
SubrectangleQueries(vector<vector<int>>& rectangle) {
    rec = rectangle;
}

void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
    for(int i = row1; i <= row2; i++)
    for(int j = col1; j <= col2; j++)
        rec[i][j] = newValue;
}

int getValue(int row, int col) {
    return rec[row][col];
}
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
```

This class `SubrectangleQueries` is designed to efficiently perform updates on subrectangles within a 2D matrix and retrieve values from it. The matrix is represented by a 2D vector (`rec`). The class includes methods to update a subrectangle's values and get a specific value from the matrix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Declaration**
	```cpp
	vector<vector<int>> rec;
	```
	This line declares a 2D vector `rec` that will hold the values of the subrectangle matrix. It is used to store the entire rectangle's data.

2. **Constructor**
	```cpp
	SubrectangleQueries(vector<vector<int>>& rectangle) {
	```
	The constructor initializes the `SubrectangleQueries` object with an existing 2D matrix `rectangle` passed by reference. This matrix is then stored in the `rec` variable.

3. **Initialization**
	```cpp
	    rec = rectangle;
	```
	The matrix `rec` is initialized with the values from the provided `rectangle` matrix. This effectively stores the rectangle in the object for later updates and queries.

4. **Method**
	```cpp
	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
	```
	The `updateSubrectangle` method is used to update the values of a subrectangle in the matrix. The rectangle to be updated is defined by the top-left (`row1`, `col1`) and bottom-right (`row2`, `col2`) corners, and the new value `newValue` is applied to all elements within this subrectangle.

5. **Loop**
	```cpp
	    for(int i = row1; i <= row2; i++)
	```
	The outer loop iterates through all rows of the subrectangle, starting from `row1` to `row2`.

6. **Loop**
	```cpp
	    for(int j = col1; j <= col2; j++)
	```
	The inner loop iterates through all columns of the subrectangle, starting from `col1` to `col2`.

7. **Update**
	```cpp
	        rec[i][j] = newValue;
	```
	This line updates the value of each element in the subrectangle to the new value (`newValue`).

8. **Method**
	```cpp
	int getValue(int row, int col) {
	```
	The `getValue` method returns the value of the matrix at the specified position (`row`, `col`). This method allows querying individual values from the rectangle.

9. **Return**
	```cpp
	    return rec[row][col];
	```
	This line retrieves the value from the matrix at the given position and returns it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for getValue
- **Average Case:** O(k) for updateSubrectangle, where k is the size of the subrectangle
- **Worst Case:** O(k) for updateSubrectangle

The time complexity of getValue is constant, but updating the subrectangle requires iterating through the cells of the subrectangle.

### Space Complexity 💾
- **Best Case:** O(n * m)
- **Worst Case:** O(n * m) where n is the number of rows and m is the number of columns in the rectangle.

The space complexity depends on the size of the matrix, as we store it in memory.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subrectangle-queries/description/)

---
{{< youtube cMBkZMNVDdE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
