
+++
authors = ["grid47"]
title = "Leetcode 1738: Find Kth Largest XOR Coordinate Value"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1738: Find Kth Largest XOR Coordinate Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Bit Manipulation","Sorting","Heap (Priority Queue)","Matrix","Prefix Sum","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3geaHSLu4PA"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/3geaHSLu4PA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mtx, int k) {
        int m = mtx.size(), n = mtx[0].size();
        for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            mtx[i][j] = mtx[i][j-1]^mtx[i][j];}
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                mtx[j][i] = mtx[j -1][i]^mtx[j][i]; }
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n; j++) {
                if(pq.size() < k) {
                    pq.push(mtx[i][j]); }
        else {
            
            if(pq.top() < mtx[i][j]) {
                pq.pop();
                pq.push(mtx[i][j]);
            }
            
            }
                }
            }
        
        return pq.top();
    }
    

};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the k-th largest value in a 2D matrix after applying specific transformations. The transformation requires each element of the matrix to be replaced with the XOR of its corresponding row and column prefix values. The k-th largest value is then to be determined from the transformed matrix.

### Approach

To solve the problem, the approach can be broken down into several key steps:

1. **Transformation of the Matrix**: We need to modify the matrix such that each element at position `(i, j)` is the XOR of all elements in its row from the start to column `j` and all elements in its column from the start to row `i`.

2. **Utilizing a Min-Heap**: To efficiently track the k largest values in the transformed matrix, we can use a min-heap (priority queue). This will allow us to maintain only the k largest values encountered during our traversal of the matrix.

3. **Iterate and Update**: By iterating through the matrix after transformation, we will either add a new value to the heap or replace the smallest value in the heap if the current value is larger.

4. **Return the k-th Largest Value**: Finally, after processing the entire matrix, the top element of the min-heap will represent the k-th largest value.

### Code Breakdown (Step by Step)

Let's go through the code to understand each component in detail:

1. **Class and Function Definition**: The `Solution` class contains the method `kthLargestValue`, which will be the entry point for our solution.

   ```cpp
   class Solution {
   public:
       int kthLargestValue(vector<vector<int>>& mtx, int k) {
   ```

2. **Matrix Dimensions**: We determine the dimensions of the matrix (number of rows `m` and number of columns `n`).

   ```cpp
           int m = mtx.size(), n = mtx[0].size();
   ```

3. **Transforming the Matrix (Row-wise)**: The first nested loop applies the XOR transformation on each row. Each element at `(i, j)` is replaced by the XOR of itself and the preceding element in the same row.

   ```cpp
           for(int i = 0; i < m; i++) {
               for(int j = 1; j < n; j++) {
                   mtx[i][j] = mtx[i][j-1]^mtx[i][j];
               }
           }
   ```

4. **Transforming the Matrix (Column-wise)**: The second nested loop applies the XOR transformation on each column. Each element at `(j, i)` is replaced by the XOR of itself and the preceding element in the same column.

   ```cpp
           for(int i = 0; i < n; i++) {
               for(int j = 1; j < m; j++) {
                   mtx[j][i] = mtx[j -1][i]^mtx[j][i];
               }
           }
   ```

5. **Using a Min-Heap**: A min-heap (priority queue) is initialized to keep track of the k largest values. The type of the priority queue is defined as `greater<int>`, ensuring that the smallest element is at the top.

   ```cpp
           priority_queue<int, vector<int>, greater<int>> pq;
   ```

6. **Iterating through the Matrix**: We traverse the transformed matrix to populate the min-heap.

   ```cpp
           for(int i = 0; i < m; i++) {
               for(int j= 0; j < n; j++) {
                   if(pq.size() < k) {
                       pq.push(mtx[i][j]);
                   } else {
                       if(pq.top() < mtx[i][j]) {
                           pq.pop();
                           pq.push(mtx[i][j]);
                       }
                   }
               }
           }
   ```

   - If the size of the heap is less than `k`, we push the current value onto the heap.
   - If the heap already contains `k` elements, we check if the current value is greater than the smallest value in the heap. If it is, we replace the smallest value.

7. **Returning the Result**: After all values are processed, we return the top value of the heap, which will be the k-th largest.

   ```cpp
           return pq.top();
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(m \times n + k \log k)\), where \(m\) and \(n\) are the dimensions of the matrix. The first part accounts for the time taken to transform the matrix, and the second part accounts for the time taken to maintain the min-heap.

- **Space Complexity**: The space complexity is \(O(k)\) due to the storage of up to `k` elements in the min-heap.

### Conclusion

The solution efficiently determines the k-th largest value from a transformed 2D matrix by applying XOR operations and utilizing a min-heap for optimal performance. By processing the matrix in a systematic manner and leveraging data structures like priority queues, this approach provides a clear and effective solution to the problem. The method is both time-efficient and straightforward, making it suitable for competitive programming and practical applications in data analysis involving matrices. This algorithm exemplifies the power of combining mathematical transformations with efficient data structures to tackle complex problems in an elegant manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/)

---
{{< youtube 3geaHSLu4PA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
