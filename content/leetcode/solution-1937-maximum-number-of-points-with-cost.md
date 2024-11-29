
+++
authors = ["grid47"]
title = "Leetcode 1937: Maximum Number of Points with Cost"
date = "2024-04-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1937: Maximum Number of Points with Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ik1y7fz8AOc"
youtube_upload_date="2024-08-17"
youtube_thumbnail="https://i.ytimg.com/vi/ik1y7fz8AOc/maxresdefault.jpg"
comments = true
+++



---
You are given a matrix of integers `points` with dimensions `m x n` (0-indexed). Initially, you are at score 0, and your goal is to maximize the score by selecting one cell in each row. To gain points, you can select a cell `(r, c)` from each row. The value at `points[r][c]` will add to your score. However, if you choose cells from different columns in adjacent rows, the difference between their column indices will subtract from your score. Specifically, if you select a cell at `(r, c1)` in row `r` and a cell at `(r + 1, c2)` in row `r + 1`, the penalty is `abs(c1 - c2)`. Your task is to return the maximum score you can achieve by choosing cells from each row.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer matrix `points` of size `m x n`.
- **Example:** `points = [[3, 1, 4], [1, 2, 5], [2, 6, 7]]`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 1 <= m * n <= 10^5
	- 0 <= points[r][c] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the maximum score you can achieve by selecting cells from each row.
- **Example:** `Output: 15`
- **Constraints:**
	- The output is an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the score by selecting cells in each row while minimizing the penalty caused by column differences in adjacent rows.

- Start from the first row and select the cell with the maximum value.
- For each subsequent row, select the cell that maximizes the score while minimizing the column difference penalty with the cell selected in the previous row.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is non-empty and contains only non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[3, 1, 4], [1, 2, 5], [2, 6, 7]]`  \
  **Explanation:** Select the cell at (0, 2), (1, 2), and (2, 1) for the optimal score of 15. The penalty for column difference is 1.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming. We calculate the maximum points from each row by considering both the selection of cells and the penalty for column difference between adjacent rows.

### Initial Thoughts 💭
- Each row must be processed independently, with the maximum points calculated by considering the previous row's selected cell.
- The key is to track the maximum score as we process each row while keeping track of the column indices selected in the previous row.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the matrix has at least one row and one column.
- Ensure that the solution can handle matrices with up to 100,000 rows and columns.
- Consider matrices with all elements being the same value.
- Handle the upper bound of matrix size efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> pts;
map<int, map<int, long long>> mp;
long long dp(int idx, int prv) {
    if(idx == pts.size()) return 0;
    
    if(mp.count(idx) && mp[idx].count(prv)) return mp[idx][prv];
    
    long long ans = LLONG_MIN;
    if(prv == -1) {
        for(int i = 0; i < pts[0].size(); i++)
            ans = max(ans, pts[idx][i] + dp(idx + 1, i));
    } else {
        for(int i = 0; i < pts[0].size(); i++)
            ans = max(ans, pts[idx][i] - abs(i - prv) + dp(idx + 1, i));
    }
    return mp[idx][prv] = ans;
}

long long maxPoints(vector<vector<int>>& points) {
    pts = points;
    int m = pts.size(), n = pts[0].size();
    
    vector<long long> prv(n);
    for(int i = 0; i < n; i++) prv[i] = pts[0][i];
    
    for(int j = 0; j < m - 1; j++) {
        vector<long long> left(n, 0), right(n, 0), cur(n, 0);
        
        left[0] = prv[0];
        right[n - 1] = prv[n - 1];
        
        for(int i = 1; i < n; i++)
            left[i] = max(left[i - 1] - 1, prv[i]);
        
        for(int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1] - 1, prv[i]);
        
        for(int i = 0; i < n; i++)
            cur[i] = max(left[i], right[i]) + pts[j + 1][i];
        
        prv = cur;
    }
    
    long long ans = LLONG_MIN;
    for(int i = 0; i < n; i++)
        ans = max(ans, prv[i]);

    return ans;
}
```

