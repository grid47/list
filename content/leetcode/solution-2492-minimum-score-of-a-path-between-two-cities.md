
+++
authors = ["grid47"]
title = "Leetcode 2492: Minimum Score of a Path Between Two Cities"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2492: Minimum Score of a Path Between Two Cities in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7epgOP3ezWM"
youtube_upload_date="2023-03-22"
youtube_thumbnail="https://i.ytimg.com/vi/7epgOP3ezWM/maxresdefault.jpg"
comments = true
+++



---
You are given a set of cities, each connected by bidirectional roads. Each road has a distance, and the score of a path between two cities is defined as the minimum distance of any road on that path. The task is to find the minimum score of a path between city 1 and city n. You are allowed to visit the cities multiple times, and the roads may be repeated.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n representing the number of cities, and a 2D array roads, where each road is represented as [ai, bi, distancei] meaning there is a bidirectional road between city ai and bi with distance distancei.
- **Example:** `n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]`
- **Constraints:**
	- 2 <= n <= 10^5
	- 1 <= roads.length <= 10^5
	- 1 <= ai, bi <= n
	- 1 <= distancei <= 10^4
	- There are no repeated edges.
	- There is at least one path between city 1 and city n.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible score of a path between city 1 and city n. If no path exists, return -1.
- **Example:** `Output: 5`
- **Constraints:**
	- The score is calculated by considering the minimum distance in the path between city 1 and city n.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum score of a path between cities 1 and n by traversing the graph of cities and roads.

- 1. Construct an adjacency list for the graph.
- 2. Use BFS or DFS starting from city 1 to visit all connected cities.
- 3. Track the minimum distance of any road encountered during traversal.
- 4. Return the minimum score of the path when city n is reached.
{{< dots >}}
### Problem Assumptions ✅
- The input graph is connected for cities 1 and n.
- The roads form a connected graph between cities, ensuring that there is at least one path between city 1 and city n.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]`  \
  **Explanation:** The cities can be connected through the path 1 -> 2 -> 4 with the minimum score being min(9,5), which is 5.

- **Input:** `Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]`  \
  **Explanation:** The minimum score of the path from city 1 to city 4 is 2, which is the minimum distance encountered in the path 1 -> 2 -> 1 -> 3 -> 4.

{{< dots >}}
## Approach 🚀
To solve this problem, the approach uses breadth-first search (BFS) or depth-first search (DFS) to explore all the possible paths between cities, ensuring that the minimum road distance along the path is tracked.

### Initial Thoughts 💭
- The problem involves a pathfinding task with the additional requirement to track the minimum score of the roads on the path.
- By using BFS or DFS, we can efficiently explore the graph while keeping track of the minimum distance encountered on the path.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain valid roads between cities and will not be empty.
- For large inputs, the algorithm should handle up to 100,000 cities and roads efficiently using BFS or DFS.
- The distances of the roads range between 1 and 10,000, ensuring no edge cases involving extreme values.
- Ensure BFS/DFS is implemented with efficient traversal to handle large inputs.
{{< dots >}}
## Code 💻
```cpp
int minScore(int n, vector<vector<int>>& roads) {
    
    vector<vector<vector<int>>> grid(n + 1);

    for(auto it: roads) {
        grid[it[0]].push_back({it[1], it[2]});
        grid[it[1]].push_back({it[0], it[2]});
    }
    
    vector<int> vis(n + 1, false); 
    queue<int> q;
    q.push(1);
    vis[1] = true;
    int mn = INT_MAX;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto it = q.front();
            q.pop();
            for(auto x: grid[it]) {
                    mn = min(mn, x[1]);                    
                if(!vis[x[0]]) {
                    q.push(x[0]);
                    vis[x[0]] = true;
                }
            }
        }
    }

    return mn;
}

```

This function calculates the minimum score in a graph where nodes are connected by roads, each with a score. It uses BFS to explore the graph and find the smallest score in the connected component starting from node 1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minScore(int n, vector<vector<int>>& roads) {
	```
	This line declares the function `minScore` which takes in two parameters: `n` (number of nodes) and `roads` (a 2D vector representing the roads between nodes). It returns an integer representing the minimum score.

2. **Grid Initialization**
	```cpp
	    vector<vector<vector<int>>> grid(n + 1);
	```
	A 3D vector `grid` is initialized to store the adjacency list representation of the graph. The `n + 1` ensures that node indexing starts from 1.

3. **Edge Addition**
	```cpp
	    for(auto it: roads) {
	```
	This loop iterates through each road in the `roads` vector and updates the adjacency list (`grid`) for both directions of the road.

4. **Adjacency List Update**
	```cpp
	        grid[it[0]].push_back({it[1], it[2]});
	```
	For each road, this line adds the edge from node `it[0]` to node `it[1]` with the corresponding score `it[2]`.

5. **Adjacency List Update**
	```cpp
	        grid[it[1]].push_back({it[0], it[2]});
	```
	This line ensures the adjacency list is updated in both directions, so the graph is undirected.

6. **Visited Nodes Initialization**
	```cpp
	    vector<int> vis(n + 1, false); 
	```
	A vector `vis` of size `n + 1` is initialized to keep track of visited nodes. Initially, all nodes are set to `false`.

7. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	A queue `q` is initialized to facilitate BFS traversal of the graph.

8. **Start BFS**
	```cpp
	    q.push(1);
	```
	Node 1 is pushed onto the queue to start the BFS traversal.

9. **Mark Start Node as Visited**
	```cpp
	    vis[1] = true;
	```
	Mark node 1 as visited.

10. **Minimum Score Initialization**
	```cpp
	    int mn = INT_MAX;
	```
	The variable `mn` is initialized to `INT_MAX` to track the minimum score during the BFS traversal.

11. **BFS Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	This while loop runs as long as the queue is not empty, processing each node in the BFS.

12. **Queue Size Calculation**
	```cpp
	        int sz = q.size();
	```
	The size of the queue is stored in `sz` to control the number of nodes to be processed in the current BFS level.

13. **Inner Loop**
	```cpp
	        while(sz--) {
	```
	This inner loop processes each node at the current level of the BFS.

14. **Queue Front**
	```cpp
	            auto it = q.front();
	```
	The front element of the queue is retrieved and stored in `it`, representing the current node to process.

15. **Queue Pop**
	```cpp
	            q.pop();
	```
	The front element is removed from the queue after processing.

16. **Adjacency List Traversal**
	```cpp
	            for(auto x: grid[it]) {
	```
	This loop iterates over all neighbors of the current node `it` by accessing the adjacency list `grid[it]`.

17. **Minimum Score Update**
	```cpp
	                    mn = min(mn, x[1]);                    
	```
	The minimum score is updated by comparing the current minimum with the score of the edge `x[1]`.

18. **Node Visit Check**
	```cpp
	                if(!vis[x[0]]) {
	```
	If the neighboring node `x[0]` has not been visited, it is added to the BFS queue.

19. **Queue Push**
	```cpp
	                    q.push(x[0]);
	```
	The neighboring node `x[0]` is pushed to the queue for future processing.

20. **Mark Node as Visited**
	```cpp
	                    vis[x[0]] = true;
	```
	Mark the neighboring node `x[0]` as visited.

21. **Return Minimum Score**
	```cpp
	    return mn;
	```
	The function returns the minimum score found during the BFS traversal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m) where n is the number of cities and m is the number of roads, as each city and road is visited at most once during traversal.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n + m)

The space complexity is O(n + m) due to the adjacency list and visited array. This accounts for the number of cities and roads.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/)

---
{{< youtube 7epgOP3ezWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
