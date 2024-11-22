
+++
authors = ["grid47"]
title = "Leetcode 36: Valid Sudoku"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 36: Valid Sudoku in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/36.webp"
youtube = "TjFXEUCMqI8"
youtube_upload_date="2021-07-05"
youtube_thumbnail="https://i.ytimg.com/vi/TjFXEUCMqI8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/36.webp" 
    alt="A soft grid of numbers and symbols, gently highlighting valid sequences."
    caption="Solution to LeetCode 36: Valid Sudoku Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<string, bool> ma;
        
        for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.') {
                string key = "(";
                    key+=board[i][j];
                key+=")";
                if(ma.count(to_string(i)+key)) return false;
                else ma[to_string(i)+key] = true;
                // cout << to_string(i)+key;
                if(ma.count(key+to_string(j))) return false;
                else ma[key+to_string(j)] = true;
                // cout << key+to_string(j);
                int x = i / 3, y = j / 3;
                if(ma.count(to_string(x)+ key+ to_string(y))) return false;
                else ma[to_string(x)+ key+ to_string(y)] = true;
                // cout<< to_string(i)+ key+ to_string(j);
            }
        }
            return true;
    }
};
{{< /highlight >}}
---

### 🏷️ **Problem Statement**

Given a **9x9 Sudoku board**, the task is to determine whether the board is valid according to the following rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3x3 subgrids must contain the digits 1-9 without repetition.

The task is to return `true` if the given board is valid, and `false` otherwise.

### 🧠 **Approach**

To check the validity of the Sudoku board, we can utilize a **hash map** (`map<string, bool>`) to keep track of digits encountered in the rows, columns, and subgrids. Here's how the algorithm works:

#### Key Observations:
1. A **row** is valid if no digit is repeated in that row.
2. A **column** is valid if no digit is repeated in that column.
3. A **subgrid (3x3 box)** is valid if no digit is repeated in that subgrid.

The solution will:
- Traverse the entire board and for each non-empty cell, check whether it violates the Sudoku rules.
- The validity is checked by ensuring that a digit has not already been encountered in the same row, column, or 3x3 subgrid.
  
We will use a hash map to track occurrences:
- Row: `(i, digit)`
- Column: `(digit, j)`
- Subgrid: `(x, digit, y)`, where `x` and `y` are the subgrid indices.

### 💻 **Code Breakdown**

```cpp
map<string, bool> ma;
```
- **Step 1:** Initialize a map `ma` to track digits in rows, columns, and subgrids. The key is a string representing a unique combination of the current cell's row, column, or subgrid information, and the value is a boolean indicating whether that combination has been encountered.

```cpp
for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++) {
        if(board[i][j] != '.') {
```
- **Step 2:** Loop through the entire 9x9 board. The outer loop iterates over rows, and the inner loop iterates over columns. For each non-empty cell (`board[i][j] != '.'`), we proceed to check for validity.

```cpp
string key = "(";
key += board[i][j];
key += ")";
if(ma.count(to_string(i) + key)) return false;
else ma[to_string(i) + key] = true;
```
- **Step 3:** For a non-empty cell, we construct a key that uniquely identifies the digit in the current row. The key format is `"(digit)"`. We then check if this key has already been encountered for the current row. If so, we return `false` (duplicate found). Otherwise, we add the key to the map.

```cpp
if(ma.count(key + to_string(j))) return false;
else ma[key + to_string(j)] = true;
```
- **Step 4:** We repeat the same process for the column. The key is formed by appending the column index (`to_string(j)`) to the digit key. If a duplicate is found in the column, we return `false`. If no duplicates are found, we add the key to the map.

```cpp
int x = i / 3, y = j / 3;
if(ma.count(to_string(x) + key + to_string(y))) return false;
else ma[to_string(x) + key + to_string(y)] = true;
```
- **Step 5:** We now check the validity of the digit in the **3x3 subgrid**. We calculate the subgrid's indices `x = i / 3` and `y = j / 3` to identify the subgrid. The key is formed by appending `x`, the digit, and `y`. If this key is found in the map, it indicates a violation, and we return `false`. Otherwise, we add the key to the map to mark it as visited.

```cpp
return true;
```
- **Step 6:** After traversing the entire board and checking all rows, columns, and subgrids for duplicates, we return `true` to indicate that the board is valid.

### 📊 **Time and Space Complexity**

#### Time Complexity:
- **O(1):** The time complexity is constant because we are always working with a fixed-size 9x9 board. Each operation (checking and inserting into the map) is done in constant time, and we process a fixed number of cells (81 cells). Therefore, the overall time complexity is **O(1)**.

#### Space Complexity:
- **O(1):** The space complexity is also constant because the size of the map is limited to a fixed number of keys. The map can hold at most 81 cells * 3 (for row, column, and subgrid), resulting in a maximum of 243 entries. Thus, the space complexity is **O(1)**.

### 🚀 **Conclusion**

The `isValidSudoku` function efficiently checks the validity of a 9x9 Sudoku board using a hash map to track the occurrence of digits in rows, columns, and subgrids. The approach guarantees a constant-time solution due to the fixed size of the board. The space complexity remains constant, making the algorithm both time and space efficient. This solution provides a scalable and optimal method for verifying a valid Sudoku board.

[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-sudoku/description/)

---
{{< youtube TjFXEUCMqI8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
