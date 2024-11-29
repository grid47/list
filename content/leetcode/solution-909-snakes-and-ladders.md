
+++
authors = ["grid47"]
title = "Leetcode 909: Snakes and Ladders"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 909: Snakes and Ladders in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6lH4nO3JfLk"
youtube_upload_date="2022-01-08"
youtube_thumbnail="https://i.ytimg.com/vi/6lH4nO3JfLk/maxresdefault.jpg"
comments = true
+++



---
You are given an n x n integer matrix `board` where the cells are numbered from 1 to n² in a zigzag pattern starting from the bottom-left corner. Each cell may contain either `-1` (indicating no special feature) or a number indicating a snake or ladder destination. You start at square 1 and can roll a 6-sided die to move between 1 and 6 steps. If you land on a square with a snake or ladder, you must move to its destination. Determine the minimum number of dice rolls needed to reach the final square `n²`. Return -1 if it is not possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An `n x n` matrix `board` where each cell represents a square in the game, containing either `-1` or a number indicating a snake or ladder destination.
- **Example:** `Input: board = [[-1,-1,-1],[-1,-1,-1],[-1,-1,2]]`
- **Constraints:**
	- n == board.length == board[i].length
	- 2 <= n <= 20
	- board[i][j] is either -1 or in the range [1, n²]
	- Squares 1 and n² are not the start of any snake or ladder.

{{< dots >}}
### Output Specifications 📤
- **Output:** The minimum number of dice rolls required to reach the final square `n²`. If unreachable, return -1.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Use Breadth-First Search (BFS) to calculate the minimum steps to reach square `n²`.

- Convert the 2D matrix to a 1D representation for easier traversal.
- Use BFS starting from square 1, keeping track of visited squares to avoid revisits.
- For each square, simulate a dice roll (1 to 6 steps) and determine the next position.
- If a square has a snake or ladder, move to its destination; otherwise, move normally.
- If the final square `n²` is reached, return the current roll count. If the queue is empty and `n²` is not reached, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The board dimensions are valid (n x n).
- Dice rolls always provide up to 6 possible moves unless constrained by board size.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: board = [[-1,-1,-1],[6,-1,-1],[-1,-1,2]]`  \
  **Explanation:** Start at square 1. Move to square 2 and follow the ladder to square 6. Then, roll to square 7 and follow the snake to square 2. Finally, roll to square 9 to win in 3 moves.

- **Input:** `Input: board = [[-1,-1],[-1,-1]]`  \
  **Explanation:** There are no snakes or ladders. The quickest path is to roll the dice 2 times to reach square 4.

{{< dots >}}
## Approach 🚀
Use BFS to explore the shortest path to square `n²` in terms of dice rolls, accounting for snakes and ladders.

### Initial Thoughts 💭
- This problem can be modeled as a shortest-path problem in an unweighted graph.
- Snakes and ladders alter the natural progression, requiring specific handling.
- Using BFS ensures we explore the shortest path first due to its level-order traversal.
{{< dots >}}
### Edge Cases 🌐
- The board has the smallest possible size (2x2).
- The board has the largest possible size (20x20) with complex snake and ladder placements.
- The board has no snakes or ladders.
- The board is entirely filled with snakes or ladders, forcing specific paths.
- The dice roll moves beyond the board's bounds.
{{< dots >}}
## Code 💻
```cpp
void getCoordinate(int n, int s, int &row, int &col) {
    row = n-1-(s-1)/n;
    col = (s-1)%n;
    if((n%2 ==1 && row%2==1) || (n%2==0 && row%2==0))
        col= n-1-col;
}
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<bool> seen(n*n+1, false);
    seen[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int row, col, s = p.first, dist = p.second;
        if(s == n*n) 
            return dist;
        for(int i = 1; s+i<= n *n && i<=6;i++) {
            getCoordinate(n, s+i, row, col);
            int sfinal = board[row][col] == -1? s+i:board[row][col];
            if(seen[sfinal] == false) {
                seen[sfinal] = true;
                q.push({sfinal, dist + 1});
            }
        }
    }
    return -1;
}
```

This code implements the solution to the Snakes and Ladders game problem using breadth-first search (BFS) to find the minimum number of moves required to reach the last cell from the first cell.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void getCoordinate(int n, int s, int &row, int &col) {
	```
	Define the function `getCoordinate` to compute the row and column based on the given board size and the cell number.

2. **Formula**
	```cpp
	    row = n-1-(s-1)/n;
	```
	Calculate the row of the cell based on the board size and the cell number.

3. **Formula**
	```cpp
	    col = (s-1)%n;
	```
	Calculate the column of the cell based on the board size and the cell number.

4. **Conditional**
	```cpp
	    if((n%2 ==1 && row%2==1) || (n%2==0 && row%2==0))
	```
	Check if the row needs to be reversed based on the board size and row parity.

5. **Action**
	```cpp
	        col= n-1-col;
	```
	Reverse the column if the row direction is reversed.

6. **Function Definition**
	```cpp
	int snakesAndLadders(vector<vector<int>>& board) {
	```
	Define the `snakesAndLadders` function to solve the problem using BFS.

7. **Variable Initialization**
	```cpp
	    int n = board.size();
	```
	Initialize `n` as the size of the board.

8. **Data Structure**
	```cpp
	    vector<bool> seen(n*n+1, false);
	```
	Create a vector `seen` to track visited cells.

9. **Action**
	```cpp
	    seen[1] = true;
	```
	Mark the first cell as visited.

10. **Queue**
	```cpp
	    queue<pair<int, int>> q;
	```
	Initialize a queue to store the current cell and the number of moves taken to reach it.

11. **Queue Operation**
	```cpp
	    q.push({1, 0});
	```
	Push the starting cell (1, 0 moves) into the queue.

12. **Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start a while loop to process cells in the queue.

13. **Queue Operation**
	```cpp
	        pair<int, int> p = q.front();
	```
	Retrieve the front element of the queue.

14. **Queue Operation**
	```cpp
	        q.pop();
	```
	Pop the front element from the queue.

15. **Variable Assignment**
	```cpp
	        int row, col, s = p.first, dist = p.second;
	```
	Extract the current cell and distance from the pair.

16. **Conditional**
	```cpp
	        if(s == n*n) 
	```
	Check if the current cell is the last cell.

17. **Return**
	```cpp
	            return dist;
	```
	Return the current distance if the last cell is reached.

18. **Loop**
	```cpp
	        for(int i = 1; s+i<= n *n && i<=6;i++) {
	```
	Loop through the next possible cells (dice rolls 1 to 6).

19. **Function Call**
	```cpp
	            getCoordinate(n, s+i, row, col);
	```
	Call `getCoordinate` to compute the row and column for the new cell.

20. **Action**
	```cpp
	            int sfinal = board[row][col] == -1? s+i:board[row][col];
	```
	Determine the final cell based on ladders or snakes.

21. **Conditional**
	```cpp
	            if(seen[sfinal] == false) {
	```
	Check if the final cell has already been visited.

22. **Action**
	```cpp
	                seen[sfinal] = true;
	```
	Mark the final cell as visited.

23. **Queue Operation**
	```cpp
	                q.push({sfinal, dist + 1});
	```
	Push the final cell into the queue with the updated distance.

24. **Return**
	```cpp
	    return -1;
	```
	Return -1 if no solution is found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n²)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)

Each square is visited once, and up to 6 moves are checked for each square.

### Space Complexity 💾
- **Best Case:** O(n²)
- **Worst Case:** O(n²)

The BFS queue and visited array each store up to n² elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/snakes-and-ladders/description/)

---
{{< youtube 6lH4nO3JfLk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
