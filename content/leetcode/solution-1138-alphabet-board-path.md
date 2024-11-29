
+++
authors = ["grid47"]
title = "Leetcode 1138: Alphabet Board Path"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1138: Alphabet Board Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rk-aB4rEOyU"
youtube_upload_date="2020-12-20"
youtube_thumbnail="https://i.ytimg.com/vi/rk-aB4rEOyU/maxresdefault.jpg"
comments = true
+++



---
You are given an alphabet board. Starting at position (0, 0), you need to move around the board to form the target string using the minimum number of moves. The allowed moves are 'U', 'D', 'L', 'R', and '!' to select the character at the current position.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string target that consists of lowercase English letters.
- **Example:** `Input: target = 'hello'`
- **Constraints:**
	- 1 <= target.length <= 100
	- The target string consists of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string representing the sequence of moves that spell out the target string, using the minimum number of steps.
- **Example:** `Output: 'RR!DDDLL!RR!D!'`
- **Constraints:**
	- The output string will contain a valid sequence of moves, including '!' for each character in the target string.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the minimum number of moves that will result in the target string being spelled out.

- Start at position (0, 0).
- For each character in the target string, find the corresponding position on the board.
- Calculate the number of moves required to go from the current position to the target character's position.
- Move accordingly using 'U', 'D', 'L', 'R'.
- Add '!' to the result after each character.
- Update the current position and repeat for the next character.
{{< dots >}}
### Problem Assumptions ✅
- The board layout is fixed and the starting position is always (0, 0).
- The target string is always valid with lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: target = 'hello'`  \
  **Explanation:** To spell 'hello', we start at 'a' and make the following moves: 'RR!' to get to 'h', 'DDDLL!' to get to 'e', then 'RR!' for 'l', and so on.

- **Input:** `Input: target = 'world'`  \
  **Explanation:** For 'world', we make similar moves starting from 'a' to spell out each letter in the target.

{{< dots >}}
## Approach 🚀
We need to calculate the optimal sequence of moves to reach each character in the target string, moving from the current position to the target position on the alphabet board.

### Initial Thoughts 💭
- The board is fixed and letters are positioned in a grid pattern.
- The position of each letter is predictable based on its index in the alphabet.
- We can use simple logic to calculate how many steps to move in each direction (up, down, left, right).
{{< dots >}}
### Edge Cases 🌐
- An empty input will not be given as per the constraints.
- The solution should handle inputs with target.length up to 100 efficiently.
- The board has only lowercase letters, so no edge cases related to non-alphabet characters are expected.
- The result will always fit within the constraints since the maximum number of moves required is limited by the size of the alphabet board.
{{< dots >}}
## Code 💻
```cpp
string alphabetBoardPath(string target) {
    string res;
    int x = 0, y = 0;
    for(auto ch: target) {
        int x1 = (ch - 'a') %5, y1 = (ch - 'a') / 5;
        res +=  string(max(0, y-y1), 'U') +
                string(max(0, x1-x), 'R') +
                string(max(0, x-x1), 'L') +
                string(max(0, y1-y), 'D') + '!';
        x = x1, y = y1;
    }
    return res;
}
```

This function calculates the path to spell a target string on a 5x5 alphabet board by moving in the directions 'U', 'R', 'L', 'D' (up, right, left, down). The string is constructed by calculating the necessary movements from the current position to the next letter in the target string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string alphabetBoardPath(string target) {
	```
	This line defines the function `alphabetBoardPath`, which takes a string `target` as an argument and returns a string representing the sequence of movements on the board.

2. **Variable Initialization**
	```cpp
	    string res;
	```
	This line initializes the result string `res`, which will store the sequence of movements generated during the traversal of the alphabet board.

3. **Coordinate Initialization**
	```cpp
	    int x = 0, y = 0;
	```
	This initializes the starting coordinates `x` and `y` to 0, representing the top-left corner of the board where the traversal begins.

4. **Main Loop**
	```cpp
	    for(auto ch: target) {
	```
	This `for` loop iterates through each character `ch` in the input string `target` to determine the movements required to reach each letter on the board.

5. **Letter Position Calculation**
	```cpp
	        int x1 = (ch - 'a') %5, y1 = (ch - 'a') / 5;
	```
	This line calculates the coordinates `(x1, y1)` of the current letter `ch` on the 5x5 alphabet board, where `x1` is the column index and `y1` is the row index.

6. **Vertical Movement Calculation**
	```cpp
	        res +=  string(max(0, y-y1), 'U') +
	```
	This line calculates and appends the vertical movements (up or down) required to reach the row `y1` from the current row `y`. The `max(0, y-y1)` ensures that no negative values are passed to `string`, as movement in the opposite direction isn't needed.

7. **Horizontal Movement (Right) Calculation**
	```cpp
	                string(max(0, x1-x), 'R') +
	```
	This line calculates and appends the rightward movements required to reach column `x1` from the current column `x`. It uses `max(0, x1-x)` to ensure no negative values are used.

8. **Horizontal Movement (Left) Calculation**
	```cpp
	                string(max(0, x-x1), 'L') +
	```
	This line calculates and appends the leftward movements required to reach column `x1` from the current column `x`, using `max(0, x-x1)` for non-negative movement values.

9. **Vertical Movement (Down) Calculation**
	```cpp
	                string(max(0, y1-y), 'D') + '!';
	```
	This line calculates and appends the downward movements required to reach row `y1` from the current row `y`, and adds the exclamation mark (`'!'`) to signify the end of the current letter movement.

10. **Update Coordinates**
	```cpp
	        x = x1, y = y1;
	```
	After the current movement sequence is appended to `res`, the coordinates `x` and `y` are updated to the new position `(x1, y1)` for the next iteration.

11. **Return Statement**
	```cpp
	    return res;
	```
	This line returns the final result string `res`, which contains the entire sequence of movements needed to spell the target string on the alphabet board.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Since we calculate the position and move direction for each character in the target, the time complexity is linear with respect to the length of the target string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We need space to store the result string, which is proportional to the length of the target string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/alphabet-board-path/description/)

---
{{< youtube rk-aB4rEOyU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
