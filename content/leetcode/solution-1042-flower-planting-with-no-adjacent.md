
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The problem involves a number of gardens arranged in a graph-like structure where each garden can be connected to others via paths. The objective is to assign one of four colors to each garden in such a way that no two adjacent gardens share the same color. This is a classic graph coloring problem that can be efficiently solved using greedy algorithms.

### Approach
To solve this problem, we can use the following approach:

1. **Graph Representation**: Represent the gardens and their connections as a graph using an adjacency list. Each garden corresponds to a node, and each path corresponds to an edge between two nodes.

2. **Color Assignment**: For each garden, determine which colors are already used by its adjacent gardens. Based on this information, assign the first available color that hasn't been used.

3. **Iterative Coloring**: Iterate through each garden, check the colors of its neighbors, and assign an appropriate color accordingly.

### Code Breakdown (Step by Step)

1. **Class Definition**: The solution is encapsulated within a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**: 
   - The `gardenNoAdj` function takes an integer `n` representing the number of gardens and a 2D vector `paths` representing the connections between the gardens. It returns a vector of integers representing the color assigned to each garden.

   ```cpp
   vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
   ```

3. **Initializing Results and Graph Structure**:
   - A result vector `res` is initialized with size `n`, where each element starts with 0 (indicating no color assigned).
   - An adjacency list `gph` is created to store the graph representation.

   ```cpp
   vector<int> res(n, 0);
   vector<vector<int>> gph(n);
   ```

4. **Building the Graph**:
   - The input `paths` is iterated over to populate the adjacency list. For each path, both gardens are updated to reflect their mutual connection.

   ```cpp
   for(vector<int> &p: paths) {
       gph[p[0]-1].push_back(p[1]-1);
       gph[p[1]-1].push_back(p[0]-1);
   }
   ```

5. **Coloring the Gardens**:
   - The outer loop iterates through each garden to assign colors.
   - An auxiliary array `colors` of size 5 is used to track which colors are already used by the adjacent gardens (index 0 is ignored).

   ```cpp
   for(int i = 0; i < n; i++) {
       int colors[5] = {};
       for(int j: gph[i]) {
           colors[res[j]] = 1;  // Mark the colors used by neighbors
       }
   ```

6. **Assigning Available Color**:
   - A nested loop iterates through potential colors from 4 to 1 (to prioritize higher colors) and checks if the color is available (not used by adjacent gardens). When an available color is found, it is assigned to the garden.

   ```cpp
   for(int c = 4; c > 0; c--)
       if(!colors[c])
           res[i] = c; // Assign the first available color
   ```

7. **Returning the Result**:
   - Finally, the function returns the result vector containing the assigned colors for each garden.

   ```cpp
   return res;
   }
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this solution is \(O(V + E)\), where \(V\) is the number of gardens (nodes) and \(E\) is the number of paths (edges). This is efficient because we are essentially visiting each node and its neighbors a limited number of times.

- **Space Complexity**: The space complexity is also \(O(V + E)\) due to the storage required for the adjacency list.

### Conclusion
The provided code effectively addresses the garden coloring problem by utilizing a greedy algorithm to ensure that no two adjacent gardens are assigned the same color. 

The implementation first constructs a graph using an adjacency list, allowing for efficient access to neighboring gardens during the coloring process. By iterating through each garden and checking the colors of adjacent gardens, the algorithm ensures that each garden receives a valid color assignment.

This solution is not only optimal but also straightforward, making it easy to understand and adapt for similar problems involving graph coloring. The approach illustrates the utility of greedy algorithms in solving real-world problems efficiently, providing a clear path from problem statement to solution.

In summary, the `gardenNoAdj` function demonstrates a robust method for assigning colors to gardens, ensuring proper differentiation between adjacent gardens while adhering to the constraints of the problem. This efficient algorithm can be applied to various scenarios within graph theory, highlighting its versatility and effectiveness.


[`Link to LeetCode Lab`](https://leetcode.com/problems/flower-planting-with-no-adjacent/description/)

---
{{< youtube 63xMlAAvEnA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
