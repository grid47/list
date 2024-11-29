
+++
authors = ["grid47"]
title = "Leetcode 1072: Flip Columns For Maximum Number of Equal Rows"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1072: Flip Columns For Maximum Number of Equal Rows in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xj3ltfSh9Io"
youtube_upload_date="2020-03-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xj3ltfSh9Io/maxresdefault.webp"
comments = true
+++



---
You are given an m x n binary matrix. You can choose any number of columns in the matrix and flip every cell in that column (i.e., change the value of the cell from 0 to 1 or vice versa). Your task is to find the maximum number of rows that can be made equal after performing a number of column flips.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary matrix with m rows and n columns, where each element is either 0 or 1.
- **Example:** `Input: matrix = [[1,0],[0,0]]`
- **Constraints:**
	- 1 <= m, n <= 300
	- matrix[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer, which represents the maximum number of rows that can be made equal after performing some number of column flips.
- **Example:** `Output: 1`
- **Constraints:**
	- The output should be an integer value representing the maximum number of rows with identical values after flips.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of rows that can be made identical after flipping columns in the matrix.

- 1. Iterate through each row in the matrix.
- 2. For each row, convert it into a binary string where flipped columns are taken into account.
- 3. Track how many times each unique row pattern appears using a hashmap.
- 4. The answer will be the maximum frequency of any row pattern.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix is valid and contains only binary values.
- The matrix dimensions are within the specified constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[0, 1], [1, 1]]`  \
  **Explanation:** In this case, no column flips are needed, as only one row has identical values. The output is 1.

- **Input:** `Input: matrix = [[0, 1], [1, 0]]`  \
  **Explanation:** Flipping the first column will make both rows identical. The output is 2.

- **Input:** `Input: matrix = [[0, 0, 0], [0, 0, 1], [1, 1, 0]]`  \
  **Explanation:** Flipping the first two columns will make the second and third rows identical. The output is 2.

{{< dots >}}
## Approach 🚀
We can solve this problem by tracking the frequency of row patterns. By flipping columns, we can create row patterns that can be stored in a hashmap to count their occurrences. The result is the maximum count of any identical row pattern.

### Initial Thoughts 💭
- Each row can either stay the same or change after flipping columns.
- The key observation is that rows that are already identical after column flips should be counted together.
- We need a way to count how often each unique row pattern appears after flipping columns, and the maximum count will be our answer.
{{< dots >}}
### Edge Cases 🌐
- The problem does not expect an empty matrix, as there must be at least one row and one column.
- Ensure the solution is efficient enough to handle matrices with up to 300 rows and columns.
- If all elements in the matrix are already the same, no flips are needed, and the result is the number of rows.
- The solution must operate efficiently within the given input constraints.
{{< dots >}}
## Code 💻
```cpp
int maxEqualRowsAfterFlips(vector<vector<int>>& mtx) {
    unordered_map<string, int> mp;
    for(auto x: mtx) {
        string s = "";
        int top = x[0];
        for(int i = 0; i < x.size(); i++) {
            if(x[i] == top) s += '1';
            else s += '0';
        }
        mp[s]++;
    }
    int res = 0;
    for(auto [k, v]: mp)
        res = max(res, v);
    return res;
}
```

This code defines a function `maxEqualRowsAfterFlips`, which calculates the maximum number of rows in a binary matrix that can be made identical by flipping any number of rows. It uses a hash map to count occurrences of binary row patterns after normalizing them by making the first element the same.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxEqualRowsAfterFlips(vector<vector<int>>& mtx) {
	```
	This line defines the function `maxEqualRowsAfterFlips`, which takes a 2D vector `mtx` (a binary matrix) and returns the maximum number of rows that can be made equal by flipping some of them.

2. **HashMap Initialization**
	```cpp
	    unordered_map<string, int> mp;
	```
	This line initializes an unordered map `mp`, where the keys will be string representations of rows, and the values will be their frequencies (the number of times each row pattern appears).

3. **Matrix Loop**
	```cpp
	    for(auto x: mtx) {
	```
	This loop iterates over each row `x` in the matrix `mtx`.

4. **String Initialization**
	```cpp
	        string s = "";
	```
	This line initializes an empty string `s`, which will be used to store the binary string representation of the current row.

5. **Top Element Extraction**
	```cpp
	        int top = x[0];
	```
	This line stores the first element of the row `x` in the variable `top`. This will be used to normalize the row by flipping the row to make its first element the same for all rows.

6. **Row Loop**
	```cpp
	        for(int i = 0; i < x.size(); i++) {
	```
	This loop iterates through each element of the row `x`.

7. **Row Normalization**
	```cpp
	            if(x[i] == top) s += '1';
	```
	This line adds '1' to the string `s` if the current element `x[i]` is equal to `top`.

8. **Row Normalization**
	```cpp
	            else s += '0';
	```
	This line adds '0' to the string `s` if the current element `x[i]` is not equal to `top`.

9. **Map Update**
	```cpp
	        mp[s]++;
	```
	This line updates the map `mp`, incrementing the count of the binary string `s`, which represents the current normalized row.

10. **Result Initialization**
	```cpp
	    int res = 0;
	```
	This line initializes the variable `res`, which will store the maximum frequency of any row pattern in the matrix.

11. **Map Loop**
	```cpp
	    for(auto [k, v]: mp)
	```
	This loop iterates over the map `mp`, where `k` is the key (row pattern) and `v` is the frequency of that row pattern.

12. **Result Calculation**
	```cpp
	        res = max(res, v);
	```
	This line updates the result `res` with the maximum value between the current value of `res` and the frequency `v` of the current row pattern `k`.

13. **Return Statement**
	```cpp
	    return res;
	```
	This line returns the value of `res`, which is the maximum frequency of any row pattern in the matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) due to processing each element in the matrix and hashing the row patterns.

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) for storing the row patterns, where m is the number of rows and n is the number of columns in the matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/)

---
{{< youtube xj3ltfSh9Io >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
