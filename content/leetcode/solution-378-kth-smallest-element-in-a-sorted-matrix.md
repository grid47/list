
+++
authors = ["grid47"]
title = "Leetcode 378: Kth Smallest Element in a Sorted Matrix"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 378: Kth Smallest Element in a Sorted Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Heap (Priority Queue)","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/378.webp"
youtube = "PKj4LyF5iCk"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/PKj4LyF5iCk/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/378.webp" 
    alt="A matrix where the kth smallest element glows softly, showing its position within the sorted matrix."
    caption="Solution to LeetCode 378: Kth Smallest Element in a Sorted Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an n x n matrix where each row and column is sorted in ascending order, find the kth smallest element in the matrix. The matrix is sorted in both rows and columns, but the kth smallest element is the one in the sorted order, not necessarily distinct.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a matrix with n rows and n columns, where each element in the matrix is sorted in non-decreasing order. You are also given a value k.
- **Example:** `matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]], k = 8`
- **Constraints:**
	- n == matrix.length == matrix[i].length
	- 1 <= n <= 300
	- -10^9 <= matrix[i][j] <= 10^9
	- All the rows and columns of matrix are sorted in non-decreasing order.
	- 1 <= k <= n^2

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the kth smallest element from the matrix.
- **Example:** `Output: 13`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Use a min-heap (priority queue) to efficiently find the kth smallest element from the matrix.

- Initialize a priority queue and push the first element from each row along with its position in the row.
- Pop the top element from the priority queue, and push the next element from the same row (if it exists) into the priority queue.
- Repeat the process until you pop the kth element, which is the kth smallest element in the matrix.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is sorted both row-wise and column-wise.
- The value of k is valid and within the range of the total number of elements in the matrix.
{{< dots >}}
## Examples 🧩
- **Input:** `matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]], k = 8`  \
  **Explanation:** The sorted matrix elements are [1, 5, 9, 10, 11, 12, 13, 13, 15]. The 8th smallest element is 13.

- **Input:** `matrix = [[-5]], k = 1`  \
  **Explanation:** The only element in the matrix is -5, so the 1st smallest element is -5.

{{< dots >}}
## Approach 🚀
We can solve this problem by using a priority queue (min-heap) to efficiently track the smallest elements in the matrix.

### Initial Thoughts 💭
- Since the matrix is sorted, we can use a priority queue to extract the smallest elements efficiently.
- The priority queue will allow us to track the smallest element and ensure that we find the kth smallest element without having to sort the entire matrix.
{{< dots >}}
### Edge Cases 🌐
- The input matrix will always be non-empty as per the problem constraints.
- The algorithm should handle up to the maximum constraints efficiently, with matrix size up to 300 x 300.
- The matrix may contain negative values, and the kth smallest element can be negative as well.
- The value of k will always be valid, and the matrix is guaranteed to be sorted.
{{< dots >}}
## Code 💻
```cpp
int kthSmallest(vector<vector<int>>& mtx, int k) {
    int m = mtx.size(), n = mtx[0].size();
    
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    for(int r = 0; r < min(m, k); r++)
        pq.push({mtx[r][0], r, 0});
    
    vector<int> cur;
    while(k-- > 1 && !pq.empty()) {
        
        cur = pq.top();
        pq.pop();
        
        if(cur[2] + 1 < n)
        pq.push({ mtx[cur[1]][cur[2] + 1], cur[1], cur[2] + 1 });
        
    }
    
    cur = pq.top();
    
    return cur[0];
}
```

This code finds the kth smallest element in a sorted matrix using a priority queue (min-heap). The matrix is sorted row-wise, and the algorithm efficiently selects the smallest elements from each row to compute the kth smallest.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int kthSmallest(vector<vector<int>>& mtx, int k) {
	```
	Declares the function `kthSmallest` which takes a matrix `mtx` and an integer `k` as inputs, and returns the kth smallest element from the matrix.

2. **Matrix Dimensions**
	```cpp
	    int m = mtx.size(), n = mtx[0].size();
	```
	Extracts the number of rows (`m`) and columns (`n`) from the matrix `mtx`.

3. **Priority Queue Initialization**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
	```
	Initializes a min-heap priority queue `pq` to store elements in ascending order. Each element in the queue is a vector containing a matrix element, its row index, and its column index.

4. **Loop Initialization**
	```cpp
	    for(int r = 0; r < min(m, k); r++)
	```
	Loops through the first `k` rows (or less if the matrix has fewer rows) and pushes the first element of each row into the priority queue.

5. **Heap Insertion**
	```cpp
	        pq.push({mtx[r][0], r, 0});
	```
	Pushes a triplet (value, row index, column index) for the first element of each row into the priority queue.

6. **Vector Declaration**
	```cpp
	    vector<int> cur;
	```
	Declares a vector `cur` to temporarily store the current smallest element and its indices from the priority queue.

7. **Main Loop**
	```cpp
	    while(k-- > 1 && !pq.empty()) {
	```
	Runs a loop to extract the smallest element from the heap `k-1` times, ensuring that the heap contains the next smallest elements.

8. **Heap Top Extraction**
	```cpp
	        cur = pq.top();
	```
	Extracts the top (smallest) element from the priority queue into the `cur` vector.

9. **Heap Pop**
	```cpp
	        pq.pop();
	```
	Removes the extracted top element from the priority queue.

10. **Next Element Insertion**
	```cpp
	        if(cur[2] + 1 < n)
	```
	Checks if the next element in the current row exists (i.e., the current column index is within bounds).

11. **Heap Push**
	```cpp
	        pq.push({ mtx[cur[1]][cur[2] + 1], cur[1], cur[2] + 1 });
	```
	Pushes the next element from the current row into the priority queue.

12. **End of Main Loop**
	```cpp
	    }
	```
	Marks the end of the main while loop that processes the next smallest elements from the heap.

13. **Final Result**
	```cpp
	    cur = pq.top();
	```
	Extracts the top element from the priority queue, which is now the kth smallest element after `k-1` extractions.

14. **Return Statement**
	```cpp
	    return cur[0];
	```
	Returns the value of the kth smallest element from the top of the priority queue.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log n)
- **Average Case:** O(k log n)
- **Worst Case:** O(k log n)

The time complexity is O(k log n) because we are performing k operations with a priority queue of size n.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the elements in the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/)

---
{{< youtube PKj4LyF5iCk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
