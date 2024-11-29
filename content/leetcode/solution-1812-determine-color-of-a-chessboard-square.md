
+++
authors = ["grid47"]
title = "Leetcode 1812: Determine Color of a Chessboard Square"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1812: Determine Color of a Chessboard Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "7qcZLTyTl5s"
youtube_upload_date="2021-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7qcZLTyTl5s/maxresdefault.webp"
comments = true
+++



---
You are given the coordinates of a square on a chessboard. The coordinate is represented as a string where the first character is a letter representing the column ('a' to 'h') and the second character is a number representing the row ('1' to '8'). Determine if the square is white or black. A square is white if the sum of its row and column is even, and black if it is odd.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string with two characters, where the first character represents the column ('a' to 'h') and the second character represents the row ('1' to '8').
- **Example:** `coordinates = "b2"`
- **Constraints:**
	- coordinates.length == 2
	- 'a' <= coordinates[0] <= 'h'
	- '1' <= coordinates[1] <= '8'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the square is white, and false if the square is black.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean indicating whether the square is white (true) or black (false).

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if the square represented by the input coordinates is white or black.

- Convert the column letter to a numeric value (a = 1, b = 2, ..., h = 8).
- Convert the row number from a character to an integer.
- Sum the column and row values.
- If the sum is even, the square is white; if the sum is odd, the square is black.
{{< dots >}}
### Problem Assumptions ✅
- The input will always represent a valid square on the chessboard.
- The function needs to return a boolean indicating whether the square is white or black.
{{< dots >}}
## Examples 🧩
- **Input:** `coordinates = "b2"`  \
  **Explanation:** The column 'b' corresponds to the value 2, and the row '2' is also 2. The sum of 2 + 2 = 4, which is even, so the square is black (output is false).

- **Input:** `coordinates = "d5"`  \
  **Explanation:** The column 'd' corresponds to the value 4, and the row '5' is 5. The sum of 4 + 5 = 9, which is odd, so the square is white (output is true).

{{< dots >}}
## Approach 🚀
To determine if the square is white or black, we map the column letters to numbers and then check if the sum of the column and row is even or odd.

### Initial Thoughts 💭
- We need to map the letter for the column to a corresponding integer to calculate the sum.
- This can be done by subtracting 'a' from the column letter to get its numerical index.
- The sum of the column and row numbers will determine the color of the square.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs, as coordinates are always valid.
- No large inputs to handle, as the coordinates are always limited to 2 characters.
- Consider edge cases like 'a1' and 'h8' which are at opposite corners of the chessboard.
- Ensure the input follows the specified format and always represents a valid square on the chessboard.
{{< dots >}}
## Code 💻
```cpp
bool squareIsWhite(string cord) {
    int x = cord[0] - 'a' + 1;
    x += cord[1] - '0';
    return x % 2;
}
```

This function `squareIsWhite` determines if a given chessboard square (denoted by the string `cord`) is white or black. It uses the ASCII value of the column character and the number in the row to calculate the sum, then checks if the sum is even or odd to determine the color of the square.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool squareIsWhite(string cord) {
	```
	This line defines the `squareIsWhite` function, which takes a string `cord` representing the chessboard square (e.g., 'a1', 'h8'). It returns a boolean indicating whether the square is white (true) or black (false).

2. **Character Extraction**
	```cpp
	    int x = cord[0] - 'a' + 1;
	```
	Here, the first character of the string `cord` (the column) is extracted, and its ASCII value is adjusted so that 'a' corresponds to 1, 'b' to 2, and so on. The result is stored in the variable `x`.

3. **Row Calculation**
	```cpp
	    x += cord[1] - '0';
	```
	The second character of the string `cord` (the row) is extracted, and the character is converted to an integer by subtracting the ASCII value of '0'. This integer is added to the variable `x`, which now holds the combined sum of the column and row values.

4. **Check Parity**
	```cpp
	    return x % 2;
	```
	The sum `x` is checked for parity. If `x` is even, the square is white, and the function returns `true`. If `x` is odd, the square is black, and the function returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution runs in constant time because it only involves a few arithmetic operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as the solution only requires a fixed amount of space for the calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/)

---
{{< youtube 7qcZLTyTl5s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
