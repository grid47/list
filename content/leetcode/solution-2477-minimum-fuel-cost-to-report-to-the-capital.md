
+++
authors = ["grid47"]
title = "Leetcode 2477: Minimum Fuel Cost to Report to the Capital"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2477: Minimum Fuel Cost to Report to the Capital in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I3lnDUIzIG4"
youtube_upload_date="2023-02-12"
youtube_thumbnail="https://i.ytimg.com/vi/I3lnDUIzIG4/maxresdefault.jpg"
comments = true
+++



---
A country network consists of n cities connected by n-1 bidirectional roads. The capital city is city 0, and each city has one representative with a car having a fixed number of seats. Calculate the minimum amount of fuel required for all representatives to reach the capital city.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of roads representing the connections between cities, and an integer seats indicating the number of seats in each car.
- **Example:** `roads = [[3, 1], [3, 2], [1, 0], [0, 4], [0, 5], [4, 6]], seats = 2`
- **Constraints:**
	- 1 <= n <= 10^5
	- roads.length == n - 1
	- 0 <= ai, bi < n
	- ai != bi
	- 1 <= seats <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of liters of fuel required for all representatives to reach the capital city.
- **Example:** `Output: 7`
- **Constraints:**
	- The output should be a single integer representing the minimum fuel cost.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum liters of fuel required by all representatives to reach city 0. Representatives can share rides to minimize the fuel cost.

- Construct the graph representing the road network.
- Perform a depth-first search (DFS) starting from city 0.
- For each city, calculate the number of representatives traveling to the capital.
- Optimize the fuel consumption by grouping representatives where possible.
{{< dots >}}
### Problem Assumptions ✅
- The country network is always a valid tree with no cycles.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 2: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2`  \
  **Explanation:** In this example, the representatives must share rides wherever possible to minimize the fuel consumption. The total fuel cost is 7 liters.

{{< dots >}}
## Approach 🚀
We aim to minimize the fuel usage by considering the number of representatives in each subtree. For each city, we calculate how many representatives need to travel and group them based on the seat capacity of each car.

### Initial Thoughts 💭
- Each representative can either travel alone or share a car with others.
- The number of liters required is minimized by efficiently grouping representatives to share cars.
- The solution involves a depth-first search (DFS) traversal to calculate the number of representatives traveling to the capital city from each subtree.
{{< dots >}}
### Edge Cases 🌐
- No roads exist, which means there is only one city (the capital). In this case, no travel is needed, so the fuel cost is 0.
- For large inputs (up to 10^5 cities), the algorithm should efficiently compute the minimum fuel cost using DFS traversal and seat grouping.
- If the number of seats is greater than or equal to the number of representatives in any city, no sharing is needed.
- The graph is a tree, meaning it has no cycles and a unique path between any two cities.
{{< dots >}}
## Code 💻
```cpp
long long ans;
int s;
long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    vector<vector<int>> graph(roads.size()+1);s = seats;
    for (vector<int> r: roads){
        graph[r[0]].push_back(r[1]);
                  graph[r[1]].push_back(r[0]);
    }
    dfs(0, 0, graph);
    return ans;
}
int dfs(int i, int prev, vector<vector<int>> &graph) {
    int people = 1;
    for(int &x: graph[i]) {
        if (x == prev) continue;
        people += dfs(x,i, graph);
    }
    if(i != 0) ans += (s + people - 1)/s;
    return people;
 }
```

This solution calculates the minimum fuel cost needed to transport people in a graph-like structure representing roads between cities. It uses depth-first search (DFS) to traverse the tree and calculates the fuel cost based on the number of people traveling and the number of seats available in the vehicle.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	long long ans;
	```
	This variable `ans` holds the total fuel cost for all the trips calculated during the DFS traversal.

2. **Variable Declaration**
	```cpp
	int s;
	```
	The variable `s` stores the number of seats available in each vehicle.

3. **Function Declaration**
	```cpp
	long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
	```
	The `minimumFuelCost` function calculates the total fuel cost for transporting people between cities based on the roads and the number of seats available.

4. **Graph Initialization**
	```cpp
	    vector<vector<int>> graph(roads.size()+1);s = seats;
	```
	A graph is created as an adjacency list to represent the roads between cities. Each city is a node, and the roads are the edges. The variable `s` is initialized with the number of seats.

5. **Graph Construction**
	```cpp
	    for (vector<int> r: roads){
	```
	Loops over each road, which is represented as a pair of cities, and adds edges between the two cities in the graph.

6. **Graph Edge Insertion**
	```cpp
	        graph[r[0]].push_back(r[1]);
	```
	Adds an edge from city `r[0]` to city `r[1]` in the graph.

7. **Graph Edge Insertion**
	```cpp
	                  graph[r[1]].push_back(r[0]);
	```
	Adds an edge from city `r[1]` to city `r[0]` in the graph (since the roads are bidirectional).

8. **DFS Function Call**
	```cpp
	    dfs(0, 0, graph);
	```
	Calls the DFS function starting from the root (city 0), with no previous city (0) and the graph as input.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the calculated total fuel cost `ans` after the DFS traversal.

10. **Helper Function Declaration**
	```cpp
	int dfs(int i, int prev, vector<vector<int>> &graph) {
	```
	The `dfs` function performs a depth-first search to calculate the number of people that need to be transported from each city to the root (city 0), and computes the fuel cost.

11. **People Count Initialization**
	```cpp
	    int people = 1;
	```
	Initializes the variable `people` to 1 to represent the current city (itself).

12. **DFS Loop**
	```cpp
	    for(int &x: graph[i]) {
	```
	Iterates over all neighboring cities of the current city `i` in the graph.

13. **Skip Previous City**
	```cpp
	        if (x == prev) continue;
	```
	Skips the previous city to avoid revisiting it during the DFS traversal.

14. **Recursive DFS Call**
	```cpp
	        people += dfs(x,i, graph);
	```
	Recursively calls the DFS function for the neighboring city `x` and adds the number of people from that subtree to the current city.

15. **Fuel Calculation**
	```cpp
	    if(i != 0) ans += (s + people - 1)/s;
	```
	If the current city is not the root (city 0), calculate the fuel cost for transporting `people` to the root. The formula `(s + people - 1)/s` computes the number of trips needed to transport all the people using vehicles with `s` seats.

16. **Return People Count**
	```cpp
	    return people;
	```
	Returns the total number of people (including the current city itself) for this subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because the algorithm performs a DFS traversal over all n cities.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the graph and recursive stack space used in DFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/)

---
{{< youtube I3lnDUIzIG4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
