
+++
authors = ["grid47"]
title = "Leetcode 2194: Cells in a Range on an Excel Sheet"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2194: Cells in a Range on an Excel Sheet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jGLLCLtNDbQ"
youtube_upload_date="2022-03-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jGLLCLtNDbQ/maxresdefault.webp"
comments = true
+++



---
You are given a range of cells in an Excel sheet, represented by two cell positions in the format '<col1><row1>:<col2><row2>', where `<col1>` and `<col2>` represent the starting and ending column letters, and `<row1>` and `<row2>` represent the starting and ending row numbers. Your task is to return all the cells within the specified range, sorted first by column and then by row.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` representing a range of cells in the format '<col1><row1>:<col2><row2>', where `<col1>`, `<row1>`, `<col2>`, and `<row2>` are uppercase letters and digits.
- **Example:** `s = 'C2:D4'`
- **Constraints:**
	- The input string is exactly 5 characters long.
	- The column letters are between 'A' and 'Z'.
	- The row numbers are between 1 and 9.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of strings, each representing a cell in the range, sorted first by column and then by row.
- **Example:** `["C2", "C3", "C4", "D2", "D3", "D4"]`
- **Constraints:**
	- The output should list the cells in lexicographically sorted order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all the cells within the given range in lexicographical order.

- 1. Extract the starting and ending columns and rows from the input string.
- 2. Iterate over the columns and rows within the specified range.
- 3. Format each cell as a string and add it to the result list.
- 4. Return the sorted list of cells.
{{< dots >}}
### Problem Assumptions ✅
- The input string is guaranteed to be formatted correctly.
- The range is guaranteed to be valid with `r1 <= r2` and `c1 <= c2`.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'C2:D4'`  \
  **Explanation:** In this example, we need to generate all cells starting from column 'C' row 2 to column 'D' row 4. This includes cells 'C2', 'C3', 'C4', 'D2', 'D3', and 'D4'.

- **Input:** `s = 'A1:E2'`  \
  **Explanation:** In this example, we need to generate all cells from 'A1' to 'E2', which includes cells in a 2-row by 5-column grid.

{{< dots >}}
## Approach 🚀
To solve this problem, we will extract the start and end columns and rows, iterate over them, and generate the corresponding cells. Then, we will return the list of cells sorted first by column and then by row.

### Initial Thoughts 💭
- We need to handle both the column and row ranges and generate all combinations of them.
- A nested loop over columns and rows will give us all the cells in the specified range.
{{< dots >}}
### Edge Cases 🌐
- The input string will always represent a valid range, so no need to handle empty ranges.
- There are no cases with large inputs as the range is limited to a small grid (only 9 rows and 26 columns).
- If the input range includes only a single cell (like 'A1:A1'), the output should just be that one cell.
- Ensure that the input string is properly parsed and interpreted.
{{< dots >}}
## Code 💻
```cpp
vector<string> cellsInRange(string s) {
vector<string> res;
for (char c = s[0]; c <= s[3]; ++c)
    for (char r = s[1]; r <= s[4]; ++r)
        res.push_back({c, r});
return res;
}
```

This function generates all the cell addresses within a given range in a spreadsheet-like format, where the input string `s` specifies the top-left and bottom-right corners of the range.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> cellsInRange(string s) {
	```
	This is the definition of the function `cellsInRange` which takes a string `s` as input. The function generates the range of cells in a grid between two given coordinates.

2. **Variable Declaration**
	```cpp
	vector<string> res;
	```
	A vector `res` is declared to store the resulting list of cells within the specified range.

3. **Loop Initialization**
	```cpp
	for (char c = s[0]; c <= s[3]; ++c)
	```
	This loop initializes the variable `c` to iterate over the characters from the starting column (s[0]) to the ending column (s[3]).

4. **Looping**
	```cpp
	    for (char r = s[1]; r <= s[4]; ++r)
	```
	This inner loop iterates through the rows (from s[1] to s[4]) for each column `c` in the outer loop.

5. **Result Construction**
	```cpp
	        res.push_back({c, r});
	```
	This line constructs a cell string by combining the current column and row characters and adds it to the result vector `res`.

6. **Return Statement**
	```cpp
	return res;
	```
	This returns the list of cells (`res`) that were generated by the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for a single cell range.
- **Average Case:** O(m * n), where m is the number of rows and n is the number of columns in the range.
- **Worst Case:** O(m * n), where m is the number of rows and n is the number of columns in the range.

The time complexity is linear in terms of the number of cells in the specified range.

### Space Complexity 💾
- **Best Case:** O(1) for a single cell range.
- **Worst Case:** O(m * n), where m is the number of rows and n is the number of columns in the range.

The space complexity depends on the number of cells in the range, as we store each cell in the result list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/)

---
{{< youtube jGLLCLtNDbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
