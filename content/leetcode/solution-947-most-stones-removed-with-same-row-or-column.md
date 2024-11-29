
+++
authors = ["grid47"]
title = "Leetcode 947: Most Stones Removed with Same Row or Column"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 947: Most Stones Removed with Same Row or Column in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Depth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kLUgZzUKEK0"
youtube_upload_date="2020-10-30"
youtube_thumbnail="https://i.ytimg.com/vi/kLUgZzUKEK0/maxresdefault.jpg"
comments = true
+++



---
You are given a set of stones placed on a 2D plane at various integer coordinate points. A stone can be removed if it shares the same row or column as another stone that has not been removed yet. Your task is to determine the maximum number of stones that can be removed from the plane by performing valid operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of stones, where each stone is represented by a pair of integers [xi, yi] indicating its coordinates on the 2D plane.
- **Example:** `Input: stones = [[1, 2], [2, 3], [3, 4], [4, 5]]`
- **Constraints:**
	- 1 <= stones.length <= 1000
	- 0 <= xi, yi <= 10^4
	- No two stones have the same coordinates.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of stones that can be removed by performing the valid operations as described.
- **Example:** `Output: 3`
- **Constraints:**
	- The result will always be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the maximum number of stones that can be removed from the plane by simulating the process of removal based on the given constraints.

- 1. Use a union-find (disjoint-set) data structure to track connected stones in the same row or column.
- 2. For each stone, check if it shares a row or column with any other stone that is still present on the plane.
- 3. Union the stones that are in the same row or column, and count how many stones are connected.
- 4. The maximum number of removable stones is the total number of stones minus the number of connected components (isolated stones).
{{< dots >}}
### Problem Assumptions ✅
- All stones are placed at distinct positions.
- The stones can be removed in any valid sequence where a stone shares a row or column with another stone.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: stones = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]`  \
  **Explanation:** In this example, the maximum number of stones that can be removed is 5. The stones can be removed as follows: [2, 2] -> [2, 1] -> [1, 2] -> [1, 0] -> [0, 1]. The stone at [0, 0] cannot be removed because it does not share a row or column with any remaining stones.

- **Input:** `Input: stones = [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]`  \
  **Explanation:** In this case, the maximum number of stones that can be removed is 3. The stones can be removed as follows: [2, 2] -> [2, 0] -> [0, 2]. The stones at [0, 0] and [1, 1] cannot be removed because they do not share rows or columns with any other stones.

{{< dots >}}
## Approach 🚀
The approach involves using a union-find data structure to group stones that share a row or column. The number of connected components determines the maximum number of stones that can be removed.

### Initial Thoughts 💭
- The problem can be modeled as a graph where stones are nodes, and edges exist between stones in the same row or column.
- The union-find data structure can efficiently track the connected stones.
- The core idea is to group stones that can be removed together and count how many isolated stones are left.
{{< dots >}}
### Edge Cases 🌐
- If no stones are provided, the result is 0.
- For large inputs with up to 1000 stones, ensure the union-find data structure performs efficiently.
- If there is only one stone, no stones can be removed.
- Ensure the union-find operations handle the maximum constraints of 1000 stones efficiently.
{{< dots >}}
## Code 💻
```cpp
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    UF* uf = new UF(n);
    map<int, int> x, y;
    for(int i = 0; i < n; i++) {
        int p = stones[i][0];
        int q = stones[i][1];
        if(x.count(p)) {
            uf->uni(x[p], i);
        }
        if(y.count(q)) {
            uf->uni(y[q], i);
        }
        x[p] = i;
        y[q] = i;
    }
    return n - uf->cnt;
}
```

This function calculates the maximum number of stones that can be removed from the board, where each stone is represented by a pair of coordinates. It uses a union-find (disjoint-set) data structure to group stones that are connected either by the same x or y coordinates. The function returns the number of stones that can be removed, which is the total number of stones minus the number of distinct connected groups.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int removeStones(vector<vector<int>>& stones) {
	```
	The function `removeStones` takes a 2D vector `stones` containing the coordinates of stones and returns an integer value representing the maximum number of stones that can be removed.

2. **Size Calculation**
	```cpp
	    int n = stones.size();
	```
	Store the number of stones (the size of the `stones` vector) in the variable `n`.

3. **Union-Find Initialization**
	```cpp
	    UF* uf = new UF(n);
	```
	Initialize a new Union-Find (disjoint-set) data structure to keep track of the connected components. `uf` will help manage the union and find operations for the stones.

4. **Mapping Initialization**
	```cpp
	    map<int, int> x, y;
	```
	Create two maps `x` and `y` to store the indices of the last stone placed at each unique x and y coordinate.

5. **Main Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop that iterates through all the stones (each stone is represented by its coordinates).

6. **Extract Coordinates**
	```cpp
	        int p = stones[i][0];
	```
	Extract the x-coordinate `p` of the current stone.

7. **Extract Coordinates**
	```cpp
	        int q = stones[i][1];
	```
	Extract the y-coordinate `q` of the current stone.

8. **Union by X Coordinate**
	```cpp
	        if(x.count(p)) {
	```
	If a stone with the same x-coordinate `p` has been encountered before, union the current stone with the previous stone using their indices.

9. **Union Operation**
	```cpp
	            uf->uni(x[p], i);
	```
	Perform the union operation between the stone at index `x[p]` (the last stone at the same x-coordinate) and the current stone at index `i`.

10. **Union by Y Coordinate**
	```cpp
	        if(y.count(q)) {
	```
	If a stone with the same y-coordinate `q` has been encountered before, union the current stone with the previous stone using their indices.

11. **Union Operation**
	```cpp
	            uf->uni(y[q], i);
	```
	Perform the union operation between the stone at index `y[q]` (the last stone at the same y-coordinate) and the current stone at index `i`.

12. **Update Maps**
	```cpp
	        x[p] = i;
	```
	Update the map `x` to store the current stone's index for its x-coordinate `p`.

13. **Update Maps**
	```cpp
	        y[q] = i;
	```
	Update the map `y` to store the current stone's index for its y-coordinate `q`.

14. **Return Result**
	```cpp
	    return n - uf->cnt;
	```
	Return the number of stones that can be removed. This is calculated as the total number of stones minus the number of connected components (`uf->cnt`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n α(n))
- **Worst Case:** O(n α(n))

The time complexity is O(n α(n)) where α(n) is the inverse Ackermann function, which grows very slowly.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the union-find structure and tracking stone coordinates.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/)

---
{{< youtube kLUgZzUKEK0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
