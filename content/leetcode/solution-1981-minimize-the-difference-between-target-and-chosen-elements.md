
+++
authors = ["grid47"]
title = "Leetcode 1981: Minimize the Difference Between Target and Chosen Elements"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1981: Minimize the Difference Between Target and Chosen Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cfQFu_VDISI"
youtube_upload_date="2021-08-31"
youtube_thumbnail="https://i.ytimg.com/vi/cfQFu_VDISI/maxresdefault.jpg"
comments = true
+++



---
You are given an m x n integer matrix, where each row contains n integers. You are also given a target integer. Your task is to choose one integer from each row of the matrix such that the absolute difference between the target and the sum of the chosen elements is minimized. Return the minimum absolute difference.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with a 2D matrix mat of integers and an integer target.
- **Example:** `mat = [[3, 4, 5], [7, 8, 9], [10, 11, 12]], target = 21`
- **Constraints:**
	- 1 <= m, n <= 70
	- 1 <= mat[i][j] <= 70
	- 1 <= target <= 800

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum absolute difference between the sum of selected integers and the target.
- **Example:** `Output: 1`
- **Constraints:**
	- The returned value must be the smallest possible absolute difference.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to select one integer from each row in the matrix such that the sum of the selected integers is as close as possible to the target value.

- Use dynamic programming to explore all possible sums from the selected integers.
- For each row, explore the possible integers that can be selected and calculate the sum.
- Track the minimum absolute difference as you move through the rows.
{{< dots >}}
### Problem Assumptions ✅
- The matrix has at least one row and one column.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mat = [[3, 4, 5], [7, 8, 9], [10, 11, 12]], target = 21`  \
  **Explanation:** In this case, selecting the values 4, 8, and 9 gives a sum of 21, which matches the target, resulting in an absolute difference of 0.

- **Input:** `Input: mat = [[3], [4], [5]], target = 20`  \
  **Explanation:** In this case, selecting the values 3, 4, and 5 gives a sum of 12, resulting in an absolute difference of 8.

{{< dots >}}
## Approach 🚀
We will use dynamic programming to track all possible sums of selected elements from the matrix. The goal is to minimize the absolute difference between the sum and the target.

### Initial Thoughts 💭
- The problem is essentially about exploring all possible sums and selecting the one closest to the target.
- We will build a recursive function that tries to select one number from each row and track the sums. To optimize this, we can use memoization.
{{< dots >}}
### Edge Cases 🌐
- If the matrix is empty, return the absolute difference with the target as the sum would be zero.
- The solution should efficiently handle matrices of size up to 70x70.
- If the target is too small or too large, the algorithm should still handle the problem gracefully.
- Ensure that the memoization approach efficiently handles the state space for large inputs.
{{< dots >}}
## Code 💻
```cpp

vector<vector<int>> mat;
int memo[4901][70];
int dp(int idx, int sum, int net) {
    if(idx == mat.size()) return abs(sum - net);
    
    if(memo[sum][idx] != -1) return memo[sum][idx];
    
    int ans = INT_MAX;
    for(int i = 0; i < mat[0].size(); i++)
        ans = min(ans, dp(idx + 1, sum + mat[idx][i], net));
    
    return memo[sum][idx] = ans;
}

int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    this->mat = mat;
    memset(memo, -1, sizeof(memo));
    return dp(0, 0, target);
}
```

This code defines a dynamic programming solution to minimize the difference between the sum of selected elements from a matrix and a target value. It uses memoization to optimize repeated calculations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declarations**
	```cpp
	vector<vector<int>> mat;
	```
	Declare a 2D vector `mat` that will hold the input matrix.

2. **Memoization Array**
	```cpp
	int memo[4901][70];
	```
	Declare a memoization array `memo` to store intermediate results of subproblems, optimizing repeated calculations.

3. **DP Function Definition**
	```cpp
	int dp(int idx, int sum, int net) {
	```
	Define a recursive function `dp` that computes the minimum difference between `sum` and `net` using dynamic programming with memoization.

4. **Base Case**
	```cpp
	    if(idx == mat.size()) return abs(sum - net);
	```
	Base case of the recursive function: when all rows have been processed, return the absolute difference between the current sum and the target `net`.

5. **Memoization Check**
	```cpp
	    if(memo[sum][idx] != -1) return memo[sum][idx];
	```
	Check if the result for the current state `(sum, idx)` is already computed. If so, return the stored value from `memo`.

6. **Initialization**
	```cpp
	    int ans = INT_MAX;
	```
	Initialize `ans` to the maximum possible integer value. This will store the minimum difference found.

7. **Loop Over Matrix Columns**
	```cpp
	    for(int i = 0; i < mat[0].size(); i++)
	```
	Loop over the columns of the current row `mat[idx]` to evaluate different choices.

8. **Recursion Call**
	```cpp
	        ans = min(ans, dp(idx + 1, sum + mat[idx][i], net));
	```
	Recursively call `dp` for the next row, adding the current element `mat[idx][i]` to `sum` and comparing the result to find the minimum.

9. **Memoization Store**
	```cpp
	    return memo[sum][idx] = ans;
	```
	Store the computed result `ans` in the `memo` array for future reuse.

10. **Main Function Definition**
	```cpp
	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
	```
	Define the main function `minimizeTheDifference` which initializes the `mat` and calls the recursive `dp` function to compute the result.

11. **Set Matrix**
	```cpp
	    this->mat = mat;
	```
	Assign the input matrix `mat` to the class-level variable `mat`.

12. **Memoization Initialization**
	```cpp
	    memset(memo, -1, sizeof(memo));
	```
	Initialize the memoization array `memo` with `-1` to indicate that no values have been computed yet.

13. **Return Result**
	```cpp
	    return dp(0, 0, target);
	```
	Call the `dp` function starting with the initial index `0`, initial sum `0`, and the target `target`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n * target)
- **Average Case:** O(m * n * target)
- **Worst Case:** O(m * n * target)

The time complexity depends on the number of rows (m), the number of columns (n), and the target value.

### Space Complexity 💾
- **Best Case:** O(m * target)
- **Worst Case:** O(m * target)

The space complexity is determined by the memoization table storing the possible sums for each row.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/)

---
{{< youtube cfQFu_VDISI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
