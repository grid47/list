
+++
authors = ["grid47"]
title = "Leetcode 54: Spiral Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 54: Spiral Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/54.webp"
youtube = "fcn8qkRcFVM"
youtube_upload_date="2024-06-14"
youtube_thumbnail="https://i.ytimg.com/vi/fcn8qkRcFVM/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/54.webp" 
    alt="A glowing spiral matrix, gently unfurling and revealing numbers in soft concentric rings."
    caption="Solution to LeetCode 54: Spiral Matrix Problem"
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
    vector<int> spiralOrder(vector<vector<int>>& mtx) {
        int cBgn = 0, cEnd = mtx[0].size()  - 1;
        int rBgn = 0, rEnd = mtx.size() - 1;
        vector<int> ans;
        while(cBgn <= cEnd && rBgn <= rEnd) {
            for(int i = cBgn; i <= cEnd; i++)
                ans.push_back(mtx[rBgn][i]);
            rBgn++;
            for(int i = rBgn; i <= rEnd; i++)
                ans.push_back(mtx[i][cEnd]);
            cEnd--;
            if(rBgn <= rEnd)
            for(int i = cEnd; i >= cBgn; i--)
                ans.push_back(mtx[rEnd][i]);
            rEnd--;
            if(cBgn <= cEnd)            
            for(int i = rEnd; i >= rBgn; i--)
                ans.push_back(mtx[i][cBgn]);
            cBgn++;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### 🔄 **Spiral Matrix Traversal**

The problem asks to return the elements of a given **2D matrix** in a **spiral order**. The traversal begins at the top-left corner of the matrix, moving right across the top row, down the rightmost column, left across the bottom row, and up the leftmost column. This process continues for the inner submatrix until all elements are visited.

For example, given the matrix:

```
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
```

The expected output in spiral order would be:

```
[1, 2, 3, 6, 9, 8, 7, 4, 5]
```

### 🧑‍💻 **Approach**

We solve this efficiently using a **four-pointer approach**. The key idea is to maintain four boundaries that track the current submatrix:
- **`rBgn` (row beginning)**: The first row to be considered.
- **`rEnd` (row end)**: The last row to be considered.
- **`cBgn` (column beginning)**: The first column to be considered.
- **`cEnd` (column end)**: The last column to be considered.

The traversal follows these steps:
1. Traverse from left to right across the topmost row.
2. Traverse from top to bottom down the rightmost column.
3. Traverse from right to left across the bottommost row.
4. Traverse from bottom to top up the leftmost column.

After completing each step, we update the respective boundary and repeat until all elements are visited.

### 📝 **Code Breakdown**

#### Step 1: Initialize Boundary Variables

```cpp
int cBgn = 0, cEnd = mtx[0].size() - 1;
int rBgn = 0, rEnd = mtx.size() - 1;
```

- **`cBgn` (column beginning)** is set to 0, the first column.
- **`cEnd` (column end)** is set to `mtx[0].size() - 1`, which is the index of the last column.
- **`rBgn` (row beginning)** is set to 0, the first row.
- **`rEnd` (row end)** is set to `mtx.size() - 1`, which is the index of the last row.

These boundaries define the current submatrix to be processed. The algorithm shrinks these boundaries after each pass.

#### Step 2: Initialize the Result Array

```cpp
vector<int> ans;
```

- **`ans`** is a vector to store the elements of the matrix in spiral order.

#### Step 3: Loop Until All Elements Are Traversed

```cpp
while(cBgn <= cEnd && rBgn <= rEnd) {
```

- The loop continues as long as the column and row beginning pointers (`cBgn`, `rBgn`) do not surpass their respective ending pointers (`cEnd`, `rEnd`). This ensures the entire matrix is traversed.

#### Step 4: Traverse from Left to Right across the Top Row

```cpp
for(int i = cBgn; i <= cEnd; i++)
    ans.push_back(mtx[rBgn][i]);
rBgn++;
```

- Traverse from `cBgn` to `cEnd` (the entire top row) and append each element to `ans`.
- After processing the top row, increment `rBgn` to exclude this row from future iterations.

#### Step 5: Traverse from Top to Bottom down the Right Column

```cpp
for(int i = rBgn; i <= rEnd; i++)
    ans.push_back(mtx[i][cEnd]);
cEnd--;
```

- Traverse from `rBgn` to `rEnd` (the entire right column) and append each element to `ans`.
- After processing the right column, decrement `cEnd` to exclude this column in future iterations.

#### Step 6: Traverse from Right to Left across the Bottom Row (If Valid)

```cpp
if(rBgn <= rEnd)
    for(int i = cEnd; i >= cBgn; i--)
        ans.push_back(mtx[rEnd][i]);
rEnd--;
```

- If `rBgn` is still less than or equal to `rEnd`, traverse from `cEnd` to `cBgn` (the entire bottom row) and append each element to `ans`.
- After processing the bottom row, decrement `rEnd`.

#### Step 7: Traverse from Bottom to Top up the Left Column (If Valid)

```cpp
if(cBgn <= cEnd)            
    for(int i = rEnd; i >= rBgn; i--)
        ans.push_back(mtx[i][cBgn]);
cBgn++;
```

- If `cBgn` is still less than or equal to `cEnd`, traverse from `rEnd` to `rBgn` (the entire left column) and append each element to `ans`.
- After processing the left column, increment `cBgn`.

#### Step 8: Return the Result

```cpp
return ans;
```

- Once all elements are traversed, return `ans`, which contains the elements in spiral order.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(n * m):** The algorithm visits each element of the matrix exactly once, where `n` is the number of rows and `m` is the number of columns. Therefore, the time complexity is O(n * m).

#### Space Complexity:
- **O(n * m):** The space complexity is due to storing the result vector `ans`, which holds all the elements of the matrix. Thus, the space complexity is O(n * m).

### 🌟 **Conclusion**

The solution uses an efficient **four-pointer approach** to solve the **spiral matrix traversal** problem. The algorithm traverses the matrix layer by layer, updating the boundaries as it goes. With a time complexity of **O(n * m)** and space complexity of **O(n * m)**, this solution is optimal for large matrices, ensuring a single pass through the matrix while minimizing the use of additional space.

This approach is widely applicable for problems involving spiral traversals or grid-based navigation, making it a valuable tool in algorithmic problem-solving.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/spiral-matrix/description/)

---
{{< youtube fcn8qkRcFVM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
