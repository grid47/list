
+++
authors = ["grid47"]
title = "Leetcode 2018: Check if Word Can Be Placed In Crossword"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2018: Check if Word Can Be Placed In Crossword in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "l28OqpotdbU"
youtube_upload_date="2021-09-26"
youtube_thumbnail="https://i.ytimg.com/vi/l28OqpotdbU/maxresdefault.jpg"
comments = true
+++



---
You are given an m x n matrix representing a crossword puzzle. The matrix contains lowercase English letters, empty spaces (' '), and blocked cells ('#'). Given a word, determine if it can be placed horizontally or vertically in the crossword while adhering to the following constraints.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a matrix board of size m x n, where each element is either a lowercase letter, an empty space (' '), or a blocked cell ('#'). A string word is also provided, representing the word that needs to be placed on the board.
- **Example:** `[['#', ' ', '#'], [' ', ' ', '#'], ['#', 'c', ' ']]`
- **Constraints:**
	- m == board.length
	- n == board[i].length
	- 1 <= m * n <= 2 * 10^5
	- board[i][j] will be ' ', '#', or a lowercase English letter.
	- 1 <= word.length <= max(m, n)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the word can be placed on the board, otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The output will be a boolean value indicating whether the word can be placed on the board.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the word can be placed horizontally or vertically on the crossword puzzle, considering all given constraints.

- For each row and column, check if the word fits in either direction (horizontal or vertical) with the given constraints.
- Ensure that the word does not overlap any blocked cells.
- Verify that there are no conflicting adjacent cells before and after placing the word.
{{< dots >}}
### Problem Assumptions ✅
- The word can be placed horizontally or vertically.
- The grid is a crossword puzzle containing blocked cells, empty spaces, and already placed words.
{{< dots >}}
## Examples 🧩
- **Input:** `[['#', ' ', '#'], [' ', ' ', '#'], ['#', 'c', ' ']]`  \
  **Explanation:** The word 'abc' can be placed vertically starting at (0, 1) without conflicting with other letters or blocked cells.

- **Input:** `[[' ', '#', 'a'], [' ', '#', 'c'], [' ', '#', 'a']]`  \
  **Explanation:** It is impossible to place the word 'ac' because of the blocked cells and no available continuous empty space.

- **Input:** `[['#', ' ', '#'], [' ', ' ', '#'], ['#', ' ', 'c']]`  \
  **Explanation:** The word 'ca' can be placed horizontally from right to left in the third row.

{{< dots >}}
## Approach 🚀
The approach is to iterate over each possible starting position in the matrix and check if the word can be placed both horizontally and vertically at that position while satisfying all constraints.

### Initial Thoughts 💭
- We need to check both horizontal and vertical placements of the word at each valid position in the matrix.
- We can break down the problem by checking whether the word fits and adheres to the constraints at each possible position.
{{< dots >}}
### Edge Cases 🌐
- Ensure the solution handles cases where the board has empty cells but is large in size.
- Ensure the solution works efficiently for large boards with up to 2 * 10^5 cells.
- Handle cases where the word is longer than the board dimensions (m or n).
- Handle grids with only blocked cells or only empty cells.
{{< dots >}}
## Code 💻
```cpp

bool same(vector<char> &row, int start, int end, string &s) {
    
    if(end - start + 1 != s.size()) return false;
    
    int i = 0, n = s.size();
    while(i < n && (row[start + i] == ' ' || row[start + i] == s[i])) {
        i++;
    }
    if(i == n) return true;
    i = 0;
    while(i < n && (row[end - i] == ' ' || row[end - i] == s[i]))
          i++;
    if(i == n) return true;             
         
    return false;
}

bool match(vector<vector<char>> &mtx, string &word) {
    int n = mtx[0].size();
    for(auto &row: mtx) {
        for(int i = 0; i < n; ) {
            int start;
            while(i < n && row[i] == '#') i++;
            start = i;
            while(i < n && row[i] != '#') i++;
            if(same(row, start, i - 1, word))
                return true;
        }
    }

    return false;
}

bool placeWordInCrossword(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<char>> trns(n, vector<char>(m));
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        trns[j][i] = board[i][j];
    
    return match(trns, word) || match(board, word);
}
```

