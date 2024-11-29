
+++
authors = ["grid47"]
title = "Leetcode 1042: Flower Planting With No Adjacent"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1042: Flower Planting With No Adjacent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "63xMlAAvEnA"
youtube_upload_date="2022-08-19"
youtube_thumbnail="https://i.ytimg.com/vi/63xMlAAvEnA/maxresdefault.jpg"
comments = true
+++



---
You are given n gardens labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi and garden yi. Each garden needs to be assigned one of 4 types of flowers. You need to ensure that for any two gardens connected by a path, they have different types of flowers. Your task is to return any valid flower assignment for all gardens such that no two adjacent gardens share the same flower type.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n, the number of gardens, and a list of pairs paths, where each pair [xi, yi] represents a bidirectional path between garden xi and garden yi.
- **Example:** `Input: n = 5, paths = [[1,2], [2,3], [3,4], [4,5]]`
- **Constraints:**
	- 1 <= n <= 10^4
	- 0 <= paths.length <= 2 * 10^4
	- paths[i].length == 2
	- 1 <= xi, yi <= n
	- xi != yi
	- Each garden has at most 3 paths coming into or leaving it.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where the i-th element represents the type of flower planted in the i-th garden. The flower types are denoted by integers 1, 2, 3, or 4.
- **Example:** `Output: [1, 2, 3, 4, 1]`
- **Constraints:**
	- There is guaranteed to be at least one valid answer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to assign flower types to gardens such that no two connected gardens have the same flower type.

- 1. Represent the gardens and paths as a graph.
- 2. Use a greedy approach to assign flower types to gardens, making sure adjacent gardens get different flower types.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that there is always a valid solution.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5, paths = [[1,2], [2,3], [3,4], [4,5]]`  \
  **Explanation:** In this case, we can assign flowers such that adjacent gardens have different types. One valid solution is to assign flowers [1, 2, 1, 2, 1] to gardens [1, 2, 3, 4, 5].

- **Input:** `Input: n = 6, paths = [[1,2], [1,3], [2,4], [3,5], [4,6]]`  \
  **Explanation:** Here, we can assign flowers such that adjacent gardens do not share the same flower type. One valid solution is [1, 2, 3, 4, 3, 2].

{{< dots >}}
## Approach 🚀
The approach is based on graph coloring, where each garden is a node, and paths between gardens are edges. The goal is to color the nodes (gardens) with 4 colors (flower types) such that no two connected nodes share the same color.

### Initial Thoughts 💭
- The problem can be viewed as a graph coloring problem, where adjacent gardens must be assigned different flowers.
- Since each garden has at most 3 paths, we can use a greedy approach to assign flower types.
- A greedy algorithm should suffice for this problem, where we try to assign the lowest available flower type that hasn’t been used by adjacent gardens.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees at least one valid path, so no need to handle empty inputs.
- The algorithm must efficiently handle large inputs, with up to 10^4 gardens and 2 * 10^4 paths.
- The constraints ensure there is always a valid solution, so no need to handle cases with no solution.
- The number of paths per garden will not exceed 3, so the graph is sparse.
{{< dots >}}
## Code 💻
```cpp
vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<int> res(n, 0);
    vector<vector<int>> gph(n);
    for(vector<int> &p: paths) {
        gph[p[0]-1].push_back(p[1]-1);
        gph[p[1]-1].push_back(p[0]-1);
    }
    for(int i = 0; i < n; i++) {
        int colors[5] = {};
        for(int j: gph[i]) {
            colors[res[j]] = 1;
        }
        for(int c = 4; c > 0; c--)
            if(!colors[c])
                res[i] = c;
        
    }
    return res;
}
```

This function assigns a color to each garden such that no two adjacent gardens have the same color. The problem is solved by creating a graph of gardens connected by paths, and then applying a greedy algorithm to choose colors that don't conflict with adjacent gardens.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
	```
	Define the function 'gardenNoAdj' that solves the problem of coloring the gardens such that no two adjacent gardens share the same color.

2. **Variable Initialization**
	```cpp
	    vector<int> res(n, 0);
	```
	Initialize the result vector 'res' with size 'n' and set all garden colors to 0, indicating that no garden is colored yet.

3. **Graph Initialization**
	```cpp
	    vector<vector<int>> gph(n);
	```
	Create an adjacency list 'gph' to represent the graph of gardens, where each garden's neighbors (adjacent gardens) will be stored.

4. **Graph Construction**
	```cpp
	    for(vector<int> &p: paths) {
	```
	Iterate through the paths provided, where each path connects two gardens.

5. **Graph Construction**
	```cpp
	        gph[p[0]-1].push_back(p[1]-1);
	```
	For each path, add an edge between the two gardens in the adjacency list. Since gardens are 1-indexed, subtract 1 to match the 0-indexed array.

6. **Graph Construction**
	```cpp
	        gph[p[1]-1].push_back(p[0]-1);
	```
	Similarly, add the reverse edge to ensure the graph is undirected (both gardens are adjacent to each other).

7. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate through each garden and assign a color to it.

8. **Color Initialization**
	```cpp
	        int colors[5] = {};
	```
	Initialize an array 'colors' to keep track of which colors are already used by adjacent gardens. The array size is 5 because there are 4 colors (indexed 1 to 4) and a 0 to indicate unused colors.

9. **Adjacent Gardens Loop**
	```cpp
	        for(int j: gph[i]) {
	```
	For each garden 'i', loop through its adjacent gardens to find out which colors are already taken.

10. **Mark Colors Used**
	```cpp
	            colors[res[j]] = 1;
	```
	Mark the color of each adjacent garden as used in the 'colors' array.

11. **Color Assignment Loop**
	```cpp
	        for(int c = 4; c > 0; c--)
	```
	Loop through the available colors (from 4 down to 1) and assign the first available color to the current garden.

12. **Check Available Color**
	```cpp
	            if(!colors[c])
	```
	If the current color is not used by any adjacent garden (i.e., 'colors[c]' is 0), assign this color to the garden.

13. **Assign Color**
	```cpp
	                res[i] = c;
	```
	Assign the color 'c' to the garden 'i'.

14. **Return Statement**
	```cpp
	    return res;
	```
	Return the 'res' vector, which contains the colors assigned to each garden.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m), where n is the number of gardens and m is the number of paths.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is O(n + m), where n is the number of gardens and m is the number of paths, for storing the graph and flower assignments.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flower-planting-with-no-adjacent/description/)

---
{{< youtube 63xMlAAvEnA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
