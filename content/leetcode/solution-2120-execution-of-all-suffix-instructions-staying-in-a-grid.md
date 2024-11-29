
+++
authors = ["grid47"]
title = "Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid"
date = "2024-04-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xf_naKzI_ZI"
youtube_upload_date="2021-12-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xf_naKzI_ZI/maxresdefault.webp"
comments = true
+++



---
You are given an n x n grid, with the top-left cell at (0, 0) and the bottom-right cell at (n - 1, n - 1). A robot starts at a given position startPos = [startrow, startcol] on the grid, and a string s representing a sequence of movement instructions: 'L' (move left), 'R' (move right), 'U' (move up), and 'D' (move down). The robot can execute the instructions starting from any index i in s, but it stops if it moves off the grid or runs out of instructions. Your task is to return an array answer where answer[i] represents the number of instructions the robot can execute if it starts from the ith instruction.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the size of the grid n, the starting position startPos, and a string s of instructions.
- **Example:** `n = 3, startPos = [0, 1], s = 'RRDDLU'`
- **Constraints:**
	- 1 <= n, m <= 500
	- startPos.length == 2
	- 0 <= startrow, startcol < n
	- s consists of 'L', 'R', 'U', and 'D'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers where each element at index i represents the number of instructions that can be executed if the robot begins at the ith instruction in the sequence.
- **Example:** `For n = 3, startPos = [0, 1], s = 'RRDDLU', the output is [1, 5, 4, 3, 1, 0].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine how many instructions the robot can execute starting from each index in the instruction string while staying within the bounds of the grid.

- For each instruction in the string s, simulate the robot's movement starting from that position, tracking the number of valid moves.
- Stop the simulation if the robot moves off the grid or there are no more instructions to process.
- Store the number of valid instructions the robot can execute starting from each index and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The robot will always start within the bounds of the grid.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: n = 3, startPos = [0, 1], s = 'RRDDLU'`  \
  **Explanation:** Starting from the initial position (0, 1), the robot can execute the following instructions starting from each index: 1 move from index 0 ('R'), 5 moves from index 1 ('RDDLU'), and so on.

- **Input:** `Example 2: n = 2, startPos = [1, 1], s = 'LURD'`  \
  **Explanation:** From position (1, 1), the robot can execute the following instructions starting from each index: 4 moves from index 0 ('LURD'), 1 move from index 1 ('URD'), and so on.

- **Input:** `Example 3: n = 1, startPos = [0, 0], s = 'LRUD'`  \
  **Explanation:** Since the grid is of size 1x1, no moves can be executed, and the result is [0, 0, 0, 0].

{{< dots >}}
## Approach 🚀
The approach is to simulate the robot's movement for each starting position and check how many valid moves it can make while staying within the grid.

### Initial Thoughts 💭
- We need to check each instruction starting from every index in the string s.
- We need to track the robot's position and stop when it moves off the grid.
- A simulation approach will work well here, ensuring that each instruction is processed for each possible starting point.
{{< dots >}}
### Edge Cases 🌐
- If n is 1, no movement is possible, so the result for all indices in s will be 0.
- Ensure that the solution works efficiently for n and m up to 500.
- If all instructions would cause the robot to move off the grid, the result will be 0 for every index.
- The solution should handle the largest grid size and instruction string length efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<int> executeInstructions(int n, vector<int>& st, string s) {
    int m = s.size(), h = m + n, v = m + n;
    vector<int> hor((h + m) * 2, m), ver((h +m) * 2, m), res(m);
    for(int i = m - 1; i >= 0; i--) {
        hor[h] = ver[v] = i;
        h += s[i] == 'L' ? 1 : s[i] == 'R'? -1 : 0;
        v += s[i] == 'U' ? 1 : s[i] == 'D'? -1 : 0;
        res[i] = min({  m, hor[h - st[1] - 1], hor[h - st[1] + n],
                           ver[v - st[0] - 1], ver[v - st[0] + n]  }) - i;
    }
    return res;
}
```

The code provides an implementation of a function that computes the result of executed instructions on a grid, considering various movements in four directions (Left, Right, Up, Down) and their effects on horizontal and vertical positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> executeInstructions(int n, vector<int>& st, string s) {
	```
	Function definition for 'executeInstructions' which takes an integer n, a vector of integers st, and a string s as input. It returns a vector of integers as the result.

2. **Variable Initialization**
	```cpp
	    int m = s.size(), h = m + n, v = m + n;
	```
	This line initializes variables m (size of the string), h (horizontal position), and v (vertical position), both starting from m + n.

3. **Array Initialization**
	```cpp
	    vector<int> hor((h + m) * 2, m), ver((h +m) * 2, m), res(m);
	```
	Three vectors are initialized: hor (for horizontal positions), ver (for vertical positions), and res (for storing the result).

4. **For Loop**
	```cpp
	    for(int i = m - 1; i >= 0; i--) {
	```
	A for loop that iterates through the string s in reverse order, starting from the last character.

5. **Position Update**
	```cpp
	        hor[h] = ver[v] = i;
	```
	Updates the hor and ver arrays at the current positions of h and v to the current index i.

6. **Horizontal Movement**
	```cpp
	        h += s[i] == 'L' ? 1 : s[i] == 'R'? -1 : 0;
	```
	Adjusts the horizontal position (h) based on whether the current character in the string is 'L' (left), 'R' (right), or neither.

7. **Vertical Movement**
	```cpp
	        v += s[i] == 'U' ? 1 : s[i] == 'D'? -1 : 0;
	```
	Adjusts the vertical position (v) based on whether the current character in the string is 'U' (up), 'D' (down), or neither.

8. **Result Calculation**
	```cpp
	        res[i] = min({  m, hor[h - st[1] - 1], hor[h - st[1] + n],
	```
	Calculates the result for the current position by finding the minimum of various possible values based on horizontal movements.

9. **Result Calculation (cont.)**
	```cpp
	                           ver[v - st[0] - 1], ver[v - st[0] + n]  }) - i;
	```
	Continues the result calculation for vertical movements and subtracts the current index i.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result vector containing the calculated values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

The time complexity is O(n * m), where n is the grid size and m is the length of the instruction string.

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity is O(m), as we store the result array of length m.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/)

---
{{< youtube Xf_naKzI_ZI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
