
+++
authors = ["grid47"]
title = "Leetcode 787: Cheapest Flights Within K Stops"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 787: Cheapest Flights Within K Stops in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Depth-First Search","Breadth-First Search","Graph","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/787.webp"
youtube = "WDxnQSAvNbI"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/WDxnQSAvNbI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/787.webp" 
    alt="A map where the cheapest flight path is calculated, glowing softly as the optimal path is found."
    caption="Solution to LeetCode 787: Cheapest Flights Within K Stops Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a number of cities and a list of flights between them. Each flight has a price and connects two cities. You need to find the cheapest route from a given source city to a destination city with at most a certain number of stops. If no such route exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the number of cities, the list of flights, the source city, the destination city, and the maximum number of stops allowed.
- **Example:** `n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1`
- **Constraints:**
	- 1 <= n <= 100
	- 0 <= flights.length <= (n * (n - 1) / 2)
	- flights[i].length == 3
	- 0 <= fromi, toi < n
	- fromi != toi
	- 1 <= pricei <= 104
	- There will not be any multiple flights between two cities.
	- 0 <= src, dst, k < n
	- src != dst

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the cheapest price to travel from the source city to the destination city with at most k stops. If no such route exists, return -1.
- **Example:** `Output: 700`
- **Constraints:**
	- The output will be an integer representing the cheapest price.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the cheapest price between the source and destination cities with at most k stops.

- Use the Bellman-Ford algorithm to find the shortest path.
- Run the algorithm k+1 times to account for at most k stops.
- Track the minimum price for each flight path.
{{< dots >}}
### Problem Assumptions ✅
- You can assume there are no direct flights from the source to destination if the source is not equal to the destination.
- Flights may have different costs and may be one-way only.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1`  \
  **Explanation:** In this example, we need to find the cheapest route from city 0 to city 3 with at most one stop. The cheapest route is through city 1 with a total cost of 700.

- **Input:** `Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1`  \
  **Explanation:** The cheapest route from city 0 to city 2 with one stop is through city 1, costing a total of 200.

{{< dots >}}
## Approach 🚀
We will use a modified version of the Bellman-Ford algorithm to find the minimum cost with at most k stops. This involves iterating over the flights k+1 times and updating the minimum cost for each destination city.

### Initial Thoughts 💭
- The Bellman-Ford algorithm is well-suited to this problem because it efficiently handles finding the shortest path with constraints on the number of stops.
- We will track the minimum cost for each city and update it over k+1 iterations, ensuring that we consider all possible flight paths within the stop limit.
{{< dots >}}
### Edge Cases 🌐
- If the flights array is empty, return -1.
- If the number of cities or flights is large, ensure the algorithm runs within time limits.
- If k is 0, only direct flights should be considered.
- Ensure that the solution handles cases with no valid path correctly.
{{< dots >}}
## Code 💻
```cpp
//bellman ford.
//just run it k+1 iterations.
int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
    
    vector<int> c(n, 1e8);
    c[src] = 0;
    
    for(int z=0; z<=k; z++){
        vector<int> C(c);
        for(auto e: a)
            C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
        c = C;
    }
    return c[sink] == 1e8 ? -1 : c[sink];
}
```

This function implements the Bellman-Ford algorithm to find the cheapest price to travel from a source node to a destination node within 'k' stops. It runs for k+1 iterations to relax all edges and compute the shortest path.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
	```
	This is the function definition where 'n' is the number of nodes, 'a' is the adjacency list of the graph, 'src' is the source node, 'sink' is the destination node, and 'k' is the maximum number of stops allowed.

2. **Initialization**
	```cpp
	    
	```
	This line is an empty placeholder for any future code or logic.

3. **Variable Initialization**
	```cpp
	    vector<int> c(n, 1e8);
	```
	This initializes a vector 'c' to store the cost of reaching each node, initially set to a high value (1e8).

4. **Assignment**
	```cpp
	    c[src] = 0;
	```
	The source node's cost is set to 0, as there is no cost to reach the source itself.

5. **Empty**
	```cpp
	    
	```
	This line is an empty placeholder for any future code or logic.

6. **Loop**
	```cpp
	    for(int z=0; z<=k; z++){
	```
	This for loop runs for 'k+1' iterations, where each iteration corresponds to relaxing the edges to find the shortest path.

7. **Variable Copy**
	```cpp
	        vector<int> C(c);
	```
	This creates a copy of the current cost vector 'c' into 'C' to update the costs for the current iteration.

8. **Edge Relaxation**
	```cpp
	        for(auto e: a)
	```
	This loop iterates over each edge in the adjacency list 'a' to relax the edges and update the cost vector.

9. **Edge Update**
	```cpp
	            C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
	```
	This line updates the cost to reach node 'e[1]' as the minimum of the current cost and the cost to reach 'e[0]' plus the weight of the edge 'e[2]'.

10. **Assignment**
	```cpp
	        c = C;
	```
	After the inner loop completes, the updated costs in vector 'C' are assigned back to 'c'.

11. **Return Statement**
	```cpp
	    return c[sink] == 1e8 ? -1 : c[sink];
	```
	The function returns the cost to reach the sink node. If the cost is still set to a high value (1e8), it means no valid path exists, so it returns -1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k * E), where E is the number of flights.
- **Average Case:** O(k * E), where E is the number of flights.
- **Worst Case:** O(k * E), where E is the number of flights.

The time complexity is linear with respect to the number of flights and the number of stops, with k being the maximum number of stops allowed.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of cities.
- **Worst Case:** O(n), where n is the number of cities.

The space complexity is O(n) because we need to maintain an array of size n to track the minimum cost to each city.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

---
{{< youtube WDxnQSAvNbI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
