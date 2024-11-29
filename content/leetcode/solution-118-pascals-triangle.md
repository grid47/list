
+++
authors = ["grid47"]
title = "Leetcode 118: Pascal's Triangle"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 118: Pascal's Triangle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/118.webp"
youtube = "nPVEaB3AjUM"
youtube_upload_date="2021-08-10"
youtube_thumbnail="https://i.ytimg.com/vi/nPVEaB3AjUM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/118.webp" 
    alt="A soft, glowing triangular pattern of numbers, expanding outward in delicate layers."
    caption="Solution to LeetCode 118: Pascal's Triangle Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer numRows, return the first numRows of Pascal's triangle. In Pascal's triangle, each number is the sum of the two numbers directly above it. Your task is to generate and return the first 'numRows' of the triangle.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer, numRows, which represents the number of rows to be generated from Pascal's triangle.
- **Example:** `Input: numRows = 4`
- **Constraints:**
	- 1 <= numRows <= 30

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a 2D array, where each row represents the corresponding row of Pascal's triangle, starting from the top.
- **Example:** `Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]`
- **Constraints:**
	- The number of rows in the output should not exceed 'numRows'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate Pascal's triangle row by row, where each row can be constructed by adding the elements directly above it from the previous row.

- Start with the first row, which is always [1].
- For each subsequent row, initialize the row with 1 at the start and end.
- For each intermediate position in the row, calculate the value by adding the two numbers directly above it from the previous row.
- Repeat this process for 'numRows' rows.
{{< dots >}}
### Problem Assumptions ✅
- The input value numRows is always valid and within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: numRows = 4`  \
  **Explanation:** For the input numRows = 4, Pascal's triangle is generated as follows: the first row is [1], the second row is [1, 1], the third row is [1, 2, 1], and the fourth row is [1, 3, 3, 1].

- **Input:** `Input: numRows = 2`  \
  **Explanation:** For the input numRows = 2, the output will be [[1], [1, 1]].

{{< dots >}}
## Approach 🚀
The problem can be solved iteratively by constructing each row based on the previous one. Each new row is initialized with 1 at the boundaries, and the intermediate values are calculated by summing the two values directly above.

### Initial Thoughts 💭
- We can generate each row by leveraging the values of the previous row.
- A direct approach will involve iterating through each row and filling in the values based on the previous row.
{{< dots >}}
### Edge Cases 🌐
- If numRows is 1, the output will just be [[1]].
- The solution should handle up to 30 rows efficiently.
- For numRows = 1, the output is [[1]].
- The input will always satisfy 1 <= numRows <= 30.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> generate(int numRows) {
      vector<vector<int>> r(numRows);

    for (int i = 0; i < numRows; i++) {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;
  
        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
    
    return r;      
}
```

This function generates Pascal's Triangle up to the specified number of rows using a nested loop and dynamic programming approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> generate(int numRows) {
	```
	Declare a function to generate Pascal's Triangle for a given number of rows.

2. **Vector Initialization**
	```cpp
	      vector<vector<int>> r(numRows);
	```
	Initialize a 2D vector to store the rows of Pascal's Triangle.

3. **Outer Loop**
	```cpp
	    for (int i = 0; i < numRows; i++) {
	```
	Iterate over each row to populate Pascal's Triangle.

4. **Row Resize**
	```cpp
	        r[i].resize(i + 1);
	```
	Resize the current row to accommodate the required number of elements.

5. **Row Boundaries**
	```cpp
	        r[i][0] = r[i][i] = 1;
	```
	Set the first and last elements of the row to 1, as they are boundaries in Pascal's Triangle.

6. **Inner Loop**
	```cpp
	        for (int j = 1; j < i; j++)
	```
	Iterate over the internal elements of the current row.

7. **Dynamic Calculation**
	```cpp
	            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
	```
	Compute each internal element as the sum of two elements directly above it in the triangle.

8. **Return Statement**
	```cpp
	    return r;      
	```
	Return the completed Pascal's Triangle as a 2D vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(numRows^2)
- **Average Case:** O(numRows^2)
- **Worst Case:** O(numRows^2)

The time complexity is O(numRows^2) because we process each element in the triangle once.

### Space Complexity 💾
- **Best Case:** O(numRows^2)
- **Worst Case:** O(numRows^2)

The space complexity is O(numRows^2) because the result contains a 2D array of size numRows x numRows in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/pascals-triangle/description/)

---
{{< youtube nPVEaB3AjUM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
