
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minScoreTriangulation(vector<int>& vals) {
        int dp[50][50] = {};
        
        int n = vals.size();
        
        for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
            for(int k = i + 1; k < j; k++)
        dp[i][j] = min(dp[i][j] == 0? INT_MAX : dp[i][j], dp[i][k] + vals[i] * vals[k] * vals[j] + dp[k][j]);
        
        return dp[0][n - 1];
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to find the minimum score of triangulation for a polygon represented by an array of values. Each vertex of the polygon has an associated value. The triangulation of a polygon involves dividing it into triangles by drawing non-intersecting diagonals. The score of a triangulation is defined as the sum of the products of the values of the vertices of the triangles formed. The objective is to determine the minimum possible score of any valid triangulation of the polygon.

### Approach
To solve this problem, we can use a dynamic programming approach. The key steps in our approach are as follows:

1. **Dynamic Programming Table**: We will create a 2D array `dp` where `dp[i][j]` represents the minimum score to triangulate the polygon formed by the vertices from index `i` to `j`.
2. **Base Case**: The smallest triangulations, consisting of three points (i.e., triangles), can be initialized directly as they cannot be further divided.
3. **Recursion with Memoization**: For each sub-problem defined by two vertices `i` and `j`, we will try every possible vertex `k` between `i` and `j` as the third vertex of the triangle. We will calculate the minimum score by considering the score of the triangles formed by `(i, k, j)` and combining it with the minimum scores of the remaining parts of the polygon.
4. **Iterative Calculation**: The dynamic programming table will be filled in a bottom-up manner.

### Code Breakdown (Step by Step)

1. **Class Definition**: The solution is encapsulated within a class named `Solution`.

2. **Function Signature**: 
   - The `minScoreTriangulation` function takes a vector of integers `vals`, which represents the values associated with the polygon's vertices, and returns an integer indicating the minimum score.

   ```cpp
   int minScoreTriangulation(vector<int>& vals) {
       //...
   }
   ```

3. **Dynamic Programming Table Initialization**:
   - A 2D array `dp` of size 50x50 is created to store the results of subproblems.

   ```cpp
   int dp[50][50] = {};
   ```

4. **Determine the Number of Vertices**:
   - The number of vertices `n` is determined from the size of the `vals` vector.

   ```cpp
   int n = vals.size();
   ```

5. **Iterative Filling of the DP Table**:
   - The outer loop iterates from the last vertex to the first, ensuring we evaluate shorter segments first.

   ```cpp
   for(int i = n - 1; i >= 0; i--) {
   ```

6. **Inner Loop for j**:
   - The second loop iterates from `i + 1` to `n`, representing the end of the current segment.

   ```cpp
   for(int j = i + 1; j < n; j++) {
   ```

7. **Inner Loop for k**:
   - The innermost loop iterates over potential third vertices `k`, where `k` ranges from `i + 1` to `j - 1`.

   ```cpp
   for(int k = i + 1; k < j; k++) {
   ```

8. **Score Calculation**:
   - The score of the triangulation formed by the vertices `i`, `j`, and `k` is computed. If `dp[i][j]` is still zero (uninitialized), it is set to `INT_MAX` to represent infinity.

   ```cpp
   dp[i][j] = min(dp[i][j] == 0? INT_MAX : dp[i][j], 
                  dp[i][k] + vals[i] * vals[k] * vals[j] + dp[k][j]);
   ```

9. **Return the Result**:
   - Finally, the minimum score for the triangulation of the entire polygon is returned, which is stored in `dp[0][n - 1]`.

   ```cpp
   return dp[0][n - 1];
   }
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this approach is \(O(n^3)\), where \(n\) is the number of vertices in the polygon. This is because we have three nested loops: the outer loop runs \(n\) times, the second runs \(n\) times for each outer loop iteration, and the innermost loop runs \(n\) times for each combination of the outer loops.

- **Space Complexity**: The space complexity is \(O(n^2)\) due to the storage requirements for the `dp` table, which holds results for subproblems.

### Conclusion
The provided code efficiently calculates the minimum score of triangulation for a polygon using a dynamic programming approach. By breaking down the problem into smaller subproblems and utilizing a 2D DP table, the algorithm ensures that all potential triangulations are considered, ultimately leading to the optimal solution.

This method is effective for polygons with a reasonable number of vertices, making it applicable in various computational geometry problems, including those encountered in computer graphics and optimization tasks. The clear structure of the dynamic programming solution also enhances its maintainability and adaptability for future enhancements or modifications.

In summary, the `minScoreTriangulation` function provides a robust solution to the problem of triangulating polygons, demonstrating the power of dynamic programming in solving complex combinatorial problems.


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

---
{{< youtube plKzOVMehqo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
