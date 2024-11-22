
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the shortest distance from an entrance point to the nearest exit in a maze. The maze is represented as a 2D grid consisting of open paths (denoted by '.') and walls (denoted by '+'). An exit is defined as any open path located on the border of the maze (the first or last row, or the first or last column). The entrance is provided as a coordinate, and the objective is to return the number of steps to the nearest exit. If no exit is reachable, the function should return -1.

### Approach

To solve this problem, we can utilize the **Breadth-First Search (BFS)** algorithm, which is ideal for exploring the shortest path in unweighted grids such as this maze. The steps of our approach are as follows:

1. **Initialize a Queue**: We will use a queue to keep track of the cells to explore, starting with the entrance point.

2. **Mark the Entrance**: We mark the entrance as visited to prevent revisiting it.

3. **Define Directions**: We define the possible movements (up, down, left, right) within the maze.

4. **BFS Traversal**: We perform BFS until we either find an exit or exhaust all possible paths:
   - For each cell, check its neighbors in all four directions.
   - If a neighbor is valid (within bounds and not a wall), we check if it’s an exit.
   - If it is an exit, we return the distance.
   - If not, we mark it as visited and add it to the queue.

5. **Return -1**: If we finish BFS without finding an exit, we return -1.

### Code Breakdown (Step by Step)

Let's break down the code provided step by step to understand how it implements the approach described:

```cpp
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
```
Here, we define the `Solution` class and the `nearestExit` method, which takes a reference to a 2D character vector representing the maze and a vector representing the entrance's coordinates.

```cpp
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
```
We initialize a queue to facilitate the BFS and push the entrance coordinates onto the queue. We also mark the entrance cell as visited by changing its value to '+'.

```cpp
        int ans = 1, m = maze.size(), n = maze[0].size();
        int dir[] = {0, 1, 0, -1, 0};
```
We initialize the distance counter `ans` to 1 (to count the first move), determine the dimensions of the maze \(m\) (rows) and \(n\) (columns), and define an array `dir` to simplify movement in the four cardinal directions.

```cpp
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
```
We enter a loop that continues until the queue is empty. Inside, we store the current size of the queue, indicating how many cells we will explore at this level of BFS.

```cpp
                for(int i = 0; i < 4; i++) {
                    int x = it.first + dir[i], y = it.second + dir[i + 1];
```
We iterate through each direction to calculate the potential neighboring cell’s coordinates `x` and `y`.

```cpp
                    if(x < 0 || y < 0 || x == m || y == n || maze[x][y] == '+') {
                        continue;
                    }
```
We check if the neighbor is out of bounds or has already been visited (marked with '+'). If so, we skip it.

```cpp
                    if(x == 0 || y == 0 || x == m - 1 || y == n - 1)
                        return ans;                    
```
If the current neighbor is an exit (located on the boundary of the maze), we return the current distance `ans`.

```cpp
                    maze[x][y] = '+';                    
                    q.push({x, y});
```
If the neighbor is valid and not an exit, we mark it as visited and push its coordinates onto the queue for further exploration.

```cpp
            }
            ans++;
        }
        return -1;
    }
};
```
After exploring all neighbors at the current level, we increment the distance counter `ans` to reflect the next step, and the outer loop continues. If the queue is exhausted without finding an exit, we return -1.

### Complexity

- **Time Complexity**: The time complexity is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the maze. In the worst case, we might need to visit each cell once.

- **Space Complexity**: The space complexity is also \(O(m \times n)\) due to the queue used for BFS, which could store all cells in the maze in the worst case.

### Conclusion

The `nearestExit` function efficiently finds the shortest path from a given entrance in the maze to the nearest exit using the BFS algorithm. This approach ensures that we explore all possible paths while keeping track of visited cells to prevent cycles and redundant checks.

### Key Features

1. **Efficient Pathfinding**: The use of BFS allows for efficient exploration of the shortest path in a grid-like structure.

2. **Dynamic Distance Tracking**: The algorithm dynamically tracks the number of steps taken to reach the exit, ensuring accuracy in distance measurement.

3. **Robust Input Handling**: The function handles various maze configurations, including those with no exits or surrounded entrances.

### Use Cases

1. **Game Development**: This algorithm can be used in maze-solving games where players must find exits or complete levels.

2. **Robotics**: In robotic navigation, similar algorithms are utilized for pathfinding and obstacle avoidance.

3. **Route Planning**: The method can be adapted for routing applications, such as finding the quickest path in navigation systems.

4. **Educational Tools**: The BFS approach can serve as an educational example in algorithm courses, demonstrating practical applications of graph traversal.

5. **Simulation**: In simulations that model movement in environments, this logic helps evaluate pathways and optimize routes.

By understanding this implementation, developers can improve their skills in handling grid-based problems and explore more advanced algorithms for pathfinding and navigation tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/)

---
{{< youtube KufrcPzbwko >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
