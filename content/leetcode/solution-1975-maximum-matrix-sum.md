
+++
authors = ["grid47"]
title = "Leetcode 1975: Maximum Matrix Sum"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1975: Maximum Matrix Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Qxyne1oRBm0"
youtube_upload_date="2021-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/Qxyne1oRBm0/maxresdefault.jpg"
comments = true
+++



---
You are given a square matrix of integers. You can perform the following operation multiple times: choose any two adjacent elements in the matrix and multiply both of them by -1. Your goal is to maximize the sum of the matrix elements after performing the operation any number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a square matrix of integers `matrix` with `n` rows and `n` columns (2 <= n <= 250).
- **Example:** `matrix = [[1, -2], [-3, 4]]`
- **Constraints:**
	- 2 <= n <= 250
	- -10^5 <= matrix[i][j] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer, representing the maximum sum of the matrix after performing the operation any number of times.
- **Example:** `Output: 16`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the sum of the matrix elements by applying the given operation.

- Step 1: Calculate the sum of the absolute values of all elements in the matrix.
- Step 2: Count the number of negative elements in the matrix.
- Step 3: Identify the minimum absolute value element in the matrix.
- Step 4: If the number of negative elements is odd, subtract twice the minimum absolute value from the total sum to maximize the sum.
- Step 5: Return the final sum.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is always square, i.e., the number of rows is equal to the number of columns.
- The matrix contains integers within the given bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[1, -2], [-3, 4]]`  \
  **Explanation:** In this case, the sum of absolute values is |1| + |-2| + |-3| + |4| = 10. The number of negative elements is 2, which is even. Therefore, we do not need to adjust the sum. The maximum sum is 10.

- **Input:** `Input: matrix = [[-1, 2], [-3, -4]]`  \
  **Explanation:** In this case, the sum of absolute values is |-1| + |2| + |-3| + |-4| = 10. The number of negative elements is 3, which is odd. We subtract twice the minimum absolute value (which is 1) from the sum, resulting in 10 - 2 = 8. The maximum sum is 8.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to compute the sum of absolute values and then adjust the sum if necessary based on the number of negative elements.

### Initial Thoughts 💭
- The matrix's elements can be negative, so we should consider the absolute values to maximize the sum.
- If the number of negative elements is odd, we need to adjust the total sum by subtracting twice the smallest absolute value.
- The solution should compute the sum of absolute values first, then adjust the sum based on the number of negative elements.
{{< dots >}}
### Edge Cases 🌐
- The matrix will always have at least 2 rows and 2 columns.
- The solution must efficiently handle matrices as large as 250x250.
- If all elements in the matrix are positive, no adjustments are needed.
- If all elements are negative and the number of negative elements is odd, the sum will be adjusted.
- Ensure the solution handles the matrix size and the range of integer values correctly.
{{< dots >}}
## Code 💻
```cpp
long long maxMatrixSum(vector<vector<int>>& mat) {
    int n = mat.size();
    

    long long sum = 0;
    bool isodd = n % 2;
    int cnt = 0;
    int mn = abs(mat[0][0]);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
        
        if(mat[i][j] < 0) cnt++;
        
        mn = min(mn, abs(mat[i][j]));
        sum += abs(mat[i][j]);            
    }

    if(cnt%2 == 1)
        sum -= (2 *mn);
    
    return sum;
}
```

This function calculates the maximum sum of absolute values of the elements in a square matrix, adjusting the sum based on the number of negative elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long maxMatrixSum(vector<vector<int>>& mat) {
	```
	This is the function definition for 'maxMatrixSum', which calculates the maximum sum of absolute values in a matrix while handling negative elements.

2. **Matrix Size Calculation**
	```cpp
	    int n = mat.size();
	```
	This line calculates the size of the matrix 'mat' and stores it in the variable 'n'. The matrix is assumed to be square.

3. **Variable Initialization**
	```cpp
	    long long sum = 0;
	```
	The 'sum' variable is initialized to zero, and it will hold the cumulative sum of absolute values of matrix elements.

4. **Odd Check**
	```cpp
	    bool isodd = n % 2;
	```
	The variable 'isodd' checks whether the size of the matrix 'n' is odd or even. This variable is used later for adjustments based on the number of negative values.

5. **Negative Count Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable 'cnt' is initialized to count the number of negative elements in the matrix.

6. **Minimum Value Initialization**
	```cpp
	    int mn = abs(mat[0][0]);
	```
	The 'mn' variable is initialized to the absolute value of the first element of the matrix. It will keep track of the smallest absolute value in the matrix.

7. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This is the outer loop, which iterates over each row of the matrix.

8. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	This is the inner loop, which iterates over each element in the current row of the matrix.

9. **Negative Count Update**
	```cpp
	        if(mat[i][j] < 0) cnt++;
	```
	If the current element in the matrix is negative, increment the 'cnt' variable to keep track of the number of negative elements.

10. **Minimum Value Update**
	```cpp
	        mn = min(mn, abs(mat[i][j]));
	```
	Update the 'mn' variable to store the minimum absolute value encountered in the matrix so far.

11. **Sum Update**
	```cpp
	        sum += abs(mat[i][j]);            
	```
	Add the absolute value of the current matrix element to the 'sum'.

12. **Odd Negative Count Adjustment**
	```cpp
	    if(cnt%2 == 1)
	```
	If the number of negative elements is odd, an adjustment is needed to maximize the sum.

13. **Adjustment to Sum**
	```cpp
	        sum -= (2 *mn);
	```
	If the number of negative elements is odd, subtract twice the minimum absolute value from the sum to make the total sum even.

14. **Return Statement**
	```cpp
	    return sum;
	```
	Return the computed sum, which is the maximum possible sum of absolute values in the matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), where `n` is the number of rows (or columns) in the matrix.
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

We need to iterate through all elements of the matrix to calculate the sum and count the negatives, which takes O(n^2) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only need a constant amount of extra space to store the sum, count, and minimum value, so the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-matrix-sum/description/)

---
{{< youtube Qxyne1oRBm0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
