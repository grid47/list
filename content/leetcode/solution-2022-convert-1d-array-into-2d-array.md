
+++
authors = ["grid47"]
title = "Leetcode 2022: Convert 1D Array Into 2D Array"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2022: Convert 1D Array Into 2D Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "l-VLzZ2riTc"
youtube_upload_date="2024-09-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/l-VLzZ2riTc/maxresdefault.webp"
comments = true
+++



---
You are given a 1D integer array called 'original' and two integers 'm' and 'n'. Your task is to convert this 1D array into a 2D array with 'm' rows and 'n' columns. The elements from the 'original' array should be placed row-wise in the new 2D array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 1D integer array 'original' and two integers 'm' and 'n'.
- **Example:** `original = [1, 2, 3, 4], m = 2, n = 2`
- **Constraints:**
	- 1 <= original.length <= 5 * 10^4
	- 1 <= original[i] <= 10^5
	- 1 <= m, n <= 4 * 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the newly constructed 2D array, or an empty array if it is impossible to fit the elements.
- **Example:** `Output: [[1, 2], [3, 4]]`
- **Constraints:**
	- The 2D array must have m rows and n columns if possible.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if it's possible to fit the elements into a 2D array and construct it row-wise.

- 1. Check if m * n equals the length of the original array. If not, return an empty array.
- 2. Create a new 2D array and populate each row with 'n' elements from the original array.
{{< dots >}}
### Problem Assumptions ✅
- The input array has at least 1 element.
- The integers m and n are both greater than or equal to 1.
{{< dots >}}
## Examples 🧩
- **Input:** `original = [1, 2, 3, 4], m = 2, n = 2`  \
  **Explanation:** The original array has 4 elements, and it can be evenly split into 2 rows and 2 columns.

- **Input:** `original = [1, 2], m = 1, n = 1`  \
  **Explanation:** There are 2 elements in the original array, but it's impossible to fit them into a 1x1 matrix.

{{< dots >}}
## Approach 🚀
The approach involves first checking if the array can be split into a 2D array of the desired dimensions and then constructing it row-wise.

### Initial Thoughts 💭
- Check if the product of m and n equals the length of the array.
- If not, return an empty array.
- If m * n is equal to the length of the array, proceed to construct the 2D array.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return an empty 2D array.
- Ensure that large inputs are handled efficiently by breaking the array into smaller rows.
- Handle cases where m or n is larger than the array's length, or when it's impossible to fit the elements.
- Ensure that the constructed array has m rows and n columns, or return an empty array.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (m * n != original.size()) return {};
    
    vector<vector<int>> res;
    for (int i = 0; i < m*n; i+=n)
        res.push_back(vector<int>(original.begin()+i, original.begin()+i+n));
        
    return res;
}
```

This function takes a one-dimensional array 'original' and reconstructs it into a 2D array with dimensions m x n. If the number of elements in 'original' does not match the required size m * n, it returns an empty array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
	```
	This defines the function 'construct2DArray', which takes a vector of integers 'original', and two integers 'm' and 'n' to form a 2D array.

2. **Condition Check**
	```cpp
	    if (m * n != original.size()) return {};
	```
	This checks if the total number of elements in 'original' matches the required size of the 2D array (m * n). If not, it returns an empty vector.

3. **Variable Initialization**
	```cpp
	    vector<vector<int>> res;
	```
	This initializes a 2D vector 'res' which will hold the result, i.e., the reconstructed 2D array.

4. **Loop Start**
	```cpp
	    for (int i = 0; i < m*n; i+=n)
	```
	This loop iterates over the original array in steps of size 'n', essentially breaking the 1D array into chunks of 'n' elements each to form the rows of the 2D array.

5. **Row Construction**
	```cpp
	        res.push_back(vector<int>(original.begin()+i, original.begin()+i+n));
	```
	This line extracts a subarray from 'original' starting from index 'i' to 'i+n' and adds it as a new row in the result 2D array 'res'.

6. **Return Statement**
	```cpp
	    return res;
	```
	This returns the 2D array 'res' after all rows have been constructed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

We need to iterate through the entire array to construct the 2D matrix.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

We use extra space for the 2D matrix, which has m * n elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-1d-array-into-2d-array/description/)

---
{{< youtube l-VLzZ2riTc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
