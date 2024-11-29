
+++
authors = ["grid47"]
title = "Leetcode 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Graph","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "--wKPR3ByJc"
youtube_upload_date="2024-07-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/--wKPR3ByJc/maxresdefault.webp"
comments = true
+++



---
Given a set of cities connected by weighted edges, find the city with the least number of reachable cities under a distance threshold. If multiple cities have the same number of reachable cities, return the one with the greatest index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer `n`, representing the number of cities. You are also given a list of edges where each edge is an array `[fromi, toi, weighti]`, representing a bidirectional edge between cities `fromi` and `toi` with weight `weighti`. Additionally, you are given an integer `distanceThreshold` that limits the maximum distance for considering a reachable city.
- **Example:** `n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4`
- **Constraints:**
	- 2 <= n <= 100
	- 1 <= edges.length <= n * (n - 1) / 2
	- edges[i].length == 3
	- 0 <= fromi < toi < n
	- 1 <= weighti, distanceThreshold <= 10^4
	- All pairs (fromi, toi) are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the city with the smallest number of cities reachable within the `distanceThreshold`. If there are multiple such cities, return the city with the highest index.
- **Example:** `For `n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4`, the output will be `City 3`.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the city with the least number of reachable cities within the distance threshold and return the one with the greatest index in case of ties.

- 1. Represent the cities and edges using an adjacency matrix or a graph.
- 2. Implement a shortest path algorithm (like Floyd-Warshall) to compute the minimum distances between all pairs of cities.
- 3. For each city, count the number of cities that are reachable within the distance threshold.
- 4. Keep track of the city with the fewest reachable cities, and in case of a tie, return the city with the largest index.
{{< dots >}}
### Problem Assumptions ✅
- The graph is undirected.
- The weights on edges are positive integers.
- The graph is connected enough for a reasonable number of cities to be reachable from any city.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4`  \
  **Explanation:** City 3 has the least number of reachable cities (2 cities), and has the highest index, so the answer is City 3.

- **Input:** `Example 2: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2`  \
  **Explanation:** City 0 has the fewest reachable cities (only 1), so it is the answer.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to calculate the shortest paths between all cities and determine how many cities each city can reach under the distance threshold.

### Initial Thoughts 💭
- We need a method to efficiently compute the shortest paths between all pairs of cities.
- The Floyd-Warshall algorithm is ideal for this problem since it computes all pairs shortest paths and handles the graph size well given the constraints.
- This problem requires a graph traversal technique and careful consideration of tie-breaking when cities have the same number of reachable cities.
{{< dots >}}
### Edge Cases 🌐
- This problem does not involve empty inputs.
- Handle large inputs up to 100 cities efficiently using algorithms that scale well, like Floyd-Warshall.
- Distance threshold equals the maximum edge weight, ensuring that we consider paths within the threshold.
- Ensure the adjacency matrix correctly reflects the distances for each pair of cities.
{{< dots >}}
## Code 💻
```cpp
int findTheCity(int n, vector<vector<int>>& eds, int thd) {
    vector<vector<int>> d(n, vector (n, 10001));
    for(vector<int> &e: eds) {
d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
}
    for(int i = 0; i < n; i++)
{ d[i][i] = 0; }
    
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    
    int sm = n +1, res = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0 ; j < n; j++) {
            if(d[i][j] <= thd) {
                cnt++;
                }
        }
        
        if (cnt <= sm) {
            res = i;
            sm = cnt;
        }
        
    }
    
    return res;
    
}
```

This function implements the Floyd-Warshall algorithm to find the shortest paths between all pairs of cities. It then identifies the city with the smallest number of cities within a given threshold distance and returns its index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findTheCity(int n, vector<vector<int>>& eds, int thd) {
	```
	This is the function definition where we declare the function that will find the city with the least number of reachable cities within a distance threshold.

2. **Matrix Initialization**
	```cpp
	    vector<vector<int>> d(n, vector (n, 10001));
	```
	We initialize a distance matrix 'd' of size 'n x n' with large values (10001) to represent the initial distances between cities.

3. **Edge Initialization**
	```cpp
	    for(vector<int> &e: eds) {
	```
	We loop through the edges of the graph to populate the distance matrix with the provided distances.

4. **Matrix Update**
	```cpp
	d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
	```
	For each edge, we set the distance between the cities 'e[0]' and 'e[1]' as the given distance 'e[2]' in both directions.

5. **Self-Distance Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	We set the distance from a city to itself to 0, as it will always be 0.

6. **Diagonal Initialization**
	```cpp
	{ d[i][i] = 0; }
	```
	Here, we assign 0 to the diagonal elements of the matrix, representing that the distance from each city to itself is zero.

7. **Floyd-Warshall Loop**
	```cpp
	    for(int k = 0; k < n; k++)
	```
	We begin the main loop of the Floyd-Warshall algorithm, iterating over each city 'k' as an intermediate point.

8. **Outer Loop**
	```cpp
	        for(int i = 0; i < n; i++)
	```
	We iterate through each city 'i' that may have a shorter path through 'k'.

9. **Inner Loop**
	```cpp
	            for(int j = 0; j < n; j++)
	```
	We iterate through each city 'j' that may be reached by 'i' via the intermediate city 'k'.

10. **Distance Update**
	```cpp
	                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
	```
	We update the distance from city 'i' to city 'j' to the shorter of the current distance or the distance via 'k'.

11. **City with Fewest Reachable Cities**
	```cpp
	    int sm = n +1, res = 0;
	```
	We initialize variables 'sm' to track the smallest number of reachable cities and 'res' to store the city with the fewest reachable cities.

12. **City Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	We iterate through each city 'i' to count how many cities are within the distance threshold.

13. **Counter Initialization**
	```cpp
	        int cnt = 0;
	```
	We initialize a counter 'cnt' to count the number of cities that are reachable from city 'i' within the threshold distance.

14. **Inner City Loop**
	```cpp
	        for(int j = 0 ; j < n; j++) {
	```
	We loop through all cities 'j' to check if they are reachable from city 'i' within the given distance threshold.

15. **Reachability Check**
	```cpp
	            if(d[i][j] <= thd) {
	```
	We check if the distance from city 'i' to city 'j' is within the threshold 'thd'.

16. **Counter Increment**
	```cpp
	                cnt++;
	```
	If city 'j' is reachable from city 'i', we increment the counter.

17. **City with Fewest Reachable Cities Check**
	```cpp
	        if (cnt <= sm) {
	```
	We check if the current city has fewer or equal reachable cities than the previous city with the least number of reachable cities.

18. **Update City Result**
	```cpp
	            res = i;
	```
	If city 'i' has fewer reachable cities, we update the result to this city.

19. **Update Smallest Counter**
	```cpp
	            sm = cnt;
	```
	We update the smallest counter 'sm' to the current count of reachable cities.

20. **Return Result**
	```cpp
	    return res;
	```
	Finally, we return the city with the fewest reachable cities.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^3) for the Floyd-Warshall algorithm.
- **Average Case:** O(n^3) due to the all-pairs shortest path algorithm.
- **Worst Case:** O(n^3)

The time complexity is dominated by the Floyd-Warshall algorithm, which runs in O(n^3).

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2) for storing the adjacency matrix.

The space complexity is O(n^2) due to the storage of the distance matrix for all city pairs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/)

---
{{< youtube --wKPR3ByJc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
