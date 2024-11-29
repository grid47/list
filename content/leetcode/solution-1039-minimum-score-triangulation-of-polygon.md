
+++
authors = ["grid47"]
title = "Leetcode 1039: Minimum Score Triangulation of Polygon"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1039: Minimum Score Triangulation of Polygon in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "plKzOVMehqo"
youtube_upload_date="2019-10-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/plKzOVMehqo/maxresdefault.webp"
comments = true
+++



---
Given an integer array representing the values at the vertices of a convex polygon, you need to triangulate the polygon in such a way that the sum of the products of the values at the vertices of all triangles is minimized. Each triangle must consist of three vertices of the polygon, and the number of triangles will always be n - 2, where n is the number of vertices in the polygon.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array 'values' where each element represents the value at the corresponding vertex of the polygon. The vertices are numbered in a clockwise direction.
- **Example:** `Input: values = [2, 5, 3]`
- **Constraints:**
	- 3 <= n <= 50
	- 1 <= values[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible score achievable by triangulating the polygon. The score is the sum of the products of the values of the vertices in each triangle.
- **Example:** `Output: 30`
- **Constraints:**
	- The score should be minimized by appropriately triangulating the polygon.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the sum of the products of the values of vertices in the triangles formed by triangulating the polygon.

- 1. Use dynamic programming (DP) to break the polygon into subproblems by selecting each pair of adjacent vertices and recursively solving for smaller polygons.
- 2. The key idea is to calculate the minimum score by selecting the right set of diagonals to form triangles.
{{< dots >}}
### Problem Assumptions ✅
- The input polygon is convex and the values at the vertices are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: values = [1, 2, 3]`  \
  **Explanation:** This polygon is already a triangle, and its score is simply the product of its three vertices: 1 * 2 * 3 = 6.

- **Input:** `Input: values = [3, 7, 4, 5]`  \
  **Explanation:** There are two possible triangulations for this polygon: the first has a score of 245 and the second has a score of 144. The minimum score of 144 is the correct result.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming to find the optimal triangulation of the polygon that minimizes the score. The DP table stores the minimum triangulation score for each subpolygon.

### Initial Thoughts 💭
- The problem involves dividing the polygon into triangles by drawing diagonals, and calculating the sum of the products of the values at the vertices of each triangle.
- A dynamic programming approach is suitable here because the problem involves finding the optimal way to triangulate the polygon. We can break the problem down into smaller subproblems.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least 3 vertices, so no need to handle empty inputs.
- For polygons with many vertices (up to 50), the solution should still work efficiently, considering the time complexity.
- Ensure that the DP approach handles cases with larger values (up to 100) efficiently.
- The number of vertices will always be between 3 and 50, ensuring that the problem size is manageable.
{{< dots >}}
## Code 💻
```cpp
int minScoreTriangulation(vector<int>& vals) {
    int dp[50][50] = {};
    
    int n = vals.size();
    
    for(int i = n - 1; i >= 0; i--)
    for(int j = i + 1; j < n; j++)
        for(int k = i + 1; k < j; k++)
    dp[i][j] = min(dp[i][j] == 0? INT_MAX : dp[i][j], dp[i][k] + vals[i] * vals[k] * vals[j] + dp[k][j]);
    
    return dp[0][n - 1];
}
```

This code defines a dynamic programming solution for the problem of finding the minimum score triangulation of a polygon, where 'vals' is a list of integers representing the values at the vertices of the polygon.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minScoreTriangulation(vector<int>& vals) {
	```
	Define the function 'minScoreTriangulation' that calculates the minimum score for triangulating a polygon represented by 'vals'.

2. **DP Array Initialization**
	```cpp
	    int dp[50][50] = {};
	```
	Initialize a 2D dynamic programming array 'dp' of size 50x50 to store the minimum triangulation scores for different subproblems.

3. **Array Size Calculation**
	```cpp
	    int n = vals.size();
	```
	Determine the size of the input array 'vals', which represents the vertices of the polygon.

4. **Outer Loop**
	```cpp
	    for(int i = n - 1; i >= 0; i--)
	```
	Start a loop from the last vertex to the first, iterating over possible starting points for triangulation.

5. **Middle Loop**
	```cpp
	    for(int j = i + 1; j < n; j++)
	```
	Start an inner loop from 'i + 1' to 'n', iterating over possible end points for triangulation.

6. **Inner Loop**
	```cpp
	        for(int k = i + 1; k < j; k++)
	```
	Start the innermost loop to iterate over all points between 'i' and 'j', representing potential intermediate points for the triangulation.

7. **DP Update**
	```cpp
	    dp[i][j] = min(dp[i][j] == 0? INT_MAX : dp[i][j], dp[i][k] + vals[i] * vals[k] * vals[j] + dp[k][j]);
	```
	Update the dynamic programming table by calculating the minimum triangulation score for the subproblem defined by vertices 'i' and 'j'.

8. **Return Statement**
	```cpp
	    return dp[0][n - 1];
	```
	Return the minimum score triangulation for the entire polygon, which is stored in dp[0][n - 1].

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^3)
- **Average Case:** O(n^3)
- **Worst Case:** O(n^3)

The time complexity is O(n^3) because for each pair of vertices (i, j), we check all possible diagonals to calculate the subproblems.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the DP table that stores the results for all subproblems of the polygon.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

---
{{< youtube plKzOVMehqo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
