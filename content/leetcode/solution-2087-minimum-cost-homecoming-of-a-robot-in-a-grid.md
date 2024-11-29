
+++
authors = ["grid47"]
title = "Leetcode 2087: Minimum Cost Homecoming of a Robot in a Grid"
date = "2024-04-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2087: Minimum Cost Homecoming of a Robot in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-ect7lESvLg"
youtube_upload_date="2021-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-ect7lESvLg/maxresdefault.webp"
comments = true
+++



---
You are given a grid of size m x n and two positions: the robot's starting position (startPos) and its home position (homePos). The robot can move left, right, up, or down, with associated costs for moving to new rows and columns. Calculate the minimum total cost for the robot to move from its start position to its home position.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays: startPos and homePos, both of length 2. Additionally, you are given two arrays: rowCosts of length m and colCosts of length n, representing the costs for moving to different rows and columns respectively.
- **Example:** `[1, 2], [3, 4], [5, 6]`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 0 <= rowCosts[r], colCosts[c] <= 10^4
	- 0 <= startPos[0], homePos[0] < m
	- 0 <= startPos[1], homePos[1] < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum cost for the robot to travel from startPos to homePos. If no movement is required, return 0.
- **Example:** `20`
- **Constraints:**
	- The robot must always move within the grid boundaries.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the minimum cost for the robot to move from its starting position to its home, considering the costs for moving to different rows and columns.

- Calculate the row-wise and column-wise movements needed to reach from startPos to homePos.
- Sum up the movement costs based on rowCosts and colCosts arrays for the respective movements.
- If the robot is already at homePos, return 0.
{{< dots >}}
### Problem Assumptions ✅
- The robot's startPos and homePos are valid and within the grid.
- The cost arrays (rowCosts and colCosts) are properly aligned with the grid size.
{{< dots >}}
## Examples 🧩
- **Input:** `[2, 1], [0, 3], [4, 2, 3], [5, 3, 6, 7]`  \
  **Explanation:** To go from (2, 1) to (0, 3), the robot needs to move up, incurring a row cost of 2, and then move right twice, incurring a column cost of 6 and 7 respectively. The total cost is 2 + 6 + 7 = 20.

{{< dots >}}
## Approach 🚀
The problem can be solved by calculating the cost of row-wise and column-wise movement separately and adding up the total cost. The robot needs to move step by step towards its home, adjusting the cost based on the direction and position.

### Initial Thoughts 💭
- Moving vertically costs based on the row, and moving horizontally costs based on the column.
- The robot moves in a straight line either row-wise or column-wise to minimize cost.
- We should calculate the vertical and horizontal movements separately, which will reduce the complexity.
{{< dots >}}
### Edge Cases 🌐
- Both startPos and homePos are the same, which results in no movement and zero cost.
- Ensure that the solution handles the largest grid sizes efficiently.
- Zero row or column costs where no movement occurs.
- Handle cases where the grid size and cost values are near their upper limits.
{{< dots >}}
## Code 💻
```cpp
vector<int> row, col;
vector<vector<long>> vis, vs;
int m, n;

int minCost(vector<int>& start, vector<int>& home, vector<int>& row, vector<int>& col) {
    m = row.size();
    n = col.size();
    int ans = 0;
    int i = start[0], x = home[0];
    int j = start[1], y = home[1];
    while(i != x) {
        i += (x - i) / abs(x - i);
        ans += row[i];
    }
    
    while(j != y) {
        j += (y - j) / abs(y - j);
        ans += col[j];
    }        
    return ans;
}

```

This code defines the function `minCost` that calculates the minimum cost to move from a starting point to a home point in a grid, considering the cost of movement along rows and columns. The function iterates over the rows and columns, adjusting the current position and summing the corresponding costs from the `row` and `col` vectors.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> row, col;
	```
	This initializes two vectors `row` and `col` to store the costs associated with each row and column of the grid.

2. **Variable Initialization**
	```cpp
	vector<vector<long>> vis, vs;
	```
	This initializes two 2D vectors `vis` and `vs`, which might be used for tracking visited cells and storing intermediate results (though not used in the current code).

3. **Variable Declaration**
	```cpp
	int m, n;
	```
	This declares two integer variables `m` and `n`, which will hold the dimensions of the grid (number of rows and columns).

4. **Function Definition**
	```cpp
	int minCost(vector<int>& start, vector<int>& home, vector<int>& row, vector<int>& col) {
	```
	This defines the `minCost` function, which takes the starting position (`start`), the home position (`home`), and two vectors representing row and column costs as input parameters.

5. **Variable Assignment**
	```cpp
	    m = row.size();
	```
	This assigns the number of rows (i.e., the size of the `row` vector) to the variable `m`.

6. **Variable Assignment**
	```cpp
	    n = col.size();
	```
	This assigns the number of columns (i.e., the size of the `col` vector) to the variable `n`.

7. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	This initializes the variable `ans` to 0, which will accumulate the total cost of the movement from the start to home.

8. **Variable Assignment**
	```cpp
	    int i = start[0], x = home[0];
	```
	This initializes the row positions of the start (`i`) and home (`x`) locations from the `start` and `home` vectors.

9. **Variable Assignment**
	```cpp
	    int j = start[1], y = home[1];
	```
	This initializes the column positions of the start (`j`) and home (`y`) locations from the `start` and `home` vectors.

10. **While Loop**
	```cpp
	    while(i != x) {
	```
	This starts a `while` loop to move the row position `i` towards the target row `x`.

11. **Movement Calculation**
	```cpp
	        i += (x - i) / abs(x - i);
	```
	This updates the row index `i` by adjusting it towards `x`, considering the direction of movement (up or down) based on the difference between `x` and `i`.

12. **Cost Addition**
	```cpp
	        ans += row[i];
	```
	This adds the cost from the `row` vector at index `i` to the total cost `ans`.

13. **While Loop**
	```cpp
	    while(j != y) {
	```
	This starts another `while` loop to move the column position `j` towards the target column `y`.

14. **Movement Calculation**
	```cpp
	        j += (y - j) / abs(y - j);
	```
	This updates the column index `j` by adjusting it towards `y`, considering the direction of movement (left or right) based on the difference between `y` and `j`.

15. **Cost Addition**
	```cpp
	        ans += col[j];
	```
	This adds the cost from the `col` vector at index `j` to the total cost `ans`.

16. **Return Statement**
	```cpp
	    return ans;
	```
	This returns the total cost `ans` after the movements have been completed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) when startPos is equal to homePos.
- **Average Case:** O(m + n) for the worst case of reaching from one corner to the other.
- **Worst Case:** O(m + n) where m and n are the grid dimensions.

The solution performs a linear pass based on the grid's row and column dimensions.

### Space Complexity 💾
- **Best Case:** O(1).
- **Worst Case:** O(1) as the space used does not depend on the size of the grid.

The solution uses constant space aside from input storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/)

---
{{< youtube -ect7lESvLg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
