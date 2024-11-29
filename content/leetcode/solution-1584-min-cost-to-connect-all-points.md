
+++
authors = ["grid47"]
title = "Leetcode 1584: Min Cost to Connect All Points"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1584: Min Cost to Connect All Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Union Find","Graph","Minimum Spanning Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8VPIrqwQ8sQ"
youtube_upload_date="2024-05-22"
youtube_thumbnail="https://i.ytimg.com/vi/8VPIrqwQ8sQ/maxresdefault.jpg"
comments = true
+++



---
You are given a list of points on a 2D plane, represented as coordinates [x, y]. The cost of connecting two points is defined by the Manhattan distance, which is calculated as |xi - xj| + |yi - yj|. Your task is to return the minimum total cost required to connect all the points. A valid connection between points must form a connected graph, where there is exactly one simple path between any two points.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of points, where each point is represented by a pair of integers: [xi, yi]. The length of the array is at least 1 and at most 1000.
- **Example:** `Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]`
- **Constraints:**
	- 1 <= points.length <= 1000
	- -10^6 <= xi, yi <= 10^6
	- All pairs (xi, yi) are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum cost to connect all the points such that the graph formed by the connections is a connected graph with one simple path between any two points.
- **Example:** `Output: 20`
- **Constraints:**
	- The output should be an integer value representing the minimum connection cost.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum cost of connecting all the points using a Minimum Spanning Tree (MST) approach.

- 1. Create a list of all possible point connections, each with its corresponding Manhattan distance.
- 2. Sort the connections in increasing order of distance.
- 3. Use a union-find data structure to efficiently group connected points.
- 4. Add connections to the MST, ensuring no cycles are formed, until all points are connected.
{{< dots >}}
### Problem Assumptions ✅
- The points are given in integer coordinates.
- Manhattan distance is used to calculate the cost between two points.
- All points are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: points = [[3,12],[-2,5],[-4,1]]`  \
  **Explanation:** In this case, we need to connect three points on a 2D plane. The cost of connecting them is minimized by choosing the optimal connections, leading to a total cost of 18.

{{< dots >}}
## Approach 🚀
This problem can be approached using Kruskal's algorithm for Minimum Spanning Tree (MST), where we calculate the distances between all pairs of points, sort them, and progressively build the MST while ensuring no cycles are formed.

### Initial Thoughts 💭
- We need to efficiently calculate and store the Manhattan distances between all pairs of points.
- To avoid cycles, we can use a union-find or disjoint-set data structure.
- The solution involves sorting the pairwise distances and using the union-find data structure to add edges progressively.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the algorithm handles the case when there's only one point (the cost should be 0).
- The algorithm should handle large numbers of points efficiently, particularly when points are spread across a large area.
- Handle edge cases where all points are collinear, or form an easily calculable minimal spanning tree.
- Ensure the solution works within the provided time and space constraints.
{{< dots >}}
## Code 💻
```cpp
static bool cmp(array<int, 3> &a, array<int, 3> &b) {
    return a[0] < b[0];
}
int minCostConnectPoints(vector<vector<int>>& pts) {
    vector<array<int, 3>> q;
    // priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for(int i = 0; i < pts.size(); i++) {
        for(int j = i + 1; j < pts.size(); j++)
            q.push_back({ abs(pts[i][0]-pts[j][0]) + abs(pts[i][1]-pts[j][1]), i, j});
    }
    sort(q.begin(), q.end(), cmp);
    UF* uf = new UF(pts.size());

    int cost = 0, n = pts.size();
    for(int i = 0; i < q.size(); i++) {
        // cout << uf->cnt << " " << q[0] << " " << q[1] << " " << q[2] << "\n";
        if(uf->uni(q[i][1], q[i][2])) {
// cout << n << " "<< cost << " " << q[i][0] << " " << q[i][1] << " " << q[i][2] << "\n";
            cost += q[i][0];
            n--;
            if(n == 1) return cost;
        }

    }
    
    return 0;
}
```

This function calculates the minimum cost to connect all points using a minimum spanning tree (MST) approach. It uses a priority queue to sort distances and a union-find structure to detect and manage connected components.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Function**
	```cpp
	static bool cmp(array<int, 3> &a, array<int, 3> &b) {
	```
	This function is a comparison function for sorting. It compares two arrays based on the first element, which represents the distance between two points.

2. **Comparison Logic**
	```cpp
	    return a[0] < b[0];
	```
	This line returns true if the first element of array `a` (the distance) is less than that of array `b`, which allows sorting of pairs based on distance.

3. **Function Declaration**
	```cpp
	int minCostConnectPoints(vector<vector<int>>& pts) {
	```
	The main function `minCostConnectPoints` takes a 2D vector `pts` representing the points' coordinates and returns the minimum cost to connect all points.

4. **Variable Initialization**
	```cpp
	    vector<array<int, 3>> q;
	```
	We initialize a vector `q` of arrays, where each array contains the cost (distance between two points) and the indices of the two points.

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < pts.size(); i++) {
	```
	We start a loop to iterate through all the points in the `pts` vector.

6. **Inner Loop**
	```cpp
	        for(int j = i + 1; j < pts.size(); j++)
	```
	This inner loop iterates through all points after the current point `i` to calculate distances between pairs of points.

7. **Push Distance to Vector**
	```cpp
	            q.push_back({ abs(pts[i][0]-pts[j][0]) + abs(pts[i][1]-pts[j][1]), i, j});
	```
	For each pair of points, we calculate the Manhattan distance and store it along with the indices of the points in the vector `q`.

8. **Sort Distances**
	```cpp
	    sort(q.begin(), q.end(), cmp);
	```
	Sort the vector `q` based on the distances between points using the `cmp` function defined earlier.

9. **Union-Find Initialization**
	```cpp
	    UF* uf = new UF(pts.size());
	```
	Initialize a union-find (disjoint-set) structure to manage the connected components of points.

10. **Cost and Points Count Initialization**
	```cpp
	    int cost = 0, n = pts.size();
	```
	Initialize `cost` to 0 and `n` to the number of points. `cost` will accumulate the minimum cost, and `n` tracks the number of disconnected components.

11. **Loop Over Sorted Distances**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	We loop over the sorted distances in `q` to process the smallest distances first.

12. **Union Operation**
	```cpp
	        if(uf->uni(q[i][1], q[i][2])) {
	```
	If the two points represented by `q[i][1]` and `q[i][2]` are in different components, we unite them.

13. **Update Cost**
	```cpp
	            cost += q[i][0];
	```
	Add the cost (distance) of the current edge (pair of points) to the total `cost`.

14. **Decrement Components Count**
	```cpp
	            n--;
	```
	Decrement the number of disconnected components. As two points are connected, the number of components reduces.

15. **Terminate Early**
	```cpp
	            if(n == 1) return cost;
	```
	If only one component remains, all points are connected, and we return the total `cost`.

16. **Return Result**
	```cpp
	    return 0;
	```
	Return 0 if the function did not find a valid minimum spanning tree (though this should not happen in typical use).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2 log n) - The time complexity depends on the number of points and sorting the pairwise distances.
- **Average Case:** O(n^2 log n)
- **Worst Case:** O(n^2 log n)

The dominant factor is the sorting of pairwise distances, which is O(n^2 log n).

### Space Complexity 💾
- **Best Case:** O(n) - In the case where no distances need to be stored, the space complexity can be O(n).
- **Worst Case:** O(n^2) - Storing all pairwise distances requires O(n^2) space.

The space complexity is driven by the storage of pairwise distances.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/min-cost-to-connect-all-points/description/)

---
{{< youtube 8VPIrqwQ8sQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
