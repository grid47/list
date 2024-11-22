
+++
authors = ["grid47"]
title = "Leetcode 2906: Construct Product Matrix"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2906: Construct Product Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "CXuoLKjEWIs"
youtube_upload_date="2023-10-15"
youtube_thumbnail="https://i.ytimg.com/vi/CXuoLKjEWIs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>xx(n,vector<int>(m));
        vector<vector<int>>yy(n,vector<int>(m));
        
        
        
        int mod = 12345;
        long long p = 1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                xx[i][j] = p;
                p *= grid[i][j];
                p %= mod;
            }
        }
        p = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                yy[i][j] = p;
                p *= grid[i][j];
                p %= mod;
            }
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                long long mul = xx[i][j] * yy[i][j];
                
                ans[i][j] = mul%mod;
            }
        }
        return ans;

    }
};
{{< /highlight >}}
---

The problem asks us to construct a new matrix `ans` based on the provided `grid` matrix, where each element in the new matrix represents the product of all elements in its row and column, except for the current element. The result should be taken modulo `12345` to prevent overflow due to potentially large products.

### Approach

The solution uses a two-pass approach to efficiently compute the required values for the new matrix. In this approach, we calculate partial row and column products separately, storing them in two auxiliary matrices. Then, we combine these results to compute the final `ans` matrix.

Here’s a detailed breakdown of the steps involved:

#### Step 1: Initialize Variables
The matrix `grid` is of size `n x m`. We need to compute a new matrix `ans`, where each element is the product of all elements in the same row and column, excluding the element itself.

- We define two auxiliary matrices `xx` and `yy`, where:
  - `xx[i][j]` will store the product of all elements in the `i-th` row from the beginning of the row to the `j-th` element.
  - `yy[i][j]` will store the product of all elements in the `i-th` row from the end of the row to the `j-th` element.
  
We also define a constant `mod = 12345` for the modulus operation, which is used to keep the intermediate products within bounds.

#### Step 2: First Pass – Compute Row-wise Products (`xx`)
We initialize the `xx` matrix, which stores the cumulative product of elements in each row up to the current element. The variable `p` is initialized to `1` to represent the product before we start multiplying.

The first loop iterates over each row `i` and column `j` to compute the product up to that element. For each element in `grid[i][j]`, we update the `xx[i][j]` with the value of `p`, then multiply `p` by `grid[i][j]` and take the modulo operation with `mod`.

#### Step 3: Second Pass – Compute Row-wise Products in Reverse Order (`yy`)
Next, we initialize the `yy` matrix in a similar way but in reverse order. This matrix stores the cumulative product of elements in each row from the end of the row to the current element.

We set `p` back to `1` and loop through the rows from bottom to top and the columns from right to left. The approach is the same: we update `yy[i][j]` with the value of `p` and then update `p` by multiplying it with `grid[i][j]`, followed by taking modulo `mod`.

#### Step 4: Compute the Final Answer Matrix (`ans`)
Finally, the matrix `ans` is constructed by multiplying the corresponding values from the `xx` and `yy` matrices. For each element `ans[i][j]`, we compute the product of `xx[i][j]` and `yy[i][j]`, which gives us the product of all elements in the row and column except the element itself. We also take the modulo `mod` to prevent overflow.

#### Step 5: Return the Result
After filling in the `ans` matrix, we return it as the final result.

### Code Breakdown (Step by Step)

1. **Matrix Initialization**:
   We initialize three matrices: `ans`, `xx`, and `yy`, all of size `n x m` (where `n` is the number of rows and `m` is the number of columns). These matrices will store intermediate results and the final answer.

2. **First Pass – Compute `xx` Matrix**:
   ```cpp
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
           xx[i][j] = p;
           p *= grid[i][j];
           p %= mod;
       }
   }
   ```
   In this step, we calculate the cumulative product of elements in each row and store it in the `xx` matrix. The variable `p` keeps track of the product as we move across the row.

3. **Second Pass – Compute `yy` Matrix**:
   ```cpp
   for(int i = n - 1; i >= 0; i--) {
       for(int j = m - 1; j >= 0; j--) {
           yy[i][j] = p;
           p *= grid[i][j];
           p %= mod;
       }
   }
   ```
   Here, we calculate the cumulative product of elements in each row in reverse order. The matrix `yy` stores these values.

4. **Construct the Final `ans` Matrix**:
   ```cpp
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
           long long mul = xx[i][j] * yy[i][j];
           ans[i][j] = mul % mod;
       }
   }
   ```
   The final step multiplies the corresponding values from `xx` and `yy` to calculate the product of all elements in the same row and column except the element itself. This result is then stored in the `ans` matrix, and the modulo operation ensures that the value doesn't overflow.

5. **Return the Result**:
   ```cpp
   return ans;
   ```
   After constructing the `ans` matrix, we return it as the result.

### Complexity

#### Time Complexity:
- **First Pass**: The time complexity of the first loop, which constructs the `xx` matrix, is `O(n * m)`, where `n` is the number of rows and `m` is the number of columns.
- **Second Pass**: The time complexity of the second loop, which constructs the `yy` matrix, is also `O(n * m)`.
- **Final Pass**: The final loop to construct the `ans` matrix takes `O(n * m)` time.

Thus, the overall time complexity of the solution is `O(n * m)`.

#### Space Complexity:
- We use three matrices `xx`, `yy`, and `ans`, each of size `n x m`. Therefore, the space complexity is `O(n * m)`.

### Conclusion

The given solution efficiently calculates the product of all elements in the same row and column, excluding the current element, by using a two-pass approach. The solution is optimal with a time complexity of `O(n * m)` and space complexity of `O(n * m)`, making it suitable for large grids. The use of modulo `12345` ensures that the values remain within manageable limits, preventing overflow during the multiplication steps.

[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-product-matrix/description/)

---
{{< youtube CXuoLKjEWIs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
