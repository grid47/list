
+++
authors = ["grid47"]
title = "Leetcode 2033: Minimum Operations to Make a Uni-Value Grid"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2033: Minimum Operations to Make a Uni-Value Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "c90k-5HigWs"
youtube_upload_date="2021-10-10"
youtube_thumbnail="https://i.ytimg.com/vi/c90k-5HigWs/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D grid of integers, and an integer `x`. In each operation, you can either add `x` or subtract `x` from any element in the grid. Your task is to transform the grid into a uni-value grid, where all elements are equal. Return the minimum number of operations needed to achieve this, or return -1 if it is not possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D integer grid and an integer `x`.
- **Example:** `grid = [[2,4],[6,8]], x = 2`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 1 <= m * n <= 10^5
	- 1 <= x, grid[i][j] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the minimum number of operations needed to make the grid uni-value. If it is not possible, return -1.
- **Example:** `4`
- **Constraints:**
	- Return -1 if it's impossible to make all values equal.

{{< dots >}}
### Core Logic 🔍
**Goal:** Transform the grid to have all elements equal with the minimum number of operations.

- 1. Check if all differences between grid elements and the first element are divisible by `x`. If not, return -1.
- 2. Sort the grid elements and find the median element.
- 3. Calculate the number of operations required to make all elements equal to the median element.
{{< dots >}}
### Problem Assumptions ✅
- All values in the grid are integers.
- The grid can contain up to 100,000 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[2,4],[6,8]], x = 2`  \
  **Explanation:** We can make every element equal to 4 by performing the following operations:
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
Total operations = 4.

- **Input:** `grid = [[1,5],[2,3]], x = 1`  \
  **Explanation:** We can make all elements equal to 3 by performing the following operations:
- Add x to 1 twice.
- Subtract x from 5 twice.
- Subtract x from 2 once.
Total operations = 5.

- **Input:** `grid = [[1,2],[3,4]], x = 2`  \
  **Explanation:** It is impossible to make all elements equal because the differences between the elements are not divisible by 2. Therefore, return -1.

{{< dots >}}
## Approach 🚀
The problem can be solved by checking the divisibility of the differences between the elements and finding the median element in the grid.

### Initial Thoughts 💭
- We need to check if all differences between grid elements and the first element are divisible by `x`.
- Sorting the grid elements will allow us to easily find the median element.
- We can use the median element as the target value to minimize the number of operations needed.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty, return -1.
- For large grids, ensure efficient traversal and sorting steps.
- Handle grids where all elements are already equal (0 operations needed).
- Ensure all grid values are within the specified range.
{{< dots >}}
## Code 💻
```cpp
int minOperations(vector<vector<int>>& grid, int x) {
    
    int m = grid.size(), n = grid[0].size();
    
    int num = grid[0][0];
    
    vector<int> arr;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        arr.push_back(grid[i][j]);
        if(abs(num - grid[i][j]) % x != 0) return -1;
    }
    
    sort(arr.begin(), arr.end());
    
    int pos = arr.size() / 2;

    int res = 0;
    for(int i = 0; i < arr.size(); i++)        
        res += (abs(arr[pos] - arr[i]) / x);
    
    return res;
    
}
```

This function computes the minimum number of operations to make all elements in a 2D grid divisible by 'x'. It checks if the transformation is possible and calculates the required operations using a median-based approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minOperations(vector<vector<int>>& grid, int x) {
	```
	This defines the 'minOperations' function, which calculates the minimum operations needed to make all elements in the grid divisible by 'x'.

2. **Grid Size Calculation**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This line determines the number of rows 'm' and columns 'n' in the 2D grid.

3. **Initial Number Assignment**
	```cpp
	    int num = grid[0][0];
	```
	Here, the first element of the grid is assigned to the variable 'num', which is used to check divisibility conditions for all elements.

4. **Array Initialization**
	```cpp
	    vector<int> arr;
	```
	An empty vector 'arr' is created to store all the elements of the grid for further processing.

5. **Grid Traversal**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This loop iterates through all the rows of the grid.

6. **Nested Loop Start**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	This nested loop iterates through all the columns of the grid.

7. **Array Population**
	```cpp
	        arr.push_back(grid[i][j]);
	```
	Each element of the grid is pushed into the 'arr' vector.

8. **Divisibility Check**
	```cpp
	        if(abs(num - grid[i][j]) % x != 0) return -1;
	```
	This checks if the absolute difference between 'num' and the current grid element is divisible by 'x'. If not, the function returns -1, indicating that the transformation is impossible.

9. **Array Sorting**
	```cpp
	    sort(arr.begin(), arr.end());
	```
	The vector 'arr' is sorted in ascending order to prepare for the median calculation.

10. **Median Calculation**
	```cpp
	    int pos = arr.size() / 2;
	```
	The position of the median element is calculated by dividing the size of the array by 2.

11. **Result Initialization**
	```cpp
	    int res = 0;
	```
	The variable 'res' is initialized to store the total number of operations.

12. **Operation Calculation Loop**
	```cpp
	    for(int i = 0; i < arr.size(); i++)        
	```
	This loop iterates over all the elements of the sorted array to compute the number of operations required for each element.

13. **Operation Calculation**
	```cpp
	        res += (abs(arr[pos] - arr[i]) / x);
	```
	For each element, the absolute difference between the element and the median is calculated and divided by 'x' to get the number of operations. This value is added to 'res'.

14. **Return Result**
	```cpp
	    return res;
	```
	The total number of operations 'res' is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n * log(m * n))
- **Average Case:** O(m * n * log(m * n))
- **Worst Case:** O(m * n * log(m * n))

The time complexity is dominated by the sorting step which takes O(m * n * log(m * n)) for a grid of size m x n.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to storing the grid elements in an array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/)

---
{{< youtube c90k-5HigWs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
