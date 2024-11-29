
+++
authors = ["grid47"]
title = "Leetcode 2679: Sum in a Matrix"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2679: Sum in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "oL_BwmPMkng"
youtube_upload_date="2023-05-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/oL_BwmPMkng/maxresdefault.webp"
comments = true
+++



---
You are given a 2D array `nums` where each row represents a set of numbers. You perform operations on the matrix by removing the largest number from each row at each step. After removing the largest number from each row, you identify the highest number amongst all those removed and add it to your score. Repeat this until the matrix becomes empty and return the final score.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D array `nums` which is a matrix of integers. Each row in the matrix represents a set of numbers, and the matrix may have varying numbers of columns.
- **Example:** `Input: nums = [[4, 2, 5], [3, 1, 6], [7, 2, 1]]`
- **Constraints:**
	- 1 <= nums.length <= 300
	- 1 <= nums[i].length <= 500
	- 0 <= nums[i][j] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the final score, which is the sum of the highest numbers chosen at each step.
- **Example:** `Output: 12`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To maximize the score, we need to repeatedly pick the largest number from each row and accumulate the highest number among those chosen.

- Step 1: Sort each row in descending order to easily access the largest number.
- Step 2: For each column (corresponding to the largest number from each row), find the maximum value and add it to the score.
- Step 3: Repeat the process until all rows are empty.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix is non-empty and contains valid integers within the specified range.
- All operations should be done optimally to ensure efficient execution for large inputs.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [[4, 2, 5], [3, 1, 6], [7, 2, 1]]`  \
  **Explanation:** In the first operation, the largest numbers are 5, 6, and 7. We add 7 to the score. Next, we remove the next largest numbers: 4, 3, and 2. We add 4 to the score. Finally, we remove the last remaining numbers: 2, 1, and 1. We add 2 to the score. Thus, the final score is 7 + 4 + 2 = 12.

{{< dots >}}
## Approach 🚀
The approach involves sorting each row in descending order and then iterating through each column to select the maximum number at each step, updating the score accordingly.

### Initial Thoughts 💭
- Sorting each row in descending order allows easy access to the largest number in each row.
- We can iterate over the columns to select the maximum value at each step.
- The solution should handle large inputs efficiently by ensuring the matrix is sorted only once per row.
{{< dots >}}
### Edge Cases 🌐
- The matrix will always contain at least one row and column, so no need to handle empty matrices.
- The solution must be optimized to handle matrices with up to 300 rows and 500 columns efficiently.
- If all elements in the matrix are equal, the score will be the sum of the largest number repeated for each step.
- Ensure that sorting each row and processing columns works efficiently for the largest possible inputs.
{{< dots >}}
## Code 💻
```cpp
int matrixSum(vector<vector<int>>& nums) {
    
    int res = 0;
    
    int m = nums.size(), n = nums[0].size();
    
    for(int i = 0; i < m; i++)
    sort(nums[i].rbegin(), nums[i].rend());
    
    for(int i = 0; i < n; i++) {
        int mx = nums[0][i];
        for(int j = 0; j < m; j++) {
            mx = max(mx, nums[j][i]);
        }
        res += mx;
    }
    return res;
}
```

The function 'matrixSum' calculates the sum of the maximum elements in each column after sorting the rows in descending order. It first sorts each row in reverse order and then selects the maximum element from each column to add to the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int matrixSum(vector<vector<int>>& nums) {
	```
	The function 'matrixSum' is defined to accept a 2D vector 'nums', which represents a matrix of integers. The goal is to find the sum of the maximum values from each column after sorting each row in descending order.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	A variable 'res' is initialized to 0, which will store the sum of the maximum values from each column after sorting the rows.

3. **Matrix Dimensions**
	```cpp
	    int m = nums.size(), n = nums[0].size();
	```
	The number of rows 'm' is determined by the size of 'nums', and the number of columns 'n' is determined by the size of the first row. These values will guide the iteration process.

4. **Row Sorting**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	We loop through each row of the matrix, from the first to the last.

5. **Sort Row**
	```cpp
	    sort(nums[i].rbegin(), nums[i].rend());
	```
	Each row is sorted in descending order using 'rbegin()' and 'rend()' to reverse the row, ensuring that the largest elements come first.

6. **Column Processing**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	We loop through each column of the matrix to find the maximum value from that column.

7. **Max Initialization**
	```cpp
	        int mx = nums[0][i];
	```
	The first element of the column (from the first row) is assigned to 'mx', which will track the maximum value in that column.

8. **Find Max in Column**
	```cpp
	        for(int j = 0; j < m; j++) {
	```
	We loop through each row in the current column to find the maximum value.

9. **Update Max**
	```cpp
	            mx = max(mx, nums[j][i]);
	```
	For each element in the current column, we update 'mx' to the larger of the current 'mx' and the current element in the column.

10. **Add to Result**
	```cpp
	        res += mx;
	```
	After finding the maximum element in the current column, it is added to 'res', which is accumulating the sum of maximum values for each column.

11. **Return Result**
	```cpp
	    return res;
	```
	The function returns the total sum of the maximum values from each column after sorting the rows.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n log n), where m is the number of rows and n is the number of columns.
- **Average Case:** O(m * n log n)
- **Worst Case:** O(m * n log n)

Sorting each row takes O(n log n), and iterating over each column to find the maximum takes O(m). Therefore, the overall time complexity is O(m * n log n).

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the need to store the matrix and its sorted form.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-in-a-matrix/description/)

---
{{< youtube oL_BwmPMkng >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
