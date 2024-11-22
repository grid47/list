
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> cellsInRange(string s) {
    vector<string> res;
    for (char c = s[0]; c <= s[3]; ++c)
        for (char r = s[1]; r <= s[4]; ++r)
            res.push_back({c, r});
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement
The problem asks to generate all the cells in a spreadsheet-like grid defined by two corner cells. These cells are provided in the input string `s`, where `s[0]` and `s[3]` represent the column range (from `s[0]` to `s[3]`), and `s[1]` and `s[4]` represent the row range (from `s[1]` to `s[4]`). The task is to return a list of all the cell coordinates (in the form of strings) that lie within the defined rectangular range.

For example, if the input string is `"A1:C3"`, the solution should return the cells: `"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"`.

### Approach
The task can be approached by iterating over the columns and rows defined by the string `s` and collecting the corresponding cells. Specifically, we need to:
1. Extract the column range from `s[0]` to `s[3]`.
2. Extract the row range from `s[1]` to `s[4]`.
3. Iterate over the columns and rows and construct each cell address by concatenating the column letter and row number.
4. Collect all the cell addresses and return them as the result.

The approach efficiently generates all the cells by leveraging the simple properties of characters for columns (since columns are represented by letters) and numerical values for rows.

### Code Breakdown (Step by Step)
1. **Function Declaration**:
   ```cpp
   vector<string> cellsInRange(string s) {
   ```
   - The function `cellsInRange` takes a single string `s` as input and returns a vector of strings, where each string represents a cell in the given range.

2. **Initialize Result Vector**:
   ```cpp
   vector<string> res;
   ```
   - We initialize an empty vector `res` that will hold the resulting cell addresses.

3. **Iterate Over Columns**:
   ```cpp
   for (char c = s[0]; c <= s[3]; ++c)
   ```
   - The first `for` loop iterates over the columns, which are represented by the characters `s[0]` and `s[3]`. Here, `s[0]` is the starting column, and `s[3]` is the ending column. The loop variable `c` represents the current column letter, starting from `s[0]` and incrementing until `s[3]`.

4. **Iterate Over Rows**:
   ```cpp
   for (char r = s[1]; r <= s[4]; ++r)
   ```
   - The second `for` loop iterates over the rows, represented by the characters `s[1]` and `s[4]`. Similarly, `s[1]` is the starting row, and `s[4]` is the ending row. The loop variable `r` represents the current row number, starting from `s[1]` and incrementing until `s[4]`.

5. **Construct the Cell Address**:
   ```cpp
   res.push_back({c, r});
   ```
   - For each combination of column `c` and row `r`, we create a string in the form of a cell address (e.g., "A1", "B2", etc.) and add it to the result vector `res`. The cell is formed by concatenating the column character `c` and the row character `r`.

6. **Return the Result**:
   ```cpp
   return res;
   ```
   - After completing the iteration over all columns and rows, the vector `res`, which now contains all the cell addresses in the defined range, is returned.

### Complexity
- **Time Complexity**:
  - The time complexity is O(n * m), where `n` is the number of columns in the range, and `m` is the number of rows in the range.
  - Specifically, we iterate over all columns between `s[0]` and `s[3]` (which corresponds to `O(n)` where `n` is the number of columns) and for each column, we iterate over all rows between `s[1]` and `s[4]` (which corresponds to `O(m)` where `m` is the number of rows).
  - Thus, the overall time complexity is O(n * m), where `n` is `s[3] - s[0] + 1` and `m` is `s[4] - s[1] + 1`.

- **Space Complexity**:
  - The space complexity is O(n * m), as we are storing all the generated cell addresses in the result vector `res`.

### Conclusion
This solution is an efficient and straightforward way to generate all cell addresses in a given range defined by a string input. The approach leverages simple iteration over columns and rows, making it easy to understand and implement. The time complexity is linear with respect to the number of cells in the range, and the space complexity is also linear with respect to the number of cells in the result.

The code has been optimized to use `char` values for both columns and rows, simplifying the handling of ranges and providing an intuitive solution. This solution should perform well for most practical input sizes, and its time and space complexity ensure that it scales efficiently. Whether you're working with small or large grid sizes, this approach ensures correctness and optimal performance.

[`Link to LeetCode Lab`](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/)

---
{{< youtube jGLLCLtNDbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
