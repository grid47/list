
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
comments = true
+++



---
You are given a 2D matrix of size `m x n`, consisting of non-negative integers. You are also given an integer `k`. The value of coordinate `(a, b)` in the matrix is the XOR of all the values from `matrix[0][0]` to `matrix[a][b]` (inclusive), where `0 <= a < m` and `0 <= b < n` (0-indexed). Your task is to find the `k`th largest value (1-indexed) among all the XOR values of matrix coordinates.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D matrix and an integer `k`.
- **Example:** `Input: matrix = [[1, 3], [5, 7]], k = 2`
- **Constraints:**
	- 1 <= m, n <= 1000
	- 0 <= matrix[i][j] <= 10^6
	- 1 <= k <= m * n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the `k`th largest value among all the XOR values of the coordinates in the matrix.
- **Example:** `Output: 7`
- **Constraints:**
	- The value of `k` will always be valid for the given matrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the XOR of all coordinates in the matrix, store these values, and then return the `k`th largest value.

- 1. For each row, calculate the XOR of all the elements up to that point (left to right).
- 2. For each column, calculate the XOR of all the elements up to that point (top to bottom).
- 3. Store all the XOR values in a list.
- 4. Use a priority queue to find the `k`th largest value in the list.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix will always have at least one row and column.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[1, 3], [5, 7]], k = 2`  \
  **Explanation:** The XOR values of all coordinates are: [1, 2, 7, 5]. The 2nd largest value is 7.

- **Input:** `Input: matrix = [[1, 2, 3], [4, 5, 6]], k = 3`  \
  **Explanation:** The XOR values of all coordinates are: [1, 3, 0, 4, 1, 7]. The 3rd largest value is 4.

{{< dots >}}
## Approach 🚀
The solution involves calculating the XOR of each matrix coordinate, then sorting these values to find the `k`th largest value.

### Initial Thoughts 💭
- The XOR operation combines elements in a way that is sensitive to the order of operations, so we need to compute the values step by step.
- The XOR values are dependent on both the row and column, and we must consider both dimensions while calculating.
{{< dots >}}
### Edge Cases 🌐
- The matrix will always have at least one row and one column.
- Ensure the solution handles the largest possible matrix sizes efficiently.
- Consider cases where all matrix values are the same or the XOR results in repeating values.
- The algorithm must handle matrices with dimensions up to 1000 x 1000.
{{< dots >}}
## Code 💻
```cpp
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


```

This function calculates the kth largest value from a matrix using XOR-based prefix sums. It uses a priority queue (min-heap) to maintain the largest k values and returns the smallest value among those k values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int kthLargestValue(vector<vector<int>>& mtx, int k) {
	```
	This is the function declaration for `kthLargestValue`, which takes a matrix `mtx` and an integer `k` as input, returning the kth largest value from the matrix.

2. **Variable Initialization**
	```cpp
	    int m = mtx.size(), n = mtx[0].size();
	```
	Here, the dimensions of the matrix `mtx` are stored in variables `m` (number of rows) and `n` (number of columns).

3. **Loop Start**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	This loop starts iterating through each row of the matrix.

4. **Loop Start**
	```cpp
	    for(int j = 1; j < n; j++) {
	```
	This nested loop iterates through each column of the current row, starting from the second column.

5. **XOR Operation**
	```cpp
	        mtx[i][j] = mtx[i][j-1]^mtx[i][j];}
	```
	This line performs an XOR operation on the current element and the previous element in the row, updating the matrix with the result. It builds a running XOR prefix sum along each row.

6. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop starts iterating through each column of the matrix.

7. **Loop Start**
	```cpp
	        for(int j = 1; j < m; j++) {
	```
	This nested loop iterates through each row of the current column, starting from the second row.

8. **XOR Operation**
	```cpp
	            mtx[j][i] = mtx[j -1][i]^mtx[j][i]; }
	```
	This line performs an XOR operation on the current element and the previous element in the column, updating the matrix with the result. It builds a running XOR prefix sum along each column.

9. **Priority Queue Declaration**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> pq;
	```
	This line declares a priority queue (min-heap) `pq` that will store integers and always keep the smallest value at the top.

10. **Loop Start**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	This loop starts iterating through each row of the matrix to process the elements.

11. **Loop Start**
	```cpp
	        for(int j= 0; j < n; j++) {
	```
	This nested loop iterates through each column in the current row.

12. **Condition Check**
	```cpp
	            if(pq.size() < k) {
	```
	This condition checks if the priority queue contains fewer than `k` elements.

13. **Queue Operation**
	```cpp
	                pq.push(mtx[i][j]); }
	```
	If the queue has fewer than `k` elements, the current matrix element is pushed into the priority queue.

14. **Else Block**
	```cpp
	    else {
	```
	If the queue already contains `k` elements, the program enters the `else` block to potentially replace the smallest element.

15. **Condition Check**
	```cpp
	        if(pq.top() < mtx[i][j]) {
	```
	This condition checks if the smallest element in the queue is smaller than the current matrix element.

16. **Queue Operation**
	```cpp
	            pq.pop();
	```
	If the smallest element in the queue is smaller than the current element, it is removed from the queue.

17. **Queue Operation**
	```cpp
	            pq.push(mtx[i][j]);
	```
	The current matrix element is pushed into the queue.

18. **Return**
	```cpp
	    return pq.top();
	```
	This returns the top element of the priority queue, which is the kth largest element in the matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where `m` and `n` are the dimensions of the matrix.
- **Average Case:** O(m * n log(m * n)), due to sorting or using a priority queue.
- **Worst Case:** O(m * n log(m * n)), as we need to compute XOR for every coordinate and then find the `k`th largest value.

The time complexity is dominated by the computation of XOR values and the retrieval of the `k`th largest value.

### Space Complexity 💾
- **Best Case:** O(m * n), as we need to store all the XOR values.
- **Worst Case:** O(m * n), since we store the XOR values of all coordinates.

The space complexity is proportional to the number of coordinates in the matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/)

---
{{< youtube 3geaHSLu4PA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