This function places a word into a crossword board, checking both row-wise and column-wise placements. It verifies whether the word can fit within the constraints of the board.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool same(vector<char> &row, int start, int end, string &s) {
	```
	This defines the function `same`, which checks if a substring in the `row` matches the given string `s` with allowance for spaces.

2. **Condition Check**
	```cpp
	    if(end - start + 1 != s.size()) return false;
	```
	This checks if the length of the substring from `start` to `end` is equal to the size of the string `s`. If not, it returns false.

3. **Variable Initialization**
	```cpp
	    int i = 0, n = s.size();
	```
	This initializes the loop counter `i` and stores the size of the string `s` in `n`.

4. **Loop for Matching from Start**
	```cpp
	    while(i < n && (row[start + i] == ' ' || row[start + i] == s[i])) {
	```
	This starts a loop that checks if each character in the substring starting from `start` matches the corresponding character in `s`, allowing for spaces.

5. **Increment Counter**
	```cpp
	        i++;
	```
	This increments the counter `i` to check the next character in the string and the row.

6. **Matching Check**
	```cpp
	    if(i == n) return true;
	```
	If the entire string `s` has been matched, this returns true.

7. **Reset Loop Counter**
	```cpp
	    i = 0;
	```
	This resets the counter `i` to start the second matching attempt from the end of the substring.

8. **Loop for Matching from End**
	```cpp
	    while(i < n && (row[end - i] == ' ' || row[end - i] == s[i]))
	```
	This starts a loop that checks if each character in the substring from `end` matches the corresponding character in `s`, allowing for spaces.

9. **Increment Counter**
	```cpp
	          i++;
	```
	This increments the counter `i` to check the next character in the row and the string.

10. **Matching Check**
	```cpp
	    if(i == n) return true;             
	```
	If the entire string `s` is matched in the reverse direction, this returns true.

11. **Return Statement**
	```cpp
	    return false;
	```
	If neither the forward nor reverse match succeeds, it returns false.

12. **Function Definition**
	```cpp
	bool match(vector<vector<char>> &mtx, string &word) {
	```
	This defines the function `match`, which checks whether a word can be placed on the given 2D matrix (either horizontally or vertically).

13. **Grid Size Calculation**
	```cpp
	    int n = mtx[0].size();
	```
	This calculates the number of columns in the matrix `mtx`, which will be used as the upper bound for column-wise iteration.

14. **Matrix Iteration**
	```cpp
	    for(auto &row: mtx) {
	```
	This iterates over each row of the matrix `mtx`.

15. **Column Iteration**
	```cpp
	        for(int i = 0; i < n; ) {
	```
	This iterates through the columns in the row.

16. **Start of Substring**
	```cpp
	            int start;
	```
	This declares a variable `start` to store the starting index of the substring in the row.

17. **Skip '#' Characters**
	```cpp
	            while(i < n && row[i] == '#') i++;
	```
	This skips any `#` characters in the row.

18. **Record Start Position**
	```cpp
	            start = i;
	```
	This sets `start` to the current index `i` where the word could potentially start.

19. **Skip Non- '#' Characters**
	```cpp
	            while(i < n && row[i] != '#') i++;
	```
	This skips any non-`#` characters in the row, as they mark the end of a potential word placement.

20. **Match Check**
	```cpp
	            if(same(row, start, i - 1, word))
	```
	This calls the `same` function to check if the substring from `start` to `i-1` matches the given word.

21. **Return Result**
	```cpp
	                return true;
	```
	If a match is found, it immediately returns `true`.

22. **Return Statement**
	```cpp
	    return false;
	```
	If no match is found after processing all rows, it returns `false`.

23. **Main Function**
	```cpp
	bool placeWordInCrossword(vector<vector<char>>& board, string word) {
	```
	This defines the main function `placeWordInCrossword`, which calls the `match` function for both the original and transposed board.

24. **Matrix Transposition**
	```cpp
	    vector<vector<char>> trns(n, vector<char>(m));
	```
	This initializes a transposed version of the matrix `board`.

25. **Transpose Logic**
	```cpp
	    for(int i = 0; i < m; i++)
	    for(int j = 0; j < n; j++)
	        trns[j][i] = board[i][j];
	```
	This transposes the matrix `board` to facilitate checking column-wise word placements.

26. **Final Match Check**
	```cpp
	    return match(trns, word) || match(board, word);
	```
	This checks if the word can be placed in either the transposed or original matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

We need to check each cell in the board for possible placements of the word.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to track the word placements and their validity.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/description/)

---
{{< youtube l28OqpotdbU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
