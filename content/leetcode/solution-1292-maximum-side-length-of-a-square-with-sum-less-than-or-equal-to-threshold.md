
+++
authors = ["grid47"]
title = "Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2Y2a9VbqiC4"
youtube_upload_date="2020-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/2Y2a9VbqiC4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int hit) {
        int m = mat.size(), n = mat[0].size();
        int res = 0, len = 1;
        vector<vector<int>> sum(m + 1, vector<int> (n + 1));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
                if(i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= hit)
                    res = len++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to determine the maximum side length of a square submatrix within a given matrix of integers where the sum of the elements in the square submatrix does not exceed a specified value (`hit`). 

For example, given the matrix:

```
[
 [1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]
]
```
and `hit = 4`, the largest square submatrix would be of size `2`, as a `2x2` square can be formed, summing up to `4`.

### Approach
To solve this problem, we can use a technique involving prefix sums to efficiently calculate the sum of any square submatrix. The steps are as follows:

1. **Create a Prefix Sum Matrix**: Construct a 2D array `sum` where each element `sum[i][j]` contains the sum of all elements in the matrix from the top-left corner (0,0) to the position (i-1, j-1).
   
2. **Iterate through Possible Square Sizes**: Use two nested loops to iterate over each position in the matrix. For each position, check if it can serve as the bottom-right corner of a square submatrix of increasing sizes (starting from size 1).
   
3. **Check the Sum of the Square Submatrix**: For each possible square, calculate its sum using the prefix sum matrix and check if it is less than or equal to `hit`. Keep track of the maximum side length of all valid squares found.

4. **Return the Result**: After examining all possible positions and square sizes, return the maximum side length found.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int hit) {
```
- **Line 1-2**: The class `Solution` is defined, and the method `maxSideLength` begins, which takes a 2D vector `mat` and an integer `hit`.

```cpp
        int m = mat.size(), n = mat[0].size();
        int res = 0, len = 1;
        vector<vector<int>> sum(m + 1, vector<int> (n + 1));
```
- **Lines 3-6**: The variables `m` and `n` store the dimensions of the input matrix. The variable `res` initializes the result for the maximum side length, while `len` is used to track the current side length being evaluated. A prefix sum matrix `sum` is initialized, with dimensions `(m+1) x (n+1)` to accommodate cumulative sums.

```cpp
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
```
- **Lines 7-10**: Nested loops iterate over the dimensions of the matrix starting from `1`, allowing us to fill in the prefix sum matrix starting from the top-left corner.

```cpp
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
```
- **Line 11**: Here, we compute the prefix sum for the current cell `sum[i][j]` using the formula which accumulates the values from the left, above, subtracts the overlap, and adds the current matrix value.

```cpp
                if(i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= hit)
                    res = len++;
```
- **Lines 12-14**: We check if the current indices allow for a square of side length `len` (i.e., if the current position can serve as the bottom-right corner of such a square). We calculate the sum of the square submatrix using the prefix sums and check if it does not exceed `hit`. If valid, we update the result and increment the `len` for the next square size.

```cpp
        }
        return res;
    }
};
```
- **Lines 15-18**: After finishing the loops, the function returns the maximum side length of the square submatrix found.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the matrix. Each cell of the matrix is visited once to compute the prefix sums.

2. **Space Complexity**:
   - The space complexity is \(O(m \times n)\) due to the additional prefix sum matrix we create to store cumulative sums.

### Conclusion
The `maxSideLength` function efficiently computes the maximum side length of square submatrices whose sum is within a specified threshold using a prefix sum technique. This approach ensures that the sum of any square can be calculated in constant time after an initial setup phase, which is critical for handling larger matrices.

By breaking down the problem systematically and employing an effective algorithm, this solution demonstrates the utility of prefix sums in optimizing 2D range sum queries. This makes the function suitable for competitive programming, coding interviews, and practical applications involving matrix manipulations. 

Overall, understanding and implementing this approach equips developers with powerful tools for tackling similar problems involving submatrices and constraints on their sums. This detailed analysis should serve as a valuable resource for anyone looking to deepen their understanding of matrix operations and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/)

---
{{< youtube 2Y2a9VbqiC4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
