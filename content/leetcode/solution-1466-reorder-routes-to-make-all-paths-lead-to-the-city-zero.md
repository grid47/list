
+++
authors = ["grid47"]
title = "Leetcode 1466: Reorder Routes to Make All Paths Lead to the City Zero"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1466: Reorder Routes to Make All Paths Lead to the City Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qL4UaMAdPts"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/qL4UaMAdPts/maxresdefault.jpg"
comments = true
+++



---
You are given n cities and n - 1 roads, forming a tree structure. The roads have been directed, and some roads may need to be reoriented to ensure all cities can reach the capital city (city 0). Your task is to determine the minimum number of road reorientations required to make it possible for each city to reach city 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parameters: the number of cities, n, and a list of connections, where each connection represents a directed road between two cities.
- **Example:** `Input: n = 6, connections = [[0, 1], [1, 3], [2, 3], [4, 0], [4, 5]]`
- **Constraints:**
	- 2 <= n <= 5 * 10^4
	- connections.length == n - 1
	- connections[i].length == 2
	- 0 <= ai, bi <= n - 1
	- ai != bi

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the minimum number of roads that need to be reoriented to ensure all cities can reach city 0.
- **Example:** `Output: 3`
- **Constraints:**
	- The minimum number of roads that need to be reoriented.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum number of road reorientations required for all cities to reach the capital city.

- Construct a graph representing the cities and roads.
- For each road, if it is directed away from the capital, count it as a reorientation.
- Perform a breadth-first search (BFS) starting from the capital city, visiting each city and checking if a road needs to be reoriented to allow travel to city 0.
- Return the total number of reorientations.
{{< dots >}}
### Problem Assumptions ✅
- The input guarantees that each city can eventually reach city 0 after reordering the roads.
- All roads are directed, and the tree structure is guaranteed.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 6, connections = [[0, 1], [1, 3], [2, 3], [4, 0], [4, 5]]`  \
  **Explanation:** Output: 3. To ensure that every city can reach city 0, we need to reorient three roads: from city 1 to city 0, from city 3 to city 1, and from city 4 to city 0.

- **Input:** `Input: n = 5, connections = [[1, 0], [1, 2], [3, 2], [3, 4]]`  \
  **Explanation:** Output: 2. We need to reorient the road from city 1 to city 0 and from city 2 to city 3.

{{< dots >}}
## Approach 🚀
The problem requires determining the minimum number of road reorientations by considering the graph structure of cities and roads. This can be efficiently solved by performing a BFS while counting roads that need to be reoriented.

### Initial Thoughts 💭
- Each road has a direction, and only roads directed away from the capital need to be reoriented.
- The graph is a tree, so there is exactly one path between any two cities.
- Using BFS ensures that we visit each city once and can track the number of reorientations needed as we traverse.
{{< dots >}}
### Edge Cases 🌐
- The input guarantees that there will be at least two cities, and n - 1 roads will be provided.
- For large inputs, we need to ensure that the BFS approach works efficiently within the given constraints of up to 5 * 10^4 cities.
- If the roads are already directed towards city 0, the result will be 0 (no reorientation needed).
- The solution must handle the upper limits of the input size efficiently.
{{< dots >}}
## Code 💻
```cpp
int minReorder(int n, vector<vector<int>>& conn) {
    vector<vector<int>> grid(n);
    
    map<int, map<int, bool>> mp;
    
    for(auto it: conn) {
        grid[it[0]].push_back(it[1]);
        grid[it[1]].push_back(it[0]);
        mp[it[0]][it[1]] = true;
    }
    int cnt = 0;
    queue<int> q;
    q.push(0);
    vector<int> vis(n, 0);
    vis[0] = true;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int tmp = q.front();
            q.pop();
            for(int it: grid[tmp]) {
                if(vis[it]) continue;
                vis[it] = true;
                if(mp.count(tmp) && mp[tmp].count(it)) cnt++;
                q.push(it);
            }
        }
    }
    return cnt;
}
```

This function determines the minimum number of reorders required to make all roads in a directed graph lead to city 0. It uses BFS to traverse the graph and counts the number of times we need to reverse the direction of roads.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minReorder(int n, vector<vector<int>>& conn) {
	```
	Defines the function `minReorder` that calculates the minimum reordering needed to make all roads lead to city 0 in a directed graph.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> grid(n);
	```
	Initializes a grid (adjacency list) to represent the cities and roads between them.

3. **Data Structure Initialization**
	```cpp
	    map<int, map<int, bool>> mp;
	```
	Initializes a map to track the direction of roads between cities.

4. **Loop (Connections)**
	```cpp
	    for(auto it: conn) {
	```
	Starts a loop to iterate through each connection in the `conn` vector.

5. **Update Grid**
	```cpp
	        grid[it[0]].push_back(it[1]);
	```
	Adds a road from city `it[0]` to city `it[1]` in the grid (adjacency list).

6. **Update Grid**
	```cpp
	        grid[it[1]].push_back(it[0]);
	```
	Adds a road from city `it[1]` to city `it[0]` in the grid (undirected road representation).

7. **Mark Direction**
	```cpp
	        mp[it[0]][it[1]] = true;
	```
	Marks that there is a directed road from city `it[0]` to city `it[1]` in the map.

8. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes a counter `cnt` to track the number of reorders needed.

9. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	Initializes a queue to perform BFS traversal starting from city 0.

10. **Enqueue Starting City**
	```cpp
	    q.push(0);
	```
	Pushes city 0 onto the queue to start the BFS traversal.

11. **Visited Cities Initialization**
	```cpp
	    vector<int> vis(n, 0);
	```
	Initializes a vector `vis` to keep track of visited cities.

12. **Mark Starting City as Visited**
	```cpp
	    vis[0] = true;
	```
	Marks city 0 as visited.

13. **BFS Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	Starts a while loop that runs as long as there are cities to process in the queue.

14. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Gets the size of the queue to process all cities at the current level of BFS.

15. **Inner Loop**
	```cpp
	        while(sz--) {
	```
	Starts an inner loop to process each city at the current level of BFS.

16. **Dequeue City**
	```cpp
	            int tmp = q.front();
	```
	Dequeues the front city from the queue for processing.

17. **Pop from Queue**
	```cpp
	            q.pop();
	```
	Pops the dequeued city from the queue.

18. **Loop Through Connected Cities**
	```cpp
	            for(int it: grid[tmp]) {
	```
	Loops through all cities connected to the current city `tmp`.

19. **Skip Visited Cities**
	```cpp
	                if(vis[it]) continue;
	```
	If a city has already been visited, it skips processing.

20. **Mark as Visited**
	```cpp
	                vis[it] = true;
	```
	Marks the current city `it` as visited.

21. **Count Road Reorders**
	```cpp
	                if(mp.count(tmp) && mp[tmp].count(it)) cnt++;
	```
	Increments the counter `cnt` if the road from `tmp` to `it` is directed and needs to be reordered.

22. **Enqueue City**
	```cpp
	                q.push(it);
	```
	Pushes the city `it` onto the queue for further processing.

23. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the count of reorders needed to make all roads lead to city 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the number of cities because we are performing a BFS traversal over the tree, which has n - 1 edges.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage needed for the adjacency list and visited nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/)

---
{{< youtube qL4UaMAdPts >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
