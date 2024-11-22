
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine whether one given matrix (target) can be obtained by rotating another matrix (mat) by 0, 90, 180, or 270 degrees. This requires checking if the two matrices are equivalent under these rotations.

### Approach

The approach involves the following steps:

1. **Matrix Rotation**: Implement a function to rotate the matrix 90 degrees clockwise.
2. **Matrix Comparison**: Implement a function to compare two matrices to check for equality.
3. **Iteration Through Rotations**: Use a loop to rotate the original matrix up to three times (90, 180, and 270 degrees) and check for equality with the target matrix after each rotation.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `Solution` class encapsulates all relevant methods and data.

   ```cpp
   class Solution {
   public:
   ```

2. **Main Function**: The `findRotation` function iterates through all four possible orientations of the matrix.

   ```cpp
       bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
   ```

3. **Rotation Check Loop**: A loop iterates four times to check each possible orientation:

   ```cpp
           for(int i = 0; i < 4; i++) {
               if(match(mat, target)) return true;
               rotate(mat);
           }
   ```

4. **Returning Result**: If none of the rotations match, return false:

   ```cpp
           return false;
       }
   ```

5. **Matrix Rotation Method**: The `rotate` function rotates the matrix by 90 degrees clockwise. The rotation process involves two steps:
   - First, reverse the rows of the matrix.
   - Second, swap the elements along the diagonal.

   ```cpp
       void rotate(vector<vector<int>>& mtx) {
           int n = mtx.size();
           int i = 0, j = n - 1;
           while(i <= j)
               swap(mtx[i++], mtx[j--]);
           for(int i = 0; i < n; i++)
           for(int j = i + 1; j < n; j++)
               swap(mtx[i][j], mtx[j][i]);
       }
   ```

6. **Matrix Matching Method**: The `match` function checks if two matrices are identical by comparing their elements:

   ```cpp
       bool match(vector<vector<int>>& mtx1, vector<vector<int>>& mtx2) {
           int n = mtx1.size();
           for(int i = 0; i < n; i++)
           for(int j = 0; j < n; j++)
               if(mtx1[i][j] != mtx2[i][j])
                   return false;
           return true;
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n^2) \) for each rotation and matching process, where \( n \) is the dimension of the square matrix. Since we perform these operations for four possible rotations, the overall time complexity is \( O(4n^2) \), which simplifies to \( O(n^2) \).

- **Space Complexity**: The space complexity is \( O(1) \) for this solution because the operations are performed in place on the input matrix and no additional significant space is used apart from the input matrices themselves.

### Conclusion

The solution efficiently checks whether one matrix can be derived from another through rotation. It does so by utilizing helper functions to handle rotation and comparison systematically. The approach ensures that all possible orientations are explored, guaranteeing that the solution will be accurate.

This method is particularly effective in scenarios where matrix manipulation is a common task, such as in computer graphics, robotics, or game development, where orientation changes are frequent. The use of clear and concise functions makes the code maintainable and easy to understand, highlighting good practices in software development.

Overall, this solution demonstrates the use of fundamental programming techniques such as loops, function decomposition, and matrix manipulation, providing a robust framework for handling similar problems in the future.

[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/)

---
{{< youtube vf_nUx64R0E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
