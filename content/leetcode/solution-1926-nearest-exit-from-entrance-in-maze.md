
+++
authors = ["grid47"]
title = "Leetcode 1926: Nearest Exit from Entrance in Maze"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1926: Nearest Exit from Entrance in Maze in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KufrcPzbwko"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/KufrcPzbwko/maxresdefault.jpg"
comments = true
+++



---
You are given a maze and need to find the nearest exit from the entrance. An exit is defined as an empty cell on the border of the maze. Return the shortest path to the nearest exit, or -1 if no exit is reachable.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a maze represented as a 2D grid and the coordinates of the entrance.
- **Example:** `maze = [[".", ".", "+", "+"], [".", ".", ".", "+"], ["+", "+", ".", "."]], entrance = [1, 2]`
- **Constraints:**
	- 1 <= m, n <= 100
	- maze[i][j] is either '.' or '+'
	- entrance will always be an empty cell

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of steps to the nearest exit, or -1 if no exit is reachable.
- **Example:** `1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the shortest path from the entrance to any exit using breadth-first search (BFS).

- Initialize a queue with the entrance cell.
- Use BFS to explore all possible moves from the entrance.
- Track visited cells to avoid reprocessing.
- Stop when an exit is found, or return -1 if no exit is reachable.
{{< dots >}}
### Problem Assumptions ✅
- The entrance is always an empty cell.
- You can only move in four directions: up, down, left, and right.
{{< dots >}}
## Examples 🧩
- **Input:** `maze = [[".", ".", "+", "+"], [".", ".", ".", "+"], ["+", "+", ".", "."]], entrance = [1, 2]`  \
  **Explanation:** The nearest exit is at [0, 2], which is 1 step away from the entrance at [1, 2].

{{< dots >}}
## Approach 🚀
Use breadth-first search (BFS) to find the shortest path from the entrance to the nearest exit.

### Initial Thoughts 💭
- BFS is suitable here because it explores all possible paths in increasing order of distance.
- We should use BFS to traverse the maze and return the first exit we encounter.
{{< dots >}}
### Edge Cases 🌐
- There will always be an entrance cell, so empty inputs are not a concern.
- For large mazes, the BFS approach should be efficient enough to handle the maximum grid size of 100x100.
- Mazes where there are no exits should return -1.
- Ensure the BFS algorithm handles cases where no exits are reachable efficiently.
{{< dots >}}
## Code 💻
```cpp
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    
    queue<pair<int,int>> q;
    q.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';
    
    int ans = 1, m = maze.size(), n = maze[0].size();
    int dir[] = {0, 1, 0, -1, 0};
    // vector<vector<int>> vis(m, vector<int>(n, 0));
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto it = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int x = it.first + dir[i], y = it.second + dir[i + 1];
                if(x < 0 || y < 0 || x == m || y == n || maze[x][y] == '+') {
                    continue;
                }
                if(x == 0 || y == 0 || x == m - 1 || y == n - 1)
                    return ans;                    
                maze[x][y] = '+';                    
                q.push({x, y});
            }
        }
        ans++;
    }
    return -1;
}
```

This function implements a breadth-first search (BFS) to find the nearest exit from a maze, starting at the given entrance. It explores the maze, marking visited positions, and returns the number of steps to the nearest exit or -1 if no exit is found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Header**
	```cpp
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
	```
	Defines the function `nearestExit`, which takes a maze and the entrance coordinates as input, returning the distance to the nearest exit.

2. **Queue Initialization**
	```cpp
	    queue<pair<int,int>> q;
	```
	Initializes a queue to facilitate the BFS traversal, storing positions as pairs of coordinates.

3. **Queue Push**
	```cpp
	    q.push({entrance[0], entrance[1]});
	```
	Pushes the entrance coordinates onto the queue to begin the BFS search.

4. **Mark Entrance**
	```cpp
	    maze[entrance[0]][entrance[1]] = '+';
	```
	Marks the entrance as visited by setting it to '+' in the maze.

5. **Variable Initialization**
	```cpp
	    int ans = 1, m = maze.size(), n = maze[0].size();
	```
	Initializes the answer variable (`ans`) to 1, representing the first step from the entrance. Also initializes `m` and `n` to represent the maze's dimensions.

6. **Direction Array**
	```cpp
	    int dir[] = {0, 1, 0, -1, 0};
	```
	Defines an array of directions for BFS traversal: right, down, left, and up.

7. **Main BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Starts the BFS loop that runs as long as there are elements in the queue.

8. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Gets the current size of the queue to process each position at the current level of BFS.

9. **Inner Loop**
	```cpp
	        while(sz--) {
	```
	Processes all positions in the queue at the current BFS level.

10. **Queue Front**
	```cpp
	            auto it = q.front();
	```
	Retrieves the front element of the queue (the current position).

11. **Queue Pop**
	```cpp
	            q.pop();
	```
	Removes the front element of the queue after processing.

12. **Empty Line**
	```cpp
	            
	```
	Empty line for better code readability.

13. **Direction Loop**
	```cpp
	            for(int i = 0; i < 4; i++) {
	```
	Iterates over the four possible directions to explore neighboring cells.

14. **Position Calculation**
	```cpp
	                int x = it.first + dir[i], y = it.second + dir[i + 1];
	```
	Calculates the new position by adding the direction offset to the current coordinates.

15. **Bounds Check**
	```cpp
	                if(x < 0 || y < 0 || x == m || y == n || maze[x][y] == '+') {
	```
	Checks if the new position is out of bounds or already visited (marked with '+').

16. **Continue Statement**
	```cpp
	                    continue;
	```
	If the position is invalid, continue to the next direction.

17. **Bounds Check End**
	```cpp
	                }
	```
	End of the bounds check block.

18. **Exit Check**
	```cpp
	                if(x == 0 || y == 0 || x == m - 1 || y == n - 1)
	```
	Checks if the current position is at the maze's border, indicating an exit.

19. **Return Answer**
	```cpp
	                    return ans;                    
	```
	If an exit is found, return the current answer, which is the number of steps to reach the exit.

20. **Mark Position**
	```cpp
	                maze[x][y] = '+';                    
	```
	Marks the current position as visited.

21. **Queue Push**
	```cpp
	                q.push({x, y});
	```
	Pushes the new valid position onto the queue for further exploration.

22. **Increment Answer**
	```cpp
	        ans++;
	```
	Increments the answer variable after completing one BFS level.

23. **Return -1**
	```cpp
	    return -1;
	```
	If no exit is found after exploring the entire maze, return -1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The worst-case time complexity is O(m * n) because we might need to explore every cell in the maze.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the space required to store the queue and the visited cells.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/)

---
{{< youtube KufrcPzbwko >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
