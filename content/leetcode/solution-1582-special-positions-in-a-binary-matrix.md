
+++
authors = ["grid47"]
title = "Leetcode 1582: Special Positions in a Binary Matrix"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1582: Special Positions in a Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "CsxwXaPmMyE"
youtube_upload_date="2020-09-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/CsxwXaPmMyE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) row[i]++, col[j]++;
        }

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
                res++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the number of "special" ones in a binary matrix. A "special" one is defined as a `1` that is the only `1` in its respective row and column. Given the constraints of the problem, our goal is to efficiently count how many such special ones exist in the matrix.

### Approach

To solve the problem, we can break down the task into several clear steps:

1. **Initialize Counters**: We will maintain two arrays to keep track of the number of `1`s in each row and each column.

2. **Count `1`s**: Iterate through the matrix to populate the row and column counts.

3. **Identify Special Ones**: Perform another pass through the matrix to check each `1`. If a `1` is the only `1` in its row and its column, we will count it as a special one.

4. **Return the Count**: Finally, we return the total count of special ones found.

This approach allows us to efficiently determine the number of special ones by leveraging simple counting mechanisms, which keeps our solution efficient.

### Code Breakdown (Step by Step)

Let's analyze the code to see how it implements the above approach:

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        int res = 0;
```

- **Class Definition**: We define a class `Solution` with a public member function `numSpecial`.
- **Matrix Dimensions**: We determine the dimensions of the input matrix `mat` where `m` is the number of rows and `n` is the number of columns.
- **Counters**: Two vectors, `row` and `col`, are initialized to keep track of the number of `1`s in each row and column respectively. The result counter `res` is initialized to zero.

#### Counting `1`s

```cpp
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) row[i]++, col[j]++;
        }
```

- **Nested Loop**: We use two nested loops to traverse each element in the matrix.
- **Increment Counters**: If we encounter a `1`, we increment the respective row and column counters. This operation runs in \( O(m \times n) \) time, where \( m \) and \( n \) are the dimensions of the matrix.

#### Identifying Special Ones

```cpp
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
                res++;
            }
        }
```

- **Second Nested Loop**: We again traverse the matrix with two nested loops.
- **Check Conditions**: For each `1`, we check:
  - Whether it is the only `1` in its row (i.e., `row[i] == 1`).
  - Whether it is the only `1` in its column (i.e., `col[j] == 1`).
  - Finally, we verify that the current element is indeed a `1`.
- **Count Special Ones**: If all conditions are met, we increment the result counter `res`.

#### Returning the Result

```cpp
        return res;
    }
};
```

- **Final Output**: After checking all elements, we return the total count of special ones stored in `res`.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \( O(m \times n) \). This is because we are performing two passes over the matrix: one to count the `1`s and another to check for special ones.
  
- **Space Complexity**: The space complexity is \( O(m + n) \) due to the additional space used for the `row` and `col` arrays.

### Conclusion

This solution effectively identifies special ones in a binary matrix through a straightforward counting approach. By maintaining arrays to track the number of `1`s in each row and column, we achieve an efficient solution that can handle the problem within the constraints typically encountered in competitive programming. 

The clear separation of counting and checking logic allows for easy debugging and understanding of the flow of data through the algorithm. This technique can be broadly applied to similar matrix manipulation problems where conditions are based on row and column relationships. 

Moreover, the solution adheres to best practices by ensuring clarity and simplicity, making it suitable for both educational purposes and real-world applications. It showcases how careful algorithm design can lead to efficient solutions with optimal complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/)

---
{{< youtube CsxwXaPmMyE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