The function calculates the maximum points that can be obtained by traversing through a series of points with given constraints.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<vector<int>> pts;
	```
	Declare a 2D vector `pts` to store the grid of points.

2. **Variable Declaration**
	```cpp
	map<int, map<int, long long>> mp;
	```
	Declare a memoization map `mp` to store previously computed results for subproblems.

3. **Function Declaration**
	```cpp
	long long dp(int idx, int prv) {
	```
	Define the `dp` function that calculates the maximum score from index `idx` with the previous index `prv`.

4. **Base Case**
	```cpp
	    if(idx == pts.size()) return 0;
	```
	Base case: If the index exceeds the size of points, return 0 (no more points to score).

5. **Memoization Check**
	```cpp
	    if(mp.count(idx) && mp[idx].count(prv)) return mp[idx][prv];
	```
	Check if the result for the current subproblem is already computed and stored in the `mp` map.

6. **Variable Initialization**
	```cpp
	    long long ans = LLONG_MIN;
	```
	Initialize `ans` to a very small value to track the best possible score for the current subproblem.

7. **Decision Making**
	```cpp
	    if(prv == -1) {
	```
	If this is the first index (prv == -1), calculate the maximum score by adding the value at the current index.

8. **Looping Over Columns**
	```cpp
	        for(int i = 0; i < pts[0].size(); i++)
	```
	Loop through all columns for the current row and calculate the best score.

9. **Recursive Call**
	```cpp
	            ans = max(ans, pts[idx][i] + dp(idx + 1, i));
	```
	For each column, recursively compute the score for the next index and keep track of the maximum score.

10. **Else Condition**
	```cpp
	    } else {
	```
	Else condition for handling cases where previous index `prv` is valid (not -1).

11. **Looping Over Columns**
	```cpp
	        for(int i = 0; i < pts[0].size(); i++)
	```
	Loop through the columns for the current row, similar to the previous case.

12. **Recursive Call with Absence Penalty**
	```cpp
	            ans = max(ans, pts[idx][i] - abs(i - prv) + dp(idx + 1, i));
	```
	For each column, compute the score considering the penalty for the difference between the current and previous column.

13. **Memoization**
	```cpp
	    return mp[idx][prv] = ans;
	```
	Store the computed result for the current subproblem in the `mp` map to avoid redundant calculations.

14. **Function Declaration**
	```cpp
	long long maxPoints(vector<vector<int>>& points) {
	```
	Define the `maxPoints` function that initializes necessary variables and invokes `dp` for the solution.

15. **Initialization**
	```cpp
	    pts = points;
	```
	Initialize the global variable `pts` with the input points.

16. **Variable Initialization**
	```cpp
	    int m = pts.size(), n = pts[0].size();
	```
	Initialize `m` and `n` with the number of rows and columns in the `pts` grid.

17. **Variable Initialization**
	```cpp
	    vector<long long> prv(n);
	```
	Initialize a vector `prv` to store the previous row's maximum values.

18. **Initialization**
	```cpp
	    for(int i = 0; i < n; i++) prv[i] = pts[0][i];
	```
	Initialize the `prv` vector with values from the first row of `pts`.

19. **Main Loop**
	```cpp
	    for(int j = 0; j < m - 1; j++) {
	```
	Iterate through the rows (except the last one) and calculate the new row's maximum values.

20. **Variable Initialization**
	```cpp
	        vector<long long> left(n, 0), right(n, 0), cur(n, 0);
	```
	Declare and initialize vectors `left`, `right`, and `cur` to store intermediate values for each row.

21. **Boundary Initialization**
	```cpp
	        left[0] = prv[0];
	        right[n - 1] = prv[n - 1];
	```
	Initialize boundary conditions for the left and right vectors.

22. **Left Vector Update**
	```cpp
	        for(int i = 1; i < n; i++)
	            left[i] = max(left[i - 1] - 1, prv[i]);
	```
	Update the `left` vector by computing the maximum value considering the left boundary.

23. **Right Vector Update**
	```cpp
	        for(int i = n - 2; i >= 0; i--)
	            right[i] = max(right[i + 1] - 1, prv[i]);
	```
	Update the `right` vector by computing the maximum value considering the right boundary.

24. **Current Row Update**
	```cpp
	        for(int i = 0; i < n; i++)
	            cur[i] = max(left[i], right[i]) + pts[j + 1][i];
	```
	Update the `cur` vector by considering both the left and right boundary values.

25. **Updating Previous Row**
	```cpp
	        prv = cur;
	```
	Update the `prv` vector with the new calculated values from `cur`.

26. **Finding the Maximum Value**
	```cpp
	    long long ans = LLONG_MIN;
	```
	Initialize `ans` to store the final maximum score.

27. **Final Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	        ans = max(ans, prv[i]);
	```
	Iterate through the last row and find the maximum score.

28. **Return Result**
	```cpp
	    return ans;
	```
	Return the maximum score as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is linear in the number of rows and columns in the matrix.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need to store the maximum scores for each column.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-points-with-cost/description/)

---
{{< youtube ik1y7fz8AOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
