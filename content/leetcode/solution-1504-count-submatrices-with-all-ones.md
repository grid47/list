
+++
authors = ["grid47"]
title = "Leetcode 1504: Count Submatrices With All Ones"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1504: Count Submatrices With All Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Matrix","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8miqwSN3EFo"
youtube_upload_date="2020-07-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8miqwSN3EFo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cnt += helper(mat, i, j);        
        return cnt;
    }

    int helper(vector<vector<int>>& mat, int a, int b) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0, bnd = n;
        for(int i = a; i < m; i++)
        for(int j = b; j < bnd; j++) {
            if(mat[i][j]) cnt +=1;
            else bnd = j;
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires counting the number of submatrices that consist entirely of 1s in a given binary matrix (a matrix consisting of only 0s and 1s). A submatrix is defined by a rectangular area within the matrix that has its upper left corner and lower right corner defined. 

### Approach

To solve this problem, we can adopt the following approach:

1. **Iterate through each element of the matrix**: For each cell in the matrix, we need to determine how many valid submatrices can be formed starting from that cell.

2. **Use a Helper Function**: We create a helper function that will calculate the number of valid submatrices that can be formed from a given starting cell (the top-left corner of the submatrix). 

3. **Count Submatrices**: The helper function checks for valid submatrices extending downwards and to the right, incrementing the count whenever it encounters a cell that is a 1. If it encounters a cell that is a 0, it will terminate that particular expansion since a submatrix can only consist of 1s.

4. **Return the Total Count**: The main function will sum up the counts obtained from each starting position to give the total number of submatrices.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
```
- We start by defining a class `Solution` and the method `numSubmat` which takes a 2D vector `mat` as input.
- We initialize `m` and `n` to hold the number of rows and columns of the matrix, respectively, and initialize `cnt` to zero, which will keep track of the total count of submatrices.

```cpp
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cnt += helper(mat, i, j);        
```
- We use two nested loops to iterate through each element of the matrix. For each element, we call the `helper` function, passing the current coordinates `(i, j)` of the matrix. The result from the helper function is added to `cnt`.

```cpp
        return cnt;
    }
```
- After traversing all elements and accumulating the counts, we return the total count of submatrices.

```cpp
    int helper(vector<vector<int>>& mat, int a, int b) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0, bnd = n;
```
- The `helper` function is defined to calculate the number of submatrices that can be formed starting from the position `(a, b)`.
- We again obtain the size of the matrix and initialize `cnt` to zero for counting submatrices and `bnd` to `n`, which serves as the right boundary for our exploration.

```cpp
        for(int i = a; i < m; i++)
        for(int j = b; j < bnd; j++) {
            if(mat[i][j]) cnt +=1;
            else bnd = j;
        }
```
- The helper function contains nested loops that iterate downwards (from `a` to `m`) and rightwards (from `b` to `bnd`).
- If we encounter a cell with a value of 1, we increment `cnt`, indicating that we can include this in our count of valid submatrices.
- If we encounter a 0, we update the boundary `bnd` to the current column index `j`, effectively stopping the expansion to the right for any submatrix beginning at `(a, b)`.

```cpp
        return cnt;
    }
};
```
- Finally, the helper function returns the count of valid submatrices found starting from the position `(a, b)`.

### Complexity

#### Time Complexity
- The time complexity of this approach is \(O(m \times n \times (m+n))\). This is due to the fact that for each cell in the matrix (total of \(m \times n\)), the helper function can iterate through all possible rows and columns starting from that cell.

#### Space Complexity
- The space complexity is \(O(1)\) since we are using a constant amount of extra space (the variables `cnt` and `bnd`).

### Conclusion

The solution effectively counts all submatrices filled with 1s in a given binary matrix using a systematic approach that leverages nested loops and a helper function. 

**Key Takeaways**:
- **Matrix Traversal**: Understanding how to traverse a matrix systematically is crucial for solving problems related to submatrices.
- **Dynamic Counting**: The approach dynamically counts valid submatrices based on the current position, which ensures that we account for all potential submatrices originating from each cell.
- **Efficiency Considerations**: Although the time complexity may seem high, this approach is straightforward and easy to understand, making it a good candidate for educational purposes or for understanding basic matrix manipulation.

This method highlights how effective counting techniques can be applied to matrix-related problems, which is a common theme in algorithmic challenges. The ability to recognize patterns and efficiently calculate results is a valuable skill in competitive programming and software development.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-submatrices-with-all-ones/description/)

---
{{< youtube 8miqwSN3EFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
