
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
    
};
{{< /highlight >}}
---

### Problem Statement

The problem is based on the classic **Flood Fill** algorithm, commonly used in image processing and computer graphics. The task is to perform a flood fill starting from a given pixel in a 2D grid (image) and fill all connected pixels that have the same initial color with a new color. The flood fill should be performed in four directions: up, down, left, and right. The goal is to return the image after performing the flood fill operation.

### Approach

The flood fill operation can be achieved using either a **Breadth-First Search (BFS)** or a **Depth-First Search (DFS)** algorithm. In this case, the DFS approach is used to explore the connected components starting from the given pixel and recursively fill all connected pixels that share the same initial color.

#### Steps Involved:
1. **Check for the base condition:** 
   If the color to fill is the same as the color of the starting pixel, then there's no need to modify the image, and we can return the image as is.
   
2. **Depth-First Search (DFS):**
   Start from the given pixel and explore all its neighbors. If the neighboring pixel has the same initial color, change its color to the new color and recursively explore its neighbors. This continues until all connected pixels are filled.

3. **Direction of exploration:**
   The flood fill explores the four possible directions (up, down, left, and right) from any pixel. If a neighbor is within the bounds of the image and has the same color as the starting pixel, it is recursively filled.

4. **Boundary checks:**
   Ensure that the current pixel is within the valid boundaries of the image (i.e., it should not go out of bounds).

By following this approach, we efficiently fill the connected regions in the image, and the solution has a linear time complexity proportional to the size of the image.

### Code Breakdown (Step by Step)

#### 1. **The `floodFill` Function**
   - This is the main function that initiates the flood fill process.
   - It takes the image (a 2D vector), the starting row (`sr`), starting column (`sc`), and the new color to fill (`color`).
   - Before starting the DFS, the function checks whether the new color is the same as the current color of the starting pixel (`image[sr][sc]`). If they are the same, the image is returned as is because no change is needed.

   ```cpp
   vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       if(color == image[sr][sc]) return image;  // Base case: If the target color is the same as the current color, return the image
       dfs(image, sr, sc, color, image[sr][sc]);  // Call DFS to perform the flood fill
       return image;  // Return the updated image
   }
   ```

   - If the initial pixel's color is different from the new color, the DFS function is called with the starting pixel coordinates, new color, and the current color of the starting pixel.

#### 2. **The `dfs` (Depth-First Search) Function**
   - The `dfs` function is the core of the flood fill process. It recursively explores the neighboring pixels and fills them if they match the initial color.

   ```cpp
   void dfs(vector<vector<int>> & img, int r, int c, int color, int node) {
       int m = img.size(), n = img[0].size();  // Get the dimensions of the image
       if (r < 0 || c < 0 || r == m || c == n || img[r][c] != node) return;  // Base case: Boundary or mismatched color
       
       img[r][c] = color;  // Fill the current pixel with the new color
       
       dfs(img, r + 1, c, color, node);  // Explore the pixel below (down)
       dfs(img, r, c + 1, color, node);  // Explore the pixel to the right (right)
       dfs(img, r - 1, c, color, node);  // Explore the pixel above (up)
       dfs(img, r, c - 1, color, node);  // Explore the pixel to the left (left)
   }
   ```

   - **Base Condition:** 
     The function first checks if the current pixel is out of bounds or if it doesn't match the initial color (i.e., `img[r][c] != node`). If any of these conditions are true, it simply returns without doing anything.
   
   - **Recursion:** 
     If the current pixel matches the initial color (`node`), it is filled with the new color (`color`). The DFS function is then called recursively for the neighboring pixels in all four directions (up, down, left, and right).

   - **Termination:** 
     The recursion terminates when all reachable pixels with the same color as the starting pixel are filled.

#### 3. **The Recursive Process**
   - Starting from the pixel at `(sr, sc)`, the `dfs` function works recursively to fill all connected pixels that have the same initial color. The recursion explores all directions (up, down, left, and right) until all connected pixels are processed.

   - Once all reachable pixels are filled, the function returns, and the updated image is returned from the `floodFill` function.

### Complexity

#### Time Complexity:
- The time complexity of the flood fill operation is **O(m * n)**, where `m` is the number of rows and `n` is the number of columns in the image.
- In the worst case, all pixels in the image need to be visited, which is why the time complexity is proportional to the total number of pixels.

#### Space Complexity:
- The space complexity is **O(m * n)** in the worst case, due to the space required by the recursion stack in the DFS. If the entire image is a single connected region, the recursion depth could reach `m * n`, causing the space complexity to be proportional to the number of pixels.
- In practice, the space complexity may be smaller if fewer pixels are visited.

### Conclusion

The flood fill algorithm efficiently modifies a 2D grid by starting from a given pixel and recursively filling all connected pixels with the same color using DFS. This solution is particularly useful in scenarios like image editing, where we need to change the color of a specific region in an image. 

The approach uses recursion to explore all four directions from the starting pixel and fill all connected pixels, ensuring that no pixel is missed. The solution is efficient, with a time complexity of **O(m * n)**, where `m` and `n` are the dimensions of the image.

This code provides a robust method for performing flood fills in grid-based problems and can be extended to various applications such as image processing, game development (e.g., area filling), and other grid-based algorithms.

[`Link to LeetCode Lab`](https://leetcode.com/problems/flood-fill/description/)

---
{{< youtube NomjaXe6kUE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
