
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---



### Problem Statement
The problem involves a chessboard where a king is positioned at a specific location, and there are several queens placed on the board. The goal is to determine which queens can attack the king based on their current positions on the board. The chessboard is represented as an 8x8 grid, where rows and columns are indexed from 0 to 7. A queen can attack any piece located in the same row, column, or diagonal. Given the positions of the queens and the position of the king, the task is to return the coordinates of the queens that can attack the king.

### Approach
To solve this problem, we follow these steps:

1. **Initialize a Board**: Create an 8x8 boolean grid to represent the positions of the queens.
2. **Mark Queen Positions**: Loop through the list of queens and mark their positions on the board.
3. **Check Attack Paths**: For each of the eight possible directions a queen can attack (up, down, left, right, and the four diagonals), traverse the board in that direction starting from the king's position.
4. **Record Attacking Queens**: If a queen is found in the path, record its position and stop checking further in that direction.
5. **Return Results**: Return the list of positions of queens that can attack the king.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
```
- **Line 1-2**: Define the `Solution` class and the function `queensAttacktheKing` which takes two parameters: a vector of vectors representing the positions of the queens and a vector representing the position of the king.

```cpp
        vector<vector<bool>> b(8, vector<bool>(8, false));
        for(auto q: queens)
        b[q[0]][q[1]] = true;
```
- **Lines 3-5**: Create a boolean 2D vector `b` of size 8x8 initialized to `false`. Loop through each queen's position in the input vector `queens`, and set the corresponding position in the boolean vector `b` to `true`, indicating that a queen is present at that location.

```cpp
        vector<vector<int>> res;
```
- **Line 6**: Declare a vector `res` to store the positions of the queens that can attack the king.

```cpp
        for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            if ( i == 0 && j == 0) continue;
```
- **Lines 7-11**: Use nested loops to iterate through the eight possible directions a queen can attack. The variables `i` and `j` represent the row and column offsets from the king's position. If both `i` and `j` are zero, skip this iteration since it represents the king's position itself.

```cpp
            int x = k[0] + i, y = k[1] + j;
```
- **Line 12**: Initialize `x` and `y` as the starting coordinates for checking in the current direction. This is done by adding the offsets `i` and `j` to the king's position, `k[0]` and `k[1]`, respectively.

```cpp
            while(min(x, y) >= 0 && max(x, y) < 8) {
```
- **Line 13**: Begin a while loop that continues as long as the current position `(x, y)` is within the bounds of the chessboard (0 to 7).

```cpp
                if(b[x][y]) {
                        res.push_back({x, y});
                        break;
                }
```
- **Lines 14-17**: Inside the loop, check if there is a queen at position `(x, y)` by looking it up in the boolean vector `b`. If a queen is found, add its position to the `res` vector and break out of the loop to stop checking in this direction.

```cpp
                x += i;
                y += j;
            }
```
- **Lines 18-20**: If no queen is found, move to the next position in the current direction by adding the offsets `i` and `j` to `x` and `y`, respectively. This continues until a queen is found or the bounds are exceeded.

```cpp
        return res;
    }
};
```
- **Lines 21-22**: After all directions have been checked, return the list of positions of queens that can attack the king.

### Complexity
1. **Time Complexity**:
   - The time complexity of this algorithm is \(O(1)\) in terms of the chessboard size since the maximum number of queens can only be 8. The loops that check each direction are limited by the fixed board size, making this approach very efficient.

2. **Space Complexity**:
   - The space complexity is also \(O(1)\) since the auxiliary space used for the boolean grid and the result vector does not depend on the input size in a dynamic way. The boolean grid is always fixed at 8x8.

### Conclusion
The `queensAttacktheKing` function efficiently determines which queens can attack the king by leveraging the fixed size of the chessboard and the properties of queen movements in chess. By marking queen positions in a boolean array and checking attack paths in eight possible directions, the function quickly identifies the attacking queens. This solution demonstrates a clear and effective use of algorithms and data structures to solve a combinatorial problem within the constraints of chess. The time and space complexity analysis further confirms the efficiency of the approach, making it suitable for real-time applications in chess engines and similar scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/queens-that-can-attack-the-king/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
