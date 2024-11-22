
+++
authors = ["grid47"]
title = "Leetcode 1914: Cyclically Rotating a Grid"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1914: Cyclically Rotating a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3dCs1ZHDNjM"
youtube_upload_date="2021-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/3dCs1ZHDNjM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // cout << m << " " << n;
        // k = k % (m * n);
        for(int i = 0; i < min(m, n) / 2; i++) {            


            int l = i + 0, r = n - 1 - i;
            int t = i + 0, b = m - 1 - i;

            int total = 2 * (r - l) + 2 * (b - t);
            int rot = k % total;
            if(l < r && t < b) {

                for(int j = 0; j < rot; j++) {

                    int tmp = grid[t][l];
                    for(int p = l; p < r; p++)
                        grid[t][p] = grid[t][p + 1];

                    for(int p = t; p < b; p++)
                        grid[p][r] = grid[p + 1][r];

                    for(int p = r; p > l; p--)
                        grid[b][p] = grid[b][p-1];

                    for(int p = b; p > t; p--)
                        grid[p][l] = grid[p-1][l];

                    grid[t + 1][l] = tmp;
                }

            }
        }
        return grid;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to rotate a given 2D grid (matrix) by `k` positions in a circular manner. This rotation must be performed layer by layer, starting from the outermost layer of the grid and moving inward. Each layer of the grid can be thought of as a ring, and the goal is to shift the elements in these rings to the right by `k` positions.

### Approach

To achieve the desired rotation, the algorithm follows these steps:

1. **Layer Identification**: The grid is processed layer by layer, where each layer can be defined by its boundaries (left, right, top, and bottom). The number of layers is determined by the smaller dimension of the grid divided by two.

2. **Layer Length Calculation**: For each layer, calculate the number of elements in the layer (total perimeter length) using the formula:
   \[
   \text{total} = 2 \times (r - l) + 2 \times (b - t)
   \]
   where `l`, `r`, `t`, and `b` are the left, right, top, and bottom indices of the current layer.

3. **Effective Rotations**: The effective number of rotations needed is determined by taking `k` modulo the perimeter length (`total`). This accounts for cases where `k` is larger than the number of elements in the layer.

4. **Performing Rotations**: The elements of the layer are rotated in a circular manner. This involves:
   - Saving the top left element temporarily.
   - Shifting elements in a clockwise direction, i.e., moving elements from the top row to the right column, from the right column to the bottom row, from the bottom row to the left column, and from the left column back to the top row.

5. **Return the Rotated Grid**: After processing all layers, the modified grid is returned.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
```
This line defines the `rotateGrid` function, which takes a 2D vector `grid` and an integer `k`.

```cpp
        int m = grid.size(), n = grid[0].size();
```
Here, we retrieve the dimensions of the grid, with `m` representing the number of rows and `n` representing the number of columns.

```cpp
        for(int i = 0; i < min(m, n) / 2; i++) {
```
The loop iterates over each layer of the grid. The number of layers is determined by half the minimum dimension of the grid.

```cpp
            int l = i + 0, r = n - 1 - i;
            int t = i + 0, b = m - 1 - i;
```
We define the boundaries of the current layer:
- `l`: left boundary
- `r`: right boundary
- `t`: top boundary
- `b`: bottom boundary

```cpp
            int total = 2 * (r - l) + 2 * (b - t);
            int rot = k % total;
```
Calculate the total number of elements in the layer and determine the effective number of rotations needed.

```cpp
            if(l < r && t < b) {
```
Check if the current layer contains more than one element to ensure that we only rotate valid layers.

```cpp
                for(int j = 0; j < rot; j++) {
```
This loop performs the rotation `rot` times.

```cpp
                    int tmp = grid[t][l];
```
Store the top left element of the layer temporarily.

```cpp
                    for(int p = l; p < r; p++)
                        grid[t][p] = grid[t][p + 1];
```
Shift elements from the top row to the right by one position.

```cpp
                    for(int p = t; p < b; p++)
                        grid[p][r] = grid[p + 1][r];
```
Shift elements from the right column down by one position.

```cpp
                    for(int p = r; p > l; p--)
                        grid[b][p] = grid[b][p-1];
```
Shift elements from the bottom row to the left by one position.

```cpp
                    for(int p = b; p > t; p--)
                        grid[p][l] = grid[p-1][l];
```
Shift elements from the left column up by one position.

```cpp
                    grid[t + 1][l] = tmp;
```
Place the temporarily stored element back into the grid.

```cpp
            }
        }
        return grid;
    }
};
```
After all layers have been processed, the modified grid is returned.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is O(m * n), where m is the number of rows and n is the number of columns. Each element in the grid is processed once during the rotations.

- **Space Complexity**: The space complexity is O(1), as we are only using a fixed number of variables for computations without any additional data structures that grow with input size.

### Conclusion

The `rotateGrid` function efficiently rotates the layers of a grid based on the specified number of positions `k`. By treating each layer as a separate entity and performing rotations layer by layer, the solution is both straightforward and efficient. This method ensures that the algorithm runs in linear time relative to the number of elements in the grid, making it suitable for large matrices.

### Use Cases

1. **Image Processing**: This algorithm can be applied in image manipulation tasks, such as rotating borders of an image represented as a matrix of pixels.

2. **Game Development**: In grid-based games, layer rotations can be used to create interesting visual effects or transformations of the game board.

3. **Data Representation**: The concept of rotating layers can also be applied in scenarios where data needs to be rearranged in a structured format, such as matrices used in simulations.

4. **Competitive Programming**: The algorithm serves as an example of how to manipulate 2D arrays effectively, making it a great addition to competitive programming skills.

5. **Mathematical Puzzles**: Rotating grid layers can be part of larger mathematical puzzles or challenges that involve spatial reasoning and manipulation.

By following this structured approach, developers can efficiently handle tasks related to grid manipulation and optimize their algorithms for performance and clarity. The use of clear variable naming and logical structuring makes the code easy to read and maintain, ensuring long-term usability.

[`Link to LeetCode Lab`](https://leetcode.com/problems/cyclically-rotating-a-grid/description/)

---
{{< youtube 3dCs1ZHDNjM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
