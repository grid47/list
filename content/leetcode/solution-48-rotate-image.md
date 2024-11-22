
+++
authors = ["grid47"]
title = "Leetcode 48: Rotate Image"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 48: Rotate Image in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/48.webp"
youtube = "fMSJSS7eO1w"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fMSJSS7eO1w/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/48.webp" 
    alt="A serene, slow-moving image rotating in space, shifting with soft, calming colors."
    caption="Solution to LeetCode 48: Rotate Image Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void rotate(vector<vector<int>>& mtx) {
        int i = 0, j = mtx.size() - 1;
        while(i <= j)
            swap(mtx[i++], mtx[j--]);
        
        for(int i = 0; i < mtx.size(); i++)
        for(int j = i+1; j< mtx.size(); j++)
            swap(mtx[i][j], mtx[j][i]);
    }
};
{{< /highlight >}}
---

### 🔄 **Rotate Matrix by 90 Degrees Clockwise**

The problem asks us to rotate a given `n x n` matrix (2D square matrix) by 90 degrees in a **clockwise direction**. The key challenge is to perform this rotation **in-place**, meaning we modify the original matrix without using extra space for a new one. The elements should be rearranged so that:

- The first row becomes the last column.
- The second row becomes the second-last column.
- The third row becomes the third-last column, and so on.

### 📊 **Example**

For instance, if the input matrix is:

```
1 2 3
4 5 6
7 8 9
```

After rotating it by 90 degrees clockwise, it should look like:

```
7 4 1
8 5 2
9 6 3
```

### 🧠 **Approach**

To achieve this, we can break the process into two key steps:

1. **Transpose the matrix**: This operation swaps the rows with columns. Specifically, we swap the element at position `(i, j)` with the element at position `(j, i)` for all `i` and `j` where `i < j`.
   
2. **Reverse the rows**: After transposing, we reverse the rows of the matrix. This operation swaps the first row with the last row, the second row with the second-last row, and so on.

By performing these two steps — **transposing** and **reversing the rows** — we can rotate the matrix 90 degrees clockwise in-place.

### 💻 **Code Breakdown (Step by Step)**

#### Step 1: **Reverse the Rows**

We start by reversing the rows of the matrix:

```cpp
int i = 0, j = mtx.size() - 1;
while (i <= j) {
    swap(mtx[i++], mtx[j--]);
}
```

- **Explanation**:
    - Two pointers, `i` and `j`, are initialized. `i` starts at the first row, and `j` starts at the last row.
    - The `swap(mtx[i++], mtx[j--])` operation swaps the rows at indices `i` and `j`, while incrementing `i` and decrementing `j`. This effectively reverses the rows.
    - The loop continues until all rows have been swapped.

#### Step 2: **Transpose the Matrix**

Next, we transpose the matrix by swapping elements at positions `(i, j)` and `(j, i)` for all `i < j`:

```cpp
for (int i = 0; i < mtx.size(); i++) {
    for (int j = i + 1; j < mtx.size(); j++) {
        swap(mtx[i][j], mtx[j][i]);
    }
}
```

- **Explanation**:
    - The outer loop iterates over the rows of the matrix.
    - The inner loop iterates over the columns, starting from `i + 1` to avoid swapping the same element.
    - The `swap(mtx[i][j], mtx[j][i])` operation transposes the matrix by swapping the elements at positions `(i, j)` and `(j, i)`.

After this operation, the matrix becomes:

```
1 4 7
2 5 8
3 6 9
```

#### Final Result

After both steps (reversing the rows and transposing), the matrix is rotated 90 degrees clockwise:

```
7 4 1
8 5 2
9 6 3
```

### ⏱️ **Time and Space Complexity**

#### Time Complexity

1. **Reversing the Rows**: The time complexity for reversing the rows is proportional to the number of rows in the matrix. This operation takes `O(n)` time, where `n` is the number of rows (or columns) in the matrix.
   
2. **Transposing the Matrix**: The time complexity for transposing the matrix is `O(n^2)`, as we need to process all pairs of elements in the upper triangle of the matrix (excluding the diagonal).

Thus, the overall **time complexity** is `O(n^2)`.

#### Space Complexity

- The algorithm rotates the matrix **in-place**, so no extra space is used for a new matrix. The only extra space used is for the loop variables and the temporary swap during transposition.
- Therefore, the **space complexity** is `O(1)`.

### 🎯 **Conclusion**

This approach efficiently rotates an `n x n` matrix by 90 degrees clockwise using two simple operations: reversing the rows and transposing the matrix. Both operations are performed **in-place**, meaning no extra space is used. The time complexity is **O(n²)**, and the space complexity is **O(1)**.

- **Time Complexity**: `O(n²)`, where `n` is the size of the matrix.
- **Space Complexity**: `O(1)`, as the rotation is performed in-place.

This method is optimal for rotating matrices in competitive programming and real-world applications that require in-place modifications.

---

Happy coding, and keep rotating those matrices! 🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/rotate-image/description/)

---
{{< youtube fMSJSS7eO1w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
