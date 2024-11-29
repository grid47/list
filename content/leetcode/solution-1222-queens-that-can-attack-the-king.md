
+++
authors = ["grid47"]
title = "Leetcode 1222: Queens That Can Attack the King"
date = "2024-07-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1222: Queens That Can Attack the King in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
On an 8x8 chessboard, there are multiple black queens and one white king. You are given the positions of the black queens and the white king. Your task is to find all the black queens that can directly attack the white king. A queen can attack the king if they share the same row, column, or diagonal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two inputs: a 2D array 'queens' where each element represents the position of a black queen, and a 1D array 'king' representing the position of the white king.
- **Example:** `queens = [[2, 3], [1, 1], [5, 2], [0, 7], [4, 6]], king = [2, 2]`
- **Constraints:**
	- 1 <= queens.length < 64
	- queens[i].length == king.length == 2
	- 0 <= xQueeni, yQueeni, xKing, yKing < 8
	- All the given positions are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of coordinates of the black queens that can attack the king.
- **Example:** `[[2, 3], [5, 2], [1, 1]]`
- **Constraints:**
	- The output should include all the black queens that can attack the king, in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find all queens that can attack the white king.

- 1. Mark the positions of all black queens on the chessboard.
- 2. Iterate over all possible directions from the king's position.
- 3. Check if there is a queen in each direction.
- 4. If a queen is found, add it to the result list and stop checking further in that direction.
{{< dots >}}
### Problem Assumptions ✅
- Each position is unique, meaning no two queens or the king can occupy the same square.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: queens = [[2, 3], [1, 1], [5, 2], [0, 7], [4, 6]], king = [2, 2]`  \
  **Explanation:** The queens at positions (2, 3), (5, 2), and (1, 1) are in the same row, column, or diagonal as the king. Thus, they can directly attack the king.

{{< dots >}}
## Approach 🚀
The approach to solving this problem is to simulate the chessboard and check the positions of the queens relative to the king, considering all 8 directions.

### Initial Thoughts 💭
- A queen can attack in any of the 8 directions (up, down, left, right, and the four diagonals).
- We can traverse each direction from the king and check for queens in the line of attack.
{{< dots >}}
### Edge Cases 🌐
- There are no queens on the board.
- There are 63 queens on the board, with the king in the center.
- The king is at a corner or edge of the board.
- The problem guarantees unique positions, so no two queens or the king will occupy the same space.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
    vector<vector<bool>> b(8, vector<bool>(8, false));
    for(auto q: queens)
    b[q[0]][q[1]] = true;

    vector<vector<int>> res;
    for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++) {
        if ( i == 0 && j == 0) continue;
        int x = k[0] + i, y = k[1] + j;
        while(min(x, y) >= 0 && max(x, y) < 8) {
            if(b[x][y]) {
                    res.push_back({x, y});
                    break;
            }
            x += i;
            y += j;
        }
    }

    return res;
}
```

This code defines a function `queensAttacktheKing`, which finds all the positions where queens can attack a given king's position on a chessboard.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
	```
	This is the function definition. The function accepts a list of queen positions and the king's position as inputs.

2. **Matrix Initialization**
	```cpp
	    vector<vector<bool>> b(8, vector<bool>(8, false));
	```
	Here, we initialize a 2D boolean vector `b` of size 8x8 representing the chessboard, where each position is initially set to `false`.

3. **Queen Position Setup**
	```cpp
	    for(auto q: queens)
	```
	This loop iterates through all queen positions to mark them as `true` on the chessboard `b`.

4. **Mark Queen on Board**
	```cpp
	    b[q[0]][q[1]] = true;
	```
	This line marks the corresponding position on the chessboard as `true` for each queen.

5. **Result Initialization**
	```cpp
	    vector<vector<int>> res;
	```
	This initializes a vector `res` that will hold the positions of queens that can attack the king.

6. **Direction Loop Setup**
	```cpp
	    for(int i = -1; i <= 1; i++)
	```
	This loop will check all 8 possible directions (vertical, horizontal, and diagonal) around the king.

7. **Direction Loop Inner**
	```cpp
	    for(int j = -1; j <= 1; j++) {
	```
	This loop works in conjunction with the previous loop to examine each direction surrounding the king.

8. **Skip Center Position**
	```cpp
	        if ( i == 0 && j == 0) continue;
	```
	This line ensures that the center position (the king's position) is skipped, as we want to check surrounding squares.

9. **Calculate Adjacent Position**
	```cpp
	        int x = k[0] + i, y = k[1] + j;
	```
	This calculates the adjacent position relative to the king's position by adding the offsets `i` and `j`.

10. **Position Check Loop**
	```cpp
	        while(min(x, y) >= 0 && max(x, y) < 8) {
	```
	This while loop checks if the calculated position is within the bounds of the chessboard (8x8 grid).

11. **Queen Detection**
	```cpp
	            if(b[x][y]) {
	```
	Here, we check if there is a queen at the calculated position.

12. **Add Attack Position**
	```cpp
	                    res.push_back({x, y});
	```
	If a queen is found, the position is added to the result list `res`.

13. **Break Loop**
	```cpp
	                    break;
	```
	Once a queen is found in a given direction, the loop breaks to avoid further searching in that direction.

14. **Move to Next Position**
	```cpp
	            x += i;
	```
	This moves the check to the next position in the current direction by adding `i` to `x`.

15. **Move to Next Position (y)**
	```cpp
	            y += j;
	```
	Similarly, this moves the check to the next position in the current direction by adding `j` to `y`.

16. **Return Result**
	```cpp
	    return res;
	```
	The function returns the list `res`, which contains the positions where queens can attack the king.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) - If no queens are in line with the king.
- **Average Case:** O(8) - Each direction will take at most 8 steps.
- **Worst Case:** O(8) - In the worst case, we check all 8 directions.

The time complexity is primarily dependent on the 8 possible directions from the king's position.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1) - The board is fixed at 8x8, and we only store the positions of the queens and king.

The space complexity is constant because the chessboard size is fixed and we only need space for the queens and the king.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/queens-that-can-attack-the-king/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
