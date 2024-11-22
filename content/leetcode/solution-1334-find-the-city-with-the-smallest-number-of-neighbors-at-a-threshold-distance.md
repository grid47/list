
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The goal is to find a city in a graph represented by `n` cities and `m` edges, where each edge has a weight (or distance). The task is to determine which city has the smallest number of cities that can be reached from it within a given distance threshold (`thd`). If multiple cities have the same count of reachable cities, the city with the highest index should be returned.

### Approach
To solve this problem, we utilize the Floyd-Warshall algorithm, which efficiently computes the shortest paths between all pairs of nodes in a weighted graph. Here are the main steps involved in the solution:

1. **Initialize the Distance Matrix**: Create a distance matrix to represent the direct distances between cities, initializing them to a large value (infinity) except for the distance from each city to itself, which is zero.

2. **Populate the Distance Matrix**: Fill in the distance matrix using the edges provided in the input.

3. **Compute All-Pairs Shortest Paths**: Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities.

4. **Count Reachable Cities**: For each city, count how many cities can be reached within the threshold distance.

5. **Determine the Result City**: Keep track of the city with the smallest count of reachable cities, returning the one with the highest index in case of a tie.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& eds, int thd) {
        vector<vector<int>> d(n, vector (n, 10001));
```
- The `Solution` class is defined with a public method `findTheCity`, which takes the number of cities `n`, a vector of edges `eds`, and a threshold distance `thd`.
- A 2D vector `d` is initialized to represent the distance between every pair of cities. It is filled with a large number (`10001`), which serves as a substitute for infinity.

```cpp
        for(vector<int> &e: eds) {
            d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
        }
```
- The distance matrix is populated using the edges in the input. For each edge `e`, the distance from city `e[0]` to city `e[1]` and vice versa is set to the weight `e[2]` of the edge.

```cpp
        for(int i = 0; i < n; i++) {
            d[i][i] = 0;
        }
```
- The diagonal of the distance matrix is set to zero, indicating that the distance from any city to itself is zero.

```cpp
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
```
- The core of the Floyd-Warshall algorithm is implemented here. It iteratively updates the distance matrix by considering each city `k` as an intermediate point, checking if the path from `i` to `j` through `k` is shorter than the current known distance.

```cpp
        int sm = n + 1, res = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(d[i][j] <= thd) {
                    cnt++;
                }
            }
```
- After calculating the shortest paths, we initialize `sm` (smallest count of reachable cities) and `res` (the result city index). We iterate over each city `i`, counting how many cities `j` are reachable within the threshold distance `thd`.

```cpp
            if (cnt <= sm) {
                res = i;
                sm = cnt;
            }
        }
        
        return res;
    }
};
```
- If the current city `i` has a count `cnt` of reachable cities that is less than or equal to the smallest count found (`sm`), we update `res` to `i` and `sm` to `cnt`. After evaluating all cities, the function returns the index of the city with the smallest count of reachable cities.

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm is \(O(n^3)\) due to the three nested loops in the Floyd-Warshall algorithm, which is typical for calculating shortest paths in dense graphs.

- **Space Complexity**: The space complexity is \(O(n^2)\) as we maintain a distance matrix that stores the shortest paths between all pairs of cities.

### Conclusion
The provided solution efficiently finds the city with the smallest number of reachable cities within a given distance threshold using the Floyd-Warshall algorithm. This approach is particularly useful for problems involving dense graphs where the relationships between all nodes are significant.

Understanding how to implement and optimize algorithms like Floyd-Warshall is essential for solving graph-related problems in various domains, including network routing, urban planning, and transportation systems. By mastering these concepts, developers can design systems that handle complex routing and distance-related queries effectively, enhancing both performance and usability in real-world applications. 

Overall, this solution exemplifies effective algorithm design in competitive programming and software development, ensuring accurate and efficient outcomes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/)

---
{{< youtube --wKPR3ByJc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
