
+++
authors = ["grid47"]
title = "Leetcode 733: Flood Fill"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 733: Flood Fill in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/733.webp"
youtube = "NomjaXe6kUE"
youtube_upload_date="2020-05-11"
youtube_thumbnail="https://i.ytimg.com/vi/NomjaXe6kUE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/733.webp" 
    alt="A grid where the flood fill algorithm is applied, with the flooded area glowing softly as it spreads."
    caption="Solution to LeetCode 733: Flood Fill Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an m x n grid representing an image, where each element in the grid corresponds to a pixel value. Additionally, you're provided with three integers: sr (starting row), sc (starting column), and color. Your task is to perform a flood fill operation on the image starting at the pixel located at (sr, sc).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D grid representing an image, three integers sr, sc, and color.
- **Example:** `image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]], sr = 1, sc = 1, color = 2`
- **Constraints:**
	- m == image.length
	- n == image[i].length
	- 1 <= m, n <= 50
	- 0 <= image[i][j], color < 216
	- 0 <= sr < m
	- 0 <= sc < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the modified image after performing the flood fill.
- **Example:** `After performing the flood fill on the input image, return the modified grid.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Change the color of the starting pixel and recursively change the color of adjacent pixels that share the original color.

- Check if the color to be applied is the same as the starting pixel's color.
- If different, perform a DFS (depth-first search) to apply the flood fill to all connected pixels that have the same original color.
{{< dots >}}
### Problem Assumptions ✅
- The grid will always contain at least one element.
- The target color will not be equal to the original color if the flood fill is to occur.
{{< dots >}}
## Examples 🧩
- **Input:** `Starting from (1, 1) and applying the color 2 results in a flood fill of the connected pixels.`  \
  **Explanation:** Starting from pixel (1, 1) with color 1, all connected pixels with color 1 will be changed to color 2. This process stops when there are no more pixels connected to the starting pixel with the same original color.

{{< dots >}}
## Approach 🚀
Use DFS to apply the flood fill on the grid recursively.

### Initial Thoughts 💭
- DFS can be applied to propagate the color change to adjacent pixels.
- Use a helper function to handle the recursive flood fill.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty, handle gracefully without performing any flood fill.
- Ensure the function handles larger grids efficiently within the given constraints.
- If the starting pixel already has the target color, no changes should be made to the grid.
- The maximum grid size is 50x50, which is small enough to handle with DFS efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(color == image[sr][sc]) return image;
    dfs(image, sr, sc, color, image[sr][sc]);
    return image;
}

void dfs(vector<vector<int>> & img, int r, int c, int color, int node) {
    int m = img.size(), n = img[0].size();
    if (r < 0 || c < 0 || r == m || c == n || img[r][c] != node)
        return;
    
    img[r][c] = color;
    dfs(img, r + 1, c, color, node);
    dfs(img, r, c + 1, color, node);
    dfs(img, r - 1, c, color, node);
    dfs(img, r, c - 1, color, node);
}

```

This code defines a flood fill algorithm using depth-first search (DFS). It updates an image matrix by filling a region connected to a starting point with a new color. The algorithm checks if the color at the starting point is the same as the target color to avoid redundant operations. The helper function `dfs` recursively visits connected pixels and updates their color.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	```
	This function initiates the flood fill process. It takes an image (a matrix), a starting row (`sr`), a starting column (`sc`), and a new color as inputs.

2. **Check Color**
	```cpp
	    if(color == image[sr][sc]) return image;
	```
	This step checks if the color at the starting point is already the target color. If so, it returns the image without making any changes.

3. **Call DFS**
	```cpp
	    dfs(image, sr, sc, color, image[sr][sc]);
	```
	If the color is different, the DFS function is called to start the flood fill operation, passing the image, the starting coordinates, the new color, and the current color at the starting point.

4. **Return Image**
	```cpp
	    return image;
	```
	After completing the flood fill operation, the updated image is returned.

5. **DFS Function Definition**
	```cpp
	void dfs(vector<vector<int>> & img, int r, int c, int color, int node) {
	```
	This function is a helper function that performs the depth-first search. It takes the image, the current row and column (`r`, `c`), the new color, and the original color (`node`) of the region to be filled.

6. **Matrix Dimensions**
	```cpp
	    int m = img.size(), n = img[0].size();
	```
	This line stores the number of rows (`m`) and columns (`n`) of the image matrix.

7. **Bounds Check**
	```cpp
	    if (r < 0 || c < 0 || r == m || c == n || img[r][c] != node)
	```
	This condition checks if the current pixel is out of bounds or does not match the original color. If so, the function returns without making any changes.

8. **Exit DFS**
	```cpp
	        return;
	```
	If the pixel is out of bounds or not part of the target region, the DFS recursion is terminated for this pixel.

9. **Color Update**
	```cpp
	    img[r][c] = color;
	```
	The current pixel is updated with the new color.

10. **DFS Recursion (Down)**
	```cpp
	    dfs(img, r + 1, c, color, node);
	```
	The DFS function is called recursively on the neighboring pixel below the current one.

11. **DFS Recursion (Right)**
	```cpp
	    dfs(img, r, c + 1, color, node);
	```
	The DFS function is called recursively on the neighboring pixel to the right of the current one.

12. **DFS Recursion (Up)**
	```cpp
	    dfs(img, r - 1, c, color, node);
	```
	The DFS function is called recursively on the neighboring pixel above the current one.

13. **DFS Recursion (Left)**
	```cpp
	    dfs(img, r, c - 1, color, node);
	```
	The DFS function is called recursively on the neighboring pixel to the left of the current one.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns.
- **Average Case:** O(m * n), as the flood fill may potentially visit every pixel in the worst case.
- **Worst Case:** O(m * n), where m and n are the dimensions of the grid.

The time complexity depends on the size of the grid and the number of pixels connected to the starting pixel.

### Space Complexity 💾
- **Best Case:** O(1), if no recursive calls are made (e.g., if no adjacent pixels share the same color).
- **Worst Case:** O(m * n), due to the recursive call stack in DFS.

The space complexity depends on the depth of the recursion tree, which can be proportional to the grid size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flood-fill/description/)

---
{{< youtube NomjaXe6kUE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
